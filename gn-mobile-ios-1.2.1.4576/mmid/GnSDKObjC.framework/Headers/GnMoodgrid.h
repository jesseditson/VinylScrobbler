/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMoodgrid_h_
#define _GnMoodgrid_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnMoodgridDataPoint.h"
#import "GnMoodgridPresentation.h"
#import "GnMoodgridProvider.h"
#import "GnUser.h"


@class GnMoodgridProviderEnumerator;


/**
* <b>Experimental</b>: GnMoodgrid
*
*  The GnMoodgrid class allows applications to generate playlists and user interfaces based on Gracenote Mood descriptors.
*
* <b>SDK Documentation</b>
*
* Topic: Implementing Applications (All Platforms) > Discovery Features > Implementing Moodgrid
*
* For more information on using GnMoodgrid, see the above topic which covers:
* <ul>
*     <li>Implementing Moodgrid in an application</li>
*     <li>Enumerating data sources using Mood providers<ul>
*     <li>Code samples for enumerating data sources</li></ul></li>
*     <li>Creating and populating a Mood presentation<ul>
*     <li>Code samples for creating and populating a Mood presentation</li></ul></li>
*     <li>Iterating through a Mood presentation<ul>
*     <li>Code samples for iterating through a Mood presentation</li></ul></li>
*     <li>Filtering mood results<ul>
*     <li>Code samples for filtering mood results</li></ul></li>
* </ul>
*
* <b>Sample App</b>
*
*     - .../samples/moodgrid
*
* <b>Overiew</b>
*
* Topic: Concepts > Discovery Features > Mood Overview
*/ 

@interface GnMoodgrid : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnMoodgrid
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Version information for the library
* @return version
*/ 

+(nonnull NSString*) version;

/**
* Build Date for the library
* @return build date
*/ 

+(nonnull NSString*) buildDate;

/**
* Enumeration of all providers currently available for the moodgrid.
* @return iterable container of moodgrid providers.
*/ 

-(GnMoodgridProviderEnumerator*) providers;

/**
* Creates a Presentation that represents the type of moodgrid layout to  generate recommendations for. A presentation
* object is the way to access all Mood names and recommendations supported by its layout.
* @param user [in] : valid user
* @param type [in] : enum value representing the Presentation type .
* @param coordinate [in] : enum value representing the coordinate type for the presentation layout.
* @return presentation.
*/ 

-(nullable GnMoodgridPresentation*) createPresentation: (nonnull GnUser*)user type: (GnMoodgridPresentationType)type coordinate: (GnMoodgridCoordinateType)coordinate error: (NSError**)error;

/**
* Retrieves a data point representing the dimensions of the presentation e.g. 5,5
* @return datapoint.
*/ 

-(nullable GnMoodgridDataPoint*) dimensions: (GnMoodgridPresentationType)type error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMoodgrid_h_ */

