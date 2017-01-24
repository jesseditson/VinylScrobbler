/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdFileInfoManager_h_
#define _GnMusicIdFileInfoManager_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnMusicIdFileInfo.h"
#import "GnMusicIdFileInfoEventsDelegate.h"




/**
* Provides services for adding audio tracks to GnMusicIdFile for identification.
*/ 

@interface GnMusicIdFileInfoManager : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Add an audio file to GnMusicIdFile for identification
* @param uniqueIdentifier	[in] Audio track unique identifier such as a filename or library reference
* @param pEventHandler		[in-opt] Event delegate for processing events specifically for this audio file. Use
* 							where the generic event handler provided on GnMusicIdFile construction isn't
* 							suitable
* @return Object representing the audio file
*/ 

-(nullable GnMusicIdFileInfo*) add: (nullable NSString*)uniqueIdentifier musicIdFileInfoEventsDelegate: (nullable id <GnMusicIdFileInfoEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Add audio file(s) represented by an XML string to GnMusicIdFile for identification
* @param xmlStr			[in] Audio file(s) XML string, such as one created using RenderToXml()
* @return Number of audio files added
*/ 

-(NSUInteger) addFromXml: (nullable NSString*)xmlStr error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Render all added audio files to an XML string
* @return XML string
*/ 

-(nullable NSString*) renderToXml: (NSError**)error;

/**
* Remove and audio file from GnMusicIdFile
* @param fileInfo			[in] Object representing audio file to remove
*/ 

-(void) remove: (nonnull GnMusicIdFileInfo*)fileInfo error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get number of audio files added
* @return Number of audio files
*/ 

-(NSUInteger) count;

/**
* Get audio file at specified index
* @param index				[in] Audio file index
* @return file iterator
*/ 

-(nullable GnMusicIdFileInfo*) at: (NSUInteger)index;

/**
* Retrieves the GnMusicIdFileInfo object that matches the given identifier string and is associated with the
* given MusicID-File handle.
* @param ident 			[in] String identifier of FileInfo to retrieve
* <p><b>Remarks:</b></p>
* The string identifier of each GnMusicIdFileInfo is set when Add is called.
* GnMusicIdFile enforces GnMusicIdFileInfo identifiers to be unique.
*/ 

-(nullable GnMusicIdFileInfo*) getByIdentifier: (nullable NSString*)ident error: (NSError**)error;

/**
* Retrieves the GnMusicIdFileInfo object that matches the given file name.
* @param filename 			[in] File name or other string identifier of FileInfo to retrieve
* <p><b>Remarks:</b></p>
* Only GnMusicIdFileInfo objects that have file name information set through
* GnMusicIdFile::FileName can be retrieved with this function.
* <p><b>Note:</b></p>
* GnMusicIdFile does not enforce unique GnMusucIdFileInfo file names. Consequently, to use this function
* well, it is important to give unique file names to each GnMusicIdFileInfo added (such as the full path and
* file name).
* GnMusicIdFile does not check if the given file name given is a valid path or file name, nor is it
* required to be one. GnMusicIdFile only performs a match against the existing GnMusicIdFileInfo path and file
* names.
*/ 

-(nullable GnMusicIdFileInfo*) getByFilename: (nullable NSString*)filename error: (NSError**)error;

/**
* Retrieves the index'th GnMusicIdFileInfo object matching the given folder.
* @param folder 			[in] Folder name of GnMusicIdFileInfo object to retrieve
* @param index 			[in] Index of GnMusicIdFileInfo object in folder name to retrieve
* <p><b>Remarks:</b></p>
* Only a GnMusicIdFileInfo that has path information set through GnMusicIdFile::FileName
* can be retrieved with this function. GnMusicId does not check if the given folder name is a valid path,
* nor is it required to be one. GnMusicIdFile only performs a match against existing GnMusiucIdFileInfo
* folder names.
*/ 

-(nullable GnMusicIdFileInfo*) getByFolder: (nullable NSString*)folder index: (NSUInteger)index error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdFileInfoManager_h_ */

