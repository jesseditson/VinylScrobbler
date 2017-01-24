//
//  AppDelegate.m
//  MusicIdObjectiveC
//
//  Copyright © 2016 Gracenote. All rights reserved.
//

#import "GnAppDelegate.h"
#import "History.h"

#import  <CoreData/CoreData.h>

@implementation GnAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    [self storeLastInsertedAuto_idToUserDefaults];
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
    [self getLastInsertedAuto_idFromUserDefaults];
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    
    [self storeLastInsertedAuto_idToUserDefaults];
}

#pragma mark - Core Data

static NSManagedObjectContext *_managedObjectContext = nil;
+ (NSManagedObjectContext *)sharedContext
{
    @synchronized(self)
    {
        if (_managedObjectContext == nil)
        {
            NSPersistentStoreCoordinator *coordinator = [GnAppDelegate sharedCoordinator];
            if (coordinator != nil) {
                _managedObjectContext = [[NSManagedObjectContext alloc] init];
                [_managedObjectContext setPersistentStoreCoordinator: coordinator];
            }
        }
    }
    return _managedObjectContext;
}

static NSManagedObjectModel *_managedObjectModel = nil;
+ (NSManagedObjectModel *)sharedManagedObjectModel
{
    @synchronized(self)
    {
        if (_managedObjectModel == nil)
        {
            _managedObjectModel = [NSManagedObjectModel mergedModelFromBundles:nil] ;
        }
    }
    return _managedObjectModel;
}
static NSPersistentStoreCoordinator *_persistentStoreCoordinator = nil;
+ (NSPersistentStoreCoordinator *)sharedCoordinator
{
    @synchronized(self)
    {
        if (_persistentStoreCoordinator == nil)
        {
            NSString *storePath = [[GnAppDelegate applicationDocumentsDirectory] stringByAppendingPathComponent: @"History.sqlite"];
            
            /*
             Set up the store.
             For the sake of illustration, provide a pre-populated default store.
             */
            NSFileManager *fileManager = [NSFileManager defaultManager];
            // If the expected store(sqlite file) doesn't exist, copy the default store(sqlite file).
            if (![fileManager fileExistsAtPath:storePath]) {
                NSString *defaultStorePath = [[NSBundle mainBundle] pathForResource:@"History" ofType:@"sqlite"];
                if (defaultStorePath) {
                    [fileManager copyItemAtPath:defaultStorePath toPath:storePath error:NULL];
                }
            }
            
            NSURL *storeUrl = [NSURL fileURLWithPath:storePath];
            
            NSDictionary *options = [NSDictionary dictionaryWithObjectsAndKeys:[NSNumber numberWithBool:YES], NSMigratePersistentStoresAutomaticallyOption, [NSNumber numberWithBool:YES], NSInferMappingModelAutomaticallyOption, nil];
            _persistentStoreCoordinator = [[NSPersistentStoreCoordinator alloc] initWithManagedObjectModel: [GnAppDelegate sharedManagedObjectModel]];
            
            NSError *error;
            if (![_persistentStoreCoordinator addPersistentStoreWithType:NSSQLiteStoreType configuration:nil URL:storeUrl options:options error:&error]) {
                // Update to handle the error appropriately.
                NSLog(@"Unresolved error %@, %@", error, [error userInfo]);
                exit(-1);  // Fail
            }
        }
    }
    return _persistentStoreCoordinator;
}


-(void)checkForHistoryDataLimit
{
    NSError *error = nil;
    
    NSManagedObjectContext *context = [GnAppDelegate sharedContext];
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] init];
    NSEntityDescription *entity = [NSEntityDescription
                                   entityForName:@"History" inManagedObjectContext:context];
    [fetchRequest setEntity:entity];
    NSSortDescriptor *dateSortDescriptor = [[NSSortDescriptor alloc] initWithKey:@"current_date" ascending:YES];
    [fetchRequest setSortDescriptors:[NSArray arrayWithObject:dateSortDescriptor]];
    NSArray *fetchedObjects = [context executeFetchRequest:fetchRequest error:&error];
    if(error)
    {
        NSLog(@"Could not fetch objects to delete");
    }
    error = nil;
    if(fetchedObjects.count>CAP_LIMIT)
    {
        NSUInteger noOfExtraObjects = fetchedObjects.count - CAP_LIMIT;
        
        for(NSUInteger i =0;i<noOfExtraObjects;i++)
        {
            History *historyToDelete = (History *)[fetchedObjects objectAtIndex:i];
            [context deleteObject:historyToDelete];
        }
        
        [context save:&error];
        
        if(error)
        {
            NSLog(@"Could not save the context after deleting.");
        }
    }
    
}

#pragma mark - History Record ID

static unsigned int lastInsertedAuto_id = 0;
+(unsigned int)getLastInsertedAuto_id
{
    return lastInsertedAuto_id;
}

+(void)setLastInsertedAuto_id:(unsigned int)newId
{
    lastInsertedAuto_id = newId;
}

-(void)getLastInsertedAuto_idFromUserDefaults
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    NSNumber *lastAuto_id = [userDefaults objectForKey:@"lastRecord"];
    if(!lastAuto_id)
    {
        [userDefaults setValue:[NSNumber numberWithUnsignedInt:1] forKey:@"lastRecord"];
        [userDefaults synchronize];
        lastInsertedAuto_id = 1;
    }
    else
    {
        lastInsertedAuto_id = [lastAuto_id unsignedIntValue];
    }
}

-(void)storeLastInsertedAuto_idToUserDefaults
{
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setValue:[NSNumber numberWithUnsignedInt:lastInsertedAuto_id] forKey:@"lastRecord"];
    [userDefaults synchronize];
}


+(NSString*) applicationDocumentsDirectory
{
    NSError *error = nil;
    return [[[NSFileManager defaultManager] URLForDirectory:NSDocumentDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:NO error:&error] path];
}

@end
