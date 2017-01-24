//
//  History.h
//  GN_Music_SDK_iOS
//
//  Created by Kshitij Deshpande on 11/19/13.
//  Copyright (c) 2013 Gracenote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Metadata;

@interface History : NSManagedObject

@property (nonatomic, retain) NSNumber * auto_id;
@property (nonatomic, retain) NSDate * current_date;
@property (nonatomic, retain) NSString * fingerprint;
@property (nonatomic, retain) NSNumber * latitude;
@property (nonatomic, retain) NSNumber * longitude;
@property (nonatomic, retain) Metadata *metadata;

@end
