/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnString_h_
#define _GnString_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"






@interface GnStringEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnStringBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnStringBlock)handler;

-(NSUInteger) count;

-(nullable NSString*) nextObject;

-(nullable NSString*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnString_h_ */

