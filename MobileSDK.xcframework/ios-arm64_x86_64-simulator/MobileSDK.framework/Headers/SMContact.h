/*
 * Copyright © 2014 GENBAND. All Rights Reserved.
 *
 * GENBAND CONFIDENTIAL. All information, copyrights, trade secrets
 * and other intellectual property rights, contained herein are the property
 * of GENBAND. This document is strictly confidential and must not be
 * copied, accessed, disclosed or used in any manner, in whole or in part,
 * without GENBAND's express written authorization.
 *
 * @version: 6.5.0
 *
 */

#import <Foundation/Foundation.h>

@class SMUriAddress;

/**
 * @brief Basic Entity Class for contact.
 * @since 2.0.0
 */
@interface SMContact : NSObject

/**
 * Source of contact such as SPiDR, Facebook, LinkedIn .. etc.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* sources;

/**
 * Email address of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* emailAddress;

/**
 * Unique identifier of the entry.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* entryId;

/**
 * Fax number of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* fax;

/**
 * First name of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* firstName;

/**
 * Last name of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* lastName;

/**
 * Friend status of the user.
 * @since 2.0.0
 */
@property (nonatomic) BOOL friendStatus;

/**
 * Home phone number of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* homePhone;

/**
 * Mobile phone number of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* mobilePhone;

/**
 * Name of the user as it will appear for a personal contact.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* nickName;

/**
 * Pager number of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* pager;

/**
 * URL from which to retrieve the picture of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* photoUrl;

/**
 * User's primary contact number (this should be prefered number for contacting the user).
 * @since 2.0.0
 */
@property (strong, nonatomic, nonnull) SMUriAddress* primaryContact;

/**
 * Work phone number of the user.
 * @since 2.0.0
 */
@property (strong, nonatomic, nullable) NSString* workPhone;

/**
 * Constructor method with NSDictionary
 * @param dictionary Contact information dictionary
 * @since 2.0.0
 */
- (id) initWithDictionary:(nonnull NSDictionary *) dictionary;
@end
