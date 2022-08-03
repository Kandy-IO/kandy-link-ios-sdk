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

@class SMMobileError;
@class SMContact;

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief Represents events of AddressBook.
 * This protocol must be conformed by classes which uses AddressBookService
 * @since 2.0.0
 */
@protocol SMAddressBookApplicationDelegate <NSObject>

/**
 * This is the call back method for the retrieve addressbook.
 * This method is invoked when retrieve addressbook attempt is succeeded.
 * @param addressBook list of retrieved contacts
 * @see AddressBookServiceDelegate::retrieve:
 * @since 2.0.0
 */
-(void)retrieveSucceeded:(NSArray<SMContact *> *) addressBook;

/**
 * This is the call back method for the retrieve addressbook.
 * This method is invoked when retrieve addressbook attempt is failed.
 * @param error definition of failure
 * @see AddressBookServiceDelegate::retrieve:
 * @since 2.0.0
 */
-(void)retrieveFailed:(SMMobileError *) error;
/**
 * This is the call back method for the directory search in addressbook.
 * This method is invoked when directory search is succeeded.
 * @param directoryCount count of retrieved results
 * @param addressesList array of retrieved results
 * @see AddressBookServiceDelegate::searchDirectory:
 * @since 2.0.0
 */
-(void)searchDirectorySucceeded:(int) directoryCount
                        andList:(NSArray<SMContact *> *)addressesList;
/**
 * This is the call back method for the directory search in addressbook.
 * This method is invoked when directory search is failed.
 * @param error definiton of failure
 * @see AddressBookServiceDelegate::searchDirectory:
 * @since 2.0.0
 */
-(void)searchDirectoryFailed:(SMMobileError *) error;

NS_ASSUME_NONNULL_END

@end
