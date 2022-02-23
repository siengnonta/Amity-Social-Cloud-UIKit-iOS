//
//  AmityCommunityTopic.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/12/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityCommunity.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityTopic.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityTopic : NSObject <AmityTopic>

@property (nonnull, nonatomic) AmityCommunity *community;
@property (nonatomic, readonly) AmityCommunityEvent event;

- (instancetype)initWithCommunity:(AmityCommunity *)community andEvent:(AmityCommunityEvent)event;

// Disable default intiializer
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
