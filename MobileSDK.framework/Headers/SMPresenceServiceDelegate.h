/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.12.0
 *
 */

#import <Foundation/Foundation.h>
#import "SMPresenceDelegate.h"
#import "SMPresenceApplicationDelegate.h"
#import "SMPresenceStates.h"
#import "SMPresenceActivityType.h"



/**
 * @brief PresenceService and directory.
 * @since 2.0.0
 */
@protocol SMPresenceServiceDelegate <NSObject>

/**
 * Set the event handler PresenceApplicationDelegate for the PresenceService.
 * @param app delegete of application to return callbacks for presence
 * @since 2.0.0
 */
- (void) setPresenceApplication :(nonnull id<SMPresenceApplicationDelegate>) app;

/**
 * Updates the user's presence state
 * @param app delegete of application to return callbacks
 * @param state new state for updating
 * @param activity new actity to update
 * @param note new note to update
 * @since 2.0.0
 */
- (void) updatePresence:(nonnull id<SMPresenceApplicationDelegate>) app
       andPresenceState:(SMPresenceStates) state
andPresenceActivityType:(SMPresenceActivityType) activity
      andPresenceDetail:(nullable NSString *)note;

/**
 * Start watching contacts which are given in the list.
 * @param presenceList user list
 * @since 2.0.0
 */
- (void) startWatch: (nonnull NSMutableArray<NSString *> *)presenceList;

/**
 * Stop watching contacts, which are given in the list.
 * @param presenceList user list
 * @since 2.0.0
 */
- (void) stopWatch: (nonnull NSMutableArray<NSString *> *)presenceList;

/**
 * Get status of contacts once, which are given in the list.
 * @param presenceList user list
 * @since 2.0.0
 */
- (void) retrieve: (nonnull NSMutableArray<NSString *> *)presenceList;
@end
