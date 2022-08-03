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
#import "SMAddressBookSearchType.h"
#import "SMAddressBookApplicationDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief This class represents a service for addressbook and directory.
 * @since 2.0.0
 */
@protocol SMAddressBookServiceDelegate <NSObject>

/**
 * Sets the handler to AddressBook retrieve.
 * @param app AddressBookApplicationDelegate
 * @since 2.0.0
 */
-(void) setAddressBookApplication:(id <SMAddressBookApplicationDelegate>) app;

/**
 * Retrieves the list of personal address book entries from the server.
 * @since 2.0.0
 */
- (void)retrieve;

/**
 * Searches the directory.
 * @param criteria NSString(text depending on the searchType)
 * @param searchType AddressBookSearchType
 * @since 2.0.0
 */
- (void)searchDirectory:(NSString *)criteria
                      andSearchType:(SMAddressBookSearchTypes)searchType;

@end

NS_ASSUME_NONNULL_END
