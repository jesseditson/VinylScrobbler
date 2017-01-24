/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnRenderOptions_h_
#define _GnRenderOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnRenderOptions.h"




/**
* \class GnRenderOptions
* Rendering options (e.g., JSON, XML)
*/ 

@interface GnRenderOptions : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Construct GnRenderOptions object
*/ 

-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Specify render format of XML
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) xml;

/**
* Specify render format of JSON
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) json;

/**
* Standard
*/
-(nonnull GnRenderOptions*) standard;

/**
* Specify rendered output include Credits
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) credits;

/**
* Specify rendered output include Sortable information
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) sortable;

/**
* SerialGdos
*/
-(nonnull GnRenderOptions*) serialGdos;

/**
* Specify rendered output include Product IDs
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) productIds;

/**
* Specify rendered output include raw TUIs
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) rawTuis;

/**
* Specify rendered output include Gracenote IDs
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) gnIds;

/**
* GnUIds
*/
-(nonnull GnRenderOptions*) gnUIds;

/**
* Specify rendered output include Genre descriptors for specified level
* @param level	[in] Data level
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) genres: (GnDataLevel)level;

/**
* Default
*/
-(nonnull GnRenderOptions*) defaultOptions: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Full
*/
-(nonnull GnRenderOptions*) full;

/**
* Clear render options
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) clear;

/**
* Specify format version of output to render
* @return Render options object
*/ 

-(nonnull GnRenderOptions*) version: (NSUInteger)ver;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnRenderOptions_h_ */

