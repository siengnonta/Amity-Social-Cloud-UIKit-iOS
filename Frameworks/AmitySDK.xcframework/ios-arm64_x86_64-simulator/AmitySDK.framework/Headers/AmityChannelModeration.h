//
//  AmityChannelModeration.h
//  AmitySDK
//
//  Created by amity on 2/16/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <AmitySDK/AmityChannelMembershipPrivileges.h>
#import <AmitySDK/AmityClient.h>
#import <Foundation/Foundation.h>

@class AmityChannel;

NS_ASSUME_NONNULL_BEGIN

@interface AmityChannelModeration : NSObject

/**
   Designated intializer.
   @param client A valid client instance.
   @param channelId The Id of the channel to update.
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                            andChannel:(nonnull NSString *)channelId NS_DESIGNATED_INITIALIZER;

/**
   The client used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The channel Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *channelId;

/**
   Mute users
   @param userIds An array of userIds
   @param mutePeriodInSeconds (in seconds)
   @param completion A block executed when the request has completed
 */
- (void)muteMembers:(nonnull NSArray<NSString *> *)userIds
       mutePeriod:(NSUInteger)mutePeriodInSeconds
       completion:(AmityRequestCompletion _Nullable)completion;

/**
   unmute users
   @param userIds An array of userIds
   @param completion A block executed when the request has completed
 */
- (void)unmuteMembers:(nonnull NSArray<NSString *> *)userIds
         completion:(AmityRequestCompletion _Nullable)completion;

/**
   Ban users
   @param userIds An array of userIds
   @param completion A block executed when the request has completed
 */
- (void)banMembers:(NSArray<NSString *> *)userIds
      completion:(AmityRequestCompletion _Nullable)completion;

/**
   unban users
   @param userIds An array of userIds
   @param completion A block executed when the request has completed
 */
- (void)unbanMembers:(NSArray<NSString *> *)userIds
        completion:(AmityRequestCompletion _Nullable)completion;

/**
   add role
   @param role A role
   @param userIds The userIds whose role must be added
   @param completion A block executed when the request has completed
 */
- (void)addRole:(nonnull NSString *)role
        userIds:(nonnull NSArray <NSString *> *)userIds
     completion:(AmityRequestCompletion _Nullable)completion;

/**
   remove role
   @param role A role
   @param userIds The userIds whose role must be removed
   @param completion A block executed when the request has completed
 */
- (void)removeRole:(nonnull NSString *)role
           userIds:(nonnull NSArray <NSString *> *)userIds
        completion:(AmityRequestCompletion _Nullable)completion;

/**
   Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
