//
//  AmityUserFollowInfo+Private.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 2/6/2564 BE.
//  Copyright © 2564 BE Amity. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserFollowInfo()

- (instancetype)initWithResponse:(NSDictionary<NSString *, id> *)response;

@property (strong, nonatomic, readonly)AmityFollowResponse *follow;
@property (strong, readonly, nonatomic) AmityUserFollowCount *followCount;

@end

NS_ASSUME_NONNULL_END
