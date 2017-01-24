/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLog_h_
#define _GnLog_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnLog.h"
#import "GnLogColumns.h"
#import "GnLogEventsDelegate.h"
#import "GnLogFilters.h"
#import "GnEnums.h"
#import "GnLogOptions.h"




/**
* Configures and enables GNSDK logging including registering custom logging packages
* and writing your own logging message to the GNSDK log
*/ 

@interface GnLog : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Instantiate a GNSDK logging instance
* @param logFilePath		[in] File path of the logging file
* @param pLoggingDelegate	[in] Optional delegate to receive logging messages
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLogFilePath: (nullable NSString*)logFilePath logEventsDelegate: (nullable id <GnLogEventsDelegate>)pLoggingDelegate;

/**
* Instantiate a GNSDK logging instance
* <p><b>Remarks:</b></p>
* GnLog instances setup individual logs. Any number of logs can be
* started with any configurations. Messages that filter to multiple logs will
* be written to all applicable logs.
* Logging instances are distinguished by the logFilePath. Creating GnLog instances
* with the same logFilePath as one already started will modify the configuration for
* the existing log.
* Logging is not started until the GnLog Enable() method is called.
* Logging continues until the GnLog Disable() method is called. Destruction of GnLog instance
* does not terminate logging setup by that instance.
* @param logFilePath		[in] Path and name of the logging file
* @param filters			[in] Logging filters
* @param columns			[in] Logging columns
* @param options			[in] Logging options
* @param pLoggingDelegate	[in] Optional Delegate to receive logging messages
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLogFilePath: (nullable NSString*)logFilePath filters: (nonnull GnLogFilters*)filters columns: (nonnull GnLogColumns*)columns options: (nonnull GnLogOptions*)options logEventsDelegate: (nullable id <GnLogEventsDelegate>)pLoggingDelegate;

/**
* Set logger instance options
* @param options  Selection of logging options via GnLogOptions
*/ 

-(void) options: (nullable GnLogOptions*)options;

/**
* Set logger instance filters
* @param filters  Selection of log message filters via GnLogFilters
*/ 

-(void) filters: (nullable GnLogFilters*)filters;

/**
* Set logger instance columns
* @param columns  Selection of log column format via GnLogColumns
*/ 

-(void) columns: (nullable GnLogColumns*)columns;

/**
* Enable logging for the given package with the current logging options and filters.
* Enable can be called multiple times to enable logging of multiple packages to the same log.
* <p><b>Remarks:</b></p>
* Changes to logging options and filters do not take affect until the logger is next enabled.
* @param package [in] GnLogPackage to enable for this log.
* @return This GnLog object to allow method chaining.
*/ 

-(nullable GnLog*) enableLogPackageType: (GnLogPackageType)logPackageType error: (NSError**)error;

/**
* Enable logging for the custom package id with the current logging options and filters.
* Applications can register a package id using the Register() member. This allows applications
* to use GnLog to write their own messages to configured log files.
* Enable can be called multiple times to enable logging of multiple packages to the same log.
* <p><b>Remarks:</b></p>
* Changes to logging options and filters do not take affect until the logger is next enabled.
* @param package [in] GnLogPackage to enable for this log.
* @return This GnLog object to allow method chaining.
*/ 

-(nullable GnLog*) enableCustomPackageId: (NSUInteger)customPackageId error: (NSError**)error;

/**
* Disable logging for the given package for the current log.
* If no other packages are enabled for the log, the log will be closed
* @param package [in] GnLogPackage to disable for this log.
* @return This GnLog object to allow method chaining.
*/ 

-(nullable GnLog*) disableLogPackageType: (GnLogPackageType)logPackageType error: (NSError**)error;

/**
* Disable logging for the custom package id for the current log.
* If no other packages are enabled for the log, the log will be closed
* @param package [in] GnLogPackage to disable for this log.
* @return This GnLog object to allow method chaining.
*/ 

-(nullable GnLog*) disableCustomPackageId: (NSUInteger)customPackageId error: (NSError**)error;

/**
* Register an application with a unique packageid and package name
* @param customPackageId		[in] Custom Package ID : must be unique and be within the custom package range.
* @param customPackageName     [in] Custom tag to identfiy each log message. e.g. "MYAPP" .
* @return This GnLog object to allow method chaining.
* <p><b>Remarks:</b></p>
* This function enables an application register a custom package Id and package Name for writing to the log
* system.
*/ 

-(nullable GnLog*) register: (NSUInteger)customPackageId customPackageName: (nullable NSString*)customPackageName error: (NSError**)error;

/**
* Write a message to the custom registered log
* @param line              [in] Source line number of this call
* @param fileName          [in] Source file name of this call
* @param customPackageId   [in] Custom Package ID of application making call
* @param messageType       [in] Logging message type
* @param format            [in] Log message format
* <p><b>Remarks:</b></p>
* This function enables an application to write a logging message to the GNSDK logging
* system. If a logging events delegate is provided that handles the given package ID and enabled log filters,
* then this message is written to those log(s). The customer Package ID must be one previously registered by the
* application.
*/ 

+(void) write: (NSInteger)line fileName: (nullable NSString*)fileName customPackageId: (NSUInteger)customPackageId messageType: (GnLogMessageType)messageType format: (nullable NSString*)format;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLog_h_ */

