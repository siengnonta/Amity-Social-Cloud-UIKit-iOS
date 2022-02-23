//
//  AmityChannel.h
//
//  Created by amity on 1/18/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityObject.h>
#import <Foundation/Foundation.h>

@class AmityChannel;
@class AmityChannelParticipation;
@class AmityChannelModeration;
@class AmityChannelMember;
@class AmityImageData;

/**
 * All Channel Type
 */
typedef NS_ENUM(NSUInteger, AmityChannelType) {
    AmityChannelTypeStandard,
    AmityChannelTypePrivate,
    AmityChannelTypeBroadcast,
    AmityChannelTypeConversation,
    AmityChannelTypeLive,
    AmityChannelTypeCommunity,
    AmityChannelTypeUnknown
};

NS_ASSUME_NONNULL_BEGIN

/**
 * Channel
 */
__attribute__((objc_subclassing_restricted))
@interface AmityChannel : NSObject

/**
 * The unique identifier for the channel
 */
@property (strong, readonly, nonatomic) NSString *channelId;

/**
 * Channel type
 */
@property (assign, readonly, nonatomic) enum AmityChannelType channelType;

/**
 * Channel metadata
 */
@property (nullable, strong, readonly, nonatomic) NSDictionary<NSString *, id> *metadata;

/**
 * The display name for the channel
 */
@property (nullable, strong, readonly, nonatomic) NSString *displayName;

/*
 * The current user membership type in the channel
 */
@property (readonly) AmityChannelMembershipType currentUserMembership;

/**
 * isDistinct
 */
@property (readonly, nonatomic) BOOL isDistinct;

/**
 * isMuted
 */
@property (readonly, nonatomic) BOOL isMuted;

/**
 * isRateLimited
 */
@property (readonly, nonatomic) BOOL isRateLimited;

/**
 * Number of messages within rate limit
 */
@property (readonly, assign, nonatomic) NSInteger rateLimit;

/**
 * Unread messages for the current user in the channel
 */
@property (readonly, nonatomic) NSInteger unreadCount;

/**
 * Wheather the current user has unread mentione messages for the current channel
 */
@property (readonly, nonatomic) BOOL hasMention;

/**
 * Total number of users in this channel
 */
@property (readonly, nonatomic) NSInteger memberCount;

/**
 * Total number of messages in this channel
 */
@property (readonly, nonatomic) NSInteger messageCount;

/**
   Returns a participation instance
 */
@property (readonly, nonatomic) AmityChannelParticipation *participation;

/**
 * The current user channel membership object
 */
@property (nullable, readonly, nonatomic) AmityChannelMember *currentMembership;

/**
   A moderation instance
 */
@property (readonly, nonatomic) AmityChannelModeration *moderate;

/**
   The channel tags
 */
@property (nonnull, strong, readonly, nonatomic) NSArray <NSString *> *tags;


/**
   @abstract The channel last activity
   @discussion The last activity is updated for various reasons, for example:

     - new channel tags are set

     - a new channel name is set

     - a new message has been received

     - etc
 */
@property (strong, nonatomic) NSDate *lastActivity;

/**
 The channel creation time.
 */
@property (nonnull, strong, readonly, nonatomic) NSDate *createdAt;
/**
 The last time this channel has been updated.
 */
@property (nonnull, strong, readonly, nonatomic) NSDate *updatedAt;

/**
 If this channel has been deleted already
 */
@property (assign, nonatomic) BOOL isDeleted;

/**
 * File id for the avatar for this Channel. This can be used in
 * AmityFileRepository to download actual UIImage instance.
 */
@property (nullable, strong, nonatomic) NSString *avatarFileId;

/**
 Gets the image data associated with this Channel.
 
 @return: Returns AmityImageData if present. Else returns nil.
 */
- (nullable AmityImageData *)getAvatarInfo;

/**
   Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
