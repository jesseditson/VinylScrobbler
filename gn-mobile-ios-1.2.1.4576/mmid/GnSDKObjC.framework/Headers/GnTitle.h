/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTitle_h_
#define _GnTitle_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"




/**
* Title of a work or product
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnTitle object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnTitle : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Title display language
*  @return Language string
*/ 

-(nullable NSString*) language;

/**
*  3 letter ISO code for display language
*  @return Language code
*/ 

-(nullable NSString*) languageCode;

/**
*  Title display string
*  @return Strng suitable for displaying to end user
*/ 

-(nullable NSString*) display;

/**
*  Title prefix, e.g., The
*  @return Prefix
*/ 

-(nullable NSString*) prefix;

/**
*  Sortable title
*  @return Sortable string
*/ 

-(nullable NSString*) sortable;

/**
*  Sortable title scheme
*  @return Sortable scheme
*/ 

-(nullable NSString*) sortableScheme;

/**
* Main title
* @return Title
*/ 

-(nullable NSString*) mainTitle;

/**
* Title edition
* @return Edition
*/ 

-(nullable NSString*) edition;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnTitle*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnTitle_h_ */

