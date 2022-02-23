//
//  AmityRoleFilter.h
//  AmitySDK
//
//  Created by Nontapat Siengsanor on 18/3/2564 BE.
//  Copyright © 2564 BE amity. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AmityRoleFilterType) {
    AmityRoleFilterTypeOnly,
    AmityRoleFilterTypeNot,
    AmityRoleFilterTypeAll
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityRoleFilter : NSObject

@property (nonatomic, assign) AmityRoleFilterType filterType;
@property (nonatomic, strong) NSArray<NSString *> * _Nullable roleIds;

/**
 Initializes AmityRoleFilter with AmityRoleFilterTypeOnly
 A filter for receiving the particular user roles.
 
 @param roleIds A set of role id the user would like to receive push notification from.
 */
+ (instancetype)onlyFilterWithRoleIds:(NSArray<NSString *> *)roleIds;

/**
 Initializes AmityRoleFilter with AmityRoleFilterTypeAll
 A filter for receiving any type of user roles.
 */
+ (instancetype)allFilter;

@end


NS_ASSUME_NONNULL_END
