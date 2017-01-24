/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnContributor_h_
#define _GnContributor_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContent.h"
#import "GnEnums.h"
#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnExternalId.h"
#import "GnName.h"


@class GnContentEnumerator;
@class GnExternalIdEnumerator;
@class GnNameEnumerator;


/**
* A person participating an Album or Track creation.
* Provides access to artist image when received from a query object
* with content enabled in lookup data.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnContributor object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnContributor : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Constructs a GnContributor from a Gracenote identifier and identifier tag
* @param id	[in] Identifier
* @param idTag [in] Identifier tag
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithId: (nullable NSString*)id idTag: (nullable NSString*)idTag error: (NSError**)error;

/**
*  Flag indicating if data object response contains full (true) or partial metadata.
*  Returns true if full, false if partial.
* <p><b>Note:</b></p>
*   What constitutes a full result varies among the individual response types and results, and also
*  depends on data availability.
* @ingroup GDO_ValueKeys_Misc
*/ 

-(BOOL) isFullResult;

/**
* Contributor's Gracenote identifier
* @return Gracenote ID
*/ 

-(nullable NSString*) gnId;

/**
* Contributor's Gracenote unique identifier.
* @return Gracenote Unique ID
*/ 

-(nullable NSString*) gnUId;

/**
* Retrieves the contributor's product identifier.
* @return Gracenote Product ID
* <p><b>Remarks:</b></p>
* Available for most types, this retrieves a value which can be stored or transmitted. This
* value can be used as a static identifier for the current content as it will not change over time.
*/ 

-(nullable NSString*) productId;

/**
* Contributor's Gracenote Tui (title-unique identifier)
* @return Tui
*/ 

-(nullable NSString*) tui;

/**
* Contributor's Gracenote Tui Tag
* @return Tui Tag
*/ 

-(nullable NSString*) tuiTag;

/**
* Contributor's birth date.
* @return Date of birth
*/ 

-(nullable NSString*) birthDate;

/**
* Contributor's place of birth.
* @return Place of birth
*/ 

-(nullable NSString*) birthPlace;

/**
* Date contributor died
* @return Date of death
*/ 

-(nullable NSString*) deathDate;

/**
* Contributor's place of death.
* @return Place of death
*/ 

-(nullable NSString*) deathPlace;

/**
* Contributor's media space, e.g., music, film, stage. List/locale dependent field.
* @return Media space
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) mediaSpace;

/**
*  Content (cover art, review, etc) object
*  @param GnContentType object
*  @return Content object
*/ 

-(nullable GnContent*) content: (GnContentType)contentType;

/**
*  Fetch the contributor's image content object
*  @return Content object
*/ 

-(nullable GnContent*) image;

/**
* Contributor's biography when received from a video response.
* When the contributor object was derived from a video response use this
* method to btain the biography.
* @return Biography
*/ 

-(nullable NSString*) biographyVideo;

/**
* Fetch the contributor's biography content object.
* @return Content object
*/ 

-(nullable GnContent*) biography;

/**
* Contributor name object
* @return Name
*/ 

-(nullable GnName*) name;

/**
* Iterator for accessing the contributor's official name(s).
* @return Iterator
*/ 

-(GnNameEnumerator*) namesOfficial;

/**
* Iterator for accessing the contributor's regional name(s).
* @return Iterator
*/ 

-(GnNameEnumerator*) namesRegional;

/**
* Iterator for contirbutor associated content.
* @return Iterator
*/ 

-(GnContentEnumerator*) contents;

/**
* Iterator for contributor associated external IDs (3rd party IDs, e.g., Amazon's)
* @return Iterator
*/ 

-(GnExternalIdEnumerator*) externalIds;

/**
* Contributor that collaborated with this contributor in the context of the returned result.
* @return Contributor
*/ 

-(nullable GnContributor*) collaborator;

/**
* Contributor's genre. List/locale, multi-level field.
* @param level	[in] Data level
* @return Genre
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) genre: (GnDataLevel)level;

/**
* Contributor's origin, e.g., New York City
* @param level     [in] Data level
* @return Origin
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) origin: (GnDataLevel)level;

/**
* Contributor's era. List/locale dependent, multi-level field.
* @param level	[in] Data level
* @return Era
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) era: (GnDataLevel)level;

/**
* Contributor's artist type. List/locale dependent, multi-level field.
* @param level	[in] Data level
* @return Artist type
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) artistType: (GnDataLevel)level;

/**
*  Get flag indicating if this is a collaborator result
*  @return True if a collaborator result, false otherwise
*/ 

-(BOOL) collaboratorResult;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnContributor*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnContributorEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnContributorBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnContributorBlock)handler;

-(NSUInteger) count;

-(nullable GnContributor*) nextObject;

-(nullable GnContributor*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnContributor_h_ */

