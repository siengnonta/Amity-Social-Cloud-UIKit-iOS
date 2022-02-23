//
//  AmityConversationChannelBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 8/19/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityImageData.h>

NS_ASSUME_NONNULL_BEGIN

__attribute__((objc_subclassing_restricted))
@interface AmityConversationChannelBuilder : NSObject <AmityChannelBuilderProtocol>

/**
 Channel type of the builder
 */
@property (assign, nonatomic) AmityChannelType channelType;

/**
 Sets single user id for this channel.
 */
- (void)setUserId:(NSString *)userId;

/**
 Sets user ids for this channel. This method is mandatory for converstation channel
 */
- (void)setUserIds:(NSArray<NSString *> *)userIds;

/**
 Sets metadata for this channel.
 */
- (void)setMetadata:(NSDictionary<NSString *, id> *)metaData;

/**
 Sets tags for this channel.
 */
- (void)setTags:(NSArray<NSString *> *)tags;

/**
 If this conversation is distinct, set it
 */
- (void)setIsDistinct:(BOOL)isDistinct;

/**
 Sets display name for this channel.
 */
- (void)setDisplayName:(NSString *)displayName;

/**
 Sets avatar info for this channel. Use AmityFileRepository to upload image and set the AmityImageData
 instance that you get in response over here.
 */
- (void)setAvatar:(AmityImageData *)avatarData;

@end

NS_ASSUME_NONNULL_END
