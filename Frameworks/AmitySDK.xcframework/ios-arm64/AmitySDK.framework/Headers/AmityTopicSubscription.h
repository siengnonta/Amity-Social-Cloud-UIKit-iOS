//
//  AmityTopicSubscription.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/11/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityTopic.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityTopicSubscription : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;

/// Initializes instance of this class
/// @param client Instance of AmityClient
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/// Subscribes to particular topic.
///
/// @param topic Topic to subscribe. There are 4 topics that you can subscribe.
/// * `AmityUserTopic`,
/// - `AmityPostTopic`,
/// - `AmityCommunityTopic`,
/// - `AmityCommentTopic`.
/// Each topic can contain one or more events that you can subscribe to. Please look into documentation of respective topic for more details.
///
/// @param completion Completion handler called when this action is successful or fails.
- (void)subscribeTopic:(id<AmityTopic>)topic withCompletion:(AmityRequestCompletion)completion;

/// Unsubscribes from particular topic.
/// @param topic Topic to unsubscribe from.
/// @param completion Completion handler to be called when this action succeeds or fails.
- (void)unsubscribeTopic:(id<AmityTopic>)topic withCompletion:(AmityRequestCompletion)completion;

// Default initializer is not available
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
