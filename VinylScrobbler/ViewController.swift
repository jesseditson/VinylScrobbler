//
//  ViewController.swift
//  VinylScrobbler
//
//  Created by Jesse Ditson on 1/18/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

import Foundation
import UIKit
import AVFoundation
import CoreAudio

let CLIENT_ID = "2119516911"
let CLIENT_TAG = "32A04E0232D6A7DDB56033E8E5278DB7"
let APPLICATION_VERSION = "0.1.0"

class ViewController: UIViewController, GnMusicIdStreamEventsDelegate {
    
    @IBOutlet var levelLabel: UILabel!
    
    var monitor: AVAudioRecorder!
    var recorder: AVAudioRecorder!
    var levelTimer = Timer()
    var sliceTimer = Timer()
    var lowPassResults: Double = 0.0
    var sliceURL: URL!
    var gnUser: GnUser!
    var gnMusicIdStream: GnMusicIdStream!
    var gnMic: GnMic!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let gnUserStore = GnUserStore.init()
        gnMic = GnMic(sampleRate: 44100, bitsPerChannel: 16, numberOfChannels: 2)
        
        do {
            
            gnUser = try GnUser(userStoreDelegate: gnUserStore, clientId: CLIENT_ID, clientTag: CLIENT_TAG, applicationVersion: APPLICATION_VERSION)
            
            //make an AudioSession, set it to PlayAndRecord and make it active
            let audioSession:AVAudioSession = AVAudioSession.sharedInstance()
            try audioSession.setCategory(AVAudioSessionCategoryPlayAndRecord)
            try audioSession.setActive(true)
            //        var inputSource: AVAudioSessionDataSourceDescription
            //        for input in audioSession.availableInputs! {
            //            if let sources = input.dataSources {
            //                for source in sources {
            //                    print(source)
            //                }
            //            }
            //        }
            //        try audioSession.setInputDataSource(AVAudioSessionDataSourceDescription)
            
            //set up the URL for the audio file
            let fm = FileManager.init()
            let documents = try fm.url(for: FileManager.SearchPathDirectory.documentDirectory, in: FileManager.SearchPathDomainMask.userDomainMask, appropriateFor: nil, create: true)
            
            sliceURL =  documents.appendingPathComponent("recordingBuffer.caf")
            
            try self.beginMonitoring()
//            try self.recordSlice()
        } catch let error {
            //If there's an error, print that shit
            print(error.localizedDescription)
        }
    }
    
    func beginMonitoring() throws {
        //set up the URL for the audio file
        let fm = FileManager.init()
        let documents = try fm.url(for: FileManager.SearchPathDirectory.documentDirectory, in: FileManager.SearchPathDomainMask.userDomainMask, appropriateFor: nil, create: true)
        
        let url =  documents.appendingPathComponent("monitorBuffer.caf")
        
        // make a dictionary to hold the recording settings so we can instantiate our AVAudioRecorder
        let recordSettings: [String: Any] = [AVFormatIDKey:kAudioFormatAppleIMA4,
                                             AVSampleRateKey:44100.0,
                                             AVNumberOfChannelsKey:2,AVEncoderBitRateKey:12800,
                                             AVLinearPCMBitDepthKey:16,
                                             AVEncoderAudioQualityKey:AVAudioQuality.low.rawValue
        ]
        
        //Instantiate an AVAudioRecorder
        monitor = try AVAudioRecorder(url: url, settings: recordSettings)
        
        monitor.prepareToRecord()
        monitor.isMeteringEnabled = true
        
        //start monitoring
        monitor.record()
        
        //instantiate a timer to be called with whatever frequency we want to grab metering values
        self.levelTimer = Timer.scheduledTimer(timeInterval: 0.02, target: self, selector: #selector(ViewController.levelTimerCallback), userInfo: nil, repeats: true)
    }
    
    public func statusEvent(_ status: GnStatus, percentComplete: UInt, bytesTotalSent: UInt, bytesTotalReceived: UInt, cancellableDelegate canceller: GnCancellableDelegate) {
        print(status)
    }
    func musicIdStreamProcessingStatusEvent(_ status: GnMusicIdStreamProcessingStatus, cancellableDelegate canceller: GnCancellableDelegate) {
        print(status)
    }
    func musicIdStreamIdentifyingStatusEvent(_ status: GnMusicIdStreamIdentifyingStatus, cancellableDelegate canceller: GnCancellableDelegate) {
        print(status)
    }
    func musicIdStreamIdentifyCompletedWithError(_ completeError: Error) {
        print(completeError)
    }
    func musicIdStreamAlbumResult(_ result: GnResponseAlbums, cancellableDelegate canceller: GnCancellableDelegate) {
        print(result)
    }
    
    func setupGnStream() throws {
        let stream: GnMusicIdStream = try GnMusicIdStream(user: self.gnUser, preset: kPresetRadio, musicIdStreamEventsDelegate: self)
//        stream.audioProcessStart(audioSource: self.gnMic)
    }
    
    func recordSlice() throws {
        // make a dictionary to hold the recording settings so we can instantiate our AVAudioRecorder
        let recordSettings: [String: Any] = [AVFormatIDKey:kAudioFormatAppleIMA4,
                                             AVSampleRateKey:44100.0,
                                             AVNumberOfChannelsKey:2,AVEncoderBitRateKey:12800,
                                             AVLinearPCMBitDepthKey:16,
                                             AVEncoderAudioQualityKey:AVAudioQuality.max.rawValue
        ]
        
        //Instantiate an AVAudioRecorder
        recorder = try AVAudioRecorder(url: sliceURL, settings: recordSettings)
        
        recorder.prepareToRecord()
        recorder.isMeteringEnabled = true
        
        //start recording
        recorder.record(forDuration: 20)
        
        self.sliceTimer = Timer.scheduledTimer(timeInterval: 20, target: self, selector: #selector(ViewController.sliceComplete), userInfo: nil, repeats: false)
    }
    
    func sliceComplete() {
        
        do {
            try self.recordSlice()
        } catch let error {
            //If there's an error, print that shit
            print(error.localizedDescription)
        }
    }
    
    //This selector/function is called every time our timer (levelTime) fires
    func levelTimerCallback() {
        //we have to update meters before we can get the metering values
        recorder.updateMeters()
        
        //print to the console if we are beyond a threshold value.
        let powerLevel = recorder.averagePower(forChannel: 0)
        if powerLevel > -9 {
            self.levelLabel.text = String(format: "%f", arguments: [powerLevel])
        } else {
            self.levelLabel.text = "--"
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}

