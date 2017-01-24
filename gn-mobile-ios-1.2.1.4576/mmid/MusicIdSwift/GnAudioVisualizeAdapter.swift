//
//  GnAudioVisualizeAdapter.swift
//  GN_Music_SDK_iOS
//
//  Copyright (c) 2016 Gracenote. All rights reserved.
//

import CoreAudio
import AudioToolbox
//import GnAppDelegate

class GnAudioVisualizeAdapter : NSObject, GnAudioSourceDelegate
{
	var audioSource:GnAudioSourceDelegate!
	var numBitsPerSample:UInt!
	var numChannels:UInt!
	var lastRMS:Float!
	var maxRMS:Float!
	var audioVisualizerDelegate:GnAudioVisualizerDelegate!
	
	init( audioSource:GnAudioSourceDelegate,  audioVisualizerDelegate:GnAudioVisualizerDelegate )
	{
		self.lastRMS = 0
		self.audioSource = audioSource
		self.audioVisualizerDelegate = audioVisualizerDelegate
	}

	func sourceInit() -> UInt
	{
		if ( nil == audioSource )
		{
			return 1
		}
		
		// get format information for use later
		let retVal = audioSource.sourceInit()
		if ( retVal == 0 )
		{
			numBitsPerSample = audioSource.sampleSizeInBits()
			numChannels = audioSource.numberOfChannels()
		}
		
		return retVal;
	}

	func numberOfChannels() -> UInt
	{
		return numChannels
	}


	func sampleSizeInBits() -> UInt
	{
		return numBitsPerSample
	}

	func samplesPerSecond() -> UInt
	{
		if ( nil == audioSource )
		{
			return 0
		}
		
		return audioSource.samplesPerSecond()
	}

	func getData( dataBuffer: UnsafeMutablePointer<UInt8>, dataSize: UInt ) -> UInt
	{
		if ( nil == audioSource)
		{
			return 0;
		}
		
		let bytesRead = audioSource.getData( dataBuffer, dataSize:dataSize )
		let RMS = rms16( dataBuffer, dataSize:bytesRead )
		
//		if ( nil != audioVisualizerDelegate && audioVisualizerDelegate as? GnAudioVisualizerDelegate && audioVisualizerDelegate as? RMSDidUpdateByValue )
//if ( nil != audioVisualizerDelegate && nil != (audioVisualizerDelegate as? GnAudioVisualizerDelegate) )
//		{
//			audioVisualizerDelegate.RMSDidUpdateByValue(RMS/10)
//		}

		return bytesRead
	}

	func sourceClose()
	{
		if (nil == audioSource)
		{
		   audioSource.sourceClose()
		}
	}


	// calculate the rms of a buffer containing 16 bit audio samples
	func rms16( dataBuffer: UnsafeMutablePointer<UInt8>, dataSize: UInt ) -> Float
	{
//		var sum:Float = 0.0
//		var mySize:UInt = bufferSize / sizeof(short)
//		var bufferShort:UnsafeMutablePointer<UInt16> = dataBuffer
//		
//		for i in 0...mySize
//		{
//		   sum += (float)(bufferShort[i] * bufferShort[i]);
//		}
//		
//		let sqrt1 = sqrtf( sum / mySize );
//		return (Float)(sqrt1)/mySize;
		return 0
	}
}
