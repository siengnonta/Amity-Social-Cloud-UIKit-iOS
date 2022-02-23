//
//  AmityFeedRepository.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 4/13/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityPostRepository.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Repository provides access to feed and collections of feeds
 */
@interface AmityFeedRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated intializer
 @param client A valid context instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

#pragma mark - Post CRUD Deprecated

/**
 Create the which need a text represented by string value
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post.
 @param targetId: Target id for the feed. Set nil if you are creating a post on your own feed.
 @param targetType: Target type for the feed. Either community or user.
 
 */
- (void)createPost:(nonnull id<AmityPostBuilder>)builder
          targetId:(nullable NSString *)targetId
        targetType:(AmityPostTargetType)targetType
        completion:(AmityPostRequestCompletion _Nullable)completion
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Update specific post with the updated data
 @param postId: A post id represent the post object
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post. **Note** Builder should be of same type that you used to create the original post.
 */
- (void)updatePostWithPostId:(nonnull NSString *)postId
                     builder:(nonnull id<AmityPostBuilder>)builder
                  completion:(AmityPostRequestCompletion _Nullable)completion
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Delete the specific post with provided id
 @param postId: A post id represent the post object
 @param parentId: Id of the parent post. If a post has parent, then provide its id.
 */
- (void)deletePostWithPostId:(nonnull NSString *)postId
                    parentId:(nullable NSString *)parentId
                  completion:(AmityRequestCompletion _Nullable)completion
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Approve the specific post with provided id
 @param postId: A post id represent the post object
 */
- (void)approvePostWithPostId:(nonnull NSString *)postId
                  completion:(AmityRequestCompletion _Nullable)completion
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Decline the specific post with provided id
 @param postId: A post id represent the post object
 */
- (void)declinePostWithPostId:(nonnull NSString *)postId
                  completion:(AmityRequestCompletion _Nullable)completion
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Retrieves post for particular post id
 
 @param postId The id for the post
 */
- (nonnull AmityObject<AmityPost *> *)getPostForPostId:(nonnull NSString *)postId
__attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

/**
 Get the collection of reactions for particular post for provided reaction name.
 
 @param postId: Id of the post
 @param reactionName: Name of the reaction
 @return AmityCollection of AmityReaction object. Observe the changes to get results.
 
 */
- (nonnull AmityCollection<AmityReaction *> *)getReactions:(nonnull NSString *)postId reactionName:(nullable NSString *)reactionName __attribute((deprecated("Use equivalent API in AmityPostRepository instead.")));

#pragma mark - Feed

/**
 Get the collection of own feed.
 
 @param sortBy The sort option that user wish to select
 @param includeDeleted Whether to include deleted posts in query or not
 @return The AmityCollection of AmityPost  object. Observe the changes for getting the result.
 
 */
- (nonnull AmityCollection<AmityPost *> *)getMyFeedSortedBy:(AmityPostQuerySortOption)sortBy includeDeleted:(BOOL)includeDeletedPosts;

/**
 Get the collection of user feed.
 
 @param userId The user id of selected user
 @param sortBy The sort option that user wish to select
 @param includeDeleted Whether to include deleted posts in query or not
 @return The AmityCollection of AmityPost  object. Observe the changes for getting the result.
 
 */
- (nonnull AmityCollection<AmityPost *> *)getUserFeed:(NSString *)userId sortBy:(AmityPostQuerySortOption)sortBy includeDeleted:(BOOL)includeDeletedPosts;

/**
 Get the collection of global feed.
 
 @param sortBy The sort option that user wish to select
 @param includeDeleted Whether to include deleted posts in query or not
 @return The AmityCollection of AmityPost  object. Observe the changes for getting the result.
 
 */
- (nonnull AmityCollection<AmityPost *> *)getGlobalFeed;

- (nonnull AmityCollection<AmityPost *> *)getCustomPostRankingGlobalfeed;

/**
 Get the collection of community feed.
 
 @param communityId The community id of selected community
 @param sortBy The sort option that user wish to select
 @param includeDeleted Whether to include deleted posts in query or not
 @param feedType The type option that user wish to select
 @return The AmityCollection of AmityPost  object. Observe the changes for getting the result.
 */
- (nonnull AmityCollection<AmityPost *> *)getCommunityFeedWithCommunityId:(nonnull NSString *)communityId
                                                               sortBy:(AmityPostQuerySortOption)sortBy
                                                       includeDeleted:(BOOL)includeDeletedPosts
                                                                 feedType:(AmityFeedType)feedType;

@end

NS_ASSUME_NONNULL_END
