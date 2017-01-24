/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLocaleInfo_h_
#define _GnLocaleInfo_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* Encapsulates information about a GnLocale instance. Used where GNSDK delivers a locale description such as
* iterating the available locales or when querying a GnLocale instance for information.
*/ 

@interface GnLocaleInfo : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Construct GnLocaleInfo object with default values.
* @param GnLocaleGroup group - locale group
* @param GnLanguage language - locale language
* @param GnRegion region - locale region
* @param GnDescriptor descriptor - locale descriptor
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLocaleGroup: (GnLocaleGroup)localeGroup language: (GnLanguage)language region: (GnRegion)region descriptor: (GnDescriptor)descriptor;

/**
* Get locale group
* @return Group
*/ 

-(GnLocaleGroup) group;

/**
* Get locale language
* @return Language
*/ 

-(GnLanguage) language;

/**
* Get locale region
* @return Region
*/ 

-(GnRegion) region;

/**
* Get locale descriptor
* @return Descriptor
*/ 

-(GnDescriptor) descriptor;


NS_ASSUME_NONNULL_END

@end


@interface GnLocaleInfoEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnLocaleInfoBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnLocaleInfoBlock)handler;

-(NSUInteger) count;

-(nullable GnLocaleInfo*) nextObject;

-(nullable GnLocaleInfo*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLocaleInfo_h_ */

