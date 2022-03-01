/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.0.0
 *
 */

/**
 * Enum values for TypeOfConnection
 *
 * WEBSOCKET,
 * LONGPOLLING
 *
 * @since 2.0.0
 **/
typedef NS_ENUM(NSInteger, TypeOfConnection) {
    
    /**  WEBSOCKET */
    WEBSOCKET NS_SWIFT_NAME(websocket),
    
    /** LONGPOLLING */
    LONGPOLLING NS_SWIFT_NAME(longPolling)
};

