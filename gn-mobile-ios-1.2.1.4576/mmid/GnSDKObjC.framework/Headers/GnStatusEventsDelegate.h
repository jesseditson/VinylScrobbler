/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnStatusEventsDelegate_h_
#define _GnStatusEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"




NS_ASSUME_NONNULL_BEGIN

@protocol GnStatusEventsDelegate <NSObject>

@required

/**
* Status change notification method. Override to receive notification.
* @param status				[in] Status type
* @param percentComplete		[in] Operation progress
* @param bytesTotalSent		[in] Total number of bytes sent
* @param bytesTotalReceived	[in] Total number of bytes received
* @param canceller				[in] Object that can be used to canel the operation
*/ 

-(void) statusEvent: (GnStatus)status percentComplete: (NSUInteger)percentComplete bytesTotalSent: (NSUInteger)bytesTotalSent bytesTotalReceived: (NSUInteger)bytesTotalReceived cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnStatusEventsDelegate_h_ */

