/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GNDEFINES_H_
#define _GNDEFINES_H_


#if defined __clang__
    #define INSTANCE_RETURN_TYPE    instancetype
#else
    #define INSTANCE_RETURN_TYPE    id
#endif


#if __has_feature(objc_arc)

    #define BRIDGE   __bridge
    #define WEAK     (weak)
    #define AUTORELEASE_INIT    @autoreleasepool {
    #define AUTORELEASE_END     }

#else

    #if defined __llvm__
        #define AUTORELEASE_INIT    @autoreleasepool {
        #define AUTORELEASE_END     }
    #else
        #define AUTORELEASE_INIT    NSAutoReleasePool* pool = [[NSAutoReleasePool alloc] init];
        #define AUTORELEASE_END     [pool drain];
    #endif

    #define BRIDGE
    #define WEAK

#endif



#endif /* _GNDEFINES_H_ */

