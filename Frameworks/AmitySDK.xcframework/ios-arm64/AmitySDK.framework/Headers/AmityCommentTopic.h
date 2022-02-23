//
//  AmityCommentTopic.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/12/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityComment.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityTopic.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommentTopic : NSObject <AmityTopic>

@property (nonnull, nonatomic) AmityComment *comment;
@property (nonatomic, readonly) AmityCommentEvent event;

- (instancetype)initWithComment:(AmityComment *)comment andEvent:(AmityCommentEvent)event;

// Disable default intiializer
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
