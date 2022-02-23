//
//  AmityClientErrorDelegate.h
//  AmitySDK
//
//  Created by Federico Zanetello on 5/11/18.
//  Copyright © 2018 amity. All rights reserved.
//

@protocol AmityClientErrorDelegate <NSObject>

- (void)didReceiveAsyncError:(nonnull NSError *)error;

@end
