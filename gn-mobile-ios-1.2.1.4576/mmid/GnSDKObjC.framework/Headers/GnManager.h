/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnManager_h_
#define _GnManager_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"
#import "GnList.h"
#import "GnLocale.h"
#import "GnStoreOps.h"
#import "GnSystemEventsDelegate.h"
#import "GnUser.h"




/**
* GnManager class
*
* Provides core functionality necessary to all Gracenote objects. This class must
* be instantiated prior to any other Gracenote objects.
*
* <p><b>SDK Documentation</b></p>
* Topic:  .../docs/html-oo > index.html > Implementing Applications (All Platforms) > Setup and Initialization
*
* For more information on basic setup, see the above topic, which covers the following:
*    <ul>
*        <li>Authorizing a GNSDK application</li>
*        <li>Including header files</li>
*        <li>Instantiating a GNSDK Manager object</li>
*        <li>Instantiating a User object</li>
*    </ul>
*
*/ 

@interface GnManager : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Initializes GNSDK. You must initialize the GNSDK prior to instantiating any other GNSDK objects.
* Valid license data must be provided. Gracenote team provides a license with the SDK.
* @param license			[in] license data
* @param licenseInputMode	[in] how the license data is being provided
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithLicense: (nullable NSString*)license licenseInputMode: (GnLicenseInputMode)licenseInputMode error: (NSError**)error;

/**
* Retrieves the GNSDK version string.
* You can all this API any time after a GnManager instance is constructed successfully. The returned
* string is a constant. Do not attempt to modify or delete.
* Example: 1.2.3.123 (Major.Minor.Improvement.Build)
* Major: New functionality
* Minor: New or changed features
* Improvement: Improvements and fixes
*/ 

+(nonnull NSString*) version;

/**
* Retrieves the product version string.
* You can call this API at any time after a GnManager instance is constructed successfully. The returned
* string is a constant. Do not attempt to modify or delete.
* Example: 1.2.3.123 (Major.Minor.Improvement.Build)
* Major: New functionality
* Minor: New or changed features
* Improvement: Improvements and fixes
* Build: Internal build number
*/ 

+(nonnull NSString*) productVersion;

/**
* Retrieves the GNSDK's build date string.
* You can call this API at any time after a GnManager instance is constructed successfully. The returned
* string is a constant. Do not attempt to modify or delete.
* Example: 2008-02-12 00:41 UTC
*/ 

+(nonnull NSString*) buildDate;

/**
* GlobalIdMagic
*/
+(nonnull NSString*) globalIdMagic;

/**
* Creates a new Serialized User and also increments the user's Client ID user count with Gracenote Service.
* Use this constructor to create a new user; when successful, this call registers a new user for
* a specified client in Gracenote Service. Once the new user is registered and the user count
* incremented in Gracenote Service, the count cannot be reduced, nor can the same user be
* again retrieved.
* Newly registered user handles must be serialized and stored locally for that user to be used
* again for future queries; failing to do this quickly depletes the client's allotted user quota
* within the Gracenote Service.
* @param registerMode  		[in] register as online or local only user
* @param clientId     			[in] client ID that initiates requests with this handle; value provided by
*                      		Gracenote
* @param clientTag    			[in] client ID tag value that matches client ID; value provided by Gracenote
* @param applicationVersion  	[in] client application version; numeric value provided by application, and
*                      		this value is required
*/ 

-(nullable NSString*) userRegister: (GnUserRegisterMode)registerMode clientId: (nullable NSString*)clientId clientTag: (nullable NSString*)clientTag applicationVersion: (nullable NSString*)applicationVersion error: (NSError**)error;

/**
* Get query cache storage operations instance
*/ 

-(nonnull GnStoreOps*) queryCacheStore;

/**
* Get content cache storage operations instance
*/ 

-(nonnull GnStoreOps*) contentCacheStore;

/**
* Get locales storage operations instance
*/ 

-(nonnull GnStoreOps*) localesStore;

/**
* Provide a delegate to receive system events
* @param pEventHandler		[in] event handler delegate
*/ 

-(void) systemEventHandler: (nullable id <GnSystemEventsDelegate>)pEventHandler;

/**
* SystemMemoryEvent
*/
-(void) systemMemoryEvent: (NSUInteger)memoryWarnSize;

/**
* SystemMemoryCurrent
*/
-(NSUInteger) systemMemoryCurrent;

/**
* SystemMemoryHighWater
*/
-(NSUInteger) systemMemoryHighWater: (BOOL)bResetHighWater;

/**
* TestGracenoteConnection
*/
-(void) testGracenoteConnection: (nonnull GnUser*)user error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnManager_h_ */

