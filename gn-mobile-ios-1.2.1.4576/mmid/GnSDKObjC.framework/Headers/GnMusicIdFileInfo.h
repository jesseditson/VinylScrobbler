/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdFileInfo_h_
#define _GnMusicIdFileInfo_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAudioSourceDelegate.h"
#import "GnEnums.h"
#import "GnResponseAlbums.h"
#import "GnResponseDataMatches.h"




/**
*  Container class for providing media file information to MusicID-File.
*/ 

@interface GnMusicIdFileInfo : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Retrieves the identifier string from a FileInfo object.
*  @return gnsdk_cstr_t Pointer to receive the data value defined for the identifier
*/ 

-(nullable NSString*) identifier: (NSError**)error;

/**
*  Get the file name
*  @return File name
*/ 

-(nullable NSString*) getFileName: (NSError**)error;

/**
*  Set the file name
*  @param value			[in] The file name to set
*/ 

-(void) fileName: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the Gracenote CDDB ID value from a FileInfo object.
*  @return Identifier
*/ 

-(nullable NSString*) getCddbId: (NSError**)error;

/**
*  Sets the Gracenote CDDB ID.
*  @param value			[in] The Gracenote CDDB ID to set
*/ 

-(void) cddbId: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the album artist
*  @return Artist name
*/ 

-(nullable NSString*) getAlbumArtist: (NSError**)error;

/**
*  Sets the album artist
*  @param value			[in] The album artist to set
*/ 

-(void) albumArtist: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the album title
*  @return Album title
*/ 

-(nullable NSString*) getAlbumTitle: (NSError**)error;

/**
*  Sets the album title
*  @param value			[in] The album title to set
*/ 

-(void) albumTitle: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the track artist
*  @return Track artist
*/ 

-(nullable NSString*) getTrackArtist: (NSError**)error;

/**
*  Sets the track artist
*  @param value			[in] The track artist to use
*/ 

-(void) trackArtist: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the track title
*  @return Track title
*/ 

-(nullable NSString*) getTrackTitle: (NSError**)error;

/**
*  Sets the track title
*  @param value			[in] The track title to set
*/ 

-(void) trackTitle: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the track number
*  @return Track number
*/ 

-(NSUInteger) getTrackNumber: (NSError**) error NS_REFINED_FOR_SWIFT;

/**
*  Sets the track number
*  @param value			[in] The track number to set
*/ 

-(void) trackNumber: (NSUInteger)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the disc number
*  @return Disc number
*/ 

-(NSUInteger) getDiscNumber: (NSError**) error NS_REFINED_FOR_SWIFT;

/**
*  Sets the disc number
*  @param value			[in] The disc number to set
*/ 

-(void) discNumber: (NSUInteger)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the tag ID
*  @return Tag identifier
*/ 

-(nullable NSString*) getTagId: (NSError**)error;

/**
*  Sets the tag ID
*  @param value			[in] The tag ID to set
*/ 

-(void) tagId: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the fingerprint data
*  @return Fingerprint data
*/ 

-(nullable NSString*) getFingerprint: (NSError**)error;

/**
*  Sets the fingerprint
*  @param value			[in] The fingerprint to set
*/ 

-(void) fingerprint: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the media ID
*  @return Media identifier
*/ 

-(nullable NSString*) getMediaId: (NSError**)error;

/**
*  Sets the media ID
*  @param value			[in] The media ID to set
*/ 

-(void) mediaId: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the Media Unique ID (MUI)
*  @return Media unique identifier
*/ 

-(nullable NSString*) getMui: (NSError**)error;

/**
*  Sets the Media Unique ID (MUI)
*  @param value			[in] The Media Unique ID (MUI) to set
*/ 

-(void) mui: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the CDTOC value
*  @return CDTOC value
*/ 

-(nullable NSString*) getCdToc: (NSError**)error;

/**
*  Sets the CDTOC value
*  @param value			[in] The CDTOC to set
*/ 

-(void) cdToc: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the Title Unique Identifier (Tui)
*  @return Title unique identifier
*/ 

-(nullable NSString*) getTui: (NSError**)error;

/**
*  Sets the Title Unique Identifier (Tui)
*  @param value			[in] The Title Unique Identifier (Tui) to set
*/ 

-(void) tui: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Gets the Tui tag
*  @return Tui tag
*/ 

-(nullable NSString*) getTuiTag: (NSError**)error;

/**
*  Sets the Tui tag
*  @param value			[in] The Tui tag to set
*/ 

-(void) tuiTag: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initializes fingerprint generation.
*  @param audioSampleRate	[in] Set sample frequency of audio to be provided: 11 kHz, 22 kHz, or 44 kHz
*  @param audioSampleSize	[in] Set sample rate of audio to be provided (in 8-bit, 16-bit, or 32-bit bytes per sample)
*  @param audioChannels	[in] Set number of channels for audio to be provided (1 or 2)
*  <p><b>Remarks:</b></p>
*  The MusicID-File fingerprinting APIs allow your application to provide audio data, as opposed to
*  using only associated metadata, for identification.
*  Use these APIs either before processing has begun or during a
*  GnMusicIdFileEventsDelegate or GnMusicIdFileInfoEventsDelegate delegate method call.
*/ 

-(void) fingerprintBegin: (NSUInteger)audioSampleRate audioSampleSize: (NSUInteger)audioSampleSize audioChannels: (NSUInteger)audioChannels error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Provides uncompressed audio data for fingerprint generation.
*  @param data [in] Input data
* @return bool Checks whether the fingerprint generation has received enough audio data
*  <p><b>Remarks:</b></p>
*  The provided audio data must be uncompressed PCM data and must match the format given to fingerprintBegin().
*  Returns true when the fingerprinter has received enough audio data for
*  processing. Any further provided audio data is ignored.
*  Your application must provide audio data until true is returned
*  to successfully generate an audio fingerprint.
*  Your application must complete the fingerprinting process by calling
*  FingerprintEnd() when either the audio data terminates, or after true is returned.
*  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
*  GnMusicIdFileEventsDelegate or GnMusicIdFileInfoEventsDelegate delegate method call.
*/ 

-(BOOL) fingerprintWrite:(NSData*)data  error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
*  Finalizes fingerprint generation.
*  <p><b>Remarks:</b></p>
*  The application must complete the fingerprinting process by calling
*  fingerprint_end when either the audio data terminates, or after receiving
*  a GNSDK_TRUE value.
*  Use the MusicID-File fingerprinting APIs either before processing has begun, or during a
*  GnMusicIdFileEventsDelegate or GnMusicIdFileInfoEventsDelegate delegate method call.
*/ 

-(void) fingerprintEnd: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Generate a fingerprint from audio pulled from the provided audio source
*  @param audioSource		[in] audio source representing the file being identified
*/ 

-(void) fingerprintFromSource: (nonnull id <GnAudioSourceDelegate>)audioSource error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieves the current status for a specific FileInfo object.
*  <p><b>Remarks:</b></p>
*  The File Info object's state value indicates what kind of response is available for a FileInfo object after
*  MusicID-File. In the case of an error, error info can be retrieved from the FileInfo object.
*/ 

-(GnMusicIdFileInfoStatus) status: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieves the error information for a FileInfo object. This is related to the status returned.
*  If the status is error, this call returns the extended error information.
*  <p><b>Remarks:</b></p>
*  An error object is returned representing the FileInfo error condition. An error object exception
*  may be thrown if an error occurred retrieving the FileInfo object's error object.
*/ 

-(nullable NSError*) errorInformation: (NSError**)error;

/**
*  Retrieves the album response if available
*  @return Album response
*  <p><b>Remarks:</b></p>
*  This function retrieves the album response object of the match for this file information object if available.
*  Use Status() to determine if a response is available for this file information object.
*/ 

-(nullable GnResponseAlbums*) albumResponse: (NSError**)error;

/**
*  Retrieves the data match response if available
*  @return Data match response
*  <p><b>Remarks:</b></p>
*  This function retrieves the data match response object of the match for this file information object if available.
*  Data match responses mean the match could be an album or contributor or a mix thereof depending on the query options.
*  Use Status() to determine if a response is available for this file information object.
*/ 

-(nullable GnResponseDataMatches*) dataMatchResponse: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnMusicIdFileInfoEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnMusicIdFileInfoBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnMusicIdFileInfoBlock)handler;

-(NSUInteger) count;

-(nullable GnMusicIdFileInfo*) nextObject;

-(nullable GnMusicIdFileInfo*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdFileInfo_h_ */

