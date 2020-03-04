/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.4.0
 *
 */

#import <Foundation/Foundation.h>

@class SMICEServer;

/**
 * @brief This class stores ice servers list, adds a new iceServer and  updates iceServer objects.
 *
 * @since 3.0.3
 */
@interface SMICEServers : NSObject

/**
 * Constructor method for ICEServers.
 *
 * @param url URL address of the ICEServer
 *
 * @since 3.0.3
 */
- (void) addICEServer:(nonnull NSString *)url;

/**
 * Constructor method for ICEServers.
 *
 * @param url Url address of the ICEServer
 * @param username Username of the ICEServer
 * @param password Password of the ICEServer
 *
 * @since 3.0.3
 */
- (void) addICEServer:(nonnull NSString *)url
             username:(nonnull NSString *)username
             password:(nonnull NSString *)password;

/**
 * Returns iceServersArray.
 *
 * @return iceServersArray of ICEServers
 *
 * @since 3.0.3
 */
- (nullable NSArray<SMICEServer *> *)servers;

@end


/**
 * @brief This class stores url, username and password of stun or turn servers.
 *
 * @since 3.0.3
 */
@interface SMICEServer : NSObject

/**
 * The url of iceServer.
 *
 * @since 3.0.3
 */
@property (strong, readonly, nonnull) NSString *url;

/**
 * The username of iceServer.
 *
 * @since 3.0.3
 */
@property (strong, readonly, nullable) NSString *username;

/**
 * The password of iceServer.
 *
 * @since 3.0.3
 */
@property (strong, readonly, nullable) NSString *password;

@end
