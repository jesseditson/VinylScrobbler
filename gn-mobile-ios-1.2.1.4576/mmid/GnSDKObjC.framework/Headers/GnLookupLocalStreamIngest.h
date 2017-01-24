/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLookupLocalStreamIngest_h_
#define _GnLookupLocalStreamIngest_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnLookupLocalStreamIngestEventsDelegate.h"
#import "GnEnums.h"




/**
* GnLookupLocalStreamIngest
*/
@interface GnLookupLocalStreamIngest : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Constructor for creating a GnLookupLocalStreamIngest object
*  @param pEventDelegate           [in] Delegate to receive events.
*  @param callbackData             [in] Optional user data that will be sent to the delegate.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithEventsDelegate: (nullable id <GnLookupLocalStreamIngestEventsDelegate>)eventsDelegate error: (NSError**)error;

/**
* Write to the ingestion process. You can call this multiple times to ensure that data is written when it is available.
*  @param data             [in] data to ingest
*  @param dataLength       [in] size of data being written
*/ 

-(void) write:(NSData*)data  error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Flushes the memory cache to the file storage and commits the changes. This call results in IO.
* Call this method to ensure that everything written is commited to the file system.
* Note: This is an optional call as, internally, data is flushed when it exceeds the cache size and when the object goes out of scope.
*/ 

-(void) flush: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLookupLocalStreamIngest_h_ */

