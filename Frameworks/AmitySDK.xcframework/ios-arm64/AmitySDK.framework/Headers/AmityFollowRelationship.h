//
//  AmityFollowRelationship.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 25/5/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AmityUser;

/**
 * Follow status
 */
typedef NS_ENUM(NSUInteger, AmityFollowStatus) {
    AmityFollowStatusNone,
    AmityFollowStatusPending,
    AmityFollowStatusAccepted
};

/**
 * Query options of follow status
 */
typedef NS_ENUM(NSUInteger, AmityFollowQueryOption) {
    AmityFollowQueryOptionAll,
    AmityFollowQueryOptionPending,
    AmityFollowQueryOptionAccepted
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityFollowRelationship : NSObject

/**
 * A user object of the person who is following
 */
@property (nonnull, strong, readonly, nonatomic) NSString *sourceUserId;

/**
 * A user object of the person who is being followed
 */
@property (nonnull, strong, readonly, nonatomic) NSString *targetUserId;

/**
 * A user id of the person who is following
 */
@property (nullable, strong, readonly, nonatomic) AmityUser *sourceUser;

/**
 * A user id of the person who is being followed
 */
@property (nullable, strong, readonly, nonatomic) AmityUser *targetUser;

/**
 * A follow status between 2 users
 */
@property (assign, readonly, nonatomic) enum AmityFollowStatus status;

@end

NS_ASSUME_NONNULL_END
