/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseTracks_h_
#define _GnResponseTracks_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnTrack.h"


@class GnTrackEnumerator;


/**
* Collection of track results received in response to a track query
*
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  .../docs/html-oo > index.html > Data Models
*
*  The above topic displays all the metadata returned from a recognition event.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnResponseTracks : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Result count - number of matches returned
*  @return Count
*/ 

-(NSUInteger) resultCount;

/**
*  Range start - ordinal value of first match in range total
*  @return Range start ordinal
*/ 

-(NSUInteger) rangeStart;

/**
*  Range end - ordinal value of last match in range total
*  @return Range end ordinal
*/ 

-(NSUInteger) rangeEnd;

/**
*  Range total - total number of matches that could be returned
*  @return Range total
*/ 

-(NSUInteger) rangeTotal;

/**
*  Flag indicating if response needs user decision - either multiple matches returned or less than perfect single match
*  @return True if user decision required, false otherwise
*/ 

-(BOOL) needsDecision;

/**
* Iterable for accessing response tracks
* @return Iterator
*/ 

-(GnTrackEnumerator*) tracks;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnResponseTracks*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnResponseTracks_h_ */

