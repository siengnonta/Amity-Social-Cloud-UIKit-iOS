//
//  AmityCommunityModeration.h
//  AmitySDK
//
//  Created by Michael Abadi on 31/08/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <AmitySDK/AmityClient.h>
#import <Foundation/Foundation.h>
@class AmityCommunity;

NS_ASSUME_NONNULL_BEGIN

/**
   A community moderator object
 */

@interface AmityCommunityModeration : NSObject

/**
   Designated intializer.
   @param client A valid client instance.
   @param communityId The Id of the channel to update.
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                          andCommunity:(nonnull NSString *)communityId NS_DESIGNATED_INITIALIZER;

/**
   The client used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;
/**
   The community Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *communityId;

/**
   Ban members
   @param userIds An array of userIds
   @param completion A block executed when this request is complete.
 */
- (void)banMembers:(nonnull NSArray<NSString *> *)userIds
      completion:(AmityRequestCompletion _Nullable)completion;

/**
   Unban members
   @param userIds An array of userIds
   @param completion A block executed when this request is complete.
 */
- (void)unbanMembers:(nonnull NSArray<NSString *> *)userIds
        completion:(AmityRequestCompletion _Nullable)completion;

/**
 Assigns roles to users.
 
 @param roles: Roles to be assigned
 @param userIds: Id of users to whom this roles is to be assigned
 @param completion: A block executed when this request is complete.
 */
- (void)addRoles:(nonnull NSArray<NSString *> *)roles userIds:(nonnull NSArray<NSString *> *)userIds completion:(nullable AmityRequestCompletion)completion;

/**
 Assigns role to users.
 
 @param role: Role to be assigned
 @param userIds: Id of users to whom this roles is to be assigned
 @param completion: A block executed when this request is complete.
 */
- (void)addRole:(nonnull NSString *)role userIds:(nonnull NSArray<NSString *> *)userIds completion:(nullable AmityRequestCompletion)completion
__attribute((deprecated("Use addRoles method instead")));

/**
 Removes roles assigned to users.
 
 @param roles: Roles to be removed
 @param userIds: Array of user ids from which this roles is to be removed
 @param completion: A block executed when this request is complete.
 */
- (void)removeRoles:(nonnull NSArray<NSString *> *)roles userIds:(nonnull NSArray<NSString *> *)userIds completion:(nullable AmityRequestCompletion)completion;

/**
 Removes role assigned to users.
 
 @param role: Role to be removed
 @param userIds: Array of user ids from which this roles is to be removed
 @param completion: A block executed when this request is complete.
 */
- (void)removeRole:(nonnull NSString *)role userIds:(nonnull NSArray<NSString *> *)userIds completion:(nullable AmityRequestCompletion)completion
__attribute((deprecated("Use removeRoles method instead")));

/**
   Block call of `init` and `new` because this object cannot be created directly
 */
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
