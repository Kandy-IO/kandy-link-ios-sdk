/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.4.0
 *
 */

/**
 * Enum values for ringing feedback options
 *
 *APP   --> The application side should manage the ringing feedback operations.
 *SERVER --> Server based ringing feedback.
 *AUTO --> Auto ringing feedback mechanism by SDK.
 *
 * @since 5.15.0
 * @updated 2022-06-20
 **/

typedef NS_ENUM(NSInteger, SMRingingFeedbackOptions) {
    
    /** The application side should manage the ringing feedback operations. */
    APP NS_SWIFT_NAME(app),
    
    /** Server based ringing feedback. */
    SERVER NS_SWIFT_NAME(server),
    
    /** The SDK manages the ringing feedback operations. */
    AUTO NS_SWIFT_NAME(_auto),
};
