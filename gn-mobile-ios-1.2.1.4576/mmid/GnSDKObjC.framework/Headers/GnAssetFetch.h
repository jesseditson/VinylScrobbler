/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAssetFetch_h_
#define _GnAssetFetch_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"




/**
* <b>Experimental</b>: Fetch asset raw data.
* The raw data is fetched during object construction
* and may result in lengthy network access if accessing
* from online.
*/ 

@interface GnAssetFetch : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Perform the fetch of the data from the provided URL.
* This method can fetch data from any valid URL. This class must
* be used to fetch data from a GNSDK local URL.
* Construction may result in lengthy network access if the URL is
* online and the target data is large.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUser: (nonnull GnUser*)user url: (nullable NSString*)url statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Retrieves asset data
*/
-(NSData*) data;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnAssetFetch_h_ */

