//
//  AmityNotificationToken.h
//  AmitySDK
//
//  Created by amity on 2/20/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AmityNotificationToken : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (void)invalidate;

@end
