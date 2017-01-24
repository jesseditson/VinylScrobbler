/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLogFilters_h_
#define _GnLogFilters_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnLogFilters.h"




/**
* Logging Filters
*/ 

@interface GnLogFilters : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnLogFilters
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/** Include error logging messages */ 

-(nonnull GnLogFilters*) clear;

/** Include error logging messages */ 

-(nonnull GnLogFilters*) error;

/** Include warning logging messages */ 

-(nonnull GnLogFilters*) warning;

/** Include informative logging messages */ 

-(nonnull GnLogFilters*) info;

/** Include debugging logging messages */ 

-(nonnull GnLogFilters*) debug;

/** Include all logging messages */ 

-(nonnull GnLogFilters*) all;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLogFilters_h_ */

