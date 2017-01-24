/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnResponseAlbums_h_
#define _GnResponseAlbums_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAlbum.h"
#import "GnDataObject.h"


@class GnAlbumEnumerator;


/**
* Collection of album results received in response to an album query.
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

@interface GnResponseAlbums : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
*  Number of matches returned
*  @return Count
*/ 

-(NSUInteger) resultCount;

/**
*  Ordinal of the first result in the returned range.
*  @return Range start
*  <p><b>Remarks:</b></p>
*  If you do not set a starting value, the default behavior is to return the first set of results.
*  Range values are available to aid in paging results. Gracenote limits the number of
*  responses returned in any one request, so the range values are available to indicate the total
*  number of results, and where the current results fit in within that total.
*
*  <p><b>Important:</b></p>
*  The number of results actually returned for a query may not equal the number of results initially
*  requested. To accurately iterate through results, always check the range start, end, and total
*  values and the responses returned for the query (or queries). Ensure that you
*  are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
*  using the initial requested value.
*/ 

-(NSUInteger) rangeStart;

/**
* Ordinal of the last result in the returned range.
* @return Range end
* <p><b>Remarks:</b></p>
* Range values are available to aid in paging results. Gracenote limits the number of
* responses returned in any one request, so the range values are available to indicate the total
* number of results, and where the current results fit in within that total.
*
* <p><b>Important:</b></p>
* The number of results actually returned for a query may not equal the number of results initially
* requested. To accurately iterate through results, always check the range start, end, and total
* values and the responses returned for the query (or queries). Ensure that you
* are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
* using the initial requested value.
*/ 

-(NSUInteger) rangeEnd;

/**
* Estimated total number of results possible.
* @return Range total
* <p><b>Remarks:</b></p>
* Range values are available to aid in paging results. Gracenote limits the number of
* responses returned in any one request, so the range values are available to indicate the total
* number of results, and where the current results fit in within that total.
* The total value may be estimated.
*
* <p><b>Important:</b></p>
* The number of results actually returned for a query may not equal the number of results initially
* requested. To accurately iterate through results, always check the range start, end, and total
* values and the responses returned for the query (or queries). Ensure that you
* are incrementing by using the actual last range end value plus one (range_end+1), and not by simply
* using the initial requested value.
*/ 

-(NSUInteger) rangeTotal;

/**
* Flag indicating if response need a user or app decision - either multiple matches returned or less than perfect single match.
* @return True if user decision needed, false otherwise
*/ 

-(BOOL) needsDecision;

/**
* Iterator for accessing matched albums.
* @return Iterator
*/ 

-(GnAlbumEnumerator*) albums;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnResponseAlbums*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnResponseAlbums_h_ */

