//
//  AmityTextPostBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 6/15/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <AmitySDK/AmityBuilder.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityTextPostBuilder : NSObject <AmityPostBuilder>

/**
 Sets the current text as  provided text
 */
- (void)setText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
