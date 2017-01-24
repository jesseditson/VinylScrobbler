//
//  Metadata.h
//  GN_Music_SDK_iOS
//
//  Created by Kshitij Deshpande on 11/19/13.
//  Copyright (c) 2013 Gracenote. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>


@interface Metadata : NSManagedObject

@property (nonatomic, retain) NSString * albumId;
@property (nonatomic, retain) NSString * albumTitle;
@property (nonatomic, retain) NSString * albumTitleYomi;
@property (nonatomic, retain) NSNumber * albumTrackCount;
@property (nonatomic, retain) NSString * artist;
@property (nonatomic, retain) NSString * artistBetsumei;
@property (nonatomic, retain) NSString * artistYomi;
@property (nonatomic, retain) NSString * genre;
@property (nonatomic, retain) NSNumber * trackNumber;
@property (nonatomic, retain) NSString * trackTitle;
@property (nonatomic, retain) NSString * trackTitleYomi;
@property (nonatomic, retain) NSManagedObject *history;
@property (nonatomic, retain) NSManagedObject *coverArt;

@end
