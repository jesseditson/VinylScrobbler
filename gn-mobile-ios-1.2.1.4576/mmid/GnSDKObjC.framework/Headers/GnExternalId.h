/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnExternalId_h_
#define _GnExternalId_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"




/**
* Third-party identifier used to match identified media to merchandise IDs in online stores and other services
*
*/ 

@interface GnExternalId : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  External ID source (e.g., Amazon)
*  @return External ID source
*/ 

-(nullable NSString*) source;

/**
*  External ID type
*  @return External ID type
*/ 

-(nullable NSString*) type;

/**
*  External ID value
*  @return External ID value
*/ 

-(nullable NSString*) value;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnExternalId*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnExternalIdEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnExternalIdBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnExternalIdBlock)handler;

-(NSUInteger) count;

-(nullable GnExternalId*) nextObject;

-(nullable GnExternalId*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnExternalId_h_ */

