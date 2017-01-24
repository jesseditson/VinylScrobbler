/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdFile_h_
#define _GnMusicIdFile_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"
#import "GnMusicIdFileEventsDelegate.h"
#import "GnMusicIdFileInfo.h"
#import "GnMusicIdFileInfoManager.h"
#import "GnMusicIdFileOptions.h"
#import "GnResponseAlbums.h"
#import "GnResponseDataMatches.h"
#import "GnUser.h"
#import "GnStatusEventsDelegate.h"




/**
*  Performs bulk audio track recognition
*
*  MusicID-File is intended to be used with collections of file-based media.
*  When an application provides decoded audio and text data for each file to the
*  library, the MusicID-File functionality both identifies each file and groups
*  the files into albums.
*
* <p><b>SDK Documentation</b></p>
* <b>Topic:</b> Implementing Applications (All Platforms) > Identifying Music > Identifying Audio Files
*
* For more information on using MusicID-File, see the above topic which covers:
* <ul>
*     <li>MusicID file identification mechanisms (TrackID, AlbumID, and LibraryID)</li>
*     <li>How to identify audio from a file</li>
*     <li>Implementing an events delegate<ul>
*     <li>Events delegate code samples</li></ul></li>
*     <li>Adding audio files for identification<ul>
*     <li>Adding audio files code samples</li></ul></li>
*     <li>Setting audio file identification<ul>
*     <li>Audio file identification code samples</li></ul></li>
*     <li>MusicID-File fingerprinting<ul>
*     <li>Fingerprinting code samples</li></ul></li>
*     <li>Setting options for MusicID-File queries</li>
*     <li>Making a MusicID-File query<ul>
*     <li>MusicID-file query options</li>
*     <li>Setting options code samples</li></ul></li>
* </ul>
*
* <p><b>Sample Apps</b></p>
* <ul>
*    <li>.../samples/musicid_file_trackid</li>
*    <li>.../samples/musicid_file_albumid</li>
*    <li>.../samples/musicid_file_libraryid</li>
* </ul>
*
* <p><b>Overiew</b></p>
* <b>Topic:</b> Concepts > Music Modules > Music Module Overview > MusicID-File Overview
*/ 

@interface GnMusicIdFile : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Constructs an audio track identification object
*  @param user 			[in] Gracenote user object representing the user making the GnMusicIdFile request
*  @param pEventHandler	[in] Delegate object for receiving processing events
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user musicIdFileEventsDelegate: (nullable id <GnMusicIdFileEventsDelegate>)pEventHandler error: (NSError**)error;

/**
*  Retrieves the MusicID-File library's version string.
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the MusicID-File library's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully instantiating a GnManager instance.
*  The returned string is a constant. Do not attempt to modify or delete.
*
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
*  Retrieves the GnMusicIdFileOptions object.
*/ 

-(nonnull GnMusicIdFileOptions*) options;

/**
*  Retrieves the GnMusicIdFileInfoManager object.
*/ 

-(nonnull GnMusicIdFileInfoManager*) fileInfos;

/**
*  Initiates TrackId processing.
*
*  @param processType		[in] Specifies what you get back
*  @param responseType		[in] Match response or album response
*
*  <p><b>Remarks:</b></p>
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently
*  and is intended to be used with a small number of tracks that do not relate to other tracks in
*  the user's collection.
*/ 

-(void) doTrackId: (GnMusicIdFileProcessType)processType responseType: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initiates TrackId processing asynchronously.
*
*  @param processType		[in] specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  TrackId processing performs MusicID-File recognition on each given FileInfo independently
*  and is intended to be used with small number of tracks that do not relate to other tracks in
*  the user's collection.
*/ 

-(void) doTrackIdAsync: (GnMusicIdFileProcessType)processType responseType: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initiates AlbumId processing.
*
*  @param processType		[in] Process type specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
*  the files to albums. Intended to be used with a small number of related tracks.
*/ 

-(void) doAlbumId: (GnMusicIdFileProcessType)processType responseType: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initiates AlbumId processing asynchronously .
*
*  @param processType		[in] Process type specifies what you get back
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  AlbumId processing performs MusicID-File recognition on all of the given FileInfos as a group.
*  This type of processing can be more accurate than TrackId processing, as AlbumId processing matches
*  the files to albums. Intended to be used with a small number of related tracks.
*/ 

-(void) doAlbumIdAsync: (GnMusicIdFileProcessType)processType responseType: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initiates LibraryId processing.
*
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
*  processing divides the given group of FileInfos into workable batches, and then processes each batch
*  using AlbumId functionality.
*/ 

-(void) doLibraryId: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Initiates LibraryId processing asyncronously
*
*  @param responseType		[in] match response or album response
*
*  <p><b>Remarks:</b></p>
*  LibraryId processing performs MusicID-File recognition on a large number of given FileInfos. This
*  processing divides the given group of FileInfos into workable batches, and then processes each batch
*  using AlbumId functionality.
*/ 

-(void) doLibraryIdAsync: (GnMusicIdFileResponseType)responseType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Wait for a MusicID-File operation to complete, wait for the specified number of milliseconds.
*  @param timeoutValue		[in] Length of time to wait in milliseconds
*  <p><b>Remarks:</b></p>
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
*  a given GnMusicIdFile instance.
*/ 

-(void) waitForComplete: (NSUInteger)timeoutValue error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Wait for a MusicID-File operation to complete with infinite wait time.
*  <p><b>Remarks:</b></p>
*  Use this function to set a wait for TrackId, AlbumId, or LibraryId processing to complete for
*  a given GnMusicIdFile instance.
*/ 

-(void) waitForComplete: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Set cancel state
*/ 

-(void) cancel: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdFile_h_ */

