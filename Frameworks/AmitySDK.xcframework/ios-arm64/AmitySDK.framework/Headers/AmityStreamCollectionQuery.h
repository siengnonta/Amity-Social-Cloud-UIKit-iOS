//
//  AmityStreamCollectionQuery.h
//  AmitySDK
//
//  Created by Nutchaphon Rewik on 4/2/2564 BE.
//  Copyright © 2564 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AmityStreamStatus);

NS_ASSUME_NONNULL_BEGIN

/// The query predicate for "getStreamsCollection".
@interface AmityStreamCollectionQuery : NSObject

/// Include status as part of stream collection querying.
- (void)includeStatus:(AmityStreamStatus)status NS_SWIFT_NAME(includeStatus(_:));

@end

NS_ASSUME_NONNULL_END
