/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnName_h_
#define _GnName_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"




/**
* GnName
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnName object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnName : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Name display language
*  @return Langauge string
*/ 

-(nullable NSString*) language;

/**
*  3-letter ISO code for display langauge
*  @return Language code
*/ 

-(nullable NSString*) languageCode;

/**
*  Display name string
*  @return Name suitable for displaying to the end user
*/ 

-(nullable NSString*) display;

/**
*  Sortable name
*  @return Sortable string
*/ 

-(nullable NSString*) sortable;

/**
*  Sortable scheme
*  @return Sortable Scheme
*/ 

-(nullable NSString*) sortableScheme;

/**
*  Name prefix, e.g., "The"
*  @return Prefix
*/ 

-(nullable NSString*) prefix;

/**
*  Family name
*  @return Name
*/ 

-(nullable NSString*) family;

/**
*  Given name
*  @return name
*/ 

-(nullable NSString*) given;

/**
*  Name global ID - used for transcriptions
*  @return Gracenote Global ID
*/ 

-(nullable NSString*) globalId;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnName*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnNameEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnNameBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnNameBlock)handler;

-(NSUInteger) count;

-(nullable GnName*) nextObject;

-(nullable GnName*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnName_h_ */

