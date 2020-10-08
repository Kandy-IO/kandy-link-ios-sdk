/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.11.0
 *
 */

#import <Foundation/Foundation.h>
#import "SMIMDelegate.h"

/**
 * @brief Incoming Instant Message methods.
 * @since 2.0.0
 */

@protocol SMInComingIMDelegate <SMIMDelegate>

/**
 * Makes reply to incoming IM
 *
 * @param message message of reply
 *
 * @since 2.0.0
 */
- (void) reply :(nonnull NSString *)message;
@end

