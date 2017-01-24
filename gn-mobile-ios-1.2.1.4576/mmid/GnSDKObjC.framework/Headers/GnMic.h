/*
 * Copyright (c) 2012 Gracenote.
 *
 * This software may not be used in any way or distributed without
 * permission. All rights reserved.
 *
 * Some code herein may be covered by US and international patents.
 */

// This class requires that the application link to the Apple AudioToolbox Framework.
// Public header

#import <Foundation/Foundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "GnAudioSourceDelegate.h"

/** @addtogroup ios iOS
 *  \brief iOS specific APIs
 *  @{
 */

/**
 * The GnMic class manages the recording of audio from the device microphone and
 * allows for simple plug-in of the audio source with GnMusicIdStream.
 * 
 * This is a Gracenote helper delegate class to extract receive audio from a
 * microphone. It can be used by GNSDK as an audio stream source that can be
 * identified (GnMusicIdStream).
 * 
 * For all helper delegate classes you can provide your own implementation, it just
 * needs to implement the correct interface, in this case GnAudioSourceDelegate. 
 * 
 * If you do provide your own implementation Gracenote recommends starting with
 * this implementation and altering as required; therefore the source is
 * available on request.
 *
 */
@interface GnMic : NSObject <GnAudioSourceDelegate>

/**
 * Acquires audio input hardware resource and initializes it as specified by audioConfig.
 * @param sampleRate       Preferred Sample rate to be used for recording audio.
 * @param bitsPerChannel   The number of bits per channel to use for recording audio.
 * @param numberOfChannels The number of channels used for recording audio. For example: 2 for stereo; 1 for mono.
 * @param delegate         An instance of a class conforming to GnMicDelegate protocol.
 * @return GnMic*          A valid GnMic instance if audio configuration was valid and allocation was successful; nil otherwise.
 */
- (instancetype) initWithSampleRate:(Float64) sampleRate bitsPerChannel:(UInt32) bitsPerChannel numberOfChannels:(UInt32)  numberOfChannels;
@end

/** @} */ // end of ios
