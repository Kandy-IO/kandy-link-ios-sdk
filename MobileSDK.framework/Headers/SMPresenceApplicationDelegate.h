/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.6.0
 *
 */

#import <Foundation/Foundation.h>

@protocol SMPresenceDelegate;

@class SMMobileError;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Represents events of Presence
 * This protocol must be conformed by classes which uses PresenceService
 * @since 2.0.0
 */
@protocol SMPresenceApplicationDelegate <NSObject>

/**
 * This metod is invoked, When retrieve has succeeded
 * @param presenceList list of users
 * @see PresenceServiceDelegate can see retrieve method
 * @since 2.0.0
 */
- (void) retrieveSucceeded:(NSMutableArray<NSString *> *) presenceList;

/**
 * This metod is invoked, when retrieve has failed
 * @param presenceList list of users
 * @param error MobileError
 * @see PresenceServiceDelegate can see retrieve method
 * @since 2.0.0
 */
- (void) retrieveFailed:(NSMutableArray<NSString *> *) presenceList withError:(SMMobileError *) error;

/**
 * This metod is invoked, when starting watch has succeeded
 * @param presenceList list of users
 * @see PresenceServiceDelegate can see startwatch
 * @since 2.0.0
 */
- (void) startWatchSucceeded:(NSMutableArray<NSString *> *) presenceList;

/**
 * This metod is invoked, when starting watch failed
 * @param presenceList list of users
 * @param error MobileError
 * @see PresenceServiceDelegate can see startwatch
 * @since 2.0.0
 */
- (void) startWatchFailed:(NSMutableArray<NSString *> *)presenceList withError:(SMMobileError *) error;

/**
 * This metod is invoked, when stop watch has succeeded
 * @param presenceList list of users
 * @see PresenceServiceDelegate can see stopwatch
 * @since 2.0.0
 */
- (void) stopWatchSucceeded:(NSMutableArray<NSString *> *) presenceList;

/**
 * This metod is invoked, when stop watch has failed
 * @param presenceList list of users
 * @param error MobileError
 * @see PresenceServiceDelegate can see stopwatch
 * @since 2.0.0
 */
- (void) stopWatchFailed:(NSMutableArray<NSString *> *) presenceList withError:(SMMobileError *)error;

/**
 * This metod is invoked, when local presence state has succesfully changed
 * Application shall call getPresenceStatus to check it’s current presence status.
 * @since 2.0.0
 */
- (void) updatePresenceSucceeded;

/**
 * This metod is invoked, when local presence state change has failed
 * @param error MobileError
 * @since 2.0.0
 */
- (void) updatePresenceFailed:(SMMobileError *) error;

/**
 * This metod is invoked, when presence state of user has changed which is being watched
 * Application shall call getPresenceStatus to check it’s current presence status.
 * @param presence which is updated 
 * @since 2.0.0
 */
- (void) presenceStateChanged :(id<SMPresenceDelegate>) presence;

@end

NS_ASSUME_NONNULL_END
