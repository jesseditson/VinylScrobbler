/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnTrack_h_
#define _GnTrack_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnArtist.h"
#import "GnAudioWork.h"
#import "GnContent.h"
#import "GnEnums.h"
#import "GnCredit.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnString.h"
#import "GnTitle.h"


@class GnAudioWorkEnumerator;
@class GnContentEnumerator;
@class GnCreditEnumerator;
@class GnExternalIdEnumerator;
@class GnStringEnumerator;


/**
* A song or instrumental recording.
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

@interface GnTrack : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/** Constructs a GnTrack object from identifier and identifie tag
* @param id	[in] Identifier
* @param idTag	[in] Identifier tag
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithId: (nullable NSString*)id idTag: (nullable NSString*)idTag error: (NSError**)error;

/**
*  Flag indicating if response contains full (true) or partial (false) metadata.
*  @return True if full result, false otherwise
* <p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
* Track's official title.
* @return Title
*/ 

-(nullable GnTitle*) title;

/**
* Track's artist.
* @return Artist
*/ 

-(nullable GnArtist*) artist;

/**
* Iterator for accessing audio works
* @return Iterator
*/ 

-(GnAudioWorkEnumerator*) audioWorks;

/**
* Track's mood, e.g., Playful. List/locale dependent, multi-level field.
* @param level	[in] Data level
* @return Mood
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) mood: (GnDataLevel)level;

/**
* Track's tempo, e.g., Fast. List/locale dependent, multi-leveled field.
* @param level	[in] Data level
* @return Tempo
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) tempo: (GnDataLevel)level;

/**
* Track's genre, e.g., Heavy Metal. List/locale dependent, multi-level field
* @param level	[in] Data level
* @return Genre
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) genre: (GnDataLevel)level;

/**
*  Track's content, e.g., cover image, artist image, biography etc.
*  @param GnContentType object
*  @return Content object
*/ 

-(nullable GnContent*) content: (GnContentType)contentType;

/**
*  Fetch the album's review content object
*  @return Content object
*/ 

-(nullable GnContent*) review;

/**
* Flag indicating if this is the matched track (true)
* @return True if matched track, false otherwise
*/ 

-(BOOL) matched;

/**
* Position in milliseconds of where we matched in the track
* @return Match position in milliseconds
*/ 

-(NSUInteger) matchPosition;

/**
* For MusicID-Stream fingerprint matches, this is the length of matched reference audio in
* milliseconds.
*/ 

-(NSUInteger) matchDuration;

/**
* Current position in milliseconds of the matched track.
* The current position tracks the approximate real time position of the
* playing audio track assuming it is not paused. Only available from
* GnMusicIdStream responses.
* @return Current position in milliseconds
*/ 

-(NSUInteger) currentPosition;

/**
* Duration in milliseconds of the track (only available if this is the matched track)
* @return Duration in milliseconds
*/ 

-(NSUInteger) duration;

/**
* Iterator for accessing credits for this album, except artist credit.
* The Artist Credit is accessed via a dedicated method.
* @return Iterator
*/ 

-(GnCreditEnumerator*) credits;

/**
* Iterator for the content (cover art, biography, etc.)  associated with this track.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* Iterator for the track's external identifiers (ids from sources external to Gracenote, e.g., Amazon)
* @return Iterator
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* Track's Gracenote Tui (title-unique identifier).
* @return Tui
*/ 

-(nullable NSString*) tui;

/**
* Track's Gracenote Tui Tag.
* @return Tui Tag
*/ 

-(nullable NSString*) tuiTag;

/**
* Track's Gracenote Tag identifier (same as Product ID)
* @return Gracenote Tag identifier
* <p><b>Remarks:</b></p>
* This method exists primarily to support legacy implementations. We recommend using
* the Product ID method to retrieve product related identifiers
*/ 

-(nullable NSString*) tagId;

/**
* Track's Gracenote identifier
* @return Gracenote identifier
*/ 

-(nullable NSString*) gnId;

/**
* Track's Gracenote unique identifier.
* @return Gracenote unique identifier
*/ 

-(nullable NSString*) gnUId;

/**
* Track's ordinal number on album.
* @return Track number
*/ 

-(nullable NSString*) trackNumber;

/**
* Track's year.
* @return Year
*/ 

-(nullable NSString*) year;

/**
* Track identifiers . Each identifier is associated with a file information object presented to Music-ID.
* @return Matched identifier
*/ 

-(GnStringEnumerator*) matchedIdents;

/**
* Track's match type - the most authoritative matching type for a given file info object.
* @return Match lookup type
*  <p><b>Remarks:</b></p>
* The match type indicates which query type was the most authoritative matching type for a given file
* information object.
* MusicID-File does a query for each type of input data, and each type of input data has an authoritative rank.
* The match type indicates the highest authoritative matched type for this file information object.
* The match type is only useful in comparison to other match types. By itself it does not indicate
* a strong or poor match. The higher the match type, the more authoritative the identification process
* used.
* The following table lists the possible match type values:
* <table>
* <tr><th>Match Type</th><th>Value</th></tr>
* <tr><td>MIDF_MATCH_TYPE_TUI</td><td>11</td></tr>
* <tr><td>MIDF_MATCH_TYPE_MUI</td><td>10</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TOC</td><td>9</td></tr>
* <tr><td>MIDF_MATCH_TYPE_ASSOCIATED_ID</td><td>8</td></tr>
* <tr><td>MIDF_MATCH_TYPE_WF</td><td>7</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_ON_WF</td><td>6</td></tr>
* <tr><td>MIDF_MATCH_TYPE_ASSOCIATED_TEXT</td><td>5</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_TRACK</td><td>4</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_ALBUM</td><td>3</td></tr>
* <tr><td>MIDF_MATCH_TYPE_TEXT_CONTRIBUTOR</td><td>2</td></tr>
* <tr><td>MIDF_MATCH_TYPE_NONE</td><td>1</td></tr>
* <tr><td>MIDF_MATCH_TYPE_INVALID</td><td>0</td></tr>
* </table>
*/ 

-(nullable NSString*) matchLookupType;

/**
*  Confidence score (0-100) for match
*  @return Confidence score
*/ 

-(nullable NSString*) matchConfidence;

/**
* Track's match score - correlation between input text and matched track
* @return Match score
* <p><b>Remarks:</b></p>
* The match score gives a correlation between the input text and the matched track,
* indicating how well the input text matched the track. However, any result that is returned
* is considered to be a good match. The match score is only useful in comparison to other match
* scores. By itself it does not indicate a strong or poor match.
*/ 

-(NSUInteger) matchScore;

/**
*  Title presented using Gracenote's Three Line Solution for classical track (composer/work title/movement title)
*  @return Title
*/ 

-(nullable GnTitle*) titleClassical;

/**
*  Regional title. Locale/list dependent field.
*  @return Title
*/ 

-(nullable GnTitle*) titleRegional;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnTrack*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnTrackEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnTrackBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnTrackBlock)handler;

-(NSUInteger) count;

-(nullable GnTrack*) nextObject;

-(nullable GnTrack*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnTrack_h_ */

