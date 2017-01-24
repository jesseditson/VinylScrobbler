//
//  CoverArt.h
//  GN_Music_SDK_iOS
//
//  Created by Kshitij Deshpande on 11/19/13.
//  Copyright (c) 2013 Gracenote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

@class Metadata;

@interface CoverArt : NSManagedObject

@property (nonatomic, retain) NSData * data;
@property (nonatomic, retain) NSString * mimeType;
@property (nonatomic, retain) NSString * size;
@property (nonatomic, retain) Metadata *metaData;

@end
