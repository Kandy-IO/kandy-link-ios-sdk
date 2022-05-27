/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.3.0
 *
 */

/**
 * Enum values for ringing feedback options
 *
 *NONE --> There will be no ringing feedback.
 *SERVER --> Server based ringing feedback.
 *CLIENT --> Client based ringing feedback.
 *
 * @since 5.15.0
 **/

typedef NS_ENUM(NSInteger, SMRingingFeedbackOptions) {
    
    /** There will be no ringing feedback. */
    NONE NS_SWIFT_NAME(none),
    
    /** Server based ringing feedback. */
    SERVER NS_SWIFT_NAME(server),
    
    /**  Client based ringing feedback. */
    CLIENT NS_SWIFT_NAME(client),
};
