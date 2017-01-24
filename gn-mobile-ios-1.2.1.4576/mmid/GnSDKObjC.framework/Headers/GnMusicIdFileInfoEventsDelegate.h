/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdFileInfoEventsDelegate_h_
#define _GnMusicIdFileInfoEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnMusicIdFileInfo.h"


@class GnMusicIdFileInfo;


NS_ASSUME_NONNULL_BEGIN

@protocol GnMusicIdFileInfoEventsDelegate <NSObject>

@required

/**
*  Callback function declaration for a fingerprint generation request.
*  @param fileinfo 		[in] FileInfo object that the callback operates on
*  @param currentFile 		[in] Current number of the file being processed
*  @param totalFiles 		[in] Total number of files to be processed
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*  The application can implement this callback to use the fingerprint_begin(), fingerprint_write() and fingerprint_end() APIs with the given FileInfo object to
			   generate a fingerprint from raw audio. If your application already has created the fingerprint for the respective file,
			   the application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no fingerprint has already been set for the passed FileInfo object.
*/ 

-(void) gatherFingerprint: (nonnull GnMusicIdFileInfo*)fileinfo currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
*  Callback function declaration for a metadata gathering request.
*  @param fileinfo 		[in] FileInfo object that the callback operates on
*  @param currentFile 		[in] Current number of the file being processed
*  @param totalFiles 		[in] Total number of files to be processed
*  @param canceller		[in] Object that can be used to cancel processing if desired
*  <p><b>Remarks:</b></p>
*   The application should implement this callback to use the GnMusicIdFileInfo.set*() API to set any metadata values in the FileInfo object.
			   This callback is called only if no metadata has already been set for the passed FileInfo.
*/ 

-(void) gatherMetadata: (nonnull GnMusicIdFileInfo*)fileinfo currentFile: (NSUInteger)currentFile totalFiles: (NSUInteger)totalFiles cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnMusicIdFileInfoEventsDelegate_h_ */

