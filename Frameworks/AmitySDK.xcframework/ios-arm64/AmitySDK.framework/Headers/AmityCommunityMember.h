//
//  AmityCommunityMember.h
//  AmitySDK
//
//  Created by Michael Abadi on 05/08/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUser.h>

@interface AmityCommunityMember : NSObject

/**
   The channelId
 */
@property (nonnull, strong, readonly, nonatomic) NSString *channelId;

/**
   The communityId
 */
@property (nonnull, strong, readonly, nonatomic) NSString *communityId;

/**
   The userId
 */
@property (nonnull, strong, readonly, nonatomic) NSString *userId;

/**
   The user displayName
 */
@property (nonnull, strong, readonly, nonatomic) NSString *displayName;

/**
   User object which belongs to this userId.
 */
@property (nullable, readonly, nonatomic) AmityUser *user;

/**
   Banned status
 */
@property (assign, readonly, nonatomic) BOOL isBanned;

/**
   The community member  metadata.
 */
@property (nonnull, strong, readonly, nonatomic) NSDictionary <NSString *, id> *metadata;

/**
 The user last activity time.
 */
@property (nonnull, strong, readonly, nonatomic) NSDate *lastActivityDate;

/**
 * When this model was created
 */
@property (nonnull, strong, nonatomic) NSDate *createdAt;

/**
 * The date when this model was last updated
 */
@property (nonnull, strong, nonatomic) NSDate *updatedAt;

/**
   The community membership status
 */
@property (readonly) AmityCommunityMembershipType membership;

/**
 Roles for this membership
 */
@property (nonnull, strong, readonly, nonatomic) NSArray <NSString *> *roles;

@end

