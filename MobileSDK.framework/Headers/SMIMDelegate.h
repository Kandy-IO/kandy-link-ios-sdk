/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 5.0.0
 *
 */

#import <Foundation/Foundation.h>

@class SMUriAddress;

/**
 * @brief InstantMessage related resources
 * @since 2.0.0
 */
@protocol SMIMDelegate <NSObject>

/**
 * Client type is a NSString used to identify the receiving client type such as "A2","Facebook".
 * @since 2.0.0
 */
@property (strong,nonatomic, nullable) NSString * clientType;

/**
 * Text of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nonnull) NSString * text;

/**
 * FromAddress of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nonnull) SMUriAddress * fromAddress;

/**
 * ToAddress parameter of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nonnull) SMUriAddress * toAddress;

/**
 * Originator display name of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nullable) NSString * originatorDisplayName;

/**
 * Terminator display name  of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nullable) NSString * terminatorDisplayName;

/**
 * Charset value of Instant Message
 * @since 2.0.0
 */
@property (strong,nonatomic, nullable) NSString * charset;
@end
