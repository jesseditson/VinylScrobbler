/*
 *
 *  GRACENOTE, INC. PROPRIETARY INFORMATION
 *  This software is supplied under the terms of a license agreement or
 *  nondisclosure agreement with Gracenote, Inc. and may not be copied
 *  or disclosed except in accordance with the terms of that agreement.
 *  Copyright(c) 2000-2016. Gracenote, Inc. All Rights Reserved.
 *
 */
 
#ifndef _GnLogEventsDelegate_h_
#define _GnLogEventsDelegate_h_


#import <Foundation/Foundation.h>
#import "GnDefines.h"

#import "GnEnums.h"




NS_ASSUME_NONNULL_BEGIN

@protocol GnLogEventsDelegate <NSObject>

@required

/**
* Implement to receive logging messages from GNSDK
* @param packageId  Package Id that generated this message
* @param messageType  Type of logging message
* @param errorCode  Error code related to message
* @param message  Logging message (includes configured column formatting)
*/ 

-(BOOL) logMessage: (NSUInteger)packageId messageType: (GnLogMessageType)messageType errorCode: (NSUInteger)errorCode message: (nonnull NSString*)message;


@end

NS_ASSUME_NONNULL_END



#endif /* _GnLogEventsDelegate_h_ */

