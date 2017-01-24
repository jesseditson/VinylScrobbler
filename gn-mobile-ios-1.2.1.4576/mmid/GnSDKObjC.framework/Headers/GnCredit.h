/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnCredit_h_
#define _GnCredit_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnContributor.h"
#import "GnDataObject.h"
#import "GnName.h"
#import "GnRole.h"




/**
* Lists the contribution of a person (or occasionally a company, such as a record label)
* to a recording.
*
* <p><b>SDK Documentation</b></p>
*
* Topic:  Data Models
*
*  The above topic displays all the metadata returned from a recognition event,
*  including objects containing a GnCredit object.
*  It does this in an expand/collapse format, showing object hierarchy and
*  a description of each field returned.
*
*/ 

@interface GnCredit : GnDataObject

NS_ASSUME_NONNULL_BEGIN

-(INSTANCE_RETURN_TYPE) init __attribute__((unavailable("init not available, use initWith instead")));

/**
* Credit's name, such as the name of the person or company.
* @return Name
*/ 

-(nullable GnName*) name;

/**
* Credit's role
* @return Role
* <p><b>Remarks:</b></p>
* This is a list-based value requiring that a corresponding locale or list be loaded.
*/ 

-(nullable GnRole*) role;

/**
* Credit's contributor.
* @return Contributor
*/ 

-(nullable GnContributor*) contributor;

/**
* GnType
*/
+(nonnull NSString*) gnType;

/**
* From
*/
+(nullable GnCredit*) from: (nonnull GnDataObject*)obj error: (NSError**)error;


NS_ASSUME_NONNULL_END

@end


@interface GnCreditEnumerator : NSEnumerator

NS_ASSUME_NONNULL_BEGIN

typedef void (^GnCreditBlock)(id obj, NSUInteger index, BOOL* stop);

-(void)enumerateObjectsUsingBlock: (GnCreditBlock)handler;

-(NSUInteger) count;

-(nullable GnCredit*) nextObject;

-(nullable GnCredit*) objectAtIndex:(NSUInteger)index;

-(NSArray*) allObjects;


NS_ASSUME_NONNULL_END

@end



#endif /* _GnCredit_h_ */

