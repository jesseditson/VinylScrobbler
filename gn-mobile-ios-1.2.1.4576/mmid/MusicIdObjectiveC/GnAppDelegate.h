//
//  AppDelegate.h
//  MusicIdObjectiveC
//
//  Copyright © 2016 Gracenote. All rights reserved.
//

#import <UIKit/UIKit.h>

static const unsigned int CAP_LIMIT = 1000;

@interface GnAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

+ (NSManagedObjectContext *)sharedContext;
+ (NSManagedObjectModel *)sharedManagedObjectModel;
+ (NSPersistentStoreCoordinator *)sharedCoordinator;
+ (NSString*) applicationDocumentsDirectory;

+(unsigned int)getLastInsertedAuto_id;
+(void)setLastInsertedAuto_id:(unsigned int)newId;
-(void)getLastInsertedAuto_idFromUserDefaults;
-(void)storeLastInsertedAuto_idToUserDefaults;

@end


@protocol GnAudioVisualizerDelegate <NSObject>

-(void) RMSDidUpdateByValue:(float) value;

@end