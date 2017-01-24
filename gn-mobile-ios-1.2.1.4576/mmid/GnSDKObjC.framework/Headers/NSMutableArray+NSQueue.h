//
//  NSMutableArray+NSQueue.h
//  iOSMobileSDK
//
//  Created on 9/18/13.
//  Copyright (c) 2013 Gracenote. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (NSQueue)

-(void) enqueueObj:(NSData*) object;
-(id) dequeue;
-(NSArray*) dequeueObjects:(NSInteger) count;
-(void) enqueueObjects:(NSArray*) objects;

@end
