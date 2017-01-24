/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnDataObject_h_
#define _GnDataObject_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnDataObject.h"
#import "GnEnums.h"
#import "GnLocale.h"
#import "GnRenderOptions.h"




/**
* Gracenote Data Object - encapsulation of GNSDK delivered media elements and metadata.
*/ 

@interface GnDataObject : NSObject

NS_ASSUME_NONNULL_BEGIN

/**
* GnDataObject
*/
-(nullable INSTANCE_RETURN_TYPE) init;

/**
* GnDataObject
*/
-(nullable INSTANCE_RETURN_TYPE) initWithDataObject: (nonnull GnDataObject*)dataObject;

/**
* GnDataObject
*/
-(nullable INSTANCE_RETURN_TYPE) initWithId: (nullable NSString*)id idTag: (nullable NSString*)idTag idSrc: (nullable NSString*)idSrc error: (NSError**)error;

/**
* GnDataObject
*/
-(nullable INSTANCE_RETURN_TYPE) initWithId: (nullable NSString*)id idTag: (nullable NSString*)idTag idSrcEnum: (GnIDSource)idSrcEnum error: (NSError**)error;

/**
* Mapping SOURCE_ID to string in the constructor
*/ 

-(nullable NSString*) iDSource: (GnIDSource)IDSourceEnum;

/**
*  Deserialize GNSDK data object
*  @param serializedGdo	[in] Serialized Gracenote data object string
*  @return Gracenote data object
*/ 

+(nullable GnDataObject*) deserialize: (nullable NSString*)serializedGdo error: (NSError**)error;

/**
*  Create Gracenote Data Object from XML
*  @param xml	[in] XML string
*  @return Gracenote data object
*/ 

+(nullable GnDataObject*) createFromXml: (nullable NSString*)xml error: (NSError**)error;

/**
*  Serialize this object
*  @return Serialize Gracenote data object string
*/ 

-(nullable NSString*) serialize: (NSError**)error;

/**
* Returns count of the metadata values available for the key.
* @param valueKey      [in] Key of the value count to return
* @return count
*/ 

-(NSUInteger) stringValueCount: (nullable NSString*)valueKey;

/**
* Returns media or metadata value as a string based on the provided key and ordinal.
* @param valueKey      [in] Key of the value to return
* @param ordinal		[in] 1-based specifier of a value where multiple values for a key exist
* @return Value
*/ 

-(nullable NSString*) stringValue: (nullable NSString*)valueKey ordinal: (NSUInteger)ordinal;

/**
* Returns media or metadata value as an integer based on the provided key and ordinal.
* @param valueKey      [in] Key of the value to return
* @param ordinal		[in] 1-based specifier of a value where multiple values for a key exist
* @return Value
*/ 

-(NSInteger) intValue: (nullable NSString*)valueKey ordinal: (NSUInteger)ordinal;

/**
* Child data object specified by the key and ordinal
* @param childKey      [in] Child key to return
* @param childOrdinal	[in] 1-based specifier of a child where multiple values for a key exist
*
* <p><b>Remarks:</b></p>
* Use this function to count children of a specific data instance; note that only those children
* accessible in the current type are considered.
*/ 

-(nullable GnDataObject*) child: (nullable NSString*)childKey childOrdinal: (NSUInteger)childOrdinal;

/**
* Renders contents of the data object as an XML string.
* @param options	[in] Render options object
* @return Rendered output string
*/ 

-(nullable NSString*) render: (nonnull GnRenderOptions*)options error: (NSError**)error;

/**
* Applies lists to use for retrieving and rendering locale-related values.
* @param	locale Locale to apply to this data object
* <p><b>Remarks:</b></p>
* Use this function to set the locale of retrieved and rendered locale-dependent data for this
* data object. This function overrides any applicable global locale defaults set elsewhere.
* <p><b>Locale Language Support</b></p>
* This function supports all locale languages and successfully assigns a locale for this data object.
* The locale is used for future calls to get data values when locale-dependent values are requested.
*
* When list-based locale-specific values are requested from this data object they are returned
* only if an applicable locale has been successfully set by this method or a default locale has been
* successfully set elsehwere.
*
* When a non-list-based locale-specific values are requested from this data object they are returned
* only if these values are available from Gracenote Service or the locale database (where online queries
* are not accessible or permitted). If not, the application uses the default (or "official") locale data for
* these values. For example, plot values are non-list-based. If a plot summary value is available only in the
* English language, and the specific locale is defined for the Spanish language, the application
* displays the plot summary in the English language.
*/ 

-(void) locale: (nonnull GnLocale*)locale error: (NSError**)error NS_REFINED_FOR_SWIFT;

/**
* Data object's type.
* @return Type string
* <p><b>Remarks:</b></p>
* The data object's contents are not clearly defined. Use this API to retrieve a data object's type,
* as this enables the application to more accurately determine what data the specific data it contains.
* Typically an application will use data objects subclassed from the data object, which do specifically
* define a type.
*/ 

-(nullable NSString*) getType: (NSError**)error;

/**
*  Flag indicating if object is specified type
*  @param strType	[in] Type string
*  @return True if object is if provided type, false otherwise
*/ 

-(BOOL) isType: (nullable NSString*)strType error: (NSError**)error NS_SWIFT_NOTHROW NS_REFINED_FOR_SWIFT;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnDataObject_h_ */

