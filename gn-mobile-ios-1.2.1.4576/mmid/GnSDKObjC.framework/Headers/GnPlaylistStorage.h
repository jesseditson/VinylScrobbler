/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistStorage_h_
#define _GnPlaylistStorage_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnPlaylistCollection.h"
#import "GnString.h"


@class GnStringEnumerator;


/**
* <b>Experimental</b>: Playlist Collection Summary storage management
*
* Provides services for managing the Playlist Collection Summary storage including
* adding, loading and removing collection summaries from persistent storage.
*
* Once a Collection Summary is created your application can store it persistently
* by adding it to the Playlist Collection Summary storage. When your application
* is initialized it can load the Collection Summary into heap memory from storage.
*
* Note: Once a Collection Summary is loaded from persistent storage your application
* should synchronize the summary with the media available for playlist generation as
* the user may have added or removed such media while your appication was not active.
*
* Collection Summaries can be removed from Playlist Collection Summary storage when
* no longer needed. The Playlist Collection Summary storage will retain persistent
* storage resources (file space) used by the removed Collection Summary. To return
* these resources to the operating system your application should compact the
* storage soon after removing a Collection Summary.
*
* A Gracenote storage provider must be enabled, such as GnStorageSqlite, for
* GnPlalistStorage to access persistent storage.
*
*/ 

@interface GnPlaylistStorage : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnPlaylistStorage
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Performs validation on playlist storage.
* @return Error information from storage validation
* Long Running Potential: File system I/O, database size affects running time
*/ 

-(nullable NSError*) isValid;

/**
* Compact Collection Summary storage
*/ 

-(void) compact: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Stores a Collection Summary in local storage
*
* @param collection [in] Playlist collection
*/ 

-(void) store: (nonnull GnPlaylistCollection*)collection error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Loads a Collection Summary from local storage using storage name
*
* @param collectionName [in] explicit name of the collection you want to load.
* @return Playlist collection
*/ 

-(nullable GnPlaylistCollection*) loadWithCollectionName: (nullable NSString*)collectionName error: (NSError**)error;

/**
* Removes a Collection Summary from local storage
*
* @param collection [in] Playlist collection object
*/ 

-(void) removeWithCollection: (nonnull GnPlaylistCollection*)collection error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Removes a Collection Summary from local storage using storage name
*
* @param collectionName [in] Playlist collection name
*/ 

-(void) removeWithCollectionName: (nullable NSString*)collectionName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Sets location for Collection Summary storage
*
* @param location [in] Location path
*/ 

-(void) location: (nullable NSString*)location error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get an iterator for names of all stored Collection Summaries.
*
* The iterator or the name can be used to explicitly load the
* Collection Summary from storage.
*
* @return Playist Collection Summary Name iterator
*/ 

-(GnStringEnumerator*) names;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistStorage_h_ */

