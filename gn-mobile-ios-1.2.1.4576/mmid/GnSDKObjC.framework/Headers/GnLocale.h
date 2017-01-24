/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLocale_h_
#define _GnLocale_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnCancellableDelegate.h"
#import "GnEnums.h"
#import "GnLocaleInfo.h"
#import "GnStatusEventsDelegate.h"
#import "GnUser.h"


@class GnLocaleInfoEnumerator;


/**
* locale_info_iterator
*//**
* locale_info_iterable
*//**
* Loads Gracenote data for a specified locale.
*
* The GNSDK provides locales as a convenient way to group locale-dependent metadata specific to a region
* (such as Europe) and language that should be returned from the Gracenote Service. A locale is defined by a group
* (such as Music), a language, a region and a descriptor (indicating level of metadata detail), which are identifiers
* to a specific set of lists in the Gracenote Service.
*
* The GNSDK uses locales for various reasons and it is a best practice to have an appropriate locale
* loaded. Work with your Gracenote representative to determine what locale group and descriptor to load.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b>  Implementing Applications (All Platforms) > Loading a Locale
*
* For more information on locales, see the above topic, which covers the following:
*    <ul>
*        <li>General information about locales</li>
*        <li>Code samples, in multiple programming languages, showing how to load a locale</li>
*        <li>Locale dependent data</li>
*        <li>Default regions and descriptors</li>
*        <li>Locale groups
*            <ul>
*        <li>Multi-threaded access</li>
*        <li>Updating locales and lists</li>
*        <li>Update notification</li></ul></li>
*    <li>Locale Behavior</li>
*    <li>Best practicles for using locales</li>
*    </ul>
*
* <p><b>Overview</b></p>
*
* <b>Topic:</b> Concepts > Genre and Other List-Dependent Values
*
*/ 

@interface GnLocale : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Constructs a GnLocale object
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLocaleInfo: (nonnull GnLocaleInfo*)localeInfo user: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Loads the specified locale
* @param group				Locale group
* @param language			Locale data language
* @param region			Locale region (where applicable)
* @param descriptor		Descriptor, or granularity, of the locale data where applicable
* @param user				User object
* @param pEventHandler     Status events delegate
* <p><b>Note</b><p> This method blocks the current thread until the load is complete;
* set an GnStatusEventsDelegate delegate to receive progress updates.
*
* Long Running Potential: Network I/O, File system I/O
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLocaleGroup: (GnLocaleGroup)localGroup language: (GnLanguage)language region: (GnRegion)region descriptor: (GnDescriptor)descriptor user: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Loads the specified locale with native strings
* @param group				Locale group
* @param language			Locale data language
* @param region			Locale region (where applicable)
* @param descriptor		Descriptor, or granularity, of the locale data where applicable
* @param user				User object
* @param pEventHandler     Status events delegate
* <p><b>Note</b><p> This method blocks the current thread until the load is complete;
* set an GnStatusEventsDelegate delegate to receive progress updates.
*
* Long Running Potential: Network I/O, File system I/O
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithGroup: (nullable NSString*)group language: (nullable NSString*)language region: (nullable NSString*)region descriptor: (nullable NSString*)descriptor user: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Loads the specified locale
* @param group				Locale group
* @param langIsoCode		ISO code for locale data language
* @param region			Locale region (where applicable)
* @param descriptor		Descriptor, or granularity, of the locale data where applicable
* @param user				User object
* @param pEventHandler     Status events delegate
* <p><b>Note</b><p> This method blocks the current thread until the load is complete;
* set an GnStatusEventsDelegate delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLocaleGroup: (GnLocaleGroup)localGroup langIsoCode: (nullable NSString*)langIsoCode region: (GnRegion)region descriptor: (GnDescriptor)descriptor user: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error;

/**
* Reconstitutes locale from serialized locale data.
* @param serializedLocale	String of serialized locale handle data
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithSerializedLocale: (nullable NSString*)serializedLocale error: (NSError**)error;

/**
* Get Locale information
*/ 

-(nonnull const GnLocaleInfo*) localeInformation;

/**
* Retrieves this locale's revision string.
* @return Revision
*/ 

-(nullable NSString*) revision: (NSError**)error;

/**
* Sets this locale as the default locale for the 'locale group' (see GnLocaleGroup).
*/ 

-(void) setGroupDefault: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Retrieve iterator for locales available from locale lists cache
* @return Locale info iterator
*/ 

+(GnLocaleInfoEnumerator*) storedLocales;

/**
* Updates a locale with newer locale data, if available.
* To ensure the Gracenote Service can be contacted to test for a new list version,
* your application needs to configure the user's lookup mode to allow online access.
*
* To cancel the update procedure, set the "canceller" in any method
* called in the status event delegate.
*
* @param user				User requesting the locale update
* @param pEventHandler		Status events delegate
* @return True indicates updates were applied, false indicates no updates are available
*
* <p><b>Note</b></p>
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress messages.
*
* Long Running Potential: Network I/O, File system I/O
*/ 

-(BOOL) update: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Tests a locale to determine if newer locale data is available. If it is, your application
* should call Update()to download it.
* To ensure the Gracenote Service can be contacted to test for a new list version,
* your application needs to configure the user's lookup mode to allow online access.
*
* To cancel the update check procedure, set the "canceller" in any method called in the
* status event delegate.
*
* @param user				User requesting the locale update check
* @param pEventHandler		Status event delegate
* @return True indicates updates are available, false otherwise.
*
* <p><b>Remarks:</b></p>
* You can invoke this method periodically to check the Gracenote Service for locale data updates.
*
* <p><b>Note:</b></p>
* You should immediately check for updates after constructing a locale object from a saved serialized locale
* string as it may be out of date.
*
* This methods blocks the current thread until the update procedure is complete;
* set a status events delegate to receive progress notification updates.
*
* Long Running Potential: Network I/O
*/ 

-(BOOL) updateCheck: (nonnull GnUser*)user statusEventsDelegate: (nullable id <GnStatusEventsDelegate>)pEventHandler error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Serializes locale data into an encrypted text string that you can store locally for later use.
* <p><b>Note:</b></p>
* If your application is using a GNSDK local storage solution, locale data is automatically stored
* and retrieved from a local store according to the user lookup option configuration.
* If you are implementing your own local storage functionality, you can use this method to
* render a locale into a format that can be stored persistently and restored at a later time using
* the appropriate constructor.
* @return Serialize locale data
*/ 

-(nullable NSString*) serialize: (NSError**)error;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnLocale_h_ */

