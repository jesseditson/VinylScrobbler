/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistAttributes_h_
#define _GnPlaylistAttributes_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnPlaylistAttributes.h"




/**
* <b>Experimental</b>: GnPlaylistAttributes
*/ 

@interface GnPlaylistAttributes : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* GnPlaylistAttributes
*/
-(nullable INSTANCE_RETURN_TYPE) initWithPlaylistAttributes: (nonnull GnPlaylistAttributes*)playlistAttributes;

/**
*  Retrieves the AlbumName value as a string for this attribute.
*  @return album name string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) albumName;

/**
*  Retrieves the ArtistName value as a string for this attribute.
*  @return artist name string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) artistName;

/**
*  Retrieves the ArtistType value as a string for this attribute.
*  @return artist type string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) artistType;

/**
*  Retrieves the Era value as a string for this attribute.
*  @return era string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) era;

/**
*  Retrieves the Genre value as a string for this attribute.
*  @return genre string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) genre;

/**
*  Retrieves the Origin value as a string for this attribute.
*  @return origin string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) origin;

/**
*  Retrieves the Mood value as a string for this attribute.
*  @return mood string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) mood;

/**
*  Retrieves the Tempo value as a string for this attribute.
*  @return tempo string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) tempo;

/**
*  Retrieves attribute value by given attribute name.
*  @return attribute string value if it exists else an empty string.
*
**/ 

-(nullable NSString*) value: (nullable NSString*)attrName;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistAttributes_h_ */

