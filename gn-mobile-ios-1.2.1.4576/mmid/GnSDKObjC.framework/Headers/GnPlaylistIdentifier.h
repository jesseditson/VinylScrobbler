/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistIdentifier_h_
#define _GnPlaylistIdentifier_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
* <b>Experimental</b>: GnPlaylistIdentifier
*/ 

@interface GnPlaylistIdentifier : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* MediaIdentifier
*/
-(nullable NSString*) mediaIdentifier;

/**
* CollectionName
*/
-(nullable NSString*) collectionName;


NS_ASSUME_NONNULL_END

@end


@interface GnPlaylistIdentifierEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnPlaylistIdentifierBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnPlaylistIdentifierBlock)handler;

-(NSUInteger) count;

-(nullable GnPlaylistIdentifier*) nextObject;

-(nullable GnPlaylistIdentifier*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistIdentifier_h_ */

