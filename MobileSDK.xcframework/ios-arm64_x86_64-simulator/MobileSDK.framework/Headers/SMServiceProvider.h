/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.5.0
 *
 */


#import <Foundation/Foundation.h>


@class SMPushService;
@class SMRegistrationService;
@class SMPublicRequestService;

@protocol SMCallServiceDelegate;
@protocol SMAddressBookServiceDelegate;
@protocol SMPresenceServiceDelegate;
@protocol SMIMServiceDelegate;
@protocol SMCallLogServiceDelegate;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief This class is needed for calling the services.
 * @since 2.0.0
 */
@interface SMServiceProvider : NSObject

/**
 * This method returns an instance of ServiceProvider using Singleton Pattern
 * @return ServiceProvider
 * @since 2.0.0
 */
+ (SMServiceProvider *) getInstance;


/**
 * This method returns (creates if necessary) an instance of AddressBookService using Singleton Pattern
 * @return AddressBookServiceDelegate
 * @since 2.0.0
 */
- (id<SMAddressBookServiceDelegate>) getAddressBookService;


/**
 * This method returns (creates if necessary) an instance of RegistrationService using Singleton Pattern
 * @return RegistrationServiceDelegate
 * @since 2.0.0
 */
- (SMRegistrationService *) getRegistrationService;


/**
 * This method returns (creates if necessary) an instance of CallService using Singleton Pattern
 * @return CallServiceDelegate
 * @since 2.0.0
 */
- (id<SMCallServiceDelegate>) getCallService;


/**
 * This method returns (creates if necessary) an instance of CallLogService using Singleton Pattern
 * @return CallLogServiceDelegate
 * @since 2.0.0
 */
- (id<SMCallLogServiceDelegate>) getCallLogService;

/**
 * This method returns (creates if necessary) an instance of PushService using Singleton Pattern
 * @return PushService
 * @since 3.0.5
 * @updated 4.6.0
 */
- (SMPushService *) getPushService;


/**
 * This method returns the version information about the SDK
 * @return NSString
 * @since 2.0.0
 */

- (SMPublicRequestService *) getPublicRequestService;
/**
 * This method returns (creates if necessary) an instance of PublicRequestService using Singleton Pattern
 * @return PublicRequestService
 * @since 5.24.0
 */



- (NSString *) getVersion;

NS_ASSUME_NONNULL_END

@end
