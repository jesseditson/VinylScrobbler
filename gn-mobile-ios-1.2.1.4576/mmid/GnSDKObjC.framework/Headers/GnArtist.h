/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnArtist_h_
#define _GnArtist_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnName.h"




/**
* Person or group primarily responsible for creating the Album or Track.
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

@interface GnArtist : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Artist's official name.
* @return Name
*/ 

-(nullable GnName*) name;

/**
* Contributor object - contributor associated with the work
* @return Contributor
*/ 

-(nullable GnContributor*) contributor;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnArtist*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnArtist_h_ */

