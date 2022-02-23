//
//  AmityPostTopic.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/12/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityPost.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityTopic.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityPostTopic : NSObject <AmityTopic>

@property (nonnull, nonatomic) AmityPost *post;
@property (nonatomic, readonly) AmityPostEvent event;

- (instancetype)initWithPost:(AmityPost *)post andEvent:(AmityPostEvent)event;

// Disable default intiializer
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
