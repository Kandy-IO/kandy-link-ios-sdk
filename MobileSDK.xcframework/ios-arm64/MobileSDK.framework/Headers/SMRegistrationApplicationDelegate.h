/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.8.1
 *
 */

#import <Foundation/Foundation.h>
#import "SMNotificationStates.h"
#import "SMRegistrationStates.h"

@class SMMobileError;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Represents events of Registration
 * This protocol must be conformed by classes which uses RegistrationService
 * @since 2.0.0
 */
@protocol SMRegistrationApplicationDelegate <NSObject>

/**
 * @brief This method will no longer be available in version 6.11.0.
 *
 * @param registrationState new state of the registration
 * @since 2.0.0
 */
- (void) registrationStateChanged :(SMRegistrationStates) registrationState DEPRECATED_MSG_ATTRIBUTE("This API will be deprecated. Use registrationDropped(MobileError)");

/**
 * This method will be triggered when the registration of the SDK ends due to an error.
 * When this method is triggered, you must repeat the registration process
 * to continue using the SDK functionalities.
 *
 * @param error reason of the registration drop event.
 * @since 6.8.0
 */
- (void) registrationDropped:(SMMobileError*) error;

/**
 * This method will be called, when websocet notification state changed
 *
 * @param notificationState {@link NotificationStates}
 * @since 2.0.0
 */
- (void) notificationStateChanged:(SMNotificationStates) notificationState;

/**
 * This method will be call, if any internal error occurs when MobileSDK
 * sends a request to SPiDR.
 * This method will no longer available in version 6.11.0.
 *
 * @param error SMMobileError
 * @since 4.2.4
 */
- (void) internalErrorDidOccur:(SMMobileError*) error DEPRECATED_MSG_ATTRIBUTE("This API will be deprecated. Use registrationDropped(MobileError)");

NS_ASSUME_NONNULL_END

@end
