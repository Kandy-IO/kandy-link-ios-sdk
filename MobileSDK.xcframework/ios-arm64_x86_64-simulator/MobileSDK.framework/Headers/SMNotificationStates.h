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

/**
 * @brief enum class for Notification States
 *
 * - CONNECTED
 * - DISCONNECTED
 *
 * @since 2.0.0
 */
typedef NS_ENUM(NSInteger, SMNotificationStates) {
    /**
     * @brief Notification component is disconnected and not able to receive the server notifications.
     * Notification component can be disconnected in anytime however it will be tried to connect automatically
     * until unregistration is done or network is lost.
     */
    DISCONNECTED NS_SWIFT_NAME(disconnected),
    
    /**
     * @brief Notification component is connected and able to receive the server notifications.
     * Notification component can be disconnected in anytime however it will be tried to connect automatically
     * until unregistration is done or network is lost.
     *
     */
    CONNECTED NS_SWIFT_NAME(connected)
};
