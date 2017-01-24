//
//  GnUserStore.h
//  gnsdk_objc
//
//  Created on 12/4/13.
//  Copyright (c) 2013 Gracenote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GnUserStoreDelegate.h"

/**
 * Store and load serialized GnUser using NSUserDefaults.
 * 
 * This is a Gracenote helper delegate class to store and load the Gracenote
 * serialized user. It uses NSUserDefaults to persist the user data.
 * 
 * For all helper delegate classes you can provide your own implementation, it just
 * needs to implement the correct interface, in this case GnUserStoreDelegate. 
 * 
 * If you do provide your own implementation Gracenote recommends starting with
 * this implementation and altering as required; therefore the source is
 * available on request.
 *
 */
@interface GnUserStore : NSObject <GnUserStoreDelegate>

@end
