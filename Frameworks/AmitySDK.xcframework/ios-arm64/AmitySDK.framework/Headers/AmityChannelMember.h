//
//  AmityChannelMember.h
//  AmityChat
//
//  Created by amity on 2/23/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUser.h>
@import Foundation;

@interface AmityChannelMember : NSObject

/**
   The channelId
 */
@property (nonnull, strong, readonly, nonatomic) NSString *channelId;

/**
   The userId
 */
@property (nonnull, strong, readonly, nonatomic) NSString *userId;

/**
 User object which belongs to this userId.
 */
@property (nullable, readonly, nonatomic) AmityUser *user;

/**
   The user membership status
 */
@property (readonly) AmityChannelMembershipType membership;

/**
   Banned status
 */
@property (assign, readonly, nonatomic) BOOL isBanned;

/**
   Muted status
 */
@property (assign, readonly, nonatomic) BOOL isMuted;

/**
   Roles
 */
@property (nonnull, strong, readonly, nonatomic) NSArray <NSString *> *roles;

/**
   The display name
 */
@property (nullable, strong, readonly, nonatomic) NSString *displayName;

@end
