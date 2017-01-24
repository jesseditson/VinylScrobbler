//
//  ViewController.h
//  MusicIdObjectiveC
//
//  Copyright © 2016 Gracenote. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <CoreLocation/CoreLocation.h>

typedef NS_ENUM(NSInteger, Mode)
{
    UnknownMode=-1,
    TextSearchMode=0,
    SettingsMode,
    HistoryMode,
    DebugMode,
    AdditionalContentMode
};

#define kHeightOfAdditionalMetadataCell 260
#define kHeightOfAdditionalMetadataCellPad 360

#define kHeightOfRowPad 140
#define kHeightOfRow 100

@interface GnViewController : UIViewController<CLLocationManagerDelegate, UITableViewDataSource, UITableViewDelegate, UINavigationBarDelegate, UIActionSheetDelegate>

@property (strong, nonatomic) CLLocationManager *locationManager;
@property (strong, nonatomic) IBOutlet UILabel *statusLabel;
@property (strong, nonatomic) IBOutlet UIView *lineView;
@property (weak, nonatomic) IBOutlet UIView *showOrHideVisualizationButtonView;
@property (weak, nonatomic) IBOutlet UIButton *showOrHideVisualizationButton;
@property (weak, nonatomic) IBOutlet UIView *visualizationView;
@property (weak, nonatomic) IBOutlet UIImageView *coloredRingImageView;
@property (weak, nonatomic) IBOutlet UIImageView *gracenoteLogoImageView;

@property (weak, nonatomic) IBOutlet UILabel *statusCaptionLabel;
@property (weak, nonatomic) IBOutlet UILabel *toolbarBorderCoverupLabel;
@property (weak, nonatomic) IBOutlet UITableView *resultsTableView;
@property (weak, nonatomic) IBOutlet UIActivityIndicatorView *busyIndicator;
@property (weak, nonatomic) IBOutlet UINavigationItem *titleNavigationItem;
@property (weak, nonatomic) IBOutlet UITabBarItem *albumIDTabBarItem;
@property (weak, nonatomic) IBOutlet UITabBarItem *recognizeMediaTabBarItem;
@property (weak, nonatomic) IBOutlet UITabBarItem *textSearchTabBarItem;
@property (weak, nonatomic) IBOutlet UITabBarItem *historyTabBarItem;
@property (weak, nonatomic) IBOutlet UIView *textSearchView;
@property (weak, nonatomic) IBOutlet UITableView *searchFieldsTableView;
@property (weak, nonatomic) IBOutlet UIImageView *arrowImageView;
@property (weak, nonatomic) IBOutlet UILabel *titleLabel;
@property (weak, nonatomic) IBOutlet UIButton *cancelOperationsButton;
@property (weak, nonatomic) IBOutlet UIView *debugView;
@property (weak, nonatomic) IBOutlet UILabel *debugViewTitleLabel;
@property (weak, nonatomic) IBOutlet UITextView *debugTextView;
@property (weak, nonatomic) IBOutlet UIButton *doAlbumIdButton;
@property (weak, nonatomic) IBOutlet UIButton *doRecognizeButton;
@property (weak, nonatomic) IBOutlet UIButton *showTextSearchButton;
@property (weak, nonatomic) IBOutlet UIButton *showHistoryButton;
@property (weak, nonatomic) IBOutlet UIButton *idNowButton;
@property (weak, nonatomic) IBOutlet UIButton *settingsButton;
@property (weak, nonatomic) IBOutlet UIProgressView *bundleLoadingProgressView;

- (IBAction)actionButtonTapped:(id)sender;
- (IBAction) idNow:(id) sender;
- (IBAction)showSettings:(id)sender;
- (IBAction)cancelAllOperations:(id)sender;
- (IBAction)doAlbumID:(id)sender;
- (IBAction)doRecognizeMedia:(id)sender;
- (IBAction)doTextSearch:(id)sender;
- (IBAction)showHistory:(id)sender;
- (IBAction)showTextSearch:(id)sender;
- (IBAction)showDebugConsole:(id)sender;
- (IBAction)showVisualization:(id)sender;

-(void) stopRecording;

@end

