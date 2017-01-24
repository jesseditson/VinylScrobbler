/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnCancellableDelegate_h_
#define _GnCancellableDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





NS_ASSUME_NONNULL_BEGIN

@protocol GnCancellableDelegate <NSObject>

@required

/**
* Set cancel state
* @param bCancel 	[in] Cancel state
*/ 

-(void) setCancel: (BOOL)bCancel;

/**
* Get cancel state
* @return True of cancelled, false otherwise
*/ 

-(BOOL) isCancelled;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnCancellableDelegate_h_ */

