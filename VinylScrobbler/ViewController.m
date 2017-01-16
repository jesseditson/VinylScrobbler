//
//  ViewController.m
//  VinylScrobbler
//
//  Created by Jesse Ditson on 1/15/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

#import "ViewController.h"
#include <chromaprint.h>

@interface ViewController ()

@end

@implementation ViewController

//ChromaprintContext* ctx;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
//    char *fp;
//    const int sample_rate = 44100;
//    const int num_channels = 2;
//    
//    ctx = chromaprint_new(CHROMAPRINT_ALGORITHM_DEFAULT);
//    
//    chromaprint_start(ctx, sample_rate, num_channels);
//    
//    AudioFileReadPackets(fileID, false, &outNumBytes, NULL, startingPackets, &ioNumPackets, outBuffer);
//    // I tried here reading the packets all at once or by segments, the results are almost the same.
//    
//    chromaprint_feed(ctx, data, size);
//    
//    chromaprint_finish(ctx);
//    chromaprint_get_fingerprint(ctx, &fp);
//    printf("%s\n", fp);
//    chromaprint_dealloc(fp);
//    chromaprint_free(ctx);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
