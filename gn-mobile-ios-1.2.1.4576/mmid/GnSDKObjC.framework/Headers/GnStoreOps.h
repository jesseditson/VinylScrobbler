/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnStoreOps_h_
#define _GnStoreOps_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
* GNSDK persistent store configuration and maintenance operations
*/ 

@interface GnStoreOps : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Specify the location of the persistent store.
*
*  If location is not specified using this method the location set for the initialized storage SDK will be used.
*  For example, if the SQLite Storage SDK has been initialized, any path set using
*  <code>GnStorageSqlite.StorageLocation(..)</code> will be used.
*
*  The storage location must be a valid relative or absolute path to an existing folder that
*  has the necessary write permissions.
*
*  <p><b>Important:</b></p>
*  For Windows CE an absolute path must be used.
*  @param location [in] response cache location
*/ 

-(void) location: (nullable NSString*)location error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Clears all records from the persistent store.
*
*  When the <code>bAsync</code> is set to true the function immediately
*  returns and the flush is performed in the background and on a separate thread.
*
*  Performance
*
*  If <code>bAsync</code> is true this API spawns a thread to perform the operation. This thread runs at the
*  lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This function can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  @param bAsync [in] if true perform an asynchronous cache flush in the background on a separate thread
*/ 

-(void) flush: (BOOL)bAsync error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Attempts to compact the persistent store and minimize the amount of space required.
*
*  When the <code>bAsync</code> is set to true the function immediately
*  returns and the compact is performed in the background and on a separate thread.
*
*  Performance
*
*  If <code>bAsync</code> is true this API spawns a thread to perform the operation. This thread runs at the
*  lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This method can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  @param bAsync [in] if true perform an asynchronous cache compact in the background on a separate thread
*/ 

-(void) compact: (BOOL)bAsync error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Searches the existing local store and removes any records that are expired or unneeded.
*
*  Operation
*
*  This API first decides if maintenance is required; this is determined by tracking when the next
*  record expiration is needed.
*
*  Maintenance is always run the first time this API is called; any subsequent calls only perform
*  maintenance if this is required. Consequently, calling this API multiple times does not result in
*  excessive maintenance.
*
*  Performance
*
*  If <code>bAsync</code> is true and if maintenance is necessary, this API spawns a thread to perform the clean-up.
*  This thread runs at the lowest priority to minimize the impact on other running queries or operations of the SDK.
*
*  This function can cause performance issues due to creating a large amount of disk I/O.
*
*  This operation can be performed on different storages at the same time, but note that performing
*  multiple simultaneous calls will potentially further degrade performance.
*
*  Expired Records
*
*  Expired records are those older than the maximum allowable, even if the record has been recently
*  read. Old but actively read records are removed because Gracenote Service may have an updated
*  matching record.
*
*  The maximum allowable age of a record varies by query type and is managed internally by
*  Gracenote. Applications can use GnUser option to adjust the age at which
*  records are expired.
*
*  @param bAsync [in] if true perform an asynchronous cache clean-up maintenance in the background on a separate thread
*
*/ 

-(void) cleanup: (BOOL)bAsync error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnStoreOps_h_ */

