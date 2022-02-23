//
//  EkoCommunityNotificationEventModel.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 3/3/2564 BE.
//  Copyright © 2564 BE amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityCommunityNotificationEvent.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityCommunityNotificationSettings : NSObject

@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, assign) BOOL isUserEnabled;
@property (nonatomic, strong) NSArray<AmityCommunityNotificationEvent *> *events;

- (instancetype)initWithResponse:(NSDictionary<NSString *, id> *)response;

@end

NS_ASSUME_NONNULL_END
