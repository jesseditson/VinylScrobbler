/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdFileEventsDelegate_h_
#define _GnMusicIdFileEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"
#import "GnMusicIdFileInfo.h"
#import "GnResponseAlbums.h"
#import "GnResponseDataMatches.h"
#import "GnStatusEventsDelegate.h"


@class GnMusicIdFileInfo;
@class GnResponseAlbums;
@class GnResponseDataMatches;


NS_ASSUME_NONNULL_BEGIN

@protocol GnMusicIdFileEventsDelegate <GnStatusEventsDelegate>

@required

/**
*  Retrieves the current status.
*  @param fileInfo 		[in] FileInfo object that the callback operates on
*  @param status 			[in] FileInfo status
*  @param currentFile 		[in] Current number of the file being processed
*  @param totalFiles 		[in] Total number of files to be processed by the callback
*  @param canceller		[in] Object that can be used to cancel processing if desired
*/ 

-(void) musicIdFileStatusEvent: (nonnull GnMusicIdFileInfo*)fileInfo status: (GnMusicIdFileCallbackStatus)status currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a fingerprint generation request.
*  @param fileInfo 		[in] FileInfo object that the callback operates on
*  @param currentFile  	[in] Current number of the file being processed
*  @param totalFiles 		[in] Total number of files to be processed
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*  The application can implement this callback to use the fingerprint_begin(), fingerprint_write() and fingerprint_end() APIs with the given FileInfo object to
			   generate a fingerprint from raw audio. If your application already has created the fingerprint for the respective file,
			   the application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no fingerprint has already been set for the passed FileInfo object.
*/ 

-(void) gatherFingerprint: (nonnull GnMusicIdFileInfo*)fileInfo currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a metadata gathering request.
*  @param fileInfo 		[in] FileInfo object that the callback operates on
*  @param currentFile 		[in] Current number of the file being processed
*  @param totalFiles 		[in] Total number of files to be processed
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*   The application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no metadata has already been set for the passed FileInfo.
*/ 

-(void) gatherMetadata: (nonnull GnMusicIdFileInfo*)fileInfo currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a result available notification.
*  @param albumResult  	[in] Album response
*  @param currentAlbum 	[in] Current number of the album in this response
*  @param totalAlbums 		[in] Total number of albums in this response
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*  The provided response will include results for one or more files.
*/ 

-(void) musicIdFileAlbumResult: (nonnull GnResponseAlbums*)albumResult currentAlbum: (NSUInteger)currentAlbum totalAlbums: (NSUInteger)totalAlbums cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a result available notification.
*  @param matchesResult	[in] Match response
*  @param currentAlbum 	[in] Current number of the album in this response
*  @param totalAlbums 		[in] Total number of albums in this response
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*  The provided response will include results for one or more files.
*/ 

-(void) musicIdFileMatchResult: (nonnull GnResponseDataMatches*)matchesResult currentAlbum: (NSUInteger)currentAlbum totalAlbums: (NSUInteger)totalAlbums cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a no results notification.
*  @param fileInfo 		[in] Set FileInfo object that the callback operates on
*  @param currentFile 		[in] Current number of the file that is not found
*  @param totalFiles 		[in] Total number of files to be processed
*  @param canceller		[in] Object that can be used to cancel processing if desired
*/ 

-(void) musicIdFileResultNotFound: (nonnull GnMusicIdFileInfo*)fileInfo currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for MusicID-File processing completion.
*  @param completeError 	[in] Final error value of MusicID-File operation
*/ 

-(void) musicIdFileComplete: (nonnull NSError*)completeError;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnMusicIdFileEventsDelegate_h_ */

