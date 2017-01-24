//
//  GnAudioFileDecoder.h
//  gnsdk_objc
//  Created on 10/2/13
//  Copyright Gracenote Inc. 2011. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GnAudioSourceDelegate.h"


/**
 * Provides a means to read an audio file and return data as raw PCM.
 * 
 * This is a Gracenote helper delegate class to extract raw audio from encoded
 * audio files. It can be used by GNSDK to generate MusicID-File fingerprints.
 * 
 * For all helper delegate classes you can provide your own implementation, it just
 * needs to implement the correct interface, in this case GnAudioSourceDelegate. 
 * 
 * If you do provide your own implementation Gracenote recommends starting with
 * this implementation and altering as required; therefore the source is
 * available on request.
 * 
 */
@interface GnAudioFile:NSObject <GnAudioSourceDelegate>


@property(nonatomic, strong) NSURL *audioFileUrl;
@property(nonatomic, strong) NSURL *tempFileUrl;

/**
 * Initializes and returns a GnAudioFile instance.
 * @param audioFileUrl NSURL instance containing URL to an audio file.
 * @return void        A valid GnAudioFile instance if allocation was successful; nil otherwise.
 */
-(instancetype) initWithAudioFileURL:(NSURL*) inAudioFileUrl;


/**
 * Starts decoding the audio file residing at audioFileURL passed in while initilizing GnAudioFile class.
 * @param error    NSError object that will be initialized with error code and description if an exception is caught; nil otherwise.
 * @return void    Returns nothing (void).
 */

-(void) startDecoding:(NSError**) error;


@end
