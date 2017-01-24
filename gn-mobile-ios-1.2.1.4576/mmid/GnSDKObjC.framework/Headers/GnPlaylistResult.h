/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistResult_h_
#define _GnPlaylistResult_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnPlaylistIdentifier.h"


@class GnPlaylistIdentifierEnumerator;


/**
* <b>Experimental</b>: GnPlaylistResult
*/ 

@interface GnPlaylistResult : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Identifiers
*/
-(GnPlaylistIdentifierEnumerator*) identifiers;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistResult_h_ */

