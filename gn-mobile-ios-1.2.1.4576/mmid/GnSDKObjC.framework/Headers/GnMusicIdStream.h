/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdStream_h_
#define _GnMusicIdStream_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAudioSourceDelegate.h"
#import "GnCancellableDelegate.h"
#import "GnLocale.h"
#import "GnMusicIdStreamEventsDelegate.h"
#import "GnEnums.h"
#import "GnMusicIdStreamOptions.h"
#import "GnResponseAlbums.h"
#import "GnUser.h"
#import "GnStatusEventsDelegate.h"




/**
*
* GnMusicIdStream provides services for identifying music within a continuous audio stream.
* As data is received from the audio stream, it is provided to GnMusicIdStream, when the application
* wishes to identify the audio it initializes an identification. The results of the identification
* are delivered asynchronously to a delegate object.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Streaming Music
*
* For more information on using MusicID-Stream/Radio, see the above topic which covers:
* <ul>
*     <li>General information about identifying streaming music</li>
*     <li>How to identify streaming audio from an audio source (IGnAudioSource implementation)</li>
*     <li>Setting options for streaming audio queries</li>
*     <li>Music-ID Stream/Radio code samples</li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/musicid_stream_manual
*
* <p><b>Overview</b></p>
*
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Radio
*
* Note: Customers must be licensed to implement use of a MusicID product in an application.
* Contact your Gracenote support representative with questions about product licensing and
* entitlement.
*/ 

@interface GnMusicIdStream : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Establishes an audio stream identification object with locale. The locale is used to determine
*  the preferred language and script of stream identification results.
*  Note: Results are only returned in preferred language and script where available.
*  @param user 			[in] Gracenote user
*  @param preset 			[in] Gracenote musicID stream preset
*  @param locale 			[in] Gracenote locale
*  @param pEventDelegate 	[in] Audio processing and identification query events handler
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user preset: (GnMusicIdStreamPreset)preset locale: (nonnull GnLocale*)locale musicIdStreamEventsDelegate: (nullable id <GnMusicIdStreamEventsDelegate>)pEventDelegate error: (NSError**)error;

/**
*  Establishes an audio stream identification object with locale. The locale is used determine
*  the preferred language and script of stream identification results.
*  Note: Results are only returned in preferred language and script where available.
*  @param user 			[in] Gracenote user
*  @param preset			[in] Gracenote musicID stream preset
*  @param pEventDelegate 	[in] Audio processing and identification query events handler
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user preset: (GnMusicIdStreamPreset)preset musicIdStreamEventsDelegate: (nullable id <GnMusicIdStreamEventsDelegate>)pEventDelegate error: (NSError**)error;

/**
*  Retrieves the MusicID-Stream SDK's version string.
*  @return Version string if successful
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
*  The returned string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the MusicID-Stream SDK's build date string.
*  @return Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully establishing a MusicID-Stream audio channel.
*  The returned string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
* Get GnMusicIdStream options object. Use to configure your GnMusicIdStream instance.
* @return Options objects
*/ 

-(nonnull GnMusicIdStreamOptions*) options;

/**
* Commence retrieving and processing audio from an object implementing the audio source interface.
* This is an alternate and often simpler method for providing audio to GnMusicIdStream
* instead of calling AudioProcessStart (audio format overload) and AudioProcess.
* To use this method the audio source to be identified must be accessible via an GnAudioSourceDelegate
* implementation. Custom implementations of GnAudioSourceDelegate are encouraged.
* Note: audio is retrieved from the audio source in a loop so some applications may wish to start
* automatic audio processing in a background thread to avoid stalling the main thread.
* @param audioSource	[in] Audio source to be identified
*/ 

-(void) audioProcessStart: (nonnull id <GnAudioSourceDelegate>)audioSource error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Initialize manual delivery of audio stream audio to GnMusicIdStream. GnMusicIdStream
* establishes buffers and audio processing modules, readying itself to receive audio.
* @param samplesPerSecond	[in] Number of samples per second
* @param bitsPerSample		[in] Number of bits per sample
* @param numberOfChannels	[in] Number of channels
*/ 

-(void) audioProcessStart: (NSUInteger)samplesPerSecond bitsPerSample: (NSUInteger)bitsPerSample numberOfChannels: (NSUInteger)numberOfChannels error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Stops audio processing. If audio processing was started with an object implementing GnAudioSourceDelegate
* the audio source is closed and data is no longer retrieved from that source. If manual audio processing
* was used future attempts to write audio data for processing will fail.
*/ 

-(void) audioProcessStop: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Provides audio manually for processing by GnMusicIdStream. This should not be called if
* audio processing was started with an object implementing the audio source interface.
* @param data [in] Input data
* */ 

-(void) audioProcess:(NSData*)data  error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* @deprecated Will be removed next release, use IdentifyAlbumAsync and WaitForIdentify instead.
* Identifying the audio in the audio stream and blocks until identification is
* complete. Results are delivered asynchronously via GnMusicIdStreamEventsDelegate delegate.
*/ 

-(void) identifyAlbum: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Identifying the audio in the audio stream. Results are delivered
* asynchronously via GnMusicIdStreamEventsDelegate delegate.
*/ 

-(void) identifyAlbumAsync: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Wait for currently running identify call to complete (up to timeout_ms milliseconds).
* Returns true if identification completed in the timeout period, false if not
* @param timeout_ms	[in] Timeout in milliseconds
* @return true			True if completed, false if timed out
*/ 

-(BOOL) waitForIdentify: (NSUInteger)timeout_ms error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Cancel the current identify operation blocking until the identification has stopped.
* Cannot be called from within a GnMusicIdStream delegate callback, use the canceller provided
* in the callback instead. This will throw an exception if it is used with the automatic mode
* on.
*/ 

-(void) identifyCancel: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* InfoGet
*/
-(nullable NSString*) infoGet: (nullable NSString*)info_key error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdStream_h_ */

