/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnPlaylistCollection_h_
#define _GnPlaylistCollection_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAlbum.h"
#import "GnCancellableDelegate.h"
#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnListElement.h"
#import "GnPlaylistAttributes.h"
#import "GnPlaylistCollection.h"
#import "GnPlaylistCollectionSyncEventsDelegate.h"
#import "GnEnums.h"
#import "GnPlaylistIdentifier.h"
#import "GnPlaylistMoreLikeThisOptions.h"
#import "GnPlaylistResult.h"
#import "GnString.h"
#import "GnTrack.h"
#import "GnUser.h"


@class GnPlaylistCollectionEnumerator;
@class GnPlaylistIdentifierEnumerator;
@class GnStringEnumerator;


/**
* <b>Experimental</b>: Playlist Collection Summary that represents
* the media in a user's collection and can be used to generate
* playlists from that media. A Collection Summary is not intended to be
* used as a general database of the user's media collection.
*
* <b>SDK Documentation</b>
*
* Topic: Implementing Applications (All Platforms) > Discovery Features > Generating a Playlist
*
* For more information on playlist collections, see the above topic which covers:
* <ul>
*     <li>How to generate a playlist</li>
*     <li>Creating a collection summary<ul>
*        <li>Creating a collection summary code samples</li></ul></li>
*     <li>Populating a collection summary<ul>
*         <li>Populating a collection summary code samples</li></ul></li>
*     <li>Retrieving playlist attributes in queries</li>
*     <li>How playlist gathers data</li>
*     <li>Working with local storage<ul>
*         <li>Local storage code samples</li></ul></li>
*    <li>Generating a playlist using 'More Like This'<ul>
*         <li>'More Like This' code samples</li></ul></li>
*    <li>Generating a playlist using PDL (Playlist Description Language)</li>
*    <li>Accessing playlist results<ul>
*         <li>Accessing playlist results code samples</li></ul></li>
*     <li>Working with multiple collection summaries</li>
*     <li>Synchronizing collection summaries</li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/playlist
*
* <b>Overview</b>
*
* Topic:  Concepts > Discovery Features > Playlist
*
*/ 

@interface GnPlaylistCollection : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Constructor for GnPlaylistCollection using char* string name. This creates the collection with the name that is passed in.
* @param name   The name to be used to construct the colleciton.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithName: (nullable NSString*)name error: (NSError**)error;

/**
* Constructor for GnPlaylistCollection using a buffer to deserialize it from  and the corresponding buffer size.
* The collection is created from the passed buffer if it is successfully deserialized.
* @param collData  [in] Buffer that contains the serialized data.
* @param dataSize	[in] Buffer size.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithData: (nullable NSData*)data error: (NSError**)error;

/**
* Copy Constructor for GnPlaylistCollection.
* @param other  [in] Reference to GnPlaylistCollection that is to be copied.
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithPlaylistCollection: (nonnull GnPlaylistCollection*)playlistCollection;

/**
* Get the collection name
* @return Name
*/ 

-(nullable NSString*) getName: (NSError**)error;

/**
* Change the collection name
* @param updatedName	New collection name
*/ 

-(void) name: (nullable NSString*)updatedName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a identifier with no metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
*/ 

-(void) add: (nullable NSString*)mediaIdentifier error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a GnAlbum object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param album             [in] GnAlbum object
*/ 

-(void) add: (nullable NSString*)mediaIdentifier album: (nonnull GnAlbum*)album error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a GnTrack object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param track             [in] GnTrack object
*/ 

-(void) add: (nullable NSString*)mediaIdentifier track: (nonnull GnTrack*)track error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a GnContributor object and its metadata to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param contributor       [in] GnContributor object
*/ 

-(void) add: (nullable NSString*)mediaIdentifier contributor: (nonnull GnContributor*)contributor error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a GnPlaylistAttributes object to a Collection Summary.
*
* @param mediaIdentifier       [in] Media identifier
* @param playlistAttributes	[in] Playlist attributes
*/ 

-(void) add: (nullable NSString*)mediaIdentifier playlistAttributes: (nonnull GnPlaylistAttributes*)playlistAttributes error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add a GnListElement object to a Collection Summary.
*
* @param mediaIdentifier   [in] Media identifier
* @param listElement       [in] GnListElement object
*/ 

-(void) add: (nullable NSString*)mediaIdentifier listElement: (nonnull GnListElement*)listElement error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Remove a media element from a Collection Summary.
*
* @param mediaIdentifier  [in] Media identifier
*/ 

-(void) remove: (nullable NSString*)mediaIdentifier error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Test if a media element is in a Collection Summary.
*
* @param mediaIdentifier  [in] Media identifier
*/ 

-(BOOL) contains: (nullable NSString*)mediaIdentifier error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Return metadata from a playlist using a playlist identifier
*
* @param user             [in] GN User object
* @param mediaIdentifier  [in] Playlist identifier
*/ 

-(nullable GnPlaylistAttributes*) attributes: (nonnull GnUser*)user mediaIdentifier: (nonnull GnPlaylistIdentifier*)mediaIdentifier error: (NSError**)error;

/**
* Return attributes from a playlist using a Collection Summary name
*
* @param user             [in] GN User object
* @param mediaIdentifier  [in] Playlist identifier
*/ 

-(nullable GnPlaylistAttributes*) attributes: (nonnull GnUser*)user mediaIdentifier: (nullable NSString*)mediaIdentifier joinedCollectionName: (nullable NSString*)joinedCollectionName error: (NSError**)error;

/**
* Validate a Playlist Definitioon Statement
* @param pdlStatement	Playlist Definition Statment
* @return Validation result
*/ 

-(nullable NSError*) statementValidate: (nullable NSString*)pdlStatement;

/**
* Determine if a Playlist Definition Statement requires a seed
* to generate a playlist
* @param pdlStatement	Playlist Definition Statment
* @return True if a seed is required, false otherwise
*/ 

-(BOOL) statementRequiresSeed: (nullable NSString*)pdlStatement error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* <b>Experimental</b>. Analyzes the given PDL Statement as applied to the given media identifier.
* Used for debugging and analyzing playlist generation with PDL statements, this method
* analyzes the given PDL as applied to the given media identifier.
* The output is a formatted logical tree of the PDL statement and the outcome applied
* for each operation.
* For more information on creating PDL Statements consult the PDL Specification.
* @param pdlStatment		PDL Statment being debugged
* @param mediaIdentifier	Unique identifier of a media item within the collection summary
*/ 

-(nullable NSString*) statementAnalyzeIdent: (nullable NSString*)pdlStatement mediaIdentifier: (nullable NSString*)mediaIdentifier error: (NSError**)error;

/**
* Generate a playlist from a GnDataObject
*
* @param user             [in] Gracenote user
* @param pdlStatement     [in] Playlist Description Language statement
* @param playlistSeed     [in] GN data object to use as seed for playlist
*/ 

-(nullable GnPlaylistResult*) generatePlaylist: (nonnull GnUser*)user pdlStatement: (nullable NSString*)pdlStatement playlistSeed: (nonnull GnDataObject*)playlistSeed error: (NSError**)error;

/**
* Generate a playlist using a Playlist Definition Language (PDL) Statement from this object's Collection Summary.
* For more information on creating PDL Statements consult the PDL Specification.
*
* @param user             [in] Gracenote user
* @param pdlStatement     [in] Playlist Description Language statement
*
*/ 

-(nullable GnPlaylistResult*) generatePlaylist: (nonnull GnUser*)user pdlStatement: (nullable NSString*)pdlStatement error: (NSError**)error;

/**
* Generate a playlist from a GnDataObject
*
* @param user             [in] Gracenote user
* @param musicDataObj     [in] Gracenote data object
*
*/ 

-(nullable GnPlaylistResult*) generateMoreLikeThis: (nonnull GnUser*)user musicDataObj: (nonnull GnDataObject*)musicDataObj error: (NSError**)error;

/**
*  Returns an iterable container for all the playlist attributes this collection supports.
*
*/ 

-(GnStringEnumerator*) attributesSupported;

/**
* Returns an iterable container for all the media identifiers in the collection.
*/ 

-(GnPlaylistIdentifierEnumerator*) mediaIdentifiers;

/**
*  Returns an iterable container for all the joined collections.
*
*/ 

-(GnPlaylistCollectionEnumerator*) joins;

/**
* Join a playlist collection by collection name.
*
* @param collectionName   [in] Collection Summary name
*/ 

-(nullable GnPlaylistCollection*) joinFindByName: (nullable NSString*)collectionName error: (NSError**)error;

/**
* Join a playlist collection by playlist collection object.
*
* @param toJoin   [in] GnPlaylistCollection object for join
*/ 

-(void) join: (nonnull GnPlaylistCollection*)toJoin error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Remove a join with another playlist
*
* @param toRemove   [in] GnPlaylistCollection object to remove join
*/ 

-(void) joinRemove: (nonnull GnPlaylistCollection*)toRemove error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Serialize a Collection Summary into buffer
*
* @param data [in] Input data
* @return buffer size
*/ 

-(NSUInteger) serialize:(NSData*)data  error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Returns the size of a serialized playlist collection object
* @return serialized buffer size
*/ 

-(NSUInteger) serializeSize: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Add an identifier as part of synchronizing a user's media collection with the
* corresponding Collection Summary.
*
* Collection sychronization is a two step process:
*     1)Use this method to add all unique identifiers that currently exist in the user's collection.
*     2) Execute the synchronization process.
* @param mediaIdentifier [in] unique media identifier used in you application e.g. file path
*/ 

-(void) syncProcessAdd: (nullable NSString*)mediaIdentifier error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Process synchronize identifiers previously added to the Collection Summary to complete
* synchronizing a user's media collection with the corresponding Collection Summary.
*
* As step two of the synchronization process call this method after adding all unique
* identifiers using SyncProcessAdd. This call will determine which identifiers added for
* synchronization need to be also be added to the Collection Summary; and those that need to be
* removed from the Collection Summary because they no longer exist in the user's collection.
* This information is delivered via the synchronization delegate.
* @param syncEvents [in] Synchronizations events delegate
*/ 

-(void) syncProcessExecute: (nonnull id <GnPlaylistCollectionSyncEventsDelegate>)syncEvents error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get object for setting "more like this" options
* @return	More like this options object
*/ 

-(nonnull GnPlaylistMoreLikeThisOptions*) moreLikeThisOptions;


NS_ASSUME_NONNULL_END

@end


@interface GnPlaylistCollectionEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnPlaylistCollectionBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnPlaylistCollectionBlock)handler;

-(NSUInteger) count;

-(nullable GnPlaylistCollection*) nextObject;

-(nullable GnPlaylistCollection*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnPlaylistCollection_h_ */

