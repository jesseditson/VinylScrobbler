//
//  RecordingViewController.swift
//  VinylScrobbler
//
//  Created by Jesse Ditson on 1/18/17.
//  Copyright © 2017 Jesse Ditson. All rights reserved.
//

import Foundation
import UIKit
import AVFoundation
import CoreAudio

class RecordingViewController: UIViewController {
    
    @IBOutlet var dbIndicator: UIProgressView!
    @IBOutlet var recordingButton: UIButton!
    
    var monitor: AVAudioRecorder!
    var recorder: AVAudioRecorder!
    var levelTimer = Timer()
    var sliceTimer = Timer()
    var lowPassResults: Double = 0.0
    var minPowerPercent: Float = 0.6
    var minSampleLength: Int = 10
    var sampleLength: Double = 15.0
    var recordingStartDate: Date? = nil
    var priorLevel: Float? = nil
    var sliceURL: URL!
    var monitorURL: URL!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        do {
            
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
        } catch let error {
            print(error.localizedDescription)
        }
    }
    
    func beginMonitoring() throws {
        //set up the URL for the audio file
        let fm = FileManager.init()
        let documents = try fm.url(for: FileManager.SearchPathDirectory.documentDirectory, in: FileManager.SearchPathDomainMask.userDomainMask, appropriateFor: nil, create: true)
        
        monitorURL = documents.appendingPathComponent("monitorBuffer.caf")
        
        // make a dictionary to hold the recording settings so we can instantiate our AVAudioRecorder
        let recordSettings: [String: Any] = [AVFormatIDKey:kAudioFormatAppleIMA4,
                                             AVSampleRateKey:44100.0,
                                             AVNumberOfChannelsKey:2,AVEncoderBitRateKey:12800,
                                             AVLinearPCMBitDepthKey:16,
                                             AVEncoderAudioQualityKey:AVAudioQuality.medium.rawValue
        ]
        
        //Instantiate an AVAudioRecorder
        monitor = try AVAudioRecorder(url: monitorURL, settings: recordSettings)
        
        monitor.prepareToRecord()
        monitor.isMeteringEnabled = true
        
        //start monitoring
        monitor.record()
        
        //instantiate a timer to be called with whatever frequency we want to grab metering values
        self.levelTimer = Timer.scheduledTimer(timeInterval: 0.5, target: self, selector: #selector(RecordingViewController.levelTimerCallback), userInfo: nil, repeats: true)
    }
    
    func startRecording() throws {
        // make a dictionary to hold the recording settings so we can instantiate our AVAudioRecorder
        let recordSettings: [String: Any] = [AVFormatIDKey:kAudioFormatAppleIMA4,
                                             AVSampleRateKey:44100.0,
                                             AVNumberOfChannelsKey:2,AVEncoderBitRateKey:12800,
                                             AVLinearPCMBitDepthKey:16,
                                             AVEncoderAudioQualityKey:AVAudioQuality.medium.rawValue
        ]
        
        //Instantiate an AVAudioRecorder
        recorder = try AVAudioRecorder(url: sliceURL, settings: recordSettings)
        
        recorder.prepareToRecord()
        recorder.isMeteringEnabled = true
        
        //start recording
        recorder.record(forDuration: sampleLength)
        recordingStartDate = Date()
        
        self.sliceTimer = Timer.scheduledTimer(timeInterval: sampleLength, target: self, selector: #selector(RecordingViewController.sliceComplete), userInfo: nil, repeats: false)
    }
    
    func stopRecording() {
        if recorder.isRecording {
            recorder.stop()
            sliceTimer.invalidate()
            processSlice()
        }
    }
    
    func sliceComplete() {
        processSlice()
    }
    
    func processSlice() {
        // check to see if we've recorded enough
        if let sd = recordingStartDate {
            let currentCal = NSCalendar.current
            let recordingLength = currentCal.component(.second, from: sd)
            if recordingLength > minSampleLength {
                
            }
        }
    }
    
    //This selector/function is called every time our timer (levelTime) fires
    func levelTimerCallback() {
        //we have to update meters before we can get the metering values
        monitor.updateMeters()
        
        let powerLevel = monitor.averagePower(forChannel: 0)
        let percent = 1-(powerLevel / -160) // -160-0
        
        
        if let priorLevel = self.priorLevel {
            let priorPercent = 1-(priorLevel / -160)
            if percent > minPowerPercent && priorPercent <= minPowerPercent {
                // transition from silence to noise - start sampling
                print("BEGIN RECORDING")
            } else if priorPercent >= minPowerPercent && percent < minPowerPercent {
                // transition from noise to silence - stop the current sample if it's recording
                print("STOP RECORDING")
            }
            print("\(priorLevel) -> \(powerLevel)")
            print("\(priorPercent) -> \(percent)")
        }
        self.priorLevel = powerLevel
        self.dbIndicator.progress = percent
    }
    
    @IBAction func logout() {
        monitor.stop()
        LastfmAPI.sharedInstance.logout()
        self.performSegue(withIdentifier: "showLoggedOut", sender: nil)
    }
    
    @IBAction func toggleRecording() {
        if monitor.isRecording {
            monitor.stop()
            recordingButton.setTitle("record", for: .normal)
        } else {
            do {
                try self.beginMonitoring()
            } catch let error {
                print("ERROR! \(error.localizedDescription)")
            }
            recordingButton.setTitle("stop", for: .normal)
        }
    }
    
    @IBAction func play() {
        if monitor.isRecording {
            self.toggleRecording()
        }
        do {
            let player = try AVAudioPlayer(contentsOf: monitorURL)
            player.play()
        } catch let error {
            print("ERROR! \(error.localizedDescription)")
        }
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    
}

