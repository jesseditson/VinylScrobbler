/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnUserOptions_h_
#define _GnUserOptions_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




/**
* Configuration options for GnUser
*/ 

@interface GnUserOptions : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* Constructs empty GnUserOptions object. It is not associated with any GnUser object.
*/ 

-(nullable INSTANCE_RETURN_TYPE) init;

/**
* Get lookup mode.
* @return Lookup mode
*/ 

-(GnLookupMode) getLookupMode: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Set lookup mode.
* @param lookupMode	[in] Lookup mode
*/ 

-(void) lookupMode: (GnLookupMode)lookupMode error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get network proxy hostname
* @return Network proxy hostname
*/ 

-(nullable NSString*) getNetworkProxy: (NSError**)error;

/**
* Sets host name, username and password for proxy to route GNSDK queries through
* @param hostname	[in] Fully qualified host name with optional port number. If no port number
*                  is given, the default port number is assumed to be 80.
*                  Example values are "http://proxy.mycompany.com:8080/", "proxy.mycompany.com:8080" and
*                  "proxy.mycompany.com"
* @param username  [in] Valid user name for the proxy server. Do not set this option if a username is not required.
* @param password  [in] Valid password for the proxy server. Do not set this option if a password is not required.
*/ 

-(void) networkProxy: (nullable NSString*)hostname username: (nullable NSString*)username password: (nullable NSString*)password error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Gets the network time-out for all GNSDK queries
* @return Netwrk timeout
*/ 

-(NSUInteger) getNetworkTimeout: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Sets the network time-out for all GNSDK queries in milliseconds.
* This option's value is a string containing a numeric value for network time-outs in milliseconds
* For example, for a 30-second time-out, set this to 30000.
* @param timeout_ms	[in] Time-out in milliseconds
*/ 

-(void) networkTimeout: (NSUInteger)timeout_ms error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Get network local balance state
* @return Network load balance state
*/ 

-(BOOL) getNetworkLoadBalance: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Enable/disable distributing queries across multiple Gracenote co-location facilities
* Enable to implement load balancing; otherwise, queries generally resolve to a single co-location.
*
* You might want to enable this if you are sending a large amount of traffic through a central
* point, e.g., a proxy. In this scenario, enabling load-balancing could help to improve performance. Talk to your
* Gracenote representative on how much traffic would justify doing this.
*
* @param bEnable  [in] True to enable load balancing, false otherwise.
* <p><b>Note:</b></p>
* Ensure that any security settings (such as a firewall) in your network infrastructure do not
* affect outbound access and prevent GNSDK from transmitting queries to various hosts with unique IP
* addresses.
*/ 

-(void) networkLoadBalance: (BOOL)bEnable error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Set a specific network interface to use with this object's connections. This can be useful for
* systems with multiple network interaces. Otherwise, the operating system determines the interface to use.
*  @param intfName [in] Local IP address or system name for the desired network interface
*/ 

-(void) networkInterface: (nullable NSString*)intfName error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* If one has been set, returns the network interface being used with this object's connections.
* Returns an empty string if no specific network interface has been set.
*/ 

-(nullable NSString*) getNetworkInterface: (NSError**)error;

/**
* Set information about this user
* @param location_id	[in] Set an IP address or country code to represent the location of user performing requests.
*                      Value for this parameter is a string with the IP address, or a 3-character country code
*                      for the client making the request. This is generally required when setting a proxy for
*                      GNSDK queries. Example values are "192.168.1.1", "usa" and "jpn".
* @param mfg			[in] The manufacturer of the device running the SDK. Used mostly by Gracenote Service to collect
*                      runtime statistics.
* @param os			[in] The OS version of the device running the SDK. Used mostly by Gracenote Service to collect
*                      runtime statistics.
* @param uid			[in] Unique ID of the device running the SDK, such as ESN. Used mostly by Gracenote Service to
*                      collect runtime statistics.
*/ 

-(void) userInfo: (nullable NSString*)location_id mfg: (nullable NSString*)mfg os: (nullable NSString*)os uid: (nullable NSString*)uid error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Sets the Device model
* Used for runtime statistics
* @param model of the device
*/ 

-(void) deviceModel: (nullable NSString*)model error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Gets the Device model
* @return Device model
*/ 

-(nullable NSString*) getDeviceModel: (NSError**)error;

/**
* Gets cache expiration time in seconds
* @return Cache expiration time
*/ 

-(NSUInteger) getCacheExpiration: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Sets the maximum duration for which an item in the GNSDK query cache is valid. This duration is in
* seconds, and must exceed one day.
* The value set for this option is a string with a numeric value that indicates the number of
* seconds to set for the expiration of cached queries. The maximum duration is set by Gracenote and
* varies by requirements.
* @param durationSec		[in] Expiration duration in seconds. For example, for a one day expiration
* 							set an option value of "86400" (60 seconds * 60 minutes * 24 hours); for a
* 							seven day expiration set an option value of "604800"
* 							(60 seconds * 60 minutes * 24 hours * 7 days).
* <p><b>Note:</b></p>
* Setting this option to a zero value (0) causes the cache to start deleting records upon cache
* hit, and not write new or updated records to the cache; in short, the cache effectively flushes
* itself. The cache will start caching records again once this option is set to a value greater than
* 0. Setting this option to a value less than 0 (for example: -1) causes the cache to use default
* expiration values.
*
* For mobile platforms Android, iOS and Windows Mobile the default cache expiration is zero.
*
* Cache expiration only has an effect if the application initializes a GNSDK storage provider such as
* GnStorageSqlite. Without a storage provider no cache can be created.
*
*/ 

-(void) cacheExpiration: (NSUInteger)durationSec error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Gets user option
* @param key	[in] Option key
* @return Option value
*/ 

-(nullable NSString*) getCustom: (nullable NSString*)key error: (NSError**)error;

/**
* Sets User option
* @param key	[in] Option key
* @param value	[in] Option value
*/ 

-(void) custom: (nullable NSString*)key value: (nullable NSString*)value error: (NSError**)error NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnUserOptions_h_ */

