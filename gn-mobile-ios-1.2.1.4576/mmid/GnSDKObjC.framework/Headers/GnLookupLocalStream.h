/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLookupLocalStream_h_
#define _GnLookupLocalStream_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnLookupLocalStream.h"




/**
*
* GnLookupLocalStream is a MusicID-Stream local lookup provider, providing a local
* database of MusicID-Stream tracks suitable for lookup via GnMusicIdStream or GnMusicId.
* A MusicID-Stream local database can be constructed from "bundles" (raw fingerprints and metadata) that
* Gracenote provides.
*
* <b>SDK Documentation</b>
*
* Topic: "Implementing Applications..." > "Using a Local Fingerprint Database"
*
* For more information on using the GnLookupLocalStream class see the above topic which covers
* the following:
* <ul>
*     <li>Using a local fingerprint database</li>
*     <li>Downloading and ingesting bundles</li>
*     <li>Ingesting bundles code samples</li>
*     <li>Designating a storage provider</li>
*     <li>Local fingerprinting options</li>
* </ul>
*
*/ 

@interface GnLookupLocalStream : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Enable a lookup local Stream provider.
* @return Storage provider instance
*/ 

+(nullable GnLookupLocalStream*) enable: (NSError**)error;

/**
*  Retrieves a GnLookupLocalStream SDK version string.
*  You can call this API at any time after successfully allocating a GnManager instance. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example: 1.2.3.123 (Major.Minor.Improvement.Build)
*  Major: New functionality
*  Minor: New or changed features
*  Improvement: Improvements and fixes
*  Build: Internal build number
*/ 

+(nonnull NSString*) version;

/**
*  Retrieves the GnLookupLocalStream SDK's build date string.
*  @return gnsdk_cstr_t Build date string of the format: YYYY-MM-DD hh:mm UTC
*  <p><b>Remarks:</b></p>
*  You can call this API at any time after successfully allocating a GnManager instance. The returned
*  string is a constant. Do not attempt to modify or delete.
*  Example build date string: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
*  Sets a folder location for GNSDK LookupLocalStream
*  @param folderPath	[in] Relative path name for storage
* <p><b>Remarks:</b></p>
*  This API overrides the (default or explicit) folder location of GNSDK SQLite storage - for this database.
*/ 

-(void) storageLocation: (nullable NSString*)location error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets the local fingerprint lookup engine memory type
*  @param engineType	[in] GnLocalStreamEngineType enum indicating which memory mode to use
*/ 

-(void) engineType: (GnLocalStreamEngineType)engineType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieves the local fingerprint lookup engine memory type
*/ 

-(GnLocalStreamEngineType) getEngineType: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Sets the current local fingerprint lookup processing method.
*  @param processingMethod	[in] GnLocalStreamFingerprintProcessingMethod enum indicating the local fingerprint lookup processing method.
*/ 

-(void) fingerprintProcessingMethod: (GnLocalStreamFingerprintProcessingMethod)processingMethod error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieves the current local fingerprint lookup processing method.
*/ 

-(GnLocalStreamFingerprintProcessingMethod) getFingerprintProcessingMethod: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Clear all tracks from the MusicID-Stream local database storage file.
*/ 

-(void) storageClear: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Remove a bundle item from the MusicID-Stream local database.
* @param	bundleItemId	[in] Bundle item ID
*/ 

-(void) storageRemove: (nullable NSString*)bundleItemId error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLookupLocalStream_h_ */

