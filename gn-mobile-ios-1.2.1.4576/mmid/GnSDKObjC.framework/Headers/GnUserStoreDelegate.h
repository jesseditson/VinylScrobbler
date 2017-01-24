/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnUserStoreDelegate_h_
#define _GnUserStoreDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





NS_ASSUME_NONNULL_BEGIN

@protocol GnUserStoreDelegate <NSObject>

@required

/**
* LoadSerializedUser
*/
-(nullable NSString*) loadSerializedUser: (nonnull NSString*)clientId;

/**
* StoreSerializedUser
*/
-(BOOL) storeSerializedUser: (nonnull NSString*)clientId userData: (nonnull NSString*)userData;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnUserStoreDelegate_h_ */

