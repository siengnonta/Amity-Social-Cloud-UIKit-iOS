//
//  AmityChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/3/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityChannel.h>
#import <AmitySDK/AmityClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityChannelQuery : NSObject

/// Channel types to query
///
/// All the channel types can be found at `AmityChannelQueryType` class. For example,
/// @code
/// let query = AmityChannelQuery()
/// query.types = [AmityChannelQueryType.standard, AmityChannelQueryType.live]
/// @endcode
/// The default value is an empty set, meaning that the query will include all channel types..
@property (nonnull, strong, nonatomic) NSSet<NSString *> *types;

/// Filtering by member status
///
/// The default value is `.all`.
@property (assign, nonatomic) AmityChannelQueryFilter filter;

/// Filter channels that contain all the `includingTags` tags in itself.
///
/// Specify an empty arary to ignore this filter.
/// The default value is an empty array.
@property (nonnull, strong, nonatomic) NSArray<NSString *> *includingTags;

/// Filter channels that do not contain all the `excludingTags` in itself.
///
/// Specify an empty arary to ignore this filter.
/// The default value is an empty array.
@property (nonnull, strong, nonatomic) NSArray<NSString *> *excludingTags;

/// Whether or not the query should return deleted channels.
///
/// Specify `true` to include deleted channels, `false` to not include deleted channels.
/// The default value is `true`.
@property (assign, nonatomic) BOOL includeDeleted;

@end

NS_ASSUME_NONNULL_END
