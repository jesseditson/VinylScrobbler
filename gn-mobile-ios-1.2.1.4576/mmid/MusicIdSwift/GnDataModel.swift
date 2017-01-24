//
//  GnDataModel.swift
//  GN_Music_SDK_iOS
//
//  Copyright (c) 2016 Gracenote. All rights reserved.
//

import Foundation

class GnDataModel : NSObject
{
	var albumArtist:String!
	var albumGenre:String!
	var albumID:String!
	var albumXID:String!
	var albumYear:String!
	var albumTitle:String!
	var albumTrackCount:String!
	var albumLanguage:String!
	var albumReview:String!
	var albumImageData:NSData!
	var albumImageURLString:String!

	var trackArtist:String!
	var trackMood:String!
	var artistImageData:NSData!
	var artistImageURLString:String!
	var artistBiography:String!

	var currentPosition:String!
	var trackMatchPosition:String!
	var trackDuration:String!
	var trackTempo:String!
	var trackOrigin:String!
	var trackGenre:String!
	var trackID:String!
	var trackXID:String!
	var trackNumber:String!
	var trackTitle:String!
	var trackArtistType:String!
}
