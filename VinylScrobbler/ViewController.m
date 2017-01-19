//
//  ViewController.m
//  VinylScrobbler
//
//  Created by Jesse Ditson on 1/15/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

#import "ViewController.h"
#include <chromaprint.h>

@interface ViewController () {
    AVAudioRecorder *recorder;
    AVAudioPlayer *player;
    NSURL *currentAudioFile;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // create a file to write to
    NSArray *pathComponents = [NSArray arrayWithObjects:
                               [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject],
                               @"audiobuffer.caf",
                               nil];
    currentAudioFile = [NSURL fileURLWithPathComponents:pathComponents];
    
    // set up audio session
    AVAudioSession *session = [AVAudioSession sharedInstance];
    [session setCategory:AVAudioSessionCategoryPlayAndRecord error:nil];
    
    // settings
    NSMutableDictionary *recordSettings = [[NSMutableDictionary alloc] init];
//    [recordSettings setValue:[NSNumber numberWithInt:kAudioFormatMPEG4AAC] forKey:AVFormatIDKey];
    [recordSettings setValue:[NSNumber numberWithFloat:44100.0] forKey:AVSampleRateKey];
    [recordSettings setValue:[NSNumber numberWithInt: 2] forKey:AVNumberOfChannelsKey];
    
    // init recorder
    recorder = [[AVAudioRecorder alloc] initWithURL:currentAudioFile settings:recordSettings error:nil];
    recorder.delegate = self;
    recorder.meteringEnabled = YES;
    [recorder prepareToRecord];
}

- (IBAction)startRecording:(id)sender {
    if (!recorder.recording) {
        AVAudioSession *session = [AVAudioSession sharedInstance];
        [session setActive:YES error:nil];
        [recorder record];
        [_recordButton setTitle:@"Pause" forState:UIControlStateNormal];
    } else {
        [recorder pause];
        [_recordButton setTitle:@"Record" forState:UIControlStateNormal];
    }
}

- (IBAction)fingerprint:(id)sender {
    [recorder stop];
    
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    [audioSession setActive:NO error:nil];
    
    // fingerprint resulting file
//    CFURLRef audioFileRef = (__bridge CFURLRef)(currentAudioFile);
//    AudioFileID fileID;
//    AudioFileOpenURL(audioFileRef, kAudioFileReadPermission, 0, &fileID);
    
    NSData *data = [NSData dataWithContentsOfURL:currentAudioFile options:0 error:nil];
    NSUInteger length = [data length];
    
    ChromaprintContext *ctx;
    char *fp;
    const int sample_rate = 44100;
    const int num_channels = 2;
    ctx = chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
    chromaprint_start(ctx, sample_rate, num_channels);
    
    int16_t *cdata = (int16_t*)malloc(length);
    [data getBytes:(void*)cdata length:length];
    
    chromaprint_feed(ctx, cdata, length);

    chromaprint_finish(ctx);
    chromaprint_get_fingerprint(ctx, &fp);
    printf("%s\n", fp);
    chromaprint_dealloc(fp);
    chromaprint_free(ctx);
    free(cdata);
    
    [_messageLabel setText:[NSString stringWithFormat:@"%s\n", fp]];
}

/** AVAudioRecorderDelegate **/


- (void) audioRecorderDidFinishRecording:(AVAudioRecorder *)avrecorder successfully:(BOOL)flag{
    [_recordButton setTitle:@"Record" forState:UIControlStateNormal];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
