//
//  AmityCommunityParticipation.h
//  AmitySDK
//
//  Created by Nishan Niraula on 10/7/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityCommunityMember.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityParticipation : NSObject

/**
 The client used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
 The channel Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *communityId;

/**
 Designated intializer
 @param client A valid client instance
 @param channelId The Id of the channel to update
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                        andCommunityId:(nonnull NSString *)communityId NS_DESIGNATED_INITIALIZER;

/**
 Adds users to the community
 
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
 Get membership information of this community
 
 @param communityId The id for the community
 @param membershipOptions An  AmityCommunityMembershipFilterOption to filter for channel members
 @param roles The list of roles to filter. If you don't want to filter by roles, set empty array instead.
 @param sortBy The sort option that user wish to select
 */
- (nonnull AmityCollection<AmityCommunityMember *> *)getMembers:(AmityCommunityMembershipFilterOption)membershipOptions roles:(NSArray<NSString *> *)roles sortBy:(AmityCommunityMembershipSortOption)sortBy NS_SWIFT_NAME(getMembers(membershipOptions:roles:sortBy:));

/**
 Get membership information for particular user
 
 @param userId: The id of the user
 @return: Returns AmityCommunityMembership object
 */
- (nullable AmityCommunityMember *)getMember:(NSString *)userId NS_SWIFT_NAME(getMember(withId:));

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
