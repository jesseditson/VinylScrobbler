/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylist_h_
#define _GnPlaylist_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnString.h"


@class GnStringEnumerator;


/**
* <b>Experimental</b>: Provides access to information regarding the underlying
* GNSDK playlist library. For working with user collections to create playlists
* see GnPlaylistCollection.
*/ 

@interface GnPlaylist : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnPlaylist
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/** @internal Version @endinternal
*  Retrieves the Playlist SDK version string.
*  @return version string if successful
*  @return GNSDK_NULL if not successful
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully getting a GnManager instance. The returned
*   string is a constant. Do not attempt to modify or delete.
*  Example version string: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
* @ingroup Music_Playlist_InitializationFunctions
*/ 

+(nonnull NSString*) version;

/** @internal BuildDate @endinternal
*  Retrieves the Playlist SDK's build date string.
*  @return Note Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully getting a GnManager instance. The returned
*   string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
* @ingroup Music_Playlist_InitializationFunctions
*/ 

+(nonnull NSString*) buildDate;

/**
*  Media attributes support for playlist generation such as album title,
*  artist name, and artist type.
*  @return Playlist attribute iterator
*/ 

-(GnStringEnumerator*) attributesSupported;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylist_h_ */

