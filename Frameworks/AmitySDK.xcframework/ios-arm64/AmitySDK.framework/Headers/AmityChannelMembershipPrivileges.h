//
//  AmityChannelMembershipPrivileges.h
//  AmityChat
//
//  Created by Federico Zanetello on 11/4/18.
//  Copyright © 2018 amity. All rights reserved.
//
#import <Foundation/Foundation.h>

@interface AmityChannelMembershipPrivileges : NSObject

/**
   Privileges
 */
@property (nullable, strong, readonly, nonatomic) NSArray <NSString *> *privileges;
@end
