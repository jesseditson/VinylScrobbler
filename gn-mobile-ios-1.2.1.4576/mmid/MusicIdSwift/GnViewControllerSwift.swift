//
//  GnViewControllerSwift.swift
//  MusicIdSwift
//
//  Copyright © 2016 Gracenote. All rights reserved.
//

import UIKit
import AVFoundation
import Foundation
import MediaPlayer
//import GnAudioVisualizeAdapter


let CLIENT_ID = ""
let CLIENT_TAG = ""
let LICENSE = "license.txt"
let APP_VERSION = "1.0.0.0"

let BUTTONWIDTH = 150
let BUTTONHEIGHT = 50

let ALBUMTITLELABELTAG = 7000
let TRACKTITLELABELTAG = 7001
let ARTISTLABELTAG = 7002
let TRACKDURATIONLABELTAG = 7003
let CAPTIONLABELTAG = 7004
let TEXTFIELDTAG = 7005
let SETTINGSSWITCHTAG = 7006
let ALBUMIDACTIONSHEETTAG = 7007
let ALBUMCOVERARTIMAGETAG = 7008
let ADDITIONALMETADATAVIEWTAG = 7009
let TRACKMATCHPOSITIONLABELTAG = 7010
let ADDITIONALCONTENTVIEWTAG = 7011
let ADDITIONALCONTENTIMAGEVIEWTAG = 7012
let ADDITIONALCONTENTALBUMLABELTAG = 7013
let ADDITIONALCONTENTARTISTLABELTAG = 7014
let ADDITIONALCONTENTTEXTVIEWTAG = 7015
let ADDITIONALCONTENTTITLELABELTAG = 7016

let kHeightOfAdditionalMetadataCell = 260
let kHeightOfAdditionalMetadataCellPad = 360

let kHeightOfRowPad = 140
let kHeightOfRow = 100

let LABELWIDTHIPHONE  = 150.0
let LABELWIDTHIPAD    = 420.0

enum Mode
{
    case UnknownMode
    case TextSearchMode
    case SettingsMode
    case HistoryMode
    case DebugMode
    case AdditionalContentMode
};

class GnViewControllerSwift: UIViewController, GnLookupLocalStreamIngestEventsDelegate, GnMusicIdStreamEventsDelegate, GnAudioVisualizerDelegate
{
    var gnManager:GnManager!
    var gnMic:GnMic!
    var gnUser:GnUser!
	var gnUserStore:GnUserStore!
	var gnStorageSqlite:GnStorageSqlite!
	var gnLookupLocalStream:GnLookupLocalStream!
	var gnAudioVisualizeAdapter:GnAudioVisualizeAdapter!
	var gnMusicIdStream:GnMusicIdStream!
    var gnLocale:GnLocale!
	var currentMode:Mode!
	
	var arrayOfLogStrings:NSMutableArray!
	
	var internalQueue:dispatch_queue_t!
	var microphoneIsInitialized:Bool!
	var recordingIsPaused:Bool!
	var lookupSourceIsLocal:Bool!
	var audioProcessingStarted:Bool!
	var visualizationIsVisible:Bool!
	
	var cancellableObjects:NSMutableArray!
	var results:NSMutableArray!
	
	var queryBeginTimeInterval:NSTimeInterval!
	var queryEndTimeInterval:NSTimeInterval!
	
	var dynamicAnimator:UIDynamicAnimator!
	var searchSegmentedControl:UISegmentedControl!
	var cancelSegmentedControl:UISegmentedControl!
	var currentlySelectedIndexPath:NSIndexPath!
	
    @IBOutlet weak var statusLabel:UILabel!
    @IBOutlet weak var lineView:UIView!
    @IBOutlet weak var showOrHideVisualizationButtonView:UIView!
    @IBOutlet weak var showOrHideVisualizationButton:UIButton!
    @IBOutlet weak var visualizationView:UIView!
    @IBOutlet weak var coloredRingImageView:UIImageView!
    @IBOutlet weak var gracenoteLogoImageView:UIImageView!
    
    @IBOutlet weak var statusCaptionLabel:UILabel!
    @IBOutlet weak var toolbarBorderCoverupLabel:UILabel!
    @IBOutlet weak var resultsTableView:UITableView!
    @IBOutlet weak var busyIndicator:UIActivityIndicatorView!
    @IBOutlet weak var titleNavigationItem:UINavigationItem!
    @IBOutlet weak var albumIDTabBarItem:UITabBarItem!
    @IBOutlet weak var recognizeMediaTabBarItem:UITabBarItem!
    @IBOutlet weak var textSearchTabBarItem:UITabBarItem!
    @IBOutlet weak var historyTabBarItem:UITabBarItem!
    @IBOutlet weak var textSearchView:UIView!
    @IBOutlet weak var searchFieldsTableView:UITableView!
    @IBOutlet weak var arrowImageView:UIImageView!
    @IBOutlet weak var titleLabel:UILabel!
    @IBOutlet weak var cancelOperationsButton:UIButton!
    @IBOutlet weak var debugView:UIView!
    @IBOutlet weak var debugViewTitleLabel:UILabel!
    @IBOutlet weak var debugTextView:UITextView!
    @IBOutlet weak var doAlbumIdButton:UIButton!
    @IBOutlet weak var doRecognizeButton:UIButton!
    @IBOutlet weak var showTextSearchButton:UIButton!
    @IBOutlet weak var showHistoryButton:UIButton!
    @IBOutlet weak var idNowButton:UIButton!
    @IBOutlet weak var settingsButton:UIButton!
    @IBOutlet weak var bundleLoadingProgressView:UIProgressView!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
		
		recordingIsPaused = false
		microphoneIsInitialized = false
		
		currentMode = Mode.UnknownMode
		lookupSourceIsLocal = false
		audioProcessingStarted = false
		queryBeginTimeInterval = -1;
		queryEndTimeInterval = -1;
		
		results = NSMutableArray( capacity:2 )
		cancellableObjects = NSMutableArray( capacity:2 )
		
		setupInterface()

//put in showVisualization
visualizationIsVisible = false

        do
        {
            try initializeGnsdk( clientId:CLIENT_ID, clientTag:CLIENT_TAG, license:LICENSE, applicationVersion:APP_VERSION )
        }
        catch
        {
            print("\(error)")
        }
    }

    override func didReceiveMemoryWarning()
    {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func initializeGnsdk( clientId clientId:String, clientTag:String, license:String, applicationVersion:String ) throws
    {
		if clientId.characters.count == 0 || clientTag.characters.count == 0
		{
            print("Please set Client ID and Client Tag.")
            return
		}
		
        let licensePath = NSBundle.mainBundle().pathForResource(license, ofType: nil)
        if licensePath == nil
        {
            print("Cannot get path for resource \(license)")
            return
        }
		
		let session:AVAudioSession = AVAudioSession.sharedInstance()
		try session.setPreferredSampleRate(44100)
		try session.setInputGain(0.5)
		try session.setActive(true)
		
        let licenseString = try NSString.init(contentsOfFile: licensePath!, encoding: NSUTF8StringEncoding)
        gnManager = try GnManager( license:licenseString as String, licenseInputMode:kLicenseInputModeString)

        gnUserStore = GnUserStore()
        gnUser = try GnUser(userStoreDelegate:gnUserStore, clientId:clientId, clientTag:clientTag, applicationVersion:applicationVersion)

		gnLocale = try GnLocale(localeGroup:kLocaleGroupMusic, language:kLanguageEnglish, region:kRegionGlobal, descriptor:kDescriptorDefault, user:self.gnUser, statusEventsDelegate:nil)
		try gnLocale.setGroupDefault()
//		dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
//        {
//            do
//            {
//                self.gnLocale = try GnLocale(localeGroup:kLocaleGroupMusic, language:kLanguageEnglish, region:kRegionGlobal, descriptor:kDescriptorDefault, user:self.gnUser, statusEventsDelegate:nil)
//				try self.gnLocale.setGroupDefault()
//                
//                print("Loaded locale")
//            }
//            catch
//            {
//                print("\(error)")
//            }
//        })

		gnStorageSqlite = try GnStorageSqlite.enable()
		let documentDirectoryURL =  try! NSFileManager().URLForDirectory(.DocumentDirectory, inDomain: .UserDomainMask, appropriateForURL: nil, create: true)
		try gnStorageSqlite.storageLocation(documentDirectoryURL.path!)
		try setupLocalLookup(documentDirectoryURL.path)
		try downloadLatestBundle()
		
		if (session.respondsToSelector(#selector(AVAudioSession.requestRecordPermission(_:))))
		{
			AVAudioSession.sharedInstance().requestRecordPermission({(granted: Bool)-> Void in
				do
				{
					if granted
					{
						try self.microphoneInitialize()
					}
					else
					{
						print("Microphone access denied")
					}
				}
				catch
				{
					print("\(error)")
				}
			 })
		}
	}
    
    
    func tableView( tableView:UITableView, numberOfRowsInSection:NSInteger ) -> Int
    {
		if (tableView == resultsTableView)
		{
			if (results.count == 0)
			{
				tableView.separatorColor = UIColor.clearColor()
			}
			else
			{
				tableView.separatorColor = UIColor.lightGrayColor()
			}
			
			return results.count
		}
		
        return 0;
    }
    
	func tableView( tableView:UITableView, cellForRowAtIndexPath indexPath:NSIndexPath ) -> UITableViewCell
	{
		let cellIdentifier:String = "CellID";
		var cell = tableView.dequeueReusableCellWithIdentifier(cellIdentifier)
		
		if ( nil == cell )
		{
			cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: cellIdentifier)
//			if (tableView==self.resultsTableView || (tableView==self.searchFieldsTableView && self.currentMode==HistoryMode) )
			if (tableView == resultsTableView)
			{
				let imageView = UIImageView(frame: CGRectMake(5, 10, (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 112 : 56, (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 112 : 56))
				imageView.tag = ALBUMCOVERARTIMAGETAG;
				
				let albumTitleLabel = UILabel(frame: CGRectMake(imageView.frame.origin.x+imageView.frame.size.width+12, 5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 40))
				albumTitleLabel.font = UIFont.boldSystemFontOfSize(16)
				albumTitleLabel.textColor = UIColor(red: 0.7, green: 0, blue: 0.7, alpha: 1)
				albumTitleLabel.tag=ALBUMTITLELABELTAG;
				albumTitleLabel.numberOfLines = 2;
				albumTitleLabel.lineBreakMode = NSLineBreakMode.ByCharWrapping
				albumTitleLabel.backgroundColor = UIColor.clearColor()
				
				let trackTitleLabel = UILabel(frame: CGRectMake(albumTitleLabel.frame.origin.x+albumTitleLabel.frame.size.width+5, albumTitleLabel.frame.origin.y, 120, albumTitleLabel.frame.size.height))
				trackTitleLabel.font = UIFont.systemFontOfSize(12)
				trackTitleLabel.textColor = UIColor.darkGrayColor()
				trackTitleLabel.tag = TRACKTITLELABELTAG;
				trackTitleLabel.numberOfLines = 2;
				trackTitleLabel.lineBreakMode = NSLineBreakMode.ByCharWrapping
				trackTitleLabel.backgroundColor = UIColor.clearColor()

				let artistLabel = UILabel(frame: CGRectMake(albumTitleLabel.frame.origin.x, albumTitleLabel.frame.origin.y+albumTitleLabel.frame.size.height, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 40))
				artistLabel.font = UIFont.systemFontOfSize(12)
				artistLabel.textColor = UIColor.darkGrayColor()
				artistLabel.tag = ARTISTLABELTAG;
				artistLabel.numberOfLines = 2;
				artistLabel.lineBreakMode = NSLineBreakMode.ByCharWrapping
				artistLabel.backgroundColor = UIColor.clearColor()

				let trackDurationLabel = UILabel(frame: CGRectMake(artistLabel.frame.origin.x+artistLabel.frame.size.width+5, artistLabel.frame.origin.y, 120, 40))
				trackDurationLabel.font = UIFont.boldSystemFontOfSize(10)
				trackDurationLabel.textColor = UIColor.grayColor()
				trackDurationLabel.tag = TRACKDURATIONLABELTAG
				trackDurationLabel.backgroundColor = UIColor.clearColor()

				let additionalContentView = UIView(frame: CGRectMake((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 768 : 320, 0, (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 768 : cell!.contentView.bounds.size.width, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? kHeightOfAdditionalMetadataCellPad : kHeightOfAdditionalMetadataCell)))
				additionalContentView.tag = ADDITIONALCONTENTVIEWTAG
				additionalContentView.backgroundColor = UIColor(red:0.1, green:0.1, blue:0.1, alpha:0.9)
				
				//Add content views to additional content view
				let additionalContentTitleLabel = UILabel(frame: CGRectMake(0, 0, additionalContentView.frame.size.width, 20))
				additionalContentTitleLabel.tag = ADDITIONALCONTENTTITLELABELTAG;
				additionalContentTitleLabel.layer.cornerRadius = 2.0;
				additionalContentTitleLabel.backgroundColor = UIColor.darkGrayColor()
				additionalContentTitleLabel.textColor = UIColor.blackColor()
				additionalContentTitleLabel.textAlignment = NSTextAlignment.Center
				additionalContentTitleLabel.font = UIFont.boldSystemFontOfSize(16)
				additionalContentTitleLabel.userInteractionEnabled = true

				let closeAdditionalSegment = UISegmentedControl(items: ["Close"])
				closeAdditionalSegment.momentary = true
				closeAdditionalSegment.userInteractionEnabled = true
				closeAdditionalSegment.frame = CGRectMake(additionalContentTitleLabel.frame.origin.x+additionalContentTitleLabel.frame.size.width-50, 0, 50, 20)
				closeAdditionalSegment.backgroundColor = UIColor.redColor()
				closeAdditionalSegment.tintColor = UIColor.whiteColor()
				closeAdditionalSegment.addTarget(self, action: #selector(GnViewControllerSwift.closeAdditionalContentView(_:)), forControlEvents: .ValueChanged)
				additionalContentTitleLabel.addSubview(closeAdditionalSegment)
				
				
				let additionalContentImageView = UIImageView(frame: CGRectMake(5, 25, 56, 56))
				additionalContentImageView.tag = ADDITIONALCONTENTIMAGEVIEWTAG;
				
				
				let additionalContentAlbumLabel = UILabel(frame: CGRectMake(additionalContentImageView.frame.origin.x+additionalContentImageView.frame.size.width+5, additionalContentImageView.frame.origin.y, additionalContentView.bounds.size.width-(additionalContentImageView.frame.size.width+additionalContentImageView.frame.origin.x+5), 40))
				additionalContentAlbumLabel.numberOfLines = 2;
				additionalContentAlbumLabel.lineBreakMode = NSLineBreakMode.ByCharWrapping
				additionalContentAlbumLabel.tag = ADDITIONALCONTENTALBUMLABELTAG;
				additionalContentAlbumLabel.textColor = UIColor.whiteColor()
				additionalContentAlbumLabel.backgroundColor = UIColor.clearColor()

				let additionalContentArtistLabel = UILabel(frame: CGRectMake(additionalContentAlbumLabel.frame.origin.x, additionalContentAlbumLabel.frame.origin.y+additionalContentAlbumLabel.frame.size.height+5, additionalContentView.bounds.size.width-(additionalContentImageView.frame.size.width+additionalContentImageView.frame.origin.x+5), 40))
				additionalContentArtistLabel.numberOfLines = 2;
				additionalContentArtistLabel.lineBreakMode = NSLineBreakMode.ByCharWrapping
				additionalContentArtistLabel.backgroundColor = UIColor.clearColor()
				additionalContentArtistLabel.tag = ADDITIONALCONTENTARTISTLABELTAG;
				additionalContentArtistLabel.textColor = UIColor.whiteColor()
				
				let additionalContentTextView = UITextView(frame: CGRectMake(additionalContentImageView.frame.origin.x, additionalContentArtistLabel.frame.origin.y+additionalContentArtistLabel.frame.size.height+5, additionalContentView.bounds.size.width-10, additionalContentView.bounds.size.height - (additionalContentArtistLabel.frame.origin.y+additionalContentArtistLabel.frame.size.height + 10)), textContainer: nil)
				additionalContentTextView.tag = ADDITIONALCONTENTTEXTVIEWTAG;
				additionalContentTextView.layer.cornerRadius = 5.0;
				additionalContentTextView.font = UIFont.italicSystemFontOfSize(14)
				additionalContentTextView.textColor = UIColor.darkGrayColor()
				additionalContentTextView.showsVerticalScrollIndicator = true
			
				additionalContentView.addSubview(additionalContentTitleLabel)
				additionalContentView.addSubview(additionalContentImageView)
				additionalContentView.addSubview(additionalContentAlbumLabel)
				additionalContentView.addSubview(additionalContentArtistLabel)
				additionalContentView.addSubview(additionalContentTextView)
				
				cell?.contentView.addSubview(imageView)
				cell?.contentView.addSubview(albumTitleLabel)
				cell?.contentView.addSubview(trackTitleLabel)
				cell?.contentView.addSubview(artistLabel)
				cell?.contentView.addSubview(trackDurationLabel)
				cell?.contentView.addSubview(additionalContentView)
			}
		}
		
		if (tableView==self.resultsTableView)
		{
			let albumTitleLabel = cell?.contentView.viewWithTag(TRACKTITLELABELTAG) as! UILabel
			let trackTitleLabel = cell?.contentView.viewWithTag(ALBUMTITLELABELTAG) as! UILabel
			let artistLabel = cell?.contentView.viewWithTag(ARTISTLABELTAG) as! UILabel
			let trackDurationLabel = cell?.contentView.viewWithTag(TRACKDURATIONLABELTAG) as! UILabel
			let imageView = cell?.contentView.viewWithTag(ALBUMCOVERARTIMAGETAG) as! UIImageView
			
			if(nil != results && results.count > 0)
			{
				let datamodelObject = results.objectAtIndex(indexPath.row) as! GnDataModel

				albumTitleLabel.text = datamodelObject.albumTitle;
				trackTitleLabel.text = datamodelObject.trackTitle;
				artistLabel.text = ((datamodelObject.albumArtist.characters.count > 0) ? datamodelObject.albumArtist : datamodelObject.trackArtist);
				
				let durationText = datamodelObject.trackDuration;
				if ( (durationText == nil) || (durationText == "0"))
				{
					trackDurationLabel.text = ""
				}
				else
				{
					trackDurationLabel.text = String(format: "Duration: %@s", durationText)
				}

				if (nil != datamodelObject.albumImageData)
				{
					imageView.image = UIImage(data: datamodelObject.albumImageData)
				}
				else
				{
					imageView.image = UIImage(contentsOfFile: "emptyImage.png")
				}
				
				if (nil != currentlySelectedIndexPath && indexPath.row != currentlySelectedIndexPath.row)
				{
					cell?.contentView.viewWithTag(ADDITIONALMETADATAVIEWTAG)?.removeFromSuperview()
					
					albumTitleLabel.enabled = false
					trackTitleLabel.enabled = false
					artistLabel.enabled = false
					trackDurationLabel.enabled = false
					imageView.alpha = 0.5
				}
				else
				{
					if (nil == currentlySelectedIndexPath)
					{
						cell?.contentView.backgroundColor = UIColor.whiteColor()
						cell?.contentView.viewWithTag(ADDITIONALMETADATAVIEWTAG)?.removeFromSuperview()
					}
					else if((nil != currentlySelectedIndexPath) && (indexPath.row == currentlySelectedIndexPath.row))
					{
						cell?.contentView.backgroundColor = UIColor.whiteColor()
						var additionalMetadataView = cell?.contentView.viewWithTag(ADDITIONALMETADATAVIEWTAG)
						if (nil == additionalMetadataView)
						{
							additionalMetadataView = UIView(frame: CGRectMake(cell!.contentView.frame.origin.x, imageView.frame.origin.y+imageView.frame.size.height+12, cell!.contentView.frame.size.width-10, CGFloat(kHeightOfAdditionalMetadataCell) - (artistLabel.frame.origin.y+artistLabel.frame.size.height+12)))
							additionalMetadataView?.tag = ADDITIONALMETADATAVIEWTAG;
							
							//Add additional metadata labels.
							let trackMatchPositionLabel = UILabel(frame: CGRectMake(5, 5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							trackMatchPositionLabel.text = String(format: "Match Pos: %@s", datamodelObject.trackMatchPosition)
							trackMatchPositionLabel.font = UIFont.systemFontOfSize(12)

							let lookupSourceLabel = UILabel(frame: CGRectMake(trackMatchPositionLabel.frame.origin.x+trackMatchPositionLabel.frame.size.width+5, trackMatchPositionLabel.frame.origin.y, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), trackMatchPositionLabel.frame.size.height))
							lookupSourceLabel.text = String(format: "Lookup Source:", lookupSourceIsLocal == true ? "Local" : "Online")
							lookupSourceLabel.font = UIFont.systemFontOfSize(12)
							
							let currentPositionLabel = UILabel(frame: CGRectMake(trackMatchPositionLabel.frame.origin.x, trackMatchPositionLabel.frame.origin.y+trackMatchPositionLabel.frame.size.height+5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							currentPositionLabel.text = String(format: "Current Pos:%@s", datamodelObject.currentPosition)
							currentPositionLabel.font = UIFont.systemFontOfSize(12)
							

							let genreLabel = UILabel(frame: CGRectMake(currentPositionLabel.frame.origin.x+currentPositionLabel.frame.size.width+5, currentPositionLabel.frame.origin.y, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							genreLabel.text = String(format: "Genre: %@", ((datamodelObject.trackGenre != nil) && datamodelObject.trackGenre.characters.count > 0) ? datamodelObject.trackGenre : datamodelObject.albumGenre)
							genreLabel.font = UIFont.systemFontOfSize(12)
							
							let diff = queryEndTimeInterval - queryBeginTimeInterval;
							
							let timeToMatchLabel = UILabel(frame: CGRectMake(currentPositionLabel.frame.origin.x, currentPositionLabel.frame.origin.y+currentPositionLabel.frame.size.height+5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							timeToMatchLabel.text = String(format: "Time to Match(ms): %0.4lf", diff)
							timeToMatchLabel.font = UIFont.systemFontOfSize(12)

							let tempoLabel = UILabel(frame: CGRectMake(timeToMatchLabel.frame.origin.x, timeToMatchLabel.frame.origin.y+timeToMatchLabel.frame.size.height+5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							tempoLabel.text = String(format: "Tempo: %@", datamodelObject.trackTempo)
							tempoLabel.font = UIFont.systemFontOfSize(12)

							let originLabel = UILabel(frame: CGRectMake(timeToMatchLabel.frame.origin.x+timeToMatchLabel.frame.size.width+5, timeToMatchLabel.frame.origin.y+timeToMatchLabel.frame.size.height+5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 40))
							originLabel.text = String(format: "Origin: %@", datamodelObject.trackOrigin)
							originLabel.font = UIFont.systemFontOfSize(12)

							let moodLabel = UILabel(frame: CGRectMake(tempoLabel.frame.origin.x, tempoLabel.frame.origin.y+tempoLabel.frame.size.height+5, CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? LABELWIDTHIPAD : LABELWIDTHIPHONE), 20))
							moodLabel.text = String(format: "Mood: %@", datamodelObject.trackMood)
							moodLabel.font = UIFont.systemFontOfSize(12)
							
							let artistBiographyControl = UISegmentedControl(items:["Artist Biography"])
							artistBiographyControl.frame = CGRectMake(moodLabel.frame.origin.x+((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 100 : 0),  moodLabel.frame.origin.y+moodLabel.frame.size.height+10, 150, 30)
							artistBiographyControl.layer.masksToBounds = true
							artistBiographyControl.momentary = true
							artistBiographyControl.backgroundColor = UIColor.darkGrayColor()
							artistBiographyControl.tintColor = UIColor.whiteColor()
							artistBiographyControl.layer.cornerRadius = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 5.0 : 5.0
							artistBiographyControl.layer.borderColor = UIColor.greenColor().CGColor
//							artistBiographyControl.addTarget(self, action: #selector(GnViewControllerSwift.showArtistBiography(_:)), forControlEvents: UIControlEvents.ValueChanged)

							let albumReviewControl = UISegmentedControl(items:["Artist Biography"])
							albumReviewControl.frame = CGRectMake(artistBiographyControl.frame.origin.x+artistBiographyControl.frame.size.width+((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 150 : 10),  artistBiographyControl.frame.origin.y, 150, 30)
							albumReviewControl.layer.masksToBounds = true
							albumReviewControl.momentary = true
							albumReviewControl.backgroundColor = UIColor.darkGrayColor()
							albumReviewControl.tintColor = UIColor.whiteColor()
							albumReviewControl.layer.cornerRadius = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 5.0 : 5.0
							albumReviewControl.layer.borderColor = UIColor.greenColor().CGColor
//							albumReviewControl.addTarget(self, action: #selector(GnViewControllerSwift.showAlbumReview(_:)), forControlEvents: UIControlEvents.ValueChanged)

							additionalMetadataView?.addSubview(trackMatchPositionLabel)
							additionalMetadataView?.addSubview(lookupSourceLabel)
							additionalMetadataView?.addSubview(currentPositionLabel)
							additionalMetadataView?.addSubview(genreLabel)
							additionalMetadataView?.addSubview(timeToMatchLabel)
							additionalMetadataView?.addSubview(tempoLabel)
							additionalMetadataView?.addSubview(originLabel)
							additionalMetadataView?.addSubview(moodLabel)
							additionalMetadataView?.addSubview(artistBiographyControl)
							additionalMetadataView?.addSubview(albumReviewControl)

							cell?.contentView.addSubview(additionalMetadataView!)
						}

						albumTitleLabel.enabled = true
						trackTitleLabel.enabled = true
						artistLabel.enabled = true
						trackDurationLabel.enabled = true
						imageView.alpha = 1.0
					}
				}
			}
			else
			{
				imageView.image = UIImage(contentsOfFile: "emptyImage.png")
			}
		}

		return cell!;
	}

	func tableView(tableView:UITableView, heightForRowAtIndexPath indexPath:NSIndexPath) -> CGFloat
	{
		if(tableView == resultsTableView && currentlySelectedIndexPath != nil && currentlySelectedIndexPath.row == indexPath.row)
		{
			return CGFloat((UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? kHeightOfAdditionalMetadataCellPad : kHeightOfAdditionalMetadataCell);
		}
		
		if (tableView == resultsTableView || (tableView == searchFieldsTableView && currentMode == Mode.HistoryMode))
		{
			return 100.0
		}
		
		return 45;
	}


	func tableView(tableView:UITableView, didSelectRowAtIndexPath indexPath:NSIndexPath)
	{
		if(nil == currentlySelectedIndexPath)
		{
			currentlySelectedIndexPath = indexPath;
		}
		else
		{
			let cell = tableView.cellForRowAtIndexPath(currentlySelectedIndexPath)
			
			currentlySelectedIndexPath = nil
			let additionalContentView = cell?.contentView.viewWithTag(ADDITIONALCONTENTVIEWTAG)
			var frame = additionalContentView?.frame
			frame?.origin.x = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 768 : 320;
			additionalContentView?.frame = frame!
		}
		
		tableView.deselectRowAtIndexPath(indexPath, animated: false)
		tableView.beginUpdates()
		tableView.reloadData()
		
		let dispatchTime: dispatch_time_t = dispatch_time(DISPATCH_TIME_NOW, Int64(0.1 * Double(NSEC_PER_SEC)))
		dispatch_after(dispatchTime, dispatch_get_main_queue(), {
			self.scrollPlaybackViewToVisibleRect()
		})

		tableView.endUpdates()
	}

	func scrollPlaybackViewToVisibleRect()
	{
		//SCH: This if shpouldn't be needed
		if(nil != currentlySelectedIndexPath)
		{
			let cell = resultsTableView.cellForRowAtIndexPath(currentlySelectedIndexPath)
			resultsTableView.scrollRectToVisible(cell!.frame, animated: true)
		}
	}

	func setupInterface()
	{
		// Hide Search View and Arrow.
		textSearchView.alpha = 0.0
		arrowImageView.alpha = 0.0;
		textSearchView.layer.cornerRadius = 5.0;
		searchFieldsTableView.layer.cornerRadius = 5.0;
		
		//Setup Dynamic Animator.
		dynamicAnimator = UIDynamicAnimator(referenceView: visualizationView)
		
		//Resize Visualization
		var visualizationRect = visualizationView.frame;
		visualizationRect.origin.y -= visualizationRect.size.height - (showOrHideVisualizationButtonView.frame.size.height + 10);
		visualizationView.frame = visualizationRect;
		showOrHideVisualizationButton.titleLabel!.text = "Show Visualization";
		showOrHideVisualizationButtonView.layer.cornerRadius = 10.0;
		showOrHideVisualizationButtonView.layer.borderWidth = 1.0;
		showOrHideVisualizationButtonView.layer.borderColor = UIColor.whiteColor().CGColor
		visualizationView.layer.cornerRadius = 5.0;
		visualizationView.backgroundColor = UIColor(red:0.2, green:0.2, blue:0.2, alpha:0.2)
		
		//Add Search and Cancel Buttons.
		searchSegmentedControl = UISegmentedControl(items:["Search"])
		
		let offset:CGFloat = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 20 : 100
		let width:CGFloat = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 100 : 200
		let height:CGFloat = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 35 : 50
		
		searchSegmentedControl.frame = CGRectMake(self.searchFieldsTableView.frame.origin.x+offset,  self.searchFieldsTableView.frame.origin.y+self.searchFieldsTableView.frame.size.height+10, width, height);
		searchSegmentedControl.momentary = true
		searchSegmentedControl.backgroundColor = UIColor.redColor()
		searchSegmentedControl.tintColor = UIColor.whiteColor()
		searchSegmentedControl.layer.masksToBounds = true
		searchSegmentedControl.layer.cornerRadius = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 5.0 : 5.0
		searchSegmentedControl.layer.borderColor = UIColor.greenColor().CGColor
//		searchSegmentedControl.addTarget(self, action: "doTextSearch:", forControlEvents: UIControlEvents.ValueChanged)

		textSearchView.addSubview(searchSegmentedControl)
		
		cancelSegmentedControl = UISegmentedControl(items:["Cancel"])
		cancelSegmentedControl.frame = CGRectMake(self.searchFieldsTableView.frame.origin.x+offset,  self.searchFieldsTableView.frame.origin.y+self.searchFieldsTableView.frame.size.height+10, width, height);
		cancelSegmentedControl.momentary = true
		cancelSegmentedControl.backgroundColor = UIColor.blackColor()
		cancelSegmentedControl.tintColor = UIColor.whiteColor()
		cancelSegmentedControl.layer.masksToBounds = true
		cancelSegmentedControl.layer.cornerRadius = (UIDevice.currentDevice().userInterfaceIdiom == .Pad) ? 5.0 : 5.0
		cancelSegmentedControl.layer.borderColor = UIColor.greenColor().CGColor
//		cancelSegmentedControl.addTarget(self, action: "closeTextSearchView:", forControlEvents: UIControlEvents.ValueChanged)

		textSearchView.addSubview(cancelSegmentedControl)
		
		idNowButton.layer.shadowColor = UIColor.darkGrayColor().CGColor
		idNowButton.layer.shadowOffset = CGSizeMake(0, 0)
		idNowButton.layer.shadowRadius = 10.0
		idNowButton.layer.shadowOpacity = 1
		idNowButton.layer.masksToBounds = false
		
		textSearchView.layer.shadowColor = UIColor.darkGrayColor().CGColor
		textSearchView.layer.shadowOffset = CGSizeMake(0, 0)
		textSearchView.layer.shadowRadius = 25.0
		textSearchView.layer.shadowOpacity = 1
		textSearchView.layer.masksToBounds = false

		currentlySelectedIndexPath = nil;
		
		
		//Setup Debug View.
		debugView.layer.cornerRadius = 5.0
		debugView.alpha = 0.0
		debugViewTitleLabel.layer.cornerRadius = 5.0
		debugTextView.textColor = UIColor.blackColor()
		debugTextView.backgroundColor = UIColor.whiteColor()
		
		
		arrayOfLogStrings = NSMutableArray(capacity: 1)
		
	}
	
	func enableOrDisableControls( enable:Bool )
	{
		doAlbumIdButton.enabled = enable;
		doRecognizeButton.enabled = enable;
		showHistoryButton.enabled = enable;
		showTextSearchButton.enabled = enable;
		idNowButton.enabled = enable && audioProcessingStarted;
		settingsButton.enabled = enable;
		cancelOperationsButton.enabled = !enable;
		
		resultsTableView.userInteractionEnabled = enable;
		resultsTableView.scrollEnabled = enable;
		
	}

    func idNow( sender:UIButton! )
	{
		if nil != gnMusicIdStream
		{
			cancelOperationsButton.enabled = true
			enableOrDisableControls(false)
			results.removeAllObjects()
			cancellableObjects.addObject(gnMusicIdStream)

			do
			{
				try gnMusicIdStream.identifyAlbumAsync()
				updateStatus("Identifying")
				busyIndicator.startAnimating()
			}
			catch
			{
				print("\(error)")
			}
        }
    }
	
	func doAlbumID( sender:AnyObject )
	{
	}

	func doRecognizeMedia( sender:AnyObject )
	{
	}

	func doTextSearch( sender:AnyObject )
	{
	}
	
	func showHistory( sender:AnyObject )
	{
	}

	func showSettings( sender:AnyObject )
	{
	}
	
	func showTextSearch( sender:AnyObject )
	{
	}
	
	func showVisualization( sender:AnyObject )
	{
	}
	
	func updateStatus(status: String)
	{
		//	The text view must be updated from the main thread or it throws an exception...
		dispatch_async( dispatch_get_main_queue()) {
			self.statusLabel.text = String(format: "%@\n", status)
		};
	}

	func stopBusyIndicator()
	{
		dispatch_async( dispatch_get_main_queue())
		{
			self.enableOrDisableControls(true)
			self.busyIndicator.stopAnimating()
		};
	}
	
    func cancelAllOperations( sender:UIButton! )
	{
		for obj in cancellableObjects
		{
			do
			{
				if (obj.isKindOfClass(GnMusicIdStream))
				{
					do
					{
						let stream = obj as? GnMusicIdStream
						try stream?.identifyCancel()
					}
					catch
					{
						print("\(error)")
//						NSLog("MusicIDStream Cancel Error = %@", error);
					}
				}
				else if (obj.isKindOfClass(GnMusicIdFile))
				{
					let file = obj as? GnMusicIdFile
					try file?.cancel()
				}
				else
				{
					obj.setCancel(true)
				}
			}
			catch
			{
				print("\(error)")
//				NSLog("MusicIDStream Cancel Error = %@", error);
			}
		}

        stopBusyIndicator()
    }


	func setupLocalLookup( location:String? ) throws
	{
		//	Initialize the local lookup so we can do local lookup queries.
		gnLookupLocalStream = try GnLookupLocalStream.enable()
		try gnLookupLocalStream.storageLocation(location!)
	}

	func downloadLatestBundle() throws
	{
		let BLOCK_SIZE = 1024
		if let bundlePath = NSBundle.mainBundle().pathForResource("1557", ofType: "b")
		{
			try gnLookupLocalStream.storageClear()
			dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0),
			{
				do
				{
					let lookupLocalStreamIngest:GnLookupLocalStreamIngest = try GnLookupLocalStreamIngest(eventsDelegate:self)
					let fileHandle:NSFileHandle! = NSFileHandle(forReadingAtPath:bundlePath)

					var fileData = fileHandle!.readDataOfLength(BLOCK_SIZE)
					while fileData.length != 0
					{
						try lookupLocalStreamIngest.write(fileData)
						fileData = fileHandle!.readDataOfLength(BLOCK_SIZE)
					}
					print("Loaded Bundle")
				}
				catch
				{
					print("\(error)")
				}
			})
		}
	}
	
	func microphoneInitialize() throws
	{
		// -------------------------------------------------------------------------------
		// Initialize Microphone AudioSource to Start Recording.
		// -------------------------------------------------------------------------------
		// Configure Microphone
		gnMic = GnMic(sampleRate: 44100, bitsPerChannel: 16, numberOfChannels: 1)
		
		// configure dispatch queue
		internalQueue = dispatch_queue_create("gnsdk.TaskQueue", DISPATCH_QUEUE_CONCURRENT);
		
		// If configuration succeeds, start recording.
		if (nil != gnMic)
		{
			microphoneIsInitialized = false;
			try setupMusicIDStream();
		}
	}

	func setupMusicIDStream() throws
	{
		if nil == gnUser
		{
			return;
		}

		do
		{
			recordingIsPaused = true;
			gnMusicIdStream = try GnMusicIdStream(user:gnUser, preset:kPresetMicrophone, locale:gnLocale, musicIdStreamEventsDelegate:self)
			let gnMusicIdStreamOptions = gnMusicIdStream.options()
			try gnMusicIdStreamOptions.resultSingle(true)
			try gnMusicIdStreamOptions.lookupData(kLookupDataSonicData, enable:true)
			try gnMusicIdStreamOptions.lookupData(kLookupDataContent, enable:true)
			try gnMusicIdStreamOptions.preferResultCoverart(true)
			
			dispatch_async(internalQueue,
			{
				self.idNowButton.enabled = false
				self.gnAudioVisualizeAdapter = GnAudioVisualizeAdapter( audioSource:self.gnMic, audioVisualizerDelegate:self)
				do
				{
					try self.gnMusicIdStream.audioProcessStart( self.gnAudioVisualizeAdapter )
				}
				catch
				{
					dispatch_async(dispatch_get_main_queue())
					{
						print("\(error)")
//						NSLog(@"Error while starting Audio Process With AudioSource - %@", [musicIDStreamError localizedDescription]);
					};
				}
			})
		}
		catch
		{
			print("\(error)")
//			NSLog( @"Error: %@ - %@ - %@", [exception name], [exception reason], [exception userInfo] );
		}
	}
	
	func verifyString( string:String?) -> String
	{
		if (nil == string)
		{
			return ""
		}
		
		return string!
	}

	// Implementation for processAlbumResponseAndUpdateResultsTable
	func processAlbumResponseAndUpdateResultsTable(responseAlbums: AnyObject)
	{
		var albums:GnAlbumEnumerator
		if (responseAlbums.isKindOfClass(GnResponseAlbums))
		{
			albums = responseAlbums.albums()
		}
		else
		{
			albums = responseAlbums as! GnAlbumEnumerator
		}
		
		for album in albums
		{
			let albumArtist = album.artist()?.name()?.display()
			let albumTitle = album.title()?.display()
			let albumGenre = album.genre(kDataLevel_1)
			let albumID = String(format: "%@-%@", album.tui()!, album.tuiTag()!)
			
			var albumXID:String = ""
			if (album.externalIds().count() > 0)
			{
				let externalID = album.externalIds().nextObject()!
				albumXID = verifyString(externalID.source())
			}
			
			let albumYear = album.year()
			let albumTrackCount = String(format: "%lu", album.trackCount())
			
			/* Get CoverArt */
			let coverArtContent = album.coverArt()
			let coverArtAsset = coverArtContent?.asset(kImageSizeSmall)
			
			let artistImageContent = album.artist()?.contributor()?.image()
			let artistImageAsset = artistImageContent?.asset(kImageSizeSmall);
			
			let artistBiographyContent = album.artist()?.contributor()?.biography();
			let albumReviewContent = album.review();
			
			let gnDataModelObject = GnDataModel();
			gnDataModelObject.albumArtist = verifyString(albumArtist)
			gnDataModelObject.albumGenre = verifyString(albumGenre)
			gnDataModelObject.albumID = verifyString(albumID)
			gnDataModelObject.albumXID = verifyString(albumXID)
			gnDataModelObject.albumYear = verifyString(albumYear)
			gnDataModelObject.albumTitle = verifyString(albumTitle)
			gnDataModelObject.albumTrackCount = verifyString(albumTrackCount)
			gnDataModelObject.albumLanguage = verifyString(album.language())
			
			weak var weakSelf:GnViewControllerSwift? = self;

			if let url = coverArtAsset?.url()
			{
				dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
				{
					do
					{
						let gnAssetFetch = try GnAssetFetch(user: self.gnUser, url: url, statusEventsDelegate: self)
						gnDataModelObject.albumImageData = gnAssetFetch.data();
						weakSelf?.resultsTableView.reloadData();
					}
					catch
					{
//						print("\(error)")
					}
			   })
			}

			if let url = artistImageAsset?.url()
			{
				dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
				{
					do
					{
						let gnAssetFetch = try GnAssetFetch(user: self.gnUser, url: url, statusEventsDelegate: self)
						gnDataModelObject.artistImageData = gnAssetFetch.data()
						weakSelf?.resultsTableView.reloadData()
						self.refreshArtistImage()
					}
					catch
					{
//						print("\(error)")
					}
			   })
			}

			if let url = artistBiographyContent?.assets().nextObject()!.url()
			{
				dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
				{
					do
					{
						let gnAssetFetch = try GnAssetFetch(user: self.gnUser, url: url, statusEventsDelegate: self)
						let img = gnAssetFetch.data()
						gnDataModelObject.artistBiography = String(bytes: img.bytes, length: img.length, encoding: NSUTF8StringEncoding)
					}
					catch
					{
//						print("\(error)")
					}
			   })
			}

			if let url = albumReviewContent?.assets().nextObject()?.url()
			{
				dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
				{
					do
					{
						let gnAssetFetch = try GnAssetFetch(user: self.gnUser, url: url, statusEventsDelegate: self)
						let img = gnAssetFetch.data()
						gnDataModelObject.albumReview = String(bytes: img.bytes, length: img.length, encoding: NSUTF8StringEncoding)
					}
					catch
					{
//						print("\(error)")
					}
			   })
			}

//			NSLog(@"Matched Album = %@", [[album title]display]);

			let tracksMatched = album.tracksMatched()
			for track in tracksMatched
			{
//				NSLog(@"  Matched Track = %@", [[track title]display]);
				
				let trackArtist = track.artist()?.name()?.display()
				let trackMood = track.mood(kDataLevel_1)
				let trackOrigin = track.artist()?.contributor()?.origin(kDataLevel_1)
				let trackTempo = track.tempo(kDataLevel_1)
				let trackGenre = track.genre(kDataLevel_1)
				let trackID = String(format: "%@-%@", verifyString(track.tui()), verifyString(track.tuiTag()))

				let trackDuration = String(format: "%lu", track.duration()/1000)
				let currentPosition = String(format: "%zu", track.currentPosition()/1000)
				let matchPosition = String(format: "%zu", track.matchPosition()/1000)

				var trackXID:String = ""
				if (track.externalIds().count() > 0)
				{
					let externalID = track.externalIds().nextObject()!
					trackXID = externalID.source()!
				}
				
				let trackNumber = track.trackNumber()
				let trackTitle = track.title()?.display()
				let trackArtistType = track.artist()?.contributor()?.artistType(kDataLevel_1)
				

				//Allocate GnDataModel.
				gnDataModelObject.trackArtist = verifyString(trackArtist)
				gnDataModelObject.trackMood = verifyString(trackMood)
				gnDataModelObject.trackTempo = verifyString(trackTempo)
				gnDataModelObject.trackOrigin = verifyString(trackOrigin)
				gnDataModelObject.trackGenre = verifyString(trackGenre)
				gnDataModelObject.trackID = verifyString(trackID)
				gnDataModelObject.trackXID = verifyString(trackXID)
				gnDataModelObject.trackNumber = verifyString(trackNumber)
				gnDataModelObject.trackTitle = verifyString(trackTitle)
				gnDataModelObject.trackArtistType = verifyString(trackArtistType)
				gnDataModelObject.trackMatchPosition = verifyString(matchPosition)
				gnDataModelObject.trackDuration = verifyString(trackDuration)
				gnDataModelObject.currentPosition = verifyString(currentPosition)
			}

			results.addObject(gnDataModelObject)
		}
		
		dispatch_async(dispatch_get_main_queue(), {
			self.refreshResults()
			})
	}

	// Implementation for GnMusicIdStreamEventsDelegate
	func musicIdStreamIdentifyingStatusEvent(status: GnMusicIdStreamIdentifyingStatus, cancellableDelegate canceller: GnCancellableDelegate)
	{
		var statusString:String;
		
		switch (status)
		{
			case kStatusIdentifyingInvalid:
				statusString = "Error"
				break
				
			case kStatusIdentifyingStarted:
				statusString = "Identifying"
				break
				
			case kStatusIdentifyingFpGenerated:
				statusString = "Fingerprint Generated"
				break
				
			case kStatusIdentifyingLocalQueryStarted:
				statusString = "Local Query Started"
				lookupSourceIsLocal = true;
				queryBeginTimeInterval = NSDate().timeIntervalSince1970
				break
				
			case kStatusIdentifyingLocalQueryEnded:
				statusString = "Local Query Ended"
				lookupSourceIsLocal = true;
				queryEndTimeInterval = NSDate().timeIntervalSince1970
				break
				
			case kStatusIdentifyingOnlineQueryStarted:
				statusString = "Online Query Started"
				lookupSourceIsLocal = false;
				break
				
			case kStatusIdentifyingOnlineQueryEnded:
				statusString = "Online Query Ended"
				queryEndTimeInterval = NSDate().timeIntervalSince1970
				break
				
			case kStatusIdentifyingEnded:
				statusString = "Identification Ended"
				break
				
			case kStatusIdentifyingNoNewResult:
				statusString = "No new result"
				break
			
			default:
				statusString = "No new result"
				break
		}
		
		if (statusString.characters.count > 0)
		{
			/*	Don't update status unless we have something to show.	*/
			updateStatus(statusString)
		}
	}

	func statusEvent(status: GnStatus, percentComplete: UInt, bytesTotalSent: UInt, bytesTotalReceived: UInt, cancellableDelegate canceller: GnCancellableDelegate)
	{
		var statusString:String = "";

		
		switch (status)
		{
			case kStatusUnknown:
				statusString = "Status Unknown"
				break
				
			case  kStatusBegin:
				statusString = "Status Begin"
				break
				
			case kStatusProgress:
				break
				
			case  kStatusComplete:
				statusString = "Status Complete"
				break
				
			case kStatusErrorInfo:
				statusString = "No Match";
				stopBusyIndicator()
				break;
				
			case kStatusConnecting:
				statusString = "Status Connecting"
				break;
				
			case kStatusSending:
				statusString = "Status Sending"
				break;
				
			case kStatusReceiving:
				statusString = "Status Receiving"
				break;
				
			case kStatusDisconnected:
				statusString = "Status Disconnected"
				break;
				
			case kStatusReading:
				statusString = "Status Reading"
				break;
				
			case kStatusWriting:
				statusString = "Status Writing"
				break;
				
			case kStatusCancelled:
				statusString = "Status Cancelled"
				break;
				
			default:
				break
		}
		
		updateStatus(String(format: "%@ [%zu%%]", statusString, percentComplete))
	}

	func musicIdStreamProcessingStatusEvent(status: GnMusicIdStreamProcessingStatus, cancellableDelegate canceller: GnCancellableDelegate)
	{
		switch (status)
		{
			case  kStatusProcessingInvalid:
				break
			case   kStatusProcessingAudioNone:
				break
			case kStatusProcessingAudioStarted:
				dispatch_async(dispatch_get_main_queue()) {
								   self.audioProcessingStarted = true
								   self.idNowButton.enabled = true;
							   }
				break
			case   kStatusProcessingAudioEnded:
				break
			case  kStatusProcessingAudioSilence:
				break
			case  kStatusProcessingAudioNoise:
				break
			case kStatusProcessingAudioSpeech:
				break
			case  kStatusProcessingAudioMusic:
				break
			case  kStatusProcessingTransitionNone:
				break
			case  kStatusProcessingTransitionChannelChange:
				break
			case  kStatusProcessingTransitionContentToContent:
				break
			case kStatusProcessingErrorNoClassifier:
				break
			default:
				break
		}
	}

	func musicIdStreamAlbumResult(result: GnResponseAlbums, cancellableDelegate canceller: GnCancellableDelegate)
	{
		cancellableObjects.removeObject(gnMusicIdStream)
		if cancellableObjects.count == 0
		{
			cancelOperationsButton.enabled = false
		}
		
		stopBusyIndicator()
		processAlbumResponseAndUpdateResultsTable(result)
	}

	func musicIdStreamIdentifyCompletedWithError(completeError: NSError)
	{
		cancellableObjects.removeObject(gnMusicIdStream)
		if cancellableObjects.count == 0
		{
			cancelOperationsButton.enabled = false
		}
		
		updateStatus(String(format: "%@ - [%zx]", completeError.localizedDescription, completeError.code))
		stopBusyIndicator()
	}

	// Implementation for GnLookupLocalStreamIngestEventsDelegate
	func statusEvent(status: GnLookupLocalStreamIngestStatus, bundleId: String, cancellableDelegate canceller: GnCancellableDelegate)
	{
		switch(status)
		{
			case kIngestStatusInvalid:
				NSLog("status = kIngestStatusInvalid");
				break;
			case kIngestStatusItemBegin:
				NSLog("status = kIngestStatusItemBegin");
				break;
			case kIngestStatusItemAdd:
				NSLog("status = kIngestStatusItemAdd");
				break;
			case kIngestStatusItemDelete:
				NSLog("status = kIngestStatusItemDelete");
				break;
			default:
				NSLog("status = unknown");
		}
	}

	// Implementation of GnAudioVisualizerDelegate
	func RMSDidUpdateByValue( value:Float )
	{
//		if visualizationIsVisible
//		{
//			dispatch_async(dispatch_get_main_queue(), ^{
//				
//				float scale =  value + 1.0f;
//				CGAffineTransform sscale = CGAffineTransformMakeScale (scale, scale);
//				self.coloredRingImageView.transform  = sscale;
//				
//			});
//		}
	}

	func refreshArtistImage()
	{
		if (nil != currentlySelectedIndexPath)
		{
			let cell = resultsTableView.cellForRowAtIndexPath(currentlySelectedIndexPath)
			let additionalContentView = cell?.contentView.viewWithTag(ADDITIONALCONTENTVIEWTAG)
			let additionalContentImageView = additionalContentView?.viewWithTag(ADDITIONALCONTENTIMAGEVIEWTAG) as! UIImageView
			
			if ((results != nil) && (results.count > currentlySelectedIndexPath.row))
			{
				let datamodelObject = results.objectAtIndex(currentlySelectedIndexPath.row) as! GnDataModel
				let artistImage = UIImage(data: datamodelObject.artistImageData)
				if (nil != artistImage)
				{
					additionalContentImageView.image = artistImage;
				}
				else
				{
					additionalContentImageView.image = UIImage(contentsOfFile: "emptyImage.png")
				}
			}
		}
	}

	func refreshResults()
	{
		if (results.count==0)
		{
			updateStatus("No Match")
		}
		else
		{
			let status = String(format: "Found %lu", results.count)
			updateStatus(status)
		}
		
		resultsTableView.reloadData()
		busyIndicator.stopAnimating()
	}

	func closeAdditionalContentView(sender:AnyObject)
	{
		if(nil != currentlySelectedIndexPath)
		{
			let cell = resultsTableView.cellForRowAtIndexPath(currentlySelectedIndexPath)

//			[UIView animateWithDuration:0.5 animations:^{
//				UIView *additionalContentView = (UIView*) [cell.contentView viewWithTag:ADDITIONALCONTENTVIEWTAG];
//				CGRect frame = additionalContentView.frame;
//				frame.origin.x = (UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad?768:320);
//				additionalContentView.frame = frame;
//			}];
		}
	}
}
