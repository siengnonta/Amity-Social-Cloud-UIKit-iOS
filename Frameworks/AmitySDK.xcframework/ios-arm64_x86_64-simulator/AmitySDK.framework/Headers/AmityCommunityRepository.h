//
//  AmityCommunityRepository.h
//  AmitySDK
//
//  Created by Michael Abadi on 03/07/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityCommunityCategory.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityCommunityNotificationsManager.h>
#import <AmitySDK/AmityCommunityMember.h>

@class AmityCommunity;

typedef void (^AmityCommunityRequestCompletion)(AmityCommunity * _Nullable, NSError * _Nullable);

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access to community and collections of communities
 */
@interface AmityCommunityRepository : NSObject


@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Designated intializer
 @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Create the which need a text represented by string value
 @param builder: A type of AmityCommunityBuilder object.
 */
- (void)createCommunityWithBuilder:(nonnull id<AmityCommunityBuilder>)builder completion:(nonnull AmityCommunityRequestCompletion)completion;

/**
 Update specific community with the updated data
 @param communityId A community id represent the group object
 @param builder: A type of AmityCommunityBuilder object. You can use AmityCommunityDataBuilder to update community data.
 */
- (void)updateCommunityWithCommunityId:(nonnull NSString *)communityId builder:(nonnull id<AmityCommunityBuilder>)builder completion:(nonnull AmityCommunityRequestCompletion)completion NS_SWIFT_NAME(updateCommunity(withId:builder:completion:));

/**
 Delete the specific community
 @param communityId A community id represent the community object
 */
- (void)deleteCommunityWithCommunityId:(nonnull NSString *)communityId
                            completion:(AmityRequestCompletion _Nullable)completion NS_SWIFT_NAME(deleteCommunity(withId:completion:));

/**
 Get the collection of communities.
 
 @param displayName: Search commnunities based on display name. Set it nil if you want to fetch all communities.
 @param filter: The filter option that user wish to select
 @param sortBy: The sort option that user wish to select
 @param categoryId: Category id for the community. This value is optional.
 @param includeDeleted: Should include deleted communities or not in the collection
 
 @return The AmityCollection of AmityCommunity  object. Observe the changes for getting the result.
 */
- (nonnull AmityCollection<AmityCommunity *> *)getCommunitiesWithDisplayName:(nullable NSString *)displayName
                                                                      filter:(AmityCommunityQueryFilter)filter
                                                                      sortBy:(AmityCommunitySortOption)sortBy
                                                                  categoryId:(nullable NSString *)categoryId
                                                              includeDeleted:(BOOL)includeDeletedCommunities NS_SWIFT_NAME(getCommunities(displayName:filter:sortBy:categoryId:includeDeleted:));

/**
 @abstract Community level push notifications management object.
 */
- (nonnull AmityCommunityNotificationsManager *)notificationManagerForCommunityId:(nonnull NSString *)communityId;

/**
 Retrieves community for particular community id
 
 @param communityId The id for the community
 */
- (nonnull AmityObject<AmityCommunity *> *)getCommunityWithId:(nonnull NSString *)communityId NS_SWIFT_NAME(getCommunity(withId:));

/**
 Fetches all the categories for community.
 
 @param sortedBy: Sort option for categories
 @param includeDeleted: Should include deleted categories or not for collection
 */
- (nonnull AmityCollection<AmityCommunityCategory *> *)getCategoriesSortBy:(AmityCommunityCategoriesSortOption)sortBy includeDeleted:(BOOL)includeDeletedCategories NS_SWIFT_NAME(getCategories(sortBy:includeDeleted:));

/**
 Join community for particular community id
 
 @param communityId The id for the community
 */
- (void)joinCommunityWithId:(nonnull NSString *)communityId
                          completion:(AmityRequestCompletion _Nullable)completion;

/**
 Leave community for particular community id
 
 @param communityId The id for the community
 */
- (void)leaveCommunityWithId:(nonnull NSString *)communityId
                           completion:(AmityRequestCompletion _Nullable)completion;

/**
 Get collection of trending communities
 */
- (AmityCollection<AmityCommunity *> *)getTrendingCommunities;

/**
 Get collection of recommended communities
 */
- (AmityCollection<AmityCommunity *> *)getRecommendedCommunities;

/**
 Search members in provided community
 
 @param communityId The id for the community to make a search
 @param displayName The display name to search in provided community
 @param membership The membership option that user wish to select
 @param roles The list of roles to filter. If you don't want to filter by roles, set empty array instead.
 @param sortBy The sort option that user wish to select
 */
- (nonnull AmityCollection<AmityCommunityMember *> *)searchMembers:(NSString *)communityId displayName:(NSString *) displayName membershipOptions:(AmityCommunityMembershipFilterOption)membershipOptions roles:(NSArray<NSString *> *)roles sortBy:(AmityCommunityMembershipSortOption)sortBy NS_SWIFT_NAME(searchMembers(communityId:displayName:membership:roles:sortBy:));

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

