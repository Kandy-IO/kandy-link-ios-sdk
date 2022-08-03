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

NS_ASSUME_NONNULL_BEGIN

/**
 * @brief The variable type that will be used to search the global address book.
 * SearchTypeParameter can be the following integer values:
 *
 * - SEARCHTYPE_FIRSTNAME
 * - SEARCHTYPE_LASTNAME
 * - SEARCHTYPE_NAME
 * - SEARCHTYPE_PHONENUMBER
 * - SEARCHTYPE_USERNAME
 *
 * @since 2.0.0
 **/
typedef NS_ENUM(NSInteger, SMAddressBookSearchTypes) {
    /** First name will be used to search the global address book*/
    SEARCHTYPE_FIRSTNAME NS_SWIFT_NAME(firstName) = 1,
    
    /** Last name will be used to search the global address book*/
    SEARCHTYPE_LASTNAME NS_SWIFT_NAME(lastName) = 2,
    
    /** Name will be used to search the global address book*/
    SEARCHTYPE_NAME NS_SWIFT_NAME(name) = 3,
    
    /** Phone number will be used to search the global address book*/
    SEARCHTYPE_PHONENUMBER NS_SWIFT_NAME(phoneNumber) = 4,
    
    /** User name will be used to search the global address book*/
    SEARCHTYPE_USERNAME NS_SWIFT_NAME(userName) = 5
};

/**
 * @brief This class defines event types of AddressBook
 * @since 2.0.0
 */
@interface SMAddressBookSearchType : NSObject

/**
 * This methods converts AddressBookSearchTypes to NSString
 * @param type AddressBookSearchTypes
 * @return NSString
 * @since 2.0.0
 */
+(NSString *)getAddressBookSearchType:(SMAddressBookSearchTypes)type;

NS_ASSUME_NONNULL_END

@end
