//
//  AmityPostFlagger.h
//  AmitySDK
//
//  Created by Nishan Niraula on 6/23/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityPost.h>

NS_ASSUME_NONNULL_BEGIN

@class AmityPost;

@interface AmityPostFlagger : NSObject

/**
   The context used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The post id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) NSString *postId;


/**
   Designated intializer
   @param client A valid context instance
   @param postId:  ID for the post
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                               postId:(nonnull NSString *)postId NS_DESIGNATED_INITIALIZER;

/**
 Flags the post
 */
- (void)flagPostWithCompletion:(AmityRequestCompletion _Nullable)completion;


/**
   Unflags the post
 */
- (void)unflagPostWithCompletion:(AmityRequestCompletion _Nullable)completion;

/**
 This method checks whether this particular post is flagged by you or not. If its not flagged, the completion handler
 is executed immediately.
 */
- (void)isPostFlaggedByMeWithCompletion:(void(^ _Nonnull)(BOOL isFlaggedByMe))completion;


/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
