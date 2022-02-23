//
//  AmityChannelParticipation.h
//  AmitySDK
//
//  Created by amity on 2/13/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityChannelMembershipFilterBuilder.h>

@class AmityChannel;
@class AmityChannelMember;

NS_ASSUME_NONNULL_BEGIN

/**
 A membership encapsulates methods for managing users in a channel
 */
@interface AmityChannelParticipation : NSObject

/**
 The client used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
 The channel Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *channelId;


/**
 Designated intializer
 @param client A valid client instance
 @param channelId The Id of the channel to update
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                            andChannel:(nonnull NSString *)channelId NS_DESIGNATED_INITIALIZER;

/**
 Gets the members associated with the instance filtered by the filter parameter
 
 @param filter: A vaild AmityChannelMembershipFilter enum option
 @param sortBy: Sort the results by `firstCreated` or `lastCreated`
 @param roles: Filter membership list by roles. If you don't want to filter by role, pass empty array.
 */
- (nonnull AmityCollection<AmityChannelMember *> *)getMembers:(AmityChannelMembershipFilter)filter sortBy:(AmitySortBy)sortBy roles:(NSArray<NSString *> *)roles NS_SWIFT_NAME(getMembers(filter:sortBy:roles:));

/**
 Search members associated with the instance filtered by the filter parameter
 
 @param displayName: A search keyword to search users by displayName
 @param filterBuilder: An  AmityChannelMembershipFilterBuilder to build a filter for channel members
 @param roles: Filter membership list by roles. If you don't want to filter by role, pass empty array.
 */
- (nonnull AmityCollection<AmityChannelMember *> *)searchMembers:(NSString *)displayName filterBuilder:(AmityChannelMembershipFilterBuilder *)filterBuilder roles:(NSArray<NSString *> *)roles NS_SWIFT_NAME(searchMembers(displayName:filterBuilder:roles:));

/**
 Adds users to the channel
 
 @param userIds An array of users Ids to add
 @param completion A block executed when the request has completed
 */
- (void)addMembers:(nonnull NSArray<NSString *> *)userIds completion:(AmityRequestCompletion _Nullable)completion;

/**
 Removes users from the channel
 
 @param userIds An array of users Ids to remove
 @param completion A block executed when the request has completed
 */
- (void)removeMembers:(nonnull NSArray<NSString *> *)userIds completion:(AmityRequestCompletion _Nullable)completion;

/**
 Let the server know that the user is currently viewing this channel (this automatically updates the user's readToSegment and lastMentionedSegmentt)
 A user can read multiple channels at the same time.
 */
- (void)startReading;

/**
 Let the server know that the user has stopped reading this channel (this automatically updates the user's readToSegment and lastMentionedSegment)
 */
- (void)stopReading;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
