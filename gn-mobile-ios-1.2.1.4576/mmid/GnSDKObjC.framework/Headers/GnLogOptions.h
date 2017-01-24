/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLogOptions_h_
#define _GnLogOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnLogOptions.h"




/**
*  Logging options specifies what options are applied to the GNSDK log
*/ 

@interface GnLogOptions : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnLogOptions
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Specify true for the log to be written synchronously (no background thread).
* By default, logs are written to asynchronously. No internal logging
* thread is created if all GnLog instances are specified for synchronous
* writing.
*
* Enabling synchronous logging could be useful for debugging purposes. For example, a background
* thread may not be able to complete logging some messages prior to a crash. Be aware,
* however, that writing synchronously is likely to significantly degrade performance.
*
* @param bSyncWrite  Set true to enable synchronized writing, false for asynchrounous (default)
*/ 

-(nonnull GnLogOptions*) synchronous: (BOOL)bSyncWrite;

/**
* Specify true to retain and rename old logs.
* Default behavior is to delete old logs.
* @param bArchive  Set true to keep rolled log files, false to delete rolled logs (default)
*/ 

-(nonnull GnLogOptions*) archive: (BOOL)bArchive;

/**
* Specify that when archive is also specified the logs to archive (roll)
* at the start of each day (12:00 midnight). Archiving by the given size
* parameter will still occur normally as well.
*/ 

-(nonnull GnLogOptions*) archiveDaily;

/**
* Specify the maximum size of log before a new log is created. Enter a value of zero (0) to
* always create new log on open.
* @param maxSize  Set to maximum size log file should reach to be rolled.
* Set to zero to always roll log on creation (default)
*/ 

-(nonnull GnLogOptions*) maxSize: (NSUInteger)maxSize;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLogOptions_h_ */

