//
//  AmityUserFollowCount.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 2/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserFollowCount : NSObject

@property (strong, readonly, nonatomic) NSString *userId;
@property (assign, readonly, nonatomic) int followersCount;
@property (assign, readonly, nonatomic) int followingCount;
@property (assign, readonly, nonatomic) int pendingCount;

@end

NS_ASSUME_NONNULL_END
