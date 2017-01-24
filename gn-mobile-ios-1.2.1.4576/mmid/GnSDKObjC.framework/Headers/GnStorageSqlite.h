/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnStorageSqlite_h_
#define _GnStorageSqlite_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnStorageSqlite.h"




/**
* GNSDK SQLite storage provider
*/ 

@interface GnStorageSqlite : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Enable SQLite storage provider
* @return Storage provider instance
*/ 

+(nullable GnStorageSqlite*) enable: (NSError**)error;

/**
*  Retrieves the version string of the Storage SQLite library.
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the build date string of the Storage SQLite library.
*/ 

+(nonnull NSString*) buildDate;

/**
*  Retrieves the version string of the internal SQLite database engine.
*/ 

+(nonnull NSString*) sqliteVersion;

/**
*  Sets a folder location for GNSDK SQLite storage
*  @param folderPath	[in] Relative path name for storage
* <p><b>Remarks:</b></p>
*  This API sets the folder location for ALL GNSDK SQLite storage - to set specific cache or database
*  locations use StorageLocation methods of the appropriate class.
*/ 

-(void) storageLocation: (nullable NSString*)folderPath error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get storage location folder for GNSDK SQLite storage
*/ 

-(nullable NSString*) getStorageLocation: (NSError**)error;

/**
* Get the temporary storage location folder for GNSDK SQLite storage
*/ 

-(nullable NSString*) getTemporaryStorageLocation: (NSError**)error;

/**
*  Sets a temporary folder location for GNSDK SQLite storage
*  @param folderPath	[in] Relative path name for storage
* <p><b>Remarks:</b></p>
*  This API sets the temporary folder location for ALL GNSDK SQLite storage.
*/ 

-(void) temporaryStorageLocation: (nullable NSString*)folderPath error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Sets the maximum size the GNSDK cache can grow to; for example '100' for 100 Kb or '1024' for 1
*  MB. This limit applies to each cache that is created.
*
*  The value passed for this option is the maximum number of Kilobytes that the cache files can grow
*  to. For example, '100' sets the maximum to 100 KB, and '1024' sets the maximum to 1 MB.
*
*  If the cache files' current size already exceeds the maximum when this option is set, then the
*  set maximum is not applied.
*
*  When the maximum size is reached, new cache entries are not written to the database.
*  Additionally, a maintenance thread is run that attempts to clean up expired records from the
*  database and create space for new records.
*
*  If this option is not set the cache files default to having no maximum size.
*
*  @param maxCacheSize	[in] Maximum cache file size
*/ 

-(void) maximumCacheFileSize: (NSUInteger)maxCacheSize error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get maximum cache file size
*/ 

-(NSUInteger) getMaximumCacheFileSize: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets the maximum amount of memory SQLite can use to buffer cache data.
*
*  The value passed for this option is the maximum number of Kilobytes of memory that can be used.
*  For example, '100' sets the maximum to 100 KB, and '1024' sets the maximum to 1 MB.
*
*  @param maxMemSize [in]  Maximum cache memory size
*/ 

-(void) maximumCacheMemory: (NSUInteger)maxMemSize error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get maximum cache memory
*/ 

-(NSUInteger) getMaximumCacheMemory: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets the method that SQLite uses to write to the cache files.
*
*  This option is available for SQLite performance tuning. Valid values for this option are:
*  @param mode [in]:
*  <ul>
*  <li>OFF (default setting): No synchronous writing; the quickest but least safe method.</li>
*  <li>NORMAL: Synchronous writing only at critical times; the generally quick and safe method.</li>
*  <li>FULL: Always synchronous writing; the slowest and safest method.</li>
*  </ul>
*
*  If the threat of losing a cache file due to hardware failure is high, then set this option in
*  your application to NORMAL or FULL.
*/ 

-(void) synchronousMode: (nullable NSString*)mode error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get synchronous mode setting
*/ 

-(nullable NSString*) getSynchronousMode: (NSError**)error;

/**
*  Sets how the SQLite journal file is managed for database transactions.
*
*  This option is available for SQLite performance tuning. Valid values for this option are:
*  @param mode [in]:
*  <ul>
*  <li>DELETE: Journal file is deleted after each transaction.</li>
*  <li>TRUNCATE: Journal file is truncated (but not deleted) after each transaction.</li>
*  <li>PERSIST: Journal file remains after each transaction.</li>
*  <li>MEMORY (default setting): Journal file is only stored in memory for each transaction.</li>
*  <li>OFF: No journaling is performed.</li>
*  </ul>
**/ 

-(void) journalMode: (nullable NSString*)mode error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get journalling mode setting
*/ 

-(nullable NSString*) getJournalMode: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnStorageSqlite_h_ */

