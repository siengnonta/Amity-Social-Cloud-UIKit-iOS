//
//  AmityUserListFeedServicable.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 4/13/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityChannel.h>

@protocol AmityUserListFeedServicable <NSObject>

@required
- (nonnull AmityCollection<AmityUser *> *)searchUser:(nonnull NSString *)displayName
                                          sortBy:(AmityUserSortOption)sortBy;

- (nonnull AmityCollection<AmityUser *> *)getUsers:(AmityUserSortOption)sortBy;

@end
