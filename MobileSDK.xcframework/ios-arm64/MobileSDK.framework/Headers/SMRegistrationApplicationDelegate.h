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
 * @brief This is the call back method for any registration state change on the Reqistration.
 *
 * @param registrationState new state of the registration 
 * @since 2.0.0
 */
- (void) registrationStateChanged : (SMRegistrationStates) registrationState;

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
 *
 * @param error SMMobileError
 * @since 4.2.4
 */
- (void) internalErrorDidOccur:(SMMobileError*) error;

NS_ASSUME_NONNULL_END

@end
