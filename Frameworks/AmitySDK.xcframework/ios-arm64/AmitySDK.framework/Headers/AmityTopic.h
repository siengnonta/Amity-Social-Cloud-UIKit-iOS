//
//  AmityTopic.h
//  AmitySDK
//
//  Created by Nishan Niraula on 11/15/21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AmityTopic <NSObject>

/// Returns subscription topic
- (nonnull NSString *)getSubscriptionTopic;

- (nonnull NSString *)topicDescription;

- (nonnull NSString *)eventDescription;

@end
