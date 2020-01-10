/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.3.0
 *
 */

#import <Foundation/Foundation.h>
#import "SMOutGoingIMDelegate.h"
#import "SMInComingIMDelegate.h"

@class SMMobileError;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Represents events of IM
 * This protocol must be conformed by classes which uses IMService
 * @since 2.0.0
 */
@protocol SMIMApplicationDelegate <NSObject>

/**
 * This metod is invoked when a new IM is received
 *
 * @param im InComingIMDelegate
 * @since 2.0.0
 */
-(void) incomingIM :(id<SMInComingIMDelegate>) im;

/**
 * This method is invoked when send IM has succeeded.
 *
 * @param im that sent successfully
 * @see OutGoingIMDelegate see send method
 * @since 2.0.0
 */
- (void) sendSucceeded :(id<SMOutGoingIMDelegate>)im;

/**
 * When fails, this metod will work
 *
 * @param im that can't be sent
 * @param error definition of failure
 * @see OutGoingIMDelegate see send method
 * @since 2.0.0
 */
- (void) sendFailure: (id<SMOutGoingIMDelegate>)im  withError:(SMMobileError *) error;
@end

NS_ASSUME_NONNULL_END
