//
//  AmityChannelRepository.h
//  AmitySDK
//
//  Created by amity on 1/25/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AmityChannel;
@class AmityClient;
@class AmityChannelQuery;
@class AmityChannelUpdateBuilder;
@class AmityChannelNotificationsManager;
@class AmityCollection<T>;
@class AmityObject<T>;
@protocol AmityChannelBuilderProtocol;

typedef void (^AmityRequestCompletion)(BOOL success, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access channel and collections of channels
 */
@interface AmityChannelRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;
@property (readonly, nonatomic) NSUInteger totalUnreadCount;

/**
 * Designated intializer
 * @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Creates a new channel. **Standard & Private** channel types has been depreciated. Please refer to our documentation for more info.
 */
- (nonnull AmityObject<AmityChannel *> *)createChannelWithBuilder:(nonnull id<AmityChannelBuilderProtocol>)builder NS_SWIFT_NAME(createChannel(with:));

/**
 Updates an existing channel.
 */
- (nonnull AmityObject<AmityChannel *> *)updateChannelWithBuilder:(nonnull AmityChannelUpdateBuilder *)builder NS_SWIFT_NAME(updateChannel(with:));

/**
 * Joins a channel by channel Id, if you are already in this channel, it will fetch the existing channel. **Note:** Starting from SDK version 3.0, this method doesnot creates a new channel, if the channel doesnot exists.
 * @param channelId A valid Channel Id
 * @return A Proxy Object for the channel
 */
- (AmityObject<AmityChannel *> *)joinChannel:(nonnull NSString *)channelId;

/**
 Leaves the channel for the current user
 @param completion A block executed when the request has completed
 */
- (void)leaveChannel:(NSString *)channelId withCompletion:(AmityRequestCompletion _Nullable)completion;

/**
 * Gets an existing channel by channel Id
 */
- (AmityObject<AmityChannel *> *)getChannel:(nonnull NSString *)channelId;

/**
 Getting a live collection channel by specify the query.
 @return A live collection of channels that belong to the query options.
 */
- (nonnull AmityCollection<AmityChannel *> *)getChannelsWithQuery:(AmityChannelQuery *)query NS_SWIFT_NAME(getChannels(with:));

/**
 @abstract Channel Level Push Notifications Management object.
 */
- (nonnull AmityChannelNotificationsManager *)notificationManagerForChannelWithId:(nonnull NSString *)channelId;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
