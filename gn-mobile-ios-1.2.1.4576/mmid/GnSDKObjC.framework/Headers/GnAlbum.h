/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAlbum_h_
#define _GnAlbum_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnArtist.h"
#import "GnAudioWork.h"
#import "GnContent.h"
#import "GnEnums.h"
#import "GnCredit.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnTitle.h"
#import "GnTrack.h"


@class GnAudioWorkEnumerator;
@class GnContentEnumerator;
@class GnCreditEnumerator;
@class GnExternalIdEnumerator;
@class GnTrackEnumerator;


/**
* Collection of audio recordings.
* Provides access to album cover art when received from a query object
* with content enabled in lookup data.
*
* Part of the metadata returned from a recognition event.
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

@interface GnAlbum : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Constructs a GnAlbum object from identifier and identifier tag
* @param id	[in] Identifier
* @param idTag	[in] Identifier tag
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithId: (nullable NSString*)id idTag: (nullable NSString*)idTag error: (NSError**)error;

/**
*  Flag indicating if response contains full (true) or partial (false) metadata.
*  @return True if full result, false if partial result
* <p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
* Album's official title.
* @return Title
*/ 

-(nullable GnTitle*) title;

/**
* Album's artist.
* @return Artist
*/ 

-(nullable GnArtist*) artist;

/**
* Album's genre, e.g., punk rock. List/locale dependent, multi-level field.
* @param level	[in] Data level
* @return Genre
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) genre: (GnDataLevel)level;

/**
* Album's label - record company that released the album, e.g., Atlantic.
* Album label values are not always available.
* @return Label
*/ 

-(nullable NSString*) label;

/**
*  Display language
*  @return Language string
*/ 

-(nullable NSString*) language;

/**
*  Display langauge's 3-letter ISO code
*  @return Language code
*/ 

-(nullable NSString*) languageCode;

/**
* Album's Gracenote Tui (title-unique identifier)
* @return Tui
*/ 

-(nullable NSString*) tui;

/**
* Album's Gracenote Tui Tag
* @return Tui Tag
*/ 

-(nullable NSString*) tuiTag;

/**
* Album's Gracenote Tag identifier (Tag ID is same as Product ID)
* @return Gracenote Tag identifier
* <p><b>Remarks:</b></p>
* This method exists primarily to support legacy implementations. We recommend using
* the Product ID method to retrieve product related identifiers
*/ 

-(nullable NSString*) tagId;

/**
* Album's Gracenote identifier.
* @return Gracenote identifier
*/ 

-(nullable NSString*) gnId;

/**
* Album's Gracenote unique identifier.
* @return Gracenote unique identifier
*/ 

-(nullable NSString*) gnUId;

/**
* Album's global identifier (used for transcriptions).
* @return Gracenote Global identifier
*/ 

-(nullable NSString*) globalId;

/**
* Album's volume number in a multi-volume set.
* This value is not always available.
* @return Disc in set
*/ 

-(NSUInteger) discInSet;

/**
* Total number of volumes in album's multi-volume set.
* This value is not always available.
* @return Total in set
*/ 

-(NSUInteger) totalInSet;

/**
* Year the album was released.
* @return year
*/ 

-(nullable NSString*) year;

/**
* Flag indicating if enhanced classical music data exists
* for this album.
* @return True if this is a classical album, false otherwise
*/ 

-(BOOL) isClassical;

/**
* Total number of tracks on this album.
* @return Count
*/ 

-(NSUInteger) trackCount;

/**
* Album's compilation value
* @return Compilation
*/ 

-(nullable NSString*) compilation;

/**
* Match confidence score for top-level match
* @return Match score
*/ 

-(NSUInteger) matchScore;

/**
* Album track using the track number.
* @param trackNumber	Ordinal of the desired track (1-based)
* @return Track
*/ 

-(nullable GnTrack*) track: (NSUInteger)trackNumber;

/**
* Ordinal value on album for matching track
* @param ordinal	Ordinal of the desired track (1-based)
* @return Track
*/ 

-(nullable GnTrack*) trackMatched: (NSUInteger)ordinal;

/**
* Track number on album for matching track
* @param ordinal	Ordinal of the desired track (1-based)
* @return Matched number
*/ 

-(NSUInteger) trackMatchNumber: (NSUInteger)ordinal;

/**
*  Content (cover art, biography, review, etc.) object
*  @param GnContentType object
*  @return Content object
*/ 

-(nullable GnContent*) content: (GnContentType)contentType;

/**
*  Fetch the album's cover art content object
*  @return Content object
*/ 

-(nullable GnContent*) coverArt;

/**
*  Fetch the album's review content object
*  @return Content object
*/ 

-(nullable GnContent*) review;

/**
* Iterator for accessing album tracks
* @return Iterator
*/ 

-(GnTrackEnumerator*) tracks;

/**
* Iterator for accessing album's matched track(s).
* @return Iterator
*/ 

-(GnTrackEnumerator*) tracksMatched;

/**
* Iterator for accessing album credits, except artist credit, which is accessed with another dedicated method
* The Artist Credit is accessed via a dedicated method.
* @return Iterator
*/ 

-(GnCreditEnumerator*) credits;

/**
* Iterator for accessing audio works
* @return Iterator
*/ 

-(GnAudioWorkEnumerator*) audioWorks;

/**
* Iterator for the content associated with this contributor.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* Iterator for album's external identifiers, e.g., Amazon's identifier.
* @return Iterator
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
*  Title presented using Gracenote's Three Line Solution for classical track (composer/work title/movement title)
*  @return Title
*/ 

-(nullable GnTitle*) titleClassical;

/**
*  Regional title - list/locale dependent field
*  @return Title
*/ 

-(nullable GnTitle*) titleRegional;

/**
*  Regional locale title - list/locale dependent field
*  @return Title
*/ 

-(nullable GnTitle*) titleRegionalLocale;

/**
*  Script used by the display values as ISO 15924 code
*  @return Script value.
*/ 

-(nullable NSString*) script;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnAlbum*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnAlbumEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnAlbumBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnAlbumBlock)handler;

-(NSUInteger) count;

-(nullable GnAlbum*) nextObject;

-(nullable GnAlbum*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnAlbum_h_ */

