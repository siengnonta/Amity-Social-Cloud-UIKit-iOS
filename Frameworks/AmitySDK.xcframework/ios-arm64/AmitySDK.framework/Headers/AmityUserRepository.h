//
//  AmityUserRepository.h
//  AmitySDK
//
//  Created by amity on 1/25/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUser.h>
#import <AmitySDK/AmityUserListFeedServicable.h>
#import <AmitySDK/AmityFollowRelationship.h>
#import <AmitySDK/AmityUserFollowManager.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access users and collections
 */
@interface AmityUserRepository : NSObject<AmityUserListFeedServicable>

@property (strong, readonly, nonatomic) AmityClient *client;

/**
   Designated intializer

   @param client A valid context instance
   @return returns the instance
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
   @param userId userId
 */
- (nonnull AmityObject<AmityUser *> *)getUser:(nonnull NSString *)userId;

/**
   Search an user base on the display name

   @param displayName The display name of the user we want to search
   @param sortBy The sort option provided by AmityUserSortOption
   @return returns the AmityCollection of all AmityUsers with the desired displayName
 */
- (nonnull AmityCollection<AmityUser *> *)searchUser:(NSString *)displayName
                                          sortBy:(AmityUserSortOption)sortBy;

/**
   Get all of the available users

   @param sortBy The sort option provided by AmityUserSortOption
   @return returns the AmityCollection of all AmityUsers
 */
- (nonnull AmityCollection<AmityUser *> *)getUsers:(AmityUserSortOption)sortBy;

/**
   User's follow management object.
 */
@property (nonnull, strong, readonly, nonatomic) AmityUserFollowManager *followManager;

// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
