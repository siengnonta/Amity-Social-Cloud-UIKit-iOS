//
//  AmityUserTopic.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/15/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityUser.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityTopic.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserTopic : NSObject <AmityTopic>

@property (nonnull, nonatomic) AmityUser *user;
@property (nonatomic, readonly) AmityUserEvent event;

- (instancetype)initWithUser:(AmityUser *)user andEvent:(AmityUserEvent)event;

// Disable default intiializer
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
