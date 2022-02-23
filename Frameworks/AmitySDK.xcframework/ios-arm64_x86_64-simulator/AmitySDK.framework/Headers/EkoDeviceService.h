//
//  EkoApp.h
//  AmitySDK
//
//  Created by David Zhang on 3/1/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EkoDeviceService : NSObject

+ (instancetype)sharedInstance;

// returns current device Id, generate a new one if needed
- (nonnull NSString *)deviceId;

// returns device kind and model in a dictionary
- (nonnull NSDictionary <NSString *, NSString *> *)deviceInfo;

@end

NS_ASSUME_NONNULL_END
