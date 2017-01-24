/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLogColumns_h_
#define _GnLogColumns_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnLogColumns.h"




/**
* Logging columns specifies what columns are written for each entry in the GNSDK log
*/ 

@interface GnLogColumns : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnLogColumns
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Clear options currently set
*/ 

-(void) none;

/**
* Specify to include a time stamp for each entry of the format: Wed Jan 30 18:56:37 2008
*/ 

-(nonnull GnLogColumns*) timeStamp;

/**
* Specify to categorizes the log entries by headings such as ERROR, INFO, and so on.
*/ 

-(nonnull GnLogColumns*) category;

/**
* Specify to include the Package Name, or the Package ID if the name is unavailable.
*/ 

-(nonnull GnLogColumns*) packageName;

/**
* Specify to include the Thread ID.
*/ 

-(nonnull GnLogColumns*) thread;

/**
* Specify to include the source information
*/ 

-(nonnull GnLogColumns*) sourceInfo;

/**
* Specify to include a trailing newline in the format: "\r\n"
*/ 

-(nonnull GnLogColumns*) newLine;

/**
* Specify to include all log formatting options.
*/ 

-(nonnull GnLogColumns*) all;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLogColumns_h_ */

