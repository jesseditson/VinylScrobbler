//
//  gnsdk_extensions.swift
//
//  GNSDK Swift API refinements
//
//  Copyright © 2016 Gracenote. All rights reserved.
//

#if GNSDK_ALL
extension GnConfig
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func setWithCustom( custom:String, value:String ) throws -> Bool
	{
		var error:NSError?
		__setWithCustom( custom, value: value, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func setWithAccess( access:GnConfigOptionAccess ) throws -> Bool
	{
		var error:NSError?
		__setWithAccess( access, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func setWithEnable( enable:GnConfigOptionEnable, value:Bool ) throws -> Bool
	{
		var error:NSError?
		__setWithEnable( enable, value: value, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func setWithLocation( location:GnConfigOptionLocation, value:String ) throws -> Bool
	{
		var error:NSError?
		__setWithLocation( location, value: value, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
}
#endif

extension GnDataObject
{
	public func isType( type:String ) throws -> Bool
	{
		var error:NSError?
		let tmp = __isType( type, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func locale( locale:GnLocale ) throws -> Bool
	{
		var error:NSError?
		__locale( locale, error: &error )
		if nil != error
		{
			throw error!
		}
	
		return true
	}
}

extension GnList
{
	public func update( user:GnUser, statusEventsDelegate:GnStatusEventsDelegate! ) throws -> Bool
	{
		var error:NSError?
		let tmp = __update( user, statusEventsDelegate:statusEventsDelegate, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
	
	public func updateCheck( user:GnUser, statusEventsDelegate:GnStatusEventsDelegate! ) throws -> Bool
	{
		var error:NSError?
		let tmp = __updateCheck( user, statusEventsDelegate:statusEventsDelegate, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func type() throws -> GnListType
	{
		var error:NSError?
		let tmp = __type( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func descriptor() throws -> GnDescriptor
	{
		var error:NSError?
		let tmp = __descriptor( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func language() throws -> GnLanguage
	{
		var error:NSError?
		let tmp = __language( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func region() throws -> GnRegion
	{
		var error:NSError?
		let tmp = __region( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func levelCount() throws -> UInt
	{
		var error:NSError?
        let intVal = __levelCount( &error )
		if nil != error
		{
			throw error!
		}

		return intVal
	}
}

extension GnListElement
{
	public func id() throws -> UInt
	{
		var error:NSError?
        let tmp = __id( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func idForSubmit() throws -> UInt
	{
		var error:NSError?
        let tmp = __idForSubmit( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func level() throws -> UInt
	{
		var error:NSError?
        let tmp = __level( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnLocale
{
	public func update( user:GnUser, statusEventsDelegate:GnStatusEventsDelegate! ) throws -> Bool
	{
		var error:NSError?
        let tmp = __update( user, statusEventsDelegate:statusEventsDelegate, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func updateCheck( user:GnUser, statusEventsDelegate:GnStatusEventsDelegate! ) throws -> Bool
	{
		var error:NSError?
        let tmp = __updateCheck( user, statusEventsDelegate:statusEventsDelegate, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
    
    public func setGroupDefault() throws
    {
		var error:NSError?
		__setGroupDefault( &error )
		if nil != error
		{
			throw error!
		}
    }
}

#if GNSDK_ALL
extension GnLookupLocal
{
	public func storageInfoCount( storageName:GnLocalStorageName, storageInfo:GnLocalStorageInfo) throws -> UInt
	{
		var error:NSError?
        let tmp = __storageInfoCount( storageName, storageInfo: storageInfo, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
	
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func storageLocation( storageName:GnLocalStorageName, storageLocation:String ) throws -> Bool
	{
		var error:NSError?
		__storageLocation( storageName, storageLocation: storageLocation, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func storageValidate( storageName:GnLocalStorageName ) throws -> Bool
	{
		var error:NSError?
		__storageValidate( storageName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
}
#endif

extension GnLookupLocalStream
{
	public func getEngineType() throws -> GnLocalStreamEngineType
	{
		var error:NSError?
		let tmp = __getEngineType( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

 	public func getFingerprintProcessingMethod() throws -> GnLocalStreamFingerprintProcessingMethod
	{
		var error:NSError?
		let tmp = __getFingerprintProcessingMethod( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}	

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func storageLocation( location:String ) throws -> Bool
	{
		var error:NSError?
		__storageLocation( location, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
	
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func engineType( engineType:GnLocalStreamEngineType ) throws -> Bool
	{
		var error:NSError?
		__engineType( engineType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
	
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprintProcessingMethod( processingMethod:GnLocalStreamFingerprintProcessingMethod ) throws -> Bool
	{
		var error:NSError?
		__fingerprintProcessingMethod( processingMethod, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
	
	public func storageClear() throws
	{
		var error:NSError?
		__storageClear( &error )
		if nil != error
		{
			throw error!
		}
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func storageRemove( bundleItemId:String ) throws -> Bool
	{
		var error:NSError?
		__storageRemove( bundleItemId, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
}

extension GnLookupLocalStreamIngest
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func write( data:NSData ) throws -> Bool
	{
		var error:NSError?
		__write( data, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	public func flush() throws
	{
		var error:NSError?
		__flush( &error )
		if nil != error
		{
			throw error!
		}
	}
}

extension GnManager
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func testGracenoteConnection( user:GnUser ) throws -> Bool
	{
		var error:NSError?
		__testGracenoteConnection( user, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
}

extension GnMoodgridPresentation
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func addFilter( uniqueIdentifier:String, elistType:GnMoodgridFilterListType, strValueId:String, eConditionType:GnMoodgridFilterConditionType ) throws -> Bool
	{
		var error:NSError?
		__addFilter( uniqueIdentifier, elistType: elistType, strValueId: strValueId, eConditionType: eConditionType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func removeFilter( uniqueIdentifier:String ) throws -> Bool
	{
		var error:NSError?
		__removeFilter( uniqueIdentifier, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	public func removeAllFilters() throws
	{
		var error:NSError?
		__removeAllFilters( &error )
		if nil != error
		{
			throw error!
		}
	}

	public func moods() throws -> GnMoodgridDataPointEnumerator
	{
		var error:NSError?
		let tmp = __moods( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func layoutType() throws -> GnMoodgridPresentationType
	{
		var error:NSError?
		let tmp = __layoutType( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func findRecommendationsEstimate( provider:GnMoodgridProvider, position:GnMoodgridDataPoint ) throws -> UInt
	{
		var error:NSError?
        let tmp = __findRecommendationsEstimate(provider, position:position, error: &error)
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnMoodgridProvider
{
	public func requiresNetwork() throws -> Bool
	{
		var error:NSError?
        let tmp = __requiresNetwork( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnMoodgridResult
{
	public func count() throws -> UInt
	{
		var error:NSError?
        let tmp = __count( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnMusicId
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprintBegin( fpType:GnFingerprintType, audioSampleRate:UInt, audioSampleSize:UInt, audioChannels:UInt ) throws -> Bool
	{
		var error:NSError?
		__fingerprintBegin( fpType, audioSampleRate: audioSampleRate, audioSampleSize: audioSampleSize, audioChannels: audioChannels, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	public func fingerprintWrite( data:NSData ) throws -> Bool
	{
		var error:NSError?
        let tmp = __fingerprintWrite( data, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func fingerprintEnd() throws
	{
		var error:NSError?
		__fingerprintEnd( &error )
		if nil != error
		{
			throw error!
		}
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprintFromSource( audioSource:GnAudioSourceDelegate, fpType:GnFingerprintType ) throws -> Bool
	{
		var error:NSError?
		__fingerprintFromSource( audioSource, fpType: fpType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}
}

extension GnMusicIdFile
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doTrackId( processType:GnMusicIdFileProcessType, responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doTrackId( processType, responseType: responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doTrackIdAsync( processType:GnMusicIdFileProcessType, responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doTrackIdAsync( processType, responseType: responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doAlbumId( processType:GnMusicIdFileProcessType, responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doAlbumId( processType, responseType: responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doAlbumIdAsync( processType:GnMusicIdFileProcessType, responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doAlbumIdAsync( processType, responseType: responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doLibraryId( responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doLibraryId( responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func doLibraryIdAsync( responseType:GnMusicIdFileResponseType ) throws -> Bool
	{
		var error:NSError?
		__doLibraryIdAsync( responseType, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	public func waitForComplete( timeoutValue:UInt ) throws -> Bool
	{
		var error:NSError?
		__waitForComplete( timeoutValue, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func waitForComplete() throws
	{
		var error:NSError?
		__waitForComplete( &error )
		if nil != error
		{
			throw error!
		}
	}

	public func cancel() throws
	{
		var error:NSError?
		__cancel( &error )
		if nil != error
		{
			throw error!
		}
	}
}

extension GnMusicIdFileInfo
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprintBegin( audioSampleRate:UInt, audioSampleSize:UInt, audioChannels:UInt ) throws -> Bool
	{
		var error:NSError?
		__fingerprintBegin( audioSampleRate, audioSampleSize: audioSampleSize, audioChannels: audioChannels, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	public func fingerprintWrite( data:NSData ) throws -> Bool
	{
		var error:NSError?
        let tmp = __fingerprintWrite( data, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func fingerprintEnd() throws
	{
		var error:NSError?
		__fingerprintEnd( &error )
		if nil != error
		{
			throw error!
		}
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprintFromSource( audioSource:GnAudioSourceDelegate) throws -> Bool
	{
		var error:NSError?
		__fingerprintFromSource( audioSource, error: &error )
		if nil != error
		{
			throw error!
		}
		
		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fileName( value:String ) throws -> Bool
	{
		var error:NSError?
        __fileName( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func cddbId( value:String ) throws -> Bool
	{
		var error:NSError?
        __cddbId( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func albumArtist( value:String ) throws -> Bool
	{
		var error:NSError?
        __albumArtist( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func albumTitle( value:String ) throws -> Bool
	{
		var error:NSError?
        __albumTitle( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func trackArtist( value:String ) throws -> Bool
	{
		var error:NSError?
        __trackArtist( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func trackTitle( value:String ) throws -> Bool
	{
		var error:NSError?
        __trackTitle( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func trackNumber( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __trackNumber( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func discNumber( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __discNumber( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func tagId( value:String ) throws -> Bool
	{
		var error:NSError?
        __tagId( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func fingerprint( value:String ) throws -> Bool
	{
		var error:NSError?
        __fingerprint( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func mediaId( value:String ) throws -> Bool
	{
		var error:NSError?
        __mediaId( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func mui( value:String ) throws -> Bool
	{
		var error:NSError?
        __mui( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func cdToc( value:String ) throws -> Bool
	{
		var error:NSError?
        __cdToc( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func tui( value:String ) throws -> Bool
	{
		var error:NSError?
        __tui( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func tuiTag( value:String ) throws -> Bool
	{
		var error:NSError?
        __tuiTag( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getDiscNumber() throws -> UInt
	{
		var error:NSError?
        let tmp = __getDiscNumber( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func getTrackNumber() throws -> UInt
	{
		var error:NSError?
        let tmp = __getTrackNumber( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func status() throws -> GnMusicIdFileInfoStatus
	{
		var error:NSError?
		let tmp = __status( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnMusicIdFileInfoManager
{
	public func addFromXml( xmlStr:String ) throws -> UInt
	{
		var error:NSError?
        let tmp = __addFromXml( xmlStr, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func remove( fileInfo:GnMusicIdFileInfo ) throws -> Bool
	{
		var error:NSError?
        __remove( fileInfo, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
}

extension GnMusicIdFileOptions
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupMode( lookupMode:GnLookupMode ) throws -> Bool
	{
		var error:NSError?
        __lookupMode( lookupMode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupData( val:GnLookupData, enable:Bool ) throws -> Bool
	{
		var error:NSError?
        __lookupData( val, enable: enable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func batchSize( size:UInt ) throws -> Bool
	{
		var error:NSError?
        __batchSize( size, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func customOptionEnable( option:String, enable:Bool ) throws -> Bool
	{
		var error:NSError?
        __customOptionEnable( option, enable: enable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func customOptionValue( option:String, value:String ) throws -> Bool
	{
		var error:NSError?
        __customOptionValue( option, value: value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkInterface( intfName:String ) throws -> Bool
	{
		var error:NSError?
        __networkInterface( intfName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func onlineProcessing( enable:Bool ) throws -> Bool
	{
		var error:NSError?
        __onlineProcessing( enable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultLanguage( preferredLangauge:GnLanguage ) throws -> Bool
	{
		var error:NSError?
        __preferResultLanguage( preferredLangauge, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultExternalId( preferredExternalId:String ) throws -> Bool
	{
		var error:NSError?
        __preferResultExternalId( preferredExternalId, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func threadPriority( threadPriority:GnThreadPriority ) throws -> Bool
	{
		var error:NSError?
        __threadPriority( threadPriority, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

}

extension GnMusicIdOptions
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func customOptionEnable( option:String, enable:Bool ) throws -> Bool
	{
		var error:NSError?
        __customOptionEnable( option, enable: enable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func customOptionValue( option:String, value:String ) throws -> Bool
	{
		var error:NSError?
        __customOptionValue( option, value: value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupMode( lookupMode:GnLookupMode ) throws -> Bool
	{
		var error:NSError?
        __lookupMode( lookupMode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupData( lookupData:GnLookupData, bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __lookupData( lookupData, bEnable: bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultLanguage( preferredLanguage:GnLanguage ) throws -> Bool
	{
		var error:NSError?
        __preferResultLanguage( preferredLanguage, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultExternalId( strExternalId:String ) throws -> Bool
	{
		var error:NSError?
        __preferResultExternalId( strExternalId, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultCoverart( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __preferResultCoverart( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultSingle( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __resultSingle( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func revisionCheck( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __revisionCheck( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultRangeStart( resultStart:UInt ) throws -> Bool
	{
		var error:NSError?
        __resultRangeStart( resultStart, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultCount( resultCount:UInt ) throws -> Bool
	{
		var error:NSError?
        __resultCount( resultCount, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkInterface( intfName:String ) throws -> Bool
	{
		var error:NSError?
        __networkInterface( intfName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
}

extension GnMusicIdStream
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func audioProcessStart( audioSource:GnAudioSourceDelegate ) throws -> Bool
	{
		var error:NSError?
        __audioProcessStart( audioSource, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func audioProcessStart( samplesPerSecond:UInt, bitsPerSample:UInt, numberOfChannels:UInt ) throws -> Bool
	{
		var error:NSError?
        __audioProcessStart( samplesPerSecond, bitsPerSample: bitsPerSample, numberOfChannels: numberOfChannels, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func audioProcessStop() throws
	{
		var error:NSError?
        __audioProcessStop( &error )
		if nil != error
		{
			throw error!
		}
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func audioProcess( data:NSData ) throws -> Bool
	{
		var error:NSError?
        __audioProcess( data, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func identifyAlbum() throws
	{
		var error:NSError?
        __identifyAlbum( &error )
		if nil != error
		{
			throw error!
		}
	}

	public func identifyAlbumAsync() throws
	{
		var error:NSError?
        __identifyAlbumAsync( &error )
		if nil != error
		{
			throw error!
		}
	}

	public func identifyCancel() throws
	{
		var error:NSError?
        __identifyCancel( &error )
		if nil != error
		{
			throw error!
		}
	}

#if GNSDK_ALL
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func automaticIdentification( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __automaticIdentification( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func text( textKey:GnMusicIdStreamChannelText, textValue:String ) throws -> Bool
	{
		var error:NSError?
        __text( textKey, textValue: textValue, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
#endif

	public func waitForIdentify( timeout:UInt ) throws -> Bool
	{
		var error:NSError?
        let tmp = __waitForIdentify( timeout, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	#if GNSDK_ALL
	public func getAutomaticIdentification() throws -> Bool
	{
		var error:NSError?
        let tmp = __getAutomaticIdentification( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
	#endif
}

extension GnMusicIdStreamOptions
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupMode( lookupMode:GnLookupMode ) throws -> Bool
	{
		var error:NSError?
        __lookupMode( lookupMode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupData( val:GnLookupData, enable:Bool ) throws -> Bool
	{
		var error:NSError?
        __lookupData( val, enable: enable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultLanguage( preferredLanguage:GnLanguage ) throws -> Bool
	{
		var error:NSError?
        __preferResultLanguage( preferredLanguage, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultExternalId( preferredExternalId:String ) throws -> Bool
	{
		var error:NSError?
        __preferResultExternalId( preferredExternalId, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func preferResultCoverart( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __preferResultCoverart( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultSingle( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __resultSingle( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultRangeStart( resultStart:UInt ) throws -> Bool
	{
		var error:NSError?
        __resultRangeStart( resultStart, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func resultCount( resultCount:UInt ) throws -> Bool
	{
		var error:NSError?
        __resultCount( resultCount, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkInterface( intfName:String ) throws -> Bool
	{
		var error:NSError?
        __networkInterface( intfName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func custom( optionKey:String, value:String ) throws -> Bool
	{
		var error:NSError?
        __custom( optionKey, value: value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
}

extension GnPlaylistCollection
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func name( updatedName:String ) throws -> Bool
	{
		var error:NSError?
        __name( updatedName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func add( mediaIdentifier:String ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func add( mediaIdentifier:String, album:GnAlbum ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, album: album, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func add( mediaIdentifier:String, track:GnTrack ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, track: track, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func add( mediaIdentifier:String, contributor:GnContributor ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, contributor: contributor, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func add( mediaIdentifier:String, playlistAttributes:GnPlaylistAttributes ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, playlistAttributes: playlistAttributes, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func add( mediaIdentifier:String, listElement:GnListElement ) throws -> Bool
	{
		var error:NSError?
        __add( mediaIdentifier, listElement: listElement, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func remove( mediaIdentifier:String ) throws -> Bool
	{
		var error:NSError?
        __remove( mediaIdentifier, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func join( toJoin:GnPlaylistCollection ) throws -> Bool
	{
		var error:NSError?
        __join( toJoin, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func joinRemove( toRemove:GnPlaylistCollection ) throws -> Bool
	{
		var error:NSError?
        __joinRemove( toRemove, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func serialize( data:NSData ) throws -> UInt
	{
		var error:NSError?
        let tmp = __serialize( data, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func serializeSize() throws -> UInt
	{
		var error:NSError?
        let tmp = __serializeSize( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func syncProcessAdd( mediaIdentifier:String ) throws -> Bool
	{
		var error:NSError?
        __syncProcessAdd( mediaIdentifier, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func syncProcessExecute( syncEvents:GnPlaylistCollectionSyncEventsDelegate ) throws -> Bool
	{
		var error:NSError?
        __syncProcessExecute( syncEvents, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func contains( mediaIdentifier:String ) throws -> Bool
	{
		var error:NSError?
        let tmp = __contains( mediaIdentifier, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func statementRequiresSeed( pdlStatement:String ) throws -> Bool
	{
		var error:NSError?
        let tmp = __statementRequiresSeed( pdlStatement, error: &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnPlaylistMoreLikeThisOptions
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func maxTracks( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __maxTracks( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getMaxTracks( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getMaxTracks( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func maxPerArtist( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __maxPerArtist( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getMaxPerArtist( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getMaxPerArtist( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func maxPerAlbum( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __maxPerAlbum( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getMaxPerAlbum( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getMaxPerAlbum( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func randomSeed( value:UInt ) throws -> Bool
	{
		var error:NSError?
        __randomSeed( value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getRandomSeed( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getRandomSeed( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnPlaylistStorage
{
	public func compact( ) throws
	{
		var error:NSError?
        __compact( &error )
		if nil != error
		{
			throw error!
		}
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func store( collection:GnPlaylistCollection ) throws -> Bool
	{
		var error:NSError?
        __store( collection, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func location( location:String ) throws -> Bool
	{
		var error:NSError?
        __location( location, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func removeWithCollection( collection:GnPlaylistCollection ) throws -> Bool
	{
		var error:NSError?
        __removeWithCollection( collection, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func removeWithCollectionName( collectionName:String ) throws -> Bool
	{
		var error:NSError?
        __removeWithCollectionName( collectionName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

}

#if GNSDK_ALL
extension GnRenderOptions
{
	public func defaultOptions() -> GnRenderOptions
	{
		var error:NSError?
		return __defaultOptions(&error)
	}
}
#endif

extension GnStorageSqlite
{
#if GNSDK_ALL
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	static public func useExternalLibrary( sqlite3_filepath:String ) throws -> Bool
	{
		var error:NSError?
        __useExternalLibrary( sqlite3_filepath, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
#endif

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func storageLocation( folderPath:String ) throws -> Bool
	{
		var error:NSError?
        __storageLocation( folderPath, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func temporaryStorageLocation( folderPath:String ) throws -> Bool
	{
		var error:NSError?
        __temporaryStorageLocation( folderPath, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func maximumCacheFileSize( maxCacheSize:UInt ) throws -> Bool
	{
		var error:NSError?
        __maximumCacheFileSize( maxCacheSize, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func maximumCacheMemory( maxMemSize:UInt ) throws -> Bool
	{
		var error:NSError?
        __maximumCacheMemory( maxMemSize, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func synchronousMode( mode:String ) throws -> Bool
	{
		var error:NSError?
        __synchronousMode( mode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func journalMode( mode:String ) throws -> Bool
	{
		var error:NSError?
        __journalMode( mode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getMaximumCacheFileSize( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getMaximumCacheFileSize( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func getMaximumCacheMemory( ) throws -> UInt
	{
		var error:NSError?
        let tmp = __getMaximumCacheMemory( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnStoreOps
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func location( location:String ) throws -> Bool
	{
		var error:NSError?
        __location( location, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func flush( bAsync:Bool ) throws -> Bool
	{
		var error:NSError?
        __flush( bAsync, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func compact( bAsync:Bool ) throws -> Bool
	{
		var error:NSError?
        __compact( bAsync, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func cleanup( bAsync:Bool ) throws -> Bool
	{
		var error:NSError?
        __cleanup( bAsync, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}
}

extension GnUser
{
	public func isLocalOnly() throws -> Bool
	{
		var error:NSError?
        let tmp = __isLocalOnly( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}

extension GnUserOptions 
{
	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func lookupMode( lookupMode:GnLookupMode ) throws -> Bool
	{
		var error:NSError?
        __lookupMode( lookupMode, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkProxy( hostname:String, username:String, password:String ) throws -> Bool
	{
		var error:NSError?
        __networkProxy( hostname, username: username, password: password, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkTimeout( timeout_ms:UInt ) throws -> Bool
	{
		var error:NSError?
        __networkTimeout( timeout_ms, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkLoadBalance( bEnable:Bool ) throws -> Bool
	{
		var error:NSError?
        __networkLoadBalance( bEnable, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func networkInterface( intfName:String ) throws -> Bool
	{
		var error:NSError?
        __networkInterface( intfName, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func userInfo( location_id:String, mfg:String, os:String, uid:String ) throws -> Bool
	{
		var error:NSError?
        __userInfo( location_id, mfg: mfg, os: os, uid: uid, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func deviceModel( model:String ) throws -> Bool
	{
		var error:NSError?
        __deviceModel( model, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func cacheExpiration( durationSec:UInt ) throws -> Bool
	{
		var error:NSError?
        __cacheExpiration( durationSec, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	/* Returns a bool instead of void as having Objective-C selector conflicts from 
     * NS_REFINED_FOR_SWIFT hidden '__' method, only with functions with same signature.
     */
	public func custom( key:String, value:String ) throws -> Bool
	{
		var error:NSError?
        __custom( key, value: value, error: &error )
		if nil != error
		{
			throw error!
		}

		return true
	}

	public func getLookupMode() throws -> GnLookupMode
	{
		var error:NSError?
		let tmp = __getLookupMode(&error)
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func getNetworkTimeout() throws -> UInt
	{
		var error:NSError?
        let tmp = __getNetworkTimeout( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func getNetworkLoadBalance() throws -> Bool
	{
		var error:NSError?
        let tmp = __getNetworkLoadBalance( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}

	public func getCacheExpiration() throws -> UInt
	{
		var error:NSError?
        let tmp = __getCacheExpiration( &error )
		if nil != error
		{
			throw error!
		}

		return tmp
	}
}
