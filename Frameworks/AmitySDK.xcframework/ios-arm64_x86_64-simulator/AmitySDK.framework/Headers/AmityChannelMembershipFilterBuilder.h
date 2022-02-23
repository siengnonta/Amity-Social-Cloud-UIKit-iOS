//
//  AmityChannelMembershipFilterBuilder.h
//  AmitySDK
//
//  Created by Hamlet on 31.08.21.
//  Copyright © 2021 Amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The builder class for channel membership filter.
 */
@interface AmityChannelMembershipFilterBuilder : NSObject

/**
 Adds AmityChannelMembershipSearchFilter type to the builder
 If there is no value added by default builder will take value AmityChannelMembershipSearchFilterMember.
 */
- (void)addFilter:(AmityChannelMembershipSearchFilter) filter NS_SWIFT_NAME(add(filter:));

@end

NS_ASSUME_NONNULL_END
