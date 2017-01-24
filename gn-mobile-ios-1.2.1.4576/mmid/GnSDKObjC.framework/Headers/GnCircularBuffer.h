//
//  GnCircularBuffer.h
//  GnSdk_ObjC_iOS
//
//  Created by Doug McCoy on 11/27/12.
//
//

#import <Foundation/Foundation.h>
//#import "GnAcrAudioConfig.h"

@interface GnCircularBuffer : NSObject


-(id)initWithCapacity:(NSUInteger)numBytes;

-(int)writeBytes:(void const * const)bytes length:(int)length;
-(int)readBytes:(void * const)bytes length:(int)length;

@property (atomic, readonly) NSUInteger length;

@end
