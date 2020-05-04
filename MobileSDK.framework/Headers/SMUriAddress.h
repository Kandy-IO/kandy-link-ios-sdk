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

/**
 * @brief  An UriAddress is used to indicate the originator of a request, the
 * destination of a request, and to specify any redirections of the
 * request.
 * @since 2.0.0
 **/
@interface SMUriAddress : NSObject

/**
 * The username to include in this address.
 * @since 2.0.0
 */
@property (strong,nonatomic,nonnull) NSString * userName;

/**
 * The network domain to include in this address.
 * @since 2.0.0
 */
@property (strong,nonatomic,nonnull) NSString * domain;

/**
 * Constructor method for UriAddress.
 * @param primaryContact address of user
 * @return UriAddress instance
 * @since 2.0.0
 */
-(nonnull SMUriAddress *) initWithPrimaryContact:(nonnull NSString *) primaryContact;

/**
 * Constructor method for UriAddress.
 * @param userName name of the user
 * @param domain domain of the user
 * @return UriAddress instance
 * @since 2.0.0
 */
- (nonnull SMUriAddress *) initWithUsername :(nonnull NSString *) userName withDomain:(nullable NSString *)domain;

/**
 * Static constructor method for UriAddress.
 * @param userName name of the user
 * @param domain domain of the user
 * @return UriAddress instance
 * @since 3.0.1
 */
+ (nonnull SMUriAddress *) uriAddressWithUsername :(nonnull NSString *) userName withDomain:(nullable NSString *)domain;

/**
 * Retrieve the URI of an address.
 *
 * @return NSString format of xxx\@yyyy, where xxx is the
 * username or phonenumber and yyy is the domain
 * @since 2.0.0
 */
-(nonnull NSString *) getUri;
@end
