/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnAudioWork_h_
#define _GnAudioWork_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCredit.h"
#import "GnEnums.h"
#import "GnDataObject.h"
#import "GnTitle.h"




/**
* \class GnAudioWork
* A collection of classical music recordings.
*/ 

@interface GnAudioWork : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Audio work's official title.
* @return Title
*/ 

-(nullable GnTitle*) title;

/**
* Credit object for this audio work.
* @return Credit
*/ 

-(nullable GnCredit*) credit;

/**
* Gracenote Tui (title unique identifier) for this audio work.
* @return Tui
*/ 

-(nullable NSString*) tui;

/**
* Gracenote Tui Tag for this audio work.
* @return Tui Tag
*/ 

-(nullable NSString*) tuiTag;

/**
* Gracenote Tag identifier for this audio work (Tag ID is same as Product ID)
* @return Tag identifier
* <p><b>Remarks:</b></p>
* This method exists primarily to support legacy implementations. We recommend using
* the Product ID method to retrieve product related identifiers
*/ 

-(nullable NSString*) tagId;

/**
* Audio work's Gracenote identifier
* @return Gracenote identifier
*/ 

-(nullable NSString*) gnId;

/**
* Audio work's Gracenote unique identifier.
* @return Gracenote unique identifier
*/ 

-(nullable NSString*) gnUId;

/**
* Audio work's product ID (aka Tag ID).
* <p><b>Remarks:</b></p>
* Available for most types, this value can be stored or transmitted. Can
* be used as a static identifier for the current content as it will not change over time.
* @ingroup GDO_ValueKeys_GracenoteIDs
*/ 

-(nullable NSString*) productId;

/**
* Audio work's geographic location, e.g., New York City. List/locale dependent multi-leveled field.
* @param level	[in] Data level
* @return Origin
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) origin: (GnDataLevel)level;

/**
* Audio work's era. List/locale dependent, multi-leveled field.
* @param level	[in] Data level
* @return Era
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) era: (GnDataLevel)level;

/**
* Audio work's genre, e.g. punk rock, rock opera, etc. List/locale dependent, multi-level field.
* @param level	[in] Data level
* @return Genre
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) genre: (GnDataLevel)level;

/**
* Audio work's classical music composition form value (e.g., Symphony).
* @return Compsition form
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable NSString*) compositionForm;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnAudioWork*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnAudioWorkEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnAudioWorkBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnAudioWorkBlock)handler;

-(NSUInteger) count;

-(nullable GnAudioWork*) nextObject;

-(nullable GnAudioWork*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnAudioWork_h_ */

