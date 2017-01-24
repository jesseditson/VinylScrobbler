/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdStreamEventsDelegate_h_
#define _GnMusicIdStreamEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"
#import "GnResponseAlbums.h"
#import "GnStatusEventsDelegate.h"


@class GnResponseAlbums;


NS_ASSUME_NONNULL_BEGIN

@protocol GnMusicIdStreamEventsDelegate <GnStatusEventsDelegate>

@required

/**
* MusicIdStreamProcessingStatusEvent is currently considered to be experimental.
* An application should only use this option if it is advised by Gracenote representative.
* Contact your Gracenote representative with any questions about this enhanced functionality.
* @param status		Status
* @param canceller		Cancellable that can be used to cancel this processing operation
*/ 

-(void) musicIdStreamProcessingStatusEvent: (GnMusicIdStreamProcessingStatus)status cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
* Provides GnMusicIdStream identifying status notification
* @param status		Status
* @param canceller		Cancellable that can be used to cancel this identification operation
*/ 

-(void) musicIdStreamIdentifyingStatusEvent: (GnMusicIdStreamIdentifyingStatus)status cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
* A result is available for a GnMusicIdStream identification request
* @param result		Result
* @param canceller		Cancellable that can be used to cancel this identification operation
*/ 

-(void) musicIdStreamAlbumResult: (nonnull GnResponseAlbums*)result cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;

/**
* Identifying request could not be completed due to the reported error condition
* @param completeError	Error condition information
*/ 

-(void) musicIdStreamIdentifyCompletedWithError: (nonnull NSError*)completeError;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnMusicIdStreamEventsDelegate_h_ */

