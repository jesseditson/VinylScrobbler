/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMoodgridIdentifier_h_
#define _GnMoodgridIdentifier_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"





/**
** <b>Experimental</b>: GnMoodgridIdentifier
*/ 

@interface GnMoodgridIdentifier : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Retrieves a read only string that is the media identifier.
*/ 

-(nullable NSString*) mediaIdentifier;

/**
* Retrieves a read only string that is the group the MediaIdentifier belongs to.
*  E.g. in the case of a Playlist provider , the group represents the collection name.
*/ 

-(nullable NSString*) group;


NS_ASSUME_NONNULL_END

@end


@interface GnMoodgridIdentifierEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnMoodgridIdentifierBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnMoodgridIdentifierBlock)handler;

-(NSUInteger) count;

-(nullable GnMoodgridIdentifier*) nextObject;

-(nullable GnMoodgridIdentifier*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMoodgridIdentifier_h_ */

