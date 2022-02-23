//
//  EkoPostCreator.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 4/21/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "AmityClient.h"
#import "AmityBuilder.h"
#import "AmityFeedRepository.h"

@class AmityPost;

/**
 A editor encapsulates methods for managing post
 */
@interface EkoPostCreator : NSObject

/**
 The context used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
 Designated intializer
 @param client: A valid client instance
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Create the which need a text represented by string value
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post.
 @param targetId: Target id for the feed. Set nil if you are creating a post on your own feed.
 @param targetType: Target type for the feed. Either community or user.
 
 */
- (void)createPost:(nonnull id<AmityPostBuilder>)builder
          targetId:(nullable NSString *)targetId
        targetType:(AmityPostTargetType)targetType
        completion:(AmityPostRequestCompletion _Nullable)completion;

/**
 Create the which need a text represented by string value
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post.
 @param targetId: Target id for the feed. Set nil if you are creating a post on your own feed.
 @param targetType: Target type for the feed. Either community or user.
 @param metadata The metadata for the post, it can contain information about mentions
 @param mentionees The mentiones for the post
 
 */
- (void)createPost:(nonnull id<AmityPostBuilder>)builder
          targetId:(nullable NSString *)targetId
        targetType:(AmityPostTargetType)targetType
          metadata:(nullable NSDictionary<NSString *, id> *)metadata
        mentionees:(nullable NSArray<NSDictionary<NSString *, id> *> *)mentionees
        completion:(AmityPostRequestCompletion _Nullable)completion;

/**
 Update specific post with the updated data
 @param postId: A post id represent the post object
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post. **Note** Builder should be of same type that you used to create the original post.
 */
- (void)updatePostWithPostId:(nonnull NSString *)postId
                     builder:(nonnull id<AmityPostBuilder>)builder
                  completion:(AmityPostRequestCompletion _Nullable)completion;

/**
 Update specific post with the updated data
 @param postId: A post id represent the post object
 @param builder: A type of AmityPostBuilder object. You can use AmityTextPostBuilder to create text post. **Note** Builder should be of same type that you used to create the original post.
 @param metadata The metadata for the post, it can contain information about mentions
 @param mentionees The mentiones for the post
 */
- (void)updatePostWithPostId:(nonnull NSString *)postId
                     builder:(nonnull id<AmityPostBuilder>)builder
                    metadata:(nullable NSDictionary<NSString *, id> *)metadata
                  mentionees:(nullable NSArray<NSDictionary<NSString *, id> *> *)mentionees
                  completion:(AmityPostRequestCompletion _Nullable)completion;

/**
 Delete the specific post with provided id
 @param postId: A post id represent the post object
 @param parentId: Id of the parent post. If a post has parent, then provide its id.
 */
- (void)deletePostWithPostId:(nonnull NSString *)postId
                    parentId:(nullable NSString *)parentId
                  hardDelete:(BOOL)hardDelete
                  completion:(AmityRequestCompletion _Nullable)completion;

/// Approve the specific post with provided id
/// @param postId A post id represent the post object
- (void)approvePostWithPostId:(nonnull NSString *)postId
                  completion:(AmityRequestCompletion _Nullable)completion;

/// Decline the specific post with provided id
/// @param postId A post id represent the post object
- (void)declinePostWithPostId:(nonnull NSString *)postId
                  completion:(AmityRequestCompletion _Nullable)completion;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
