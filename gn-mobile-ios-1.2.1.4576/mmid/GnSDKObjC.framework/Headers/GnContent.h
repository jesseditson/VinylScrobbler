/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnContent_h_
#define _GnContent_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnAsset.h"
#import "GnEnums.h"
#import "GnDataObject.h"


@class GnAssetEnumerator;


/**
* Provides access to content assets that can be retrieved from Urls.
* Content is only available is content is enabled from the original query's lookup data.
* Use the query object's options to enable content.
* The type of content that is available depends on the parent object. For example
* you can access album cover art from a GnAlbum object, but not an artist image. To
* retrieve an artist image navigate to a GnContributor object and invoke it's GnContent
* instance.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnContent object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnContent : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Id
*/
-(nullable NSString*) id;

/**
*  Content type - cover art, biography, etc.
*  @return Content type
*/ 

-(GnContentType) contentType;

/**
*  Content's mime type
*  @return Mime type
*/ 

-(nullable NSString*) mimeType;

/**
* Asset by image size (if applicable)
* @param imageSize	[in] Image size
* @return Asset object
*/ 

-(nullable GnAsset*) asset: (GnImageSize)imageSize;

/**
* Iterator for the external third-party IDs (e.g., Amazon's)  associated with this contributor.
* @return Iterator
*/ 

-(GnAssetEnumerator*) assets;


NS_ASSUME_NONNULL_END

@end


@interface GnContentEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnContentBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnContentBlock)handler;

-(NSUInteger) count;

-(nullable GnContent*) nextObject;

-(nullable GnContent*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnContent_h_ */

