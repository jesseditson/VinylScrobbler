/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMoodgridProvider_h_
#define _GnMoodgridProvider_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
** <b>Experimental</b>: GnMoodgridProvider
*/ 

@interface GnMoodgridProvider : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Retrieves the name of the moodgrid provider.
* @return string representing the name of the provider.
*/ 

-(nullable NSString*) name: (NSError**)error;

/**
* Retrieves the type of Moodgrid provider.e.g. playlist collection
* @return string value denoting type of provider
*/ 

-(nullable NSString*) type: (NSError**)error;

/**
* Retrieves a bool value indicating whether the provider needs network access.
* @return requiresnetwork
*/ 

-(BOOL) requiresNetwork: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end


@interface GnMoodgridProviderEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnMoodgridProviderBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnMoodgridProviderBlock)handler;

-(NSUInteger) count;

-(nullable GnMoodgridProvider*) nextObject;

-(nullable GnMoodgridProvider*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMoodgridProvider_h_ */

