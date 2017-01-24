/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnMoodgridPresentation_h_
#define _GnMoodgridPresentation_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnMoodgridDataPoint.h"
#import "GnMoodgridProvider.h"
#import "GnMoodgridResult.h"


@class GnMoodgridDataPointEnumerator;


/**
** <b>Experimental</b>: GnMoodgridPresentation
*/ 

@interface GnMoodgridPresentation : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Retrieves an iterator to access the Mood data points in this presentation.
* @return moods
*/ 

-(GnMoodgridDataPointEnumerator*) moods: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Retrieves the presentation type the defines the no. of moods available in this presentation..
* @return moods
*/ 

-(GnMoodgridPresentationType) layoutType: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
*  Retrieves the coordinate type that defines the layout of the presentation.
* @return moodgridcoordinatetype.
*/ 

-(GnMoodgridCoordinateType) coordinateType;

/**
* Adds a filter to the presentation for the inclusion of a list type to include or exclude from the recommendations.
* @param uniqueIdentifier [in] : Unique identifier for the presentation representing this filter.
* @param elistType [in] : List type
* @param strValueId [in] : List value that is to be operated upon.
* @param eConditionType [in]: Filter condition
*/ 

-(void) addFilter: (nullable NSString*)uniqueIdentifier elistType: (GnMoodgridFilterListType)elistType strValueId: (nullable NSString*)strValueId eConditionType: (GnMoodgridFilterConditionType)eConditionType error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Removes a filter from the presentation.
* @param uniqueIdentifier [in] : identifier that represents the filter to be removed.
*/ 

-(void) removeFilter: (nullable NSString*)uniqueIdentifier error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Removes all filters from the presentation.
*/ 

-(void) removeAllFilters: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Retrieves a mood name as defined by the locale for a given data point in the presentation.
* @param position [in] : data position
* @return moodname
*/ 

-(nullable NSString*) moodName: (nonnull GnMoodgridDataPoint*)position error: (NSError**)error;

/**
* Retrieves a mood id for the given data point in the presentation.
* @param position [in] : data position
* @return moodid.
*/ 

-(nullable NSString*) moodId: (nonnull GnMoodgridDataPoint*)position error: (NSError**)error;

/**
* Generates recommendations for a given mood data point and provider. The reccomentations are represented by a
* GnMoodgridResult.
* @param provider [in] : Moodgrid provider that the results must come from.
* @param position [in] : Data point that represents the mood for which reccomendation are requested.
* @return GnMoodgridResult
*/ 

-(nullable GnMoodgridResult*) findRecommendations: (nonnull GnMoodgridProvider*)provider position: (nonnull GnMoodgridDataPoint*)position error: (NSError**)error;

/**
* Generates a recommendations estimate for a given mood data point and provider. The estimate is dependent on the
* provider. Use this functionality for creating a heat map of all the moods supported in the presentation.
* @param provider [in] : Moodgrid provider that the estimate must come from.
* @param position [in] : Data point that represents the mood for which the estimate is requested.
* @return count representing the estimate.
*/ 

-(NSUInteger) findRecommendationsEstimate: (nonnull GnMoodgridProvider*)provider position: (nonnull GnMoodgridDataPoint*)position error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnMoodgridPresentation_h_ */

