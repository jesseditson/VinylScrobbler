/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMusicIdOptions_h_
#define _GnMusicIdOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* \class GnMusicIdOptions
* Configures options for GnMusicId
*/ 

@interface GnMusicIdOptions : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
*  Indicate whether the MusicID query should be performed against local embedded databases or online.
*  @param lookupMode  [in] One of the GnLookupMode values
*  @ingroup MusicId_Options
*/ 

-(void) lookupMode: (GnLookupMode)lookupMode error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the lookup data value for the MusicID query.
*  @param lookupData [in] One of the GnLookupData values
*  @param bEnable    [in] Set lookup data
*  @ingroup MusicId_Options
*/ 

-(void) lookupData: (GnLookupData)lookupData bEnable: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the preferred language for the returned results.
*  @param preferredLanguage [in] One of the GNSDK language values
*  @ingroup MusicId_Options
*/ 

-(void) preferResultLanguage: (GnLanguage)preferredLanguage error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set the preferred external ID of the returned results.
*  Only available where single result is also requested.
*  @param strExternalId [in] Gracenote external ID source name
*  @ingroup MusicId_Options
*/ 

-(void) preferResultExternalId: (nullable NSString*)strExternalId error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set that you would like cover art (if availble) in the returned results.
*  @param bEnable [in] Set prefer cover art
*  @ingroup MusicId_Options
*/ 

-(void) preferResultCoverart: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set that the response must return only a single best result.
*  When enabled, a single full result is returned; when disabled, multiple partial results may be returned.
*  @param bEnable [in] Set single result
*  <p><b>Remarks:</b></p>
*  If enabled, the MusicID library selects the single best result based on the query type and input.
*  @ingroup MusicId_Options
*/ 

-(void) resultSingle: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Enable or disable revision check option.
*  @param bEnable [in] Set revision check
*
* Long Running Potential: Network I/O, File system I/O (for online query cache or local lookup)
*  @ingroup MusicId_Options
*/ 

-(void) revisionCheck: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Specfies whether a response must return a range of results that begin and count at a specified values.
*  @param resultStart  [in] Result range start value
*  <p><b>Remarks:</b></p>
*  This Option is useful for paging through results.
*  <p><b>Note:</b></p>
*  Gracenote Service enforces that the range start value must be less than or equal to the total
*  number of results. If you specify a range start value that is greater than the total number of
*  results, no results are returned.
*  @ingroup MusicId_Options
*/ 

-(void) resultRangeStart: (NSUInteger)resultStart error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set tje maximum number of results to return.
*  @param resultCount  [in] Maximum results
*  <p><b>Note:</b></p>
*  Gracenote Service enforces its own maximum number of results that can vary over time and query types.
*  This setting sets a maximum that can be as high as the Service maximum  but not higher.
*  @ingroup MusicId_Options
*/ 

-(void) resultCount: (NSUInteger)resultCount error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*  @ingroup MusicId_Options
*/ 

-(void) networkInterface: (nullable NSString*)intfName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Return the network interface being used with this object's connections if one has been set.
* If no specific network interface has been set, this option returns an empty string.
*  @ingroup MusicId_Options
*/ 

-(nullable NSString*) getNetworkInterface: (NSError**)error;

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param value	[in] Option value
*  @ingroup MusicId_Options
*/ 

-(void) customOptionValue: (nullable NSString*)option value: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Set option using option name
*  @param option   [in] Option name
*  @param bEnable	[in] Option enable true/false
*  @ingroup MusicId_Options
*/ 

-(void) customOptionEnable: (nullable NSString*)option enable: (BOOL)enable error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMusicIdOptions_h_ */

