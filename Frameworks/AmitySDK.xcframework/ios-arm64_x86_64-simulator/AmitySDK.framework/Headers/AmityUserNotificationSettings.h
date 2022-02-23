//
//  EkoNotifiableModule.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 10/3/2564 BE.
//  Copyright © 2564 BE amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityUserNotificationModule.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityUserNotificationSettings : NSObject

@property (nonatomic, assign) BOOL isEnabled;
@property (nonatomic, strong) NSArray<AmityUserNotificationModule *> *modules;

@end

NS_ASSUME_NONNULL_END
