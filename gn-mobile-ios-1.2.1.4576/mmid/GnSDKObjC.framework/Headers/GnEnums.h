/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GNENUMS_H_
#define _GNENUMS_H_




/***************************************
* GnLookupMode
*/
typedef enum : NSInteger
{
    /**
    * Invalid lookup mode
    */
    kLookupModeInvalid = 0,
    
    /**
    * This mode forces the lookup to be done against the local database only. Local caches created from (online) query
    * results are not queried in this mode.
    * If no local database exists, the query will fail.
    */
    kLookupModeLocal,
    
    /**
    * This is the default lookup mode. If a cache exists, the query checks it first for a match.
    * If a no match is found in the cache, then an online query is performed against Gracenote Service.
    * If a result is found there, it is stored in the local cache.  If no online provider exists, the query will fail.
    * The length of time before cache lookup query expires can be set via the user object.
    */
    kLookupModeOnline,
    
    /**
    * This mode forces the query to be done online only and will not perform a local cache lookup first.
    * If no online provider exists, the query will fail. In this mode online queries and lists are not
    * written to local storage, even if a storage provider has been initialize.
    */
    kLookupModeOnlineNoCache,
    
    /**
    * This mode forces the query to be done online only and will not perform a local cache lookup first.
    * If no online provider exists, the query will fail. If a storage provider has been initialized,
    * queries and lists are immediately written to local storage, but are never read unless the lookup mode is changed.
    */
    kLookupModeOnlineNoCacheRead,
    
    /**
    * This mode forces the query to be done against the online cache only and will not perform a network lookup.
    * If no online provider exists, the query will fail.
    */
    kLookupModeOnlineCacheOnly
    
} GnLookupMode;


/***************************************
* GnLookupData
*/
typedef enum : NSInteger
{
    /**
    * Invalid lookup data
    */
    kLookupDataInvalid = 0,
    
    /**
    * Response should include data for use in fetching content (like images).
    * <p><b>Remarks:</b></p>
    * Your application's client ID must be entitled to retrieve this specialized data. See your
    *	Gracenote representative for more information.
    */
    kLookupDataContent,
    
    /**
    * Response should include any associated classical music data.
    * <p><b>Remarks:</b></p>
    * Your application's license must be entitled to retrieve this specialized data. See your
    * Gracenote representative for more information.
    */
    kLookupDataClassical,
    
    /**
    * Response should include any associated sonic attribute data.
    * <p><b>Remarks:</b></p>
    * Your application's license must be entitled to retrieve this specialized data. See your
    * Gracenote representative for more information.
    */
    kLookupDataSonicData,
    
    /**
    * Response should include associated attribute data for GNSDK Playlist.
    * <p><b>Remarks:</b></p>
    * Your application's license must be entitled to retrieve this specialized data. See your
    * Gracenote representative for more information.
    */
    kLookupDataPlaylist,
    
    /**
    * Response should include external IDs (third-party IDs).
    * <p><b>Remarks:</b></p>
    * External IDs are third-party IDs associated with the results (such as an Amazon ID),
    *	configured specifically for your application.
    * Your application's client ID must be entitled to retrieve this specialized data. See your
    * Gracenote representative for more information.
    * External IDs can be retrieved from applicable query response objects.
    */
    kLookupDataExternalIds,
    
    /**
    * Response should include global IDs.
    */
    kLookupDataGlobalIds,
    
    /**
    * Response should include additional credits.
    */
    kLookupDataAdditionalCredits,
    
    /**
    * Response should include sortable data for names and titles
    */
    kLookupDataSortable
    
} GnLookupData;


/***************************************
* GnThreadPriority
*/
typedef enum : NSInteger
{
    kThreadPriorityInvalid = 0,
    
    /**
    * Use of default thread priority.
    */
    kThreadPriorityDefault,
    
    /**
    * Use idle thread priority.
    */
    kThreadPriorityIdle,
    
    /**
    * Use low thread priority (default).
    */
    kThreadPriorityLow,
    
    /**
    * Use normal thread priority.
    */
    kThreadPriorityNormal,
    
    /**
    * Use high thread priority.
    */
    kThreadPriorityHigh
    
} GnThreadPriority;


/***************************************
* GnFingerprintType
*/
typedef enum : NSInteger
{
    /**
    * Invalid fingerprint type
    */
    kFingerprintTypeInvalid = 0,
    
    /**
    * Specifies a fingerprint data type for generating MusicID-File fingerprints.
    * <p><b>Remarks:</b></p>
    * A file's beginning 16 seconds are used for a MusicID-File fingerprint.
    * <p><b>Note:</b></p>
    * Do NOT submit only 16 seconds of a file - your
    * application must submit data until the GNSDK indicates it has received enough input.
    * Use this fingerprint type when identifying audio from a file source (MusicID-File).
    */
    kFingerprintTypeFile,
    
    /**
    *  Specifies a fingerprint used for identifying a ~3-second audio stream excerpt.
    *  Use this when identifying a continuous stream of audio data and when retrieving
    *  Track Match Position values. The fingerprint represents a
    *  specific audio stream point in time.
    *  <p><b>Note:</b></p>
    *  Do NOT submit only 3 seconds of audio data - your
    *  application must submit audio data until the GNSDK indicates it has received enough input.
    *  You must use this fingerprint, or its 6-second counterpart, to get results containing match position.
    *  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries
    *  of this type will not succeed.
    */
    kFingerprintTypeStream3,
    
    /**
    *  Specifies a fingerprint used for identifying a ~6-second audio stream excerpt.
    *  This is the same as kFingerprintTypeStream3, but requires more audio data to generate,
    *  which can be more accurate.
    *  For additional information, see kFingerprintTypeStream3.
    */
    kFingerprintTypeStream6,
    
    /**
    *  Specifies a fingerprint to identify an audio stream.
    *  The usage of this type of fingerprint must be configured to your specific User ID, otherwise queries
    *  of this type will not succeed.
    */
    kFingerprintTypeStreamFP,
    
    /**
    * @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
    *      Use kFingerprintTypeFile instead.
    */
    kFingerprintTypeCMX,
    
    /**
    * @deprecated NB: This key has been marked as deprecated and will be removed from the next major release.
    *      Use kFingerprintTypeStream3 or kFingerprintTypeStream6 instead.
    */
    kFingerprintTypeGNFPX
    
} GnFingerprintType;


/***************************************
* GnStatus
*/
typedef enum : NSInteger
{
    /** @internal kStatusUnknown @endinternal
    * Status unknown.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusUnknown = 0,
    
    /* Basic messages */
    
    /** @internal kStatusBegin @endinternal
    * Function call has begun, percentage complete == 0.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusBegin,
    
    /** @internal kStatusProgress @endinternal
    * Function call in progress. Issued 10 times per call. Percentage complete range == 1-100.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusProgress,
    
    /** @internal kStatusComplete @endinternal
    * Function call is complete.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusComplete,
    
    /** @internal kStatusErrorInfo @endinternal
    * Error has occurred, call #gnsdk_manager_error_info().
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusErrorInfo,
    
    /* Advanced messages */
    
    /** @internal kStatusConnecting @endinternal
    * Connecting to network.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusConnecting,
    
    /** @internal kStatusSending @endinternal
    * Uploading.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusSending,
    
    /** @internal kStatusReceiving @endinternal
    * Downloading.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusReceiving,
    
    /** @internal kStatusDisconnected @endinternal
    * Disconnected from network.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusDisconnected,
    
    /** @internal kStatusReading @endinternal
    * Reading from storage.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusReading,
    
    /** @internal kStatusWriting @endinternal
    * Writing to storage.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusWriting,            /* issued whenever writing to storage. */
    
    /** @internal gnsdk_status_cancelled @endinternal
    * Transaction/query is cancelled.
    * @ingroup StatusCallbacks_TypesEnums
    */
    kStatusCancelled
    
} GnStatus;


/***************************************
* GnLanguage
*/
typedef enum : NSInteger
{
    kLanguageInvalid = 0,
    
    kLanguageArabic,
    kLanguageBulgarian,
    kLanguageChineseSimplified,
    kLanguageChineseTraditional,
    kLanguageCroatian,
    kLanguageCzech,
    kLanguageDanish,
    kLanguageDutch,
    kLanguageEnglish,
    kLanguageFarsi,
    kLanguageFinnish,
    kLanguageFrench,
    kLanguageGerman,
    kLanguageGreek,
    kLanguageHungarian,
    kLanguageIndonesian,
    kLanguageItalian,
    kLanguageJapanese,
    kLanguageKorean,
    kLanguageNorwegian,
    kLanguagePolish,
    kLanguagePortuguese,
    kLanguageRomanian,
    kLanguageRussian,
    kLanguageSerbian,
    kLanguageSlovak,
    kLanguageSpanish,
    kLanguageSwedish,
    kLanguageThai,
    kLanguageTurkish,
    kLanguageVietnamese,
    kLanguageLithuanian,
    kLanguageLatvian,
    kLanguageEstonian,
    kLanguageUkrainian
} GnLanguage;


/***************************************
* GnRegion
*/
typedef enum : NSInteger
{
    /** Default region. A region will be selected based on what's available. */
    kRegionDefault = 0,
    
    /** Global */
    kRegionGlobal,
    
    /** United States */
    kRegionUS,
    
    /** Japan */
    kRegionJapan,
    
    /** China  */
    kRegionChina,
    
    /** Taiwan */
    kRegionTaiwan,
    
    /** Korea */
    kRegionKorea,
    
    /** Europe */
    kRegionEurope,
    
    /** Deprecated, will be removed in a future release, use kRegionUS. */
    kRegionNorthAmerica,
    
    /** Latin America */
    kRegionLatinAmerica,
    
    /** India */
    kRegionIndia
} GnRegion;


/***************************************
* GnDescriptor
*/
typedef enum : NSInteger
{
    kDescriptorDefault = 0,
    kDescriptorSimplified,
    kDescriptorDetailed
} GnDescriptor;


/***************************************
* GnContentType
*/
typedef enum : NSInteger
{
    kContentTypeNull = 0,
    kContentTypeUnknown = 1,
    
    kContentTypeImageCover,
    kContentTypeImageArtist,
    kContentTypeImageVideo,
    kContentTypeImageLogo,
    kContentTypeBiography,
    kContentTypeReview,
    kContentTypeNews,
    kContentTypeArtistNews,
    kContentTypeListenerComments,
    kContentTypeReleaseComments
} GnContentType;


/***************************************
* GnImageSize
*/
typedef enum : NSInteger
{
    kImageSizeUnknown = 0,
    
    kImageSize75,
    kImageSize110,
    kImageSize170,
    kImageSize220,
    kImageSize300,
    kImageSize450,
    kImageSize720,
    kImageSize1080,
    
    /* Size aliases */
    kImageSizeThumbnail = kImageSize75,
    kImageSizeSmall     = kImageSize170,
    kImageSizeMedium    = kImageSize450,
    kImageSizeLarge     = kImageSize720,
    kImageSizeXLarge    = kImageSize1080
    
} GnImageSize;


/***************************************
* GnConfigOptionAccess
*/
typedef enum : NSInteger
{
    kConfigOptionAccessInvalid = 0,
    
    kConfigOptionAccessLookupDatabaseReadOnly,
    kConfigOptionAccessLookupDatabaseReadWrite
    
} GnConfigOptionAccess;


/***************************************
* GnConfigOptionEnable
*/
typedef enum : NSInteger
{
    kConfigOptionEnableInvalid = 0,
    
    kConfigOptionEnableLookupDatabaseAll,
    kConfigOptionEnableLookupDatabaseMusicID,
    kConfigOptionEnableLookupDatabaseMusicIDText,
    kConfigOptionEnableLookupDatabaseMusicIDCD,
    kConfigOptionEnableLookupDatabaseMusicIDImages,
    kConfigOptionEnableLookupDatabaseEpgRadio,
    kConfigOptionEnableLookupDatabaseEpgTV
    
} GnConfigOptionEnable;


/***************************************
* GnConfigOptionLocation
*/
typedef enum : NSInteger
{
    kConfigOptionLocationInvalid = 0,
    
    kConfigOptionLocationLookupDatabaseAll,
    kConfigOptionLocationLookupDatabaseContent,
    kConfigOptionLocationLookupDatabaseMetadata,
    kConfigOptionLocationLookupDatabaseTocIndex,
    kConfigOptionLocationLookupDatabaseTextIndex,
    kConfigOptionLocationLookupDatabaseEpg
    
} GnConfigOptionLocation;


/***************************************
* GnLicenseInputMode
*/
typedef enum : NSInteger
{
    kLicenseInputModeInvalid = 0,
    
    /**
    * Submit license content as string
    */
    kLicenseInputModeString,
    
    /**
    * Submit license content in file
    */
    kLicenseInputModeFilename,
    
    /**
    * Submit license content from stdin
    */
    kLicenseInputModeStandardIn
} GnLicenseInputMode;


/***************************************
* GnUserRegisterMode
*/
typedef enum : NSInteger
{
    /**
    * Register a user via a netowrk connection with Gracenote Service. A user
    * must be registered online before any online queries can be made against the
    * Gracenote Service.
    */
    kUserRegisterModeOnline = 1,
    
    /**
    * Register a user for local use only. Users registered locally can only
    * perform queries against local databases and not against the Gracenote
    * Service.
    */
    kUserRegisterModeLocalOnly
} GnUserRegisterMode;


/***************************************
* GnListType
*/
typedef enum : NSInteger
{
    kListTypeInvalid = 0,
    
    /**
    * This list contains languages that are supported by Gracenote, and are typically used to indicate
    * the original language of an item.
    */
    kListTypeLanguages,
    
    /**
    * This list contains scripts that are supported by Gracenote
    */
    kListTypeScripts,
    
    /**
    * The list of supported music genres.
    * <p><b>Remarks:</b></p>
    * The genre list contains a hierarchy of genres available from Gracenote strictly for music data.
    */
    kListTypeGenres,
    
    /**
    * The list of supported geographic origins for artists.
    */
    kListTypeOrigins,
    
    /**
    * The list of supported music era categories.
    */
    kListTypeEras,
    
    /**
    * The list of supported artist type categories.
    */
    kListTypeArtistTypes,
    
    /**
    * This list contains role list elements supported Gracenote for album data, such as Vocalist and Bass Guitar.
    */
    kListTypeRoles,
    
    /**
    *  This list contains a hierarchy of genre list elements available from Gracenote, strictly for
    * video data.
    */
    kListTypeGenreVideos,
    
    /**
    * This list contains movie rating list elements supported by Gracenote.
    */
    kListTypeRatings,
    
    /**
    * This list contains film content rating list elements supported by Gracenote.
    */
    kListTypeRatingTypes,
    
    /**
    * This list contains contributor role list elements available from Gracenote, such as Actor or
    * Costume Design. These apply to video data.
    */
    kListTypeContributors,
    
    /**
    * The list of supported feature types for video data.
    */
    kListTypeFeatureTypes,
    
    /**
    *  The list of supported video regions.
    */
    kListTypeVideoRegions,
    
    /**
    * The list of supported video types, such as Documentary, Sporting Event, or Motion Picture.
    */
    kListTypeVideoTypes,
    
    /**
    * The list of supported media types for music and video, such as Audio CD, Blu-ray, DVD, or HD DVD.
    */
    kListTypeMediaTypes,
    
    /**
    * The list of supported video serial types, such as Series or Episode.
    */
    kListTypeVideoSerialTypes,
    
    /**
    * The list of supported work types for video data, such as Musical or Image.
    */
    kListTypeWorkTypes,
    
    /**
    * The list of supported media spaces for video data, such as Music, Film, or Stage.
    */
    kListTypeMediaSpaces,
    
    /**
    * The list of supported moods for music data. Moods are categorized into levels, from more general
    * (Level 1, such as Blue) to more specific (Level 2, such as Gritty/Earthy/Soulful).
    */
    kListTypeMoods,
    
    /**
    * The list of supported tempos for music data, has three levels of granularity.
    * The tempos are categorized in levels in increasing order of granularity.
    * Level 1: The meta level, such as Fast Tempo.
    * Level 2: The sub tempo level, such as Very Fast.
    * Level 3: The micro level, which may be displayed as a numeric tempo range, such as 240-249, or a
    * descriptive phrase.
    */
    kListTypeTempos,
    
    /**
    * The list of supported composition forms for classical music.
    */
    kListTypeCompostionForm,
    
    /**
    * The list of supported instrumentation for classical music.
    */
    kListTypeInstrumentation,
    
    /**
    * The list of supported overall story types for video data, such as Love Story.
    * It includes general theme classifications such as such as Love Story, Family Saga, Road Trip,
    * and Rags to Riches.
    */
    kListTypeVideoStoryType,
    
    /**
    * The list of supported audience types for video data.
    * It includes general audience classifications by age, ethnicity, gender, and spiritual beliefs,
    * such as Kids & Family, African-American, Female, Gay & Lesbian, and Buddhist.
    */
    kListTypeVideoAudience,
    
    /**
    * The list of supported moods for video data, such as Offbeat.
    * It includes general classifications such as such as Offbeat, Uplifting, Mystical, and Sarcastic.
    */
    kListTypeVideoMood,
    
    /**
    * The list of supported film reputation types for video data, such as Classic.
    * It includes general classifications such as such as Classic, Chick Flick, and Cult.
    */
    kListTypeVideoReputation,
    
    /**
    * The list of supported scenarios for video data. It
    * includes general classifications such as such as Action, Comedy, and Drama.
    */
    kListTypeVideoScenario,
    
    /**
    * The language of the list is determined by the language value given to
    */
    kListTypeVideoSettingEnv,
    
    /**
    * The list of supported historical time settings for video data, such as Elizabethan Era,
    * 1558-1603, or Jazz Age, 1919-1929.
    */
    kListTypeVideoSettingPeriod,
    
    /**
    * The list of supported story concept sources for video data, such as Fairy Tales & Nursery Rhymes.
    * It includes story source classifications such as Novel, Video Game, and True Story.
    */
    kListTypeVideoSource,
    
    /**
    * The list of supported film style types for video data, such as Film Noir.It
    * includes general style classifications such as Art House, Film Noir, and Silent.
    */
    kListTypeVideoStyle,
    
    /**
    * The list of supported film topics for video data, such as Racing or Teen Angst. It includes a diverse
    * range of film topics, such as Politics, Floods, Mercenaries, Surfing, and Adventure. It also includes
    * some list elements that can be considered sub-topics of a broader topic. For example, the list element Aliens (the broad topic),
    * and Nice Aliens and Bad Aliens (the more defined topics).
    */
    kListTypeVideoTopic,
    
    /**
    * The list of supported viewing types for EPG data, such as live and rerun.
    */
    kListTypeEpgViewingTypes,
    
    /**
    * The list of supported audio types for EPG data, such as stereo and dolby.
    */
    kListTypeEpgAudioTypes,
    
    /**
    * The list of supported video types for EPG data, such as HDTV and PAL30.
    */
    kListTypeEpgVideoTypes,
    
    /**
    * The list of supported video types for EPG data, such as closed caption.
    */
    kListTypeEpgCaptionTypes,
    
    /**
    * The list of supported categories for IPG data, such as movie and TV series.
    */
    kListTypeIpgCategoriesL1,
    
    /**
    * The list of supported categories for IPG data, such as action and adventure.
    */
    kListTypeIpgCategoriesL2,
    
    /**
    * The list of supported production types for EPG data, such as news and documentary.
    */
    kListTypeEpgProductionTypes,
    
    /**
    * The list of supported device types for EPG data.
    */
    kListTypeEpgDeviceTypes
} GnListType;


/***************************************
* GnListRenderFormat
*/
typedef enum : NSInteger
{
    kListRenderFormat_Invalid,
    
    /**
    * Render list to XML format
    */
    kListRenderFormat_XML,
    kListRenderFormat_XMLv2,
    
    /**
    * Render list to JSON format
    */
    kListRenderFormat_JSON,
    kListRenderFormat_JSONv2
} GnListRenderFormat;


/***************************************
* GnListRenderFlags
*/
typedef enum : NSInteger
{
    kListRenderDefault,
    
    /**
    * Minimal information included.
    */
    kListRenderMinimal,
    
    /**
    * All information included.
    */
    kListRenderFull
} GnListRenderFlags;


/***************************************
* GnLocaleGroup
*/
typedef enum : NSInteger
{
    /**
    * Invalid locale group
    */
    kLocaleGroupInvalid = 0,
    
    /**
    * Locale group for the GNSDK music products. Set this when creating a locale used with the MusicID and MusicID -File libraries.
    */
    kLocaleGroupMusic,
    
    /**
    * Locale group for the GNSDK video products. Set this when creating a locale used with the VideoID or Video Explore libraries (or both).
    */
    kLocaleGroupVideo,
    
    /**
    * Locale group for the GNSDK Playlist product. Set this when creating a locale used with the Playlist library.
    */
    kLocaleGroupPlaylist,
    
    /**
    * Locale group for the GNSDK EPG product. Set this when creating a locale used with the EPG library.
    */
    kLocaleGroupEpg,
    
    /**
    * Locale group for the GNSDK ACR products. Set this when creating a locale used with the ACR library.
    * Additionally, this will set the locale value for the MusicID, VideoID, VideoExplore and EPG libraries
    * that ACR uses.
    *
    * <p><b>Remarks:</b></p>
    * If kLocaleGroupAcr is set <i>after</i> kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set, then kLocaleGroupAcr
    * will override any previous locale settings used with the MusicID, VideoID/VideoExplore and EPG libraries, and set the locale
    * for all of those libraries to the same locale value.
    *
    * If kLocaleGroupMusic, kLocaleGroupVideo or kLocaleGroupEpg is set <i>after</i> kLocaleGroupAcr is set, then it will override
    * the locale value previously set by kLocaleGroupAcr for the MusicID, VideoID/VideoExplore or EPG libraries, respectively.
    */
    kLocaleGroupAcr
} GnLocaleGroup;


/***************************************
* GnLogMessageType
*/
typedef enum : NSInteger
{
    kLoggingMessageTypeInvalid = 0,
    
    kLoggingMessageTypeError,
    kLoggingMessageTypeWarning,
    kLoggingMessageTypeInfo,
    kLoggingMessageTypeDebug
    
} GnLogMessageType;


/***************************************
* GnLogPackageType
*/
typedef enum : NSInteger
{
    kLogPackageAll = 1,
    kLogPackageAllGNSDK,
    
    kLogPackageManager,
    kLogPackageMusicID,
    kLogPackageMusicIDFile,
    kLogPackageMusicIDStream,
    kLogPackageMusicIdMatch,
    kLogPackageVideoID,
    kLogPackageLink,
    kLogPackageDsp,
    kLogPackageAcr,
    kLogPackageEPG,
    kLogPackageSubmit,
    kLogPackageTaste,
    kLogPackageRhythm,
    kLogPackagePlaylist,
    kLogPackageStorageSqlite,
    kLogPackageStorageQNX,
    kLogPackageLookupLocal,
    kLogPackageLookupFPLocal,
    kLogPackageLookupLocalStream,
    kLogPackageEDBInstall,
    kLogPackageMoodGrid,
    kLogPackageCorrelates,
    kLogPackageInternal,
    kLogPackageRadio
} GnLogPackageType;


/***************************************
* GnLocalStreamEngineType
*/
typedef enum : NSInteger
{
    kLocalStreamEngineInvalid = 0,
    
    /**
    * Sets lookup local stream library to operate in memory-mapped mode.
    * Memory-mapped mode uses a memory-mapped file - the OS loads a portion of this file
    * into memory as it is accessed by an  application, which leads to overall lower peak memory
    * usage than in-memory mode.
    */
    kLocalStreamEngineMMap,
    
    /**
    * Sets lookup local stream library to operate in in-memory mode. This is faster, but
    * for mobile devices the amount of memory needed may be prohibitive.
    */
    kLocalStreamEngineInMemory
} GnLocalStreamEngineType;


/***************************************
* GnLocalStreamFingerprintProcessingMethod
*/
typedef enum : NSInteger
{
    kLocalStreamFingeprintProcessingInvalid = 0,
    
    /**
    * Only use the CPU for local fingerprint comparison.
    */
    kLocalStreamFingeprintProcessingUseCPU,
    
    /**
    * Use the GPU (if available) for local fingerprint comparison. The GPU is likely
    * faster than using the CPU, but if your app is doing lots of intense graphics it
    * may cause a "stutter" in displayed graphics.
    */
    kLocalStreamFingeprintProcessingUseGPU,
    
    /**
    * Use CUDA on the GPU (if available) for local fingerprint comparison. The GPU is likely
    * faster than using the CPU, but if your app is doing lots of intense graphics it
    * may cause a "stutter" in displayed graphics.
    */
    kLocalStreamFingeprintProcessingUseGPU_CUDA
} GnLocalStreamFingerprintProcessingMethod;


/***************************************
* GnLookupLocalStreamIngestStatus
*/
typedef enum : NSInteger
{
    kIngestStatusInvalid = 0,
    kIngestStatusItemBegin,
    kIngestStatusItemAdd,
    kIngestStatusItemDelete
} GnLookupLocalStreamIngestStatus;


/***************************************
* GnMoodgridPresentationType
*/
typedef enum : NSInteger
{
    kMoodgridPresentationType5x5   = 0x0505,
    kMoodgridPresentationType10x10 = 0x0A0A
    
} GnMoodgridPresentationType;


/***************************************
* GnMoodgridCoordinateType
*/
typedef enum : NSInteger
{
    kMoodgridCoordinateTopLeft,
    kMoodgridCoordinateBottomLeft
    
} GnMoodgridCoordinateType;


/***************************************
* GnMoodgridFilterConditionType
*/
typedef enum : NSInteger
{
    kConditionTypeInclude = 1,
    kConditionTypeExclude
    
} GnMoodgridFilterConditionType;


/***************************************
* GnMoodgridFilterListType
*/
typedef enum : NSInteger
{
    kMoodgridListTypeGenre = 1,
    kMoodgridListTypeOrigins,
    kMoodgridListTypeEras
    
} GnMoodgridFilterListType;


/***************************************
* GnMusicIdFileInfoStatus
*/
typedef enum : NSInteger
{
    /**
    * FileInfo has not been processed.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusUnprocessed  = 0,
    
    
    /**
    * FileInfo is currently being processed.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusProcessing   = 1,
    
    
    /**
    * An error occurred while processing the FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusError      = 2,
    
    
    /**
    * No results were found for FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusResultNone   = 3,
    
    
    /**
    * Single preferred response available for FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusResultSingle = 4,
    
    
    /**
    * All retrieved results available for FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileInfoStatusResultAll  = 5
    
} GnMusicIdFileInfoStatus;


/***************************************
* GnMusicIdFileCallbackStatus
*/
typedef enum : NSInteger
{
    /**
    *
    *   MusicID-File processing is beginning for a given FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileCallbackStatusProcessingBegin    = 0x100,
    
    
    /**
    *
    *   Performing a Gracenote query for given FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileCallbackStatusFileInfoQuery      = 0x150,
    
    
    /**
    *
    *   MusicID-File processing is complete for a given FileInfo.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileCallbackStatusProcessingComplete = 0x199,
    
    /**
    *
    *   MusicID-File processing for a given FileInfo has encountered an
    *   error.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileCallbackStatusProcessingError    = 0x299,
    
    
    /**
    *
    *   An error in MusicID-File querying or processing has occurred.
    * @ingroup Music_MusicIDFile_TypesEnums
    */
    kMusicIdFileCallbackStatusError              = 0x999
    
} GnMusicIdFileCallbackStatus;


/***************************************
* GnMusicIdFileProcessType
*/
typedef enum : NSInteger
{
    kQueryReturnSingle = 1,
    kQueryReturnAll
    
} GnMusicIdFileProcessType;


/***************************************
* GnMusicIdFileResponseType
*/
typedef enum : NSInteger
{
    kResponseAlbums = 1,
    kResponseMatches
    
} GnMusicIdFileResponseType;


/***************************************
* GnMusicIdStreamProcessingStatus
*/
typedef enum : NSInteger
{
    kStatusProcessingInvalid = 0,
    
    kStatusProcessingAudioNone,
    kStatusProcessingAudioSilence,
    kStatusProcessingAudioNoise,
    kStatusProcessingAudioSpeech,
    kStatusProcessingAudioMusic,
    
    kStatusProcessingTransitionNone,
    kStatusProcessingTransitionChannelChange,
    kStatusProcessingTransitionContentToContent,
    
    kStatusProcessingErrorNoClassifier,
    
    kStatusProcessingAudioStarted,
    kStatusProcessingAudioEnded
} GnMusicIdStreamProcessingStatus;


/***************************************
* GnMusicIdStreamIdentifyingStatus
*/
typedef enum : NSInteger
{
    /** Invalid status
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingInvalid = 0,
    
    
    /** Identification query started
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingStarted,
    
    /** Fingerprint generated for sample audio
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingFpGenerated,
    
    /** Local query started for identification
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingLocalQueryStarted,
    
    /** Local query ended for identification
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingLocalQueryEnded,
    
    /** Online query started for identification
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingOnlineQueryStarted,
    
    /** Online query ended for identification
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingOnlineQueryEnded,
    
    /** Identification query ended
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingEnded,
    
    /** Identification query completed with existing match
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kStatusIdentifyingNoNewResult
    
} GnMusicIdStreamIdentifyingStatus;


/***************************************
* GnMusicIdStreamPreset
*/
typedef enum : NSInteger
{
    kPresetInvalid = 0,
    
    /** Application type mobile, i.e. audio is captured by microphone
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kPresetMicrophone,
    
    /** Application type radio, i.e. audio is captured at source (e.g. speaker)
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kPresetRadio
} GnMusicIdStreamPreset;


/***************************************
* GnMusicIdStreamText
*/
typedef enum : NSInteger
{
    /** No text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextNone = 0,
    
    /** Accompanying text from shoutcast stream
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextShoutcast,
    
    /** Accompanying RDS RT Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextRdsRt,
    
    /** Accompanying RDS PTY Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextRdsPty,
    
    /** Accompanying RDS PI Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextRdsPi,
    
    /** Accompanying Artist Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextArtist,
    
    /** Accompanying Track Title Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextTrackTitle,
    
    /** Accompanying Album Title Text
    * @ingroup Music_MusicIDStream_TypesEnums
    */
    kTextAlbumTitle
    
} GnMusicIdStreamText;


/***************************************
* GnPlaylistEventsIdentiferStatus
*/
typedef enum : NSInteger
{
    /**
    * The corresponding identifier's status is unknown, the default state
    */
    kIdentifierStatusUnknown = 0,
    
    /**
    * The corresponding identifier is new, meaning it has been added to the
    * user's media collection and needs to be added to the Collection Summary
    */
    kIdentifierStatusNew     = 10,
    
    /**
    * The corresponding identifier is old, meaning it has been deleted from
    * the user's media collection and needs to be removed from the
    * Collection Summary
    */
    kIdentifierStatusOld     = 20
    
} GnPlaylistEventsIdentiferStatus;


/***************************************
* GnDataLevel
*/
typedef enum : NSInteger
{
    kDataLevelInvalid = 0,
    
    kDataLevel_1      = 1,  /* least granular */
    kDataLevel_2,
    kDataLevel_3,
    kDataLevel_4            /* most granular */
    
} GnDataLevel;


/***************************************
* GnIDSource
*/
typedef enum : NSInteger
{
    kIDSourceInvalid 	= 0,
    
    kIDSourceTrack      = 1,
    kIDSourceContributor,
    kIDSourceVideoWork,
    kIDSourceVideoProduct,
    kIDSourceVideoDisc,
    kIDSourceVideoSeason,
    kIDSourceVideoSeries,
    kIDSourceVideoTvProgram,
    kIDSourceLyric,
    kIDSourceCddbId
} GnIDSource;


#endif /* _GNENUMS_H_ */

