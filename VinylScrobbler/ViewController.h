//
//  ViewController.h
//  VinylScrobbler
//
//  Created by Jesse Ditson on 1/15/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@interface ViewController : UIViewController <AVAudioRecorderDelegate, AVAudioPlayerDelegate>

@property (weak, nonatomic) IBOutlet UILabel *messageLabel;
@property (weak, nonatomic) IBOutlet UIButton *recordButton;
@property (weak, nonatomic) IBOutlet UIButton *fingerprintButton;

@end

