/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnUser_h_
#define _GnUser_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnUserOptions.h"
#import "GnUserStoreDelegate.h"




/**
* GnUser
* To make queries, every application is required to instantiate a GnUser object for each app user.
*
* <p><b>SDK Documentation</b></p>
*
* <b>Topic:</b>  Implementing Applications (All Platforms) > Setup and Initialization
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

@interface GnUser : NSObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Reconstitutes user from serialized user handle data.
* Use this constructor to reconstitute a previously serialized GnUser. Reconstitution does not
* count towards the user count for your client in Gracenote Service.
* User's registered via Gracenote's Web API can also be used, this prevents an application
* that uses both GNSDK and Web API from having to register two users. To use a user from
* Web API construct it according to the following format and provide:
* 		<clientid>-<clienttag>:<userid>-<usertag>
* @param serializedUser		[in] String of serialized user handle data
* @param clientIdTest			[in_opt] Serialized user's expected Client ID
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithSerializedUser: (nullable NSString*)serializedUser clientIdTest: (nullable NSString*)clientIdTest error: (NSError**)error;

/**
* Create a GnUser with the provided Client ID and Client Tag. Check user storage for an
* existing user and if found reconstitutes the user. Reconstitution does not
* count towards the user count for your client in Gracenote Service. If not found in
* user storage a new user is created.
* @param userStore				[in] User store delegate
* @param clientId				[in] Client Identifer
* @param clientTag				[in] Client Tag
* @param applicationVersion	[in] Application version
*/ 

-(nullable INSTANCE_RETURN_TYPE) initWithUserStoreDelegate: (nonnull id <GnUserStoreDelegate>)userStoreDelegate clientId: (nullable NSString*)clientId clientTag: (nullable NSString*)clientTag applicationVersion: (nullable NSString*)applicationVersion error: (NSError**)error;

/**
* Gets flag indicating if the current user is only registered for local queries
* @return True if local only user, fals eotherwise
*/ 

-(BOOL) isLocalOnly: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;

/**
* Receive user options object. Use to set user options.
* @return User options object
*/ 

-(nonnull GnUserOptions*) options;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnUser_h_ */

