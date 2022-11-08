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

/**
 * @brief enum class for Registration States
 * This enum will no longer be available in version 6.11.0.
 * <p>To find out the registration status of the SDK,
 * use {@link SMRegistrationApplicationDelegate#registrationDropped(MobileError)} instead.</p>
 *
 * - UNREGISTERED
 * - REGISTERED
 *
 * @since 2.0.0
 */
typedef NS_ENUM(NSInteger, SMRegistrationStates) {
    /**
     * @brief Device registration is removed either by callling unregister method or being dropped on server.
     * Registration state can be changed to unregistered in anytime if server drops registration.
     */
    UNREGISTERED NS_SWIFT_NAME(unregistered),
    
    /**
     * @brief Device registration is created on server side by REST request. Until unregister method is called, device will be tried to
     * stay in REGISTERED state even if it is dropped by server.
     */
    REGISTERED NS_SWIFT_NAME(registered)
} DEPRECATED_MSG_ATTRIBUTE("This API will be deprecated. Use registrationDropped(MobileError)");
