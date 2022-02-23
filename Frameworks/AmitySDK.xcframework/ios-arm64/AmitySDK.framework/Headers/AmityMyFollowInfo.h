//
//  AmityMyFollowInfo.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 17/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <AmitySDK/AmityUserFollowCount.h>
#import <AmitySDK/AmityFollowResponse.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityMyFollowInfo : NSObject

@property (assign, readonly, nonatomic) int followersCount;
@property (assign, readonly, nonatomic) int followingCount;
@property (assign, readonly, nonatomic) int pendingCount;

@end

NS_ASSUME_NONNULL_END
