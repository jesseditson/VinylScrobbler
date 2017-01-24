/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicId_h_
#define _GnMusicId_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAudioSourceDelegate.h"
#import "GnCancellableDelegate.h"
#import "GnDataObject.h"
#import "GnEnums.h"
#import "GnLocale.h"
#import "GnMusicIdOptions.h"
#import "GnResponseAlbums.h"
#import "GnResponseDataMatches.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"




/**
*  \class GnMusicId
*  Provides services for audio recognition using CD TOC-based search,
*  text-based search, fingerprint, and identifier lookup functionality.
*
*  <p><b>SDK Documentation</b></p>
*  <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Music Using a CD-TOC, Text, or Fingerprints (MusicID)
*
*  For more information on using MusicID, see the above topic which covers:
*    <ul>
*   <li>MusicID queries</li>
*   <li>Options for MusicID queries</li>
*   <li>Identifying music using a CD TOC<ul>
*   <li>Code samples for identifying music using a CD TOC</li></ul></li>
*   <li>Identifying music using text<ul>
*   <li>Code samples for identifying music using text</li></ul></li>
*   <li>Identifying music using fingerprints</li>
*   <li>MusicID fingerprinting<ul>
*   <li>Code samples for identifying music using MusicID fingerprinting</li></ul></li>
*   </ul>
*
*  <p><b>Overiew</b></p>
*  <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID Overview
*
*  <p><b>Sample Apps</b></p>
*  <ul>
*     <li>.../samples/musicid_gdo_navigation</li>
*     <li>.../samples/musicid_lookup_album_id</li>
*     <li>.../samples/musicid_lookup_album_local_online</li>
*     <li>.../samples/musicid_lookup_album_toc</li>
*     <li>.../samples/musicid_lookup_matches_text</li>
*     <li>.../samples/musicid_persist_and_manage</li>
*     <li>.../samples/musicid_persist_results</li>
*   </ul>
*
*/ 

@interface GnMusicId : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Constructs a music identification query object with a Gracenote user and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicId request
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
*  Constructs a music identification query object with a Gracenote user, locale and event delegate
*  @param user          [in] Set GnUser object representing the user making the GnMusicId request
*  @param locale		 [in] GnLocale object representing region and language preferred for MusicID-Stream responses
*  @param pEventHandler [in-opt] Set Optional status event handler to get bytes sent, received, or completed.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user locale: (nonnull GnLocale*)locale statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
*  Retrieves the MusicID library version string.
*  @return gnsdk_cstr_t Version string, if successful
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*
*  Minor: New or changed features
*
*  Improvement: Improvements and fixes
*
*  Build: Internal build number
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the MusicID SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
*  Retrieves externally- and internally-generated Gracenote
*  fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint data.
*  @return String fingerprint data
*/ 

-(nullable NSString*) fingerprintDataGet: (NSError**)error;

/**
*  Initializes native fingerprint generation for a MusicID query.
*  @param fpType 			[in] One of the GnFingerprintType fingerprint data types,
*  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX)
*  @param audioSampleRate 	[in] Sample rate of audio to be provided in Hz (for example,44100)
*  @param audioSampleSize 	[in] Size of a single sample of audio to be provided: 8 for 8-bit audio
*  						(0-255 integers), 16 for 16-bit audio , and 32 for 32-bit audio (floating point)
*  @param audioChannels 	[in] Number of channels for audio to be provided (1 or 2)
*/ 

-(void) fingerprintBegin: (GnFingerprintType)fpType audioSampleRate: (NSUInteger)audioSampleRate audioSampleSize: (NSUInteger)audioSampleSize audioChannels: (NSUInteger)audioChannels error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Provides uncompressed audio data to a query for native fingerprint generation and returns
*  a boolean value indicating when enough data has been received.
*  @param data [in] Input data
* @return True fingerprint generation process gathered enough audio data, false otherwise.
*  <p><b>Remarks:</b></p>
*  Call this API after FingerprintBegin() to:
*  <ul>
*  <li>Generate a native Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX) fingerprint.
*  <li>Receive a boolean value indicating whether MusicID has
*  received sufficient audio data to generate the fingerprint.
*  </ul>
*  Additionally, if fingerprints have been generated (as shown by the returned
*  value):
*  <ul>
*  <li>Optimally, stop calling FingerprintWrite after it returns true
*  to conserve application resources.
*  <li>Call FingerprintDataGet() for cases where the application needs to retrieve the
*  raw fingerprint value from storage.
*  </ul>
*/ 

-(BOOL) fingerprintWrite:(NSData*)data  error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
*  Finalizes native fingerprint generation for a MusicID query handle.
*  <p><b>Remarks:</b></p>
*  Call this API when the audio stream ends - this alerts the system that it has received all the
*  available audio for a particular stream.
*  If FingerprintWrite() returns True before the stream ends, we recommend that you:
*  <ul>
*  <li>Stop providing audio at that time, since enough has been received.
*  <li>Do not FingerprintEnd(), as this is unnecessary.
*  </ul>
*  Fingerprints may be generated based on the call to this API; however, this is not guaranteed.
*/ 

-(void) fingerprintEnd: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Creates a fingerprint from the given audio stream represented by an implementation
*  of GnAudioSourceDelegate. Once completed, call FingerprintDataGet() for cases where the application needs
*  to retrieve the raw fingerprint value from storage.
*  This is an alternate and often simpler method for generating a
*  fingerprint instead of calling FingerprintBegin, FingerprintWrite and FingerprintEnd.
*  To use this method, the audio source to be fingerprinted must be accessible via an GnAudioSourceDelegate
*  implementation. Custom implementations of GnAudioSourceDelegate are encouraged.
*  @param audioSource		[in] Audio source to fingerprint
*  @param fpType			[in] One of the GnFingerprintType fingerprint data types,
*  						either Gracenote Fingerprint Extraction (GNFPX) or Cantametrix (CMX)
*/ 

-(void) fingerprintFromSource: (nonnull id <GnAudioSourceDelegate>)audioSource fpType: (GnFingerprintType)fpType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Performs a MusicID query for album results based on text input.
*  @param albumTitle           [in] Album title
*  @param trackTitle           [in] Track title
*  @param albumArtistName      [in] Album Artist name
*  @param trackArtistName      [in] Track Artist name
*  @param composerName         [in] Album Composer ( e.g. Classical, Instrumental, Movie Score)
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithAlbumTitle: (nullable NSString*)albumTitle trackTitle: (nullable NSString*)trackTitle albumArtistName: (nullable NSString*)albumArtistName trackArtistName: (nullable NSString*)trackArtistName composerName: (nullable NSString*)composerName error: (NSError**)error;

/**
*  Performs a MusicID query for album results using a CD TOC
*  @param CDTOC             [in] Compact Disc Table Of Contents
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
*  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithCDTOC: (nullable NSString*)CDTOC error: (NSError**)error;

/**
*  Performs a MusicID query for album results using CD TOC togther with fingerprint data
*  @param CDTOC             	[in] Compact Disc Table Of Contents
*  @param strFingerprintData	[in] Fingerprint data
*  @param fpType            	[in] One of the GnFingerprintType fingerprint types
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
*  Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithCDTOC: (nullable NSString*)CDTOC strFingerprintData: (nullable NSString*)strFingerprintData fpType: (GnFingerprintType)fpType error: (NSError**)error;

/**
*  Performs a MusicID query for album results using fingerprint data and finger print type.
*  @param fingerprintData 	[in] Fingerprint data
*  @param fpType 			[in] One of the GnFingerprintType fingerprint types
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithFingerprintData: (nullable NSString*)fingerprintData fpType: (GnFingerprintType)fpType error: (NSError**)error;

/**
*  Performs a MusicID query for album results.
*  @param gnDataObject      [in] Gracenote data object
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithDataObject: (nonnull GnDataObject*)dataObject error: (NSError**)error;

/**
*  Performs a MusicID query for album results.
*  @param audioSource     	[in] A valid GnAudioSourceDelegate object.
*  @param fpType 			[in] One of the GnFingerprintType fingerprint types
*  @return An instance of GnResponseAlbums that contain Album metadata.
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseAlbums*) findAlbumsWithAudioSource: (nonnull id <GnAudioSourceDelegate>)audioSource fpType: (GnFingerprintType)fpType error: (NSError**)error;

/**
*  Performs a MusicID query for best Matches results, being GnAlbum and/or GnContributor matches ordered in priority.
*  @param albumTitle             [in] Album title
*  @param trackTitle             [in] Track title
*  @param albumArtistName        [in] Album Artist name
*  @param trackArtistName        [in] Track Artist name
*  @param composerName           [in] Album Composer ( e.g. Classical, Instrumental, Movie Score)
*  @return Response containing Album, Track and Artist metadata.
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*/ 

-(nullable GnResponseDataMatches*) findMatches: (nullable NSString*)albumTitle trackTitle: (nullable NSString*)trackTitle albumArtistName: (nullable NSString*)albumArtistName trackArtistName: (nullable NSString*)trackArtistName composerName: (nullable NSString*)composerName error: (NSError**)error;

/**
* Get GnMusicId options object. Use to configure your GnMusicId instance.
* @return Options objects
*/ 

-(nonnull GnMusicIdOptions*) options;

/**
* Set cancel state
* @param bCancel 	[in] Cancel state
*/ 

-(void) setCancel: (BOOL)bCancel;

/**
* Get cancel state.
* @return Cancel state
*/ 

-(BOOL) isCancelled;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicId_h_ */

