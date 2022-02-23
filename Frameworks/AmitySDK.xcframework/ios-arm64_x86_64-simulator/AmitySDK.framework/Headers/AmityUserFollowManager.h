//
//  AmityUserFollowManager.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 1/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityFollowRelationship.h>
#import <AmitySDK/AmityFollowResponse.h>
#import <AmitySDK/AmityUserFollowInfo.h>
#import <AmitySDK/AmityMyFollowInfo.h>

typedef void (^AmityFollowRequestCompletion)(BOOL success, AmityFollowResponse * _Nullable response, NSError * _Nullable error);
typedef void (^AmityUserFollowInfoRequestCompletion)(BOOL success, AmityUserFollowInfo * _Nullable followInfo, NSError * _Nullable error);
typedef void (^AmityMyFollowInfoRequestCompletion)(BOOL success, AmityMyFollowInfo * _Nullable followInfo, NSError * _Nullable error);

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserFollowManager : NSObject

/**
 Create a follow request to the particular user
 
 @param userId The id of user we are sending the request to.
 @param completion A block executed when this request is complete.
 */
- (void)followUserWithUserId:(NSString *)userId completion:(nullable AmityFollowRequestCompletion)completion;

/**
 Cancel a pending request or unfollow the particular user
 
 @param userId The id of user we want to unfollow or withdraw a pending request.
 @param completion A block executed when this request is complete.
 */
- (void)unfollowUserWithUserId:(NSString *)userId completion:(nullable AmityFollowRequestCompletion)completion;

/**
 Accept an incoming request of a particular user
 
 @param userId The id of user we want to accept a request..
 @param completion A block executed when this request is complete.
 */
- (void)acceptUserRequestWithUserId:(NSString *)userId completion:(nullable AmityFollowRequestCompletion)completion;

/**
 Decline an incoming request of a particular user or remove the follower
 
 @param userId The id of user we want decline a request.
 @param completion A block executed when this request is complete.
 */
- (void)declineUserRequestWithUserId:(NSString *)userId completion:(nullable AmityFollowRequestCompletion)completion;

/**
 Get my follow information in order to see following count, follower count and pending count
 
 @param completion A block executed when this request is complete.
 */
- (void)getMyFollowInfoWithCompletion:(AmityMyFollowInfoRequestCompletion)completion;

/**
 Get my collection of follower users
 
 @param option An option for querying
 */
- (AmityCollection<AmityFollowRelationship *> *)getMyFollowerListWithOption:(AmityFollowQueryOption)option;

/**
 Get my collection of following users
 
 @param option An option for querying
 */
- (AmityCollection<AmityFollowRelationship *> *)getMyFollowingListWithOption:(AmityFollowQueryOption)option;
    
/**
 Get particular user's follow information in order to see following count, follower count and relation status
 
 @param completion A block executed when this request is complete.
 */
- (void)getUserFollowInfoWithUserId:(NSString *)userId completion:(nullable AmityUserFollowInfoRequestCompletion)completion;

/**
 Get the particular user a collection of follower users
 */
- (AmityCollection<AmityFollowRelationship *> *)getUserFollowerListWithUserId:(NSString *)userId;

/**
 Get the particular user a  collection of follower users
 */
- (AmityCollection<AmityFollowRelationship *> *)getUserFollowingListWithUserId:(NSString *)userId;

-(void)clearAmityFollowRelationshipLocalData;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
