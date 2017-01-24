/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLookupLocalStreamIngestEventsDelegate_h_
#define _GnLookupLocalStreamIngestEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"




NS_ASSUME_NONNULL_BEGIN

@protocol GnLookupLocalStreamIngestEventsDelegate <NSObject>

@required

/**
* StatusEvent
*/
-(void) statusEvent: (GnLookupLocalStreamIngestStatus)status bundleId: (nonnull NSString*)bundleId cancellableDelegate: (nonnull id <GnCancellableDelegate>)canceller;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnLookupLocalStreamIngestEventsDelegate_h_ */

