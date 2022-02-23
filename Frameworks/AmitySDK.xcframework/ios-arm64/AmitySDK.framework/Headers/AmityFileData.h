//
//  AmityFileData.h
//  AmitySDK
//
//  Created by Nishan Niraula on 7/9/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Class containing information about uploaded images to FileService.
__attribute__((objc_subclassing_restricted))
@interface AmityFileData : NSObject

@property (strong, nonatomic) NSString *fileId;
@property (strong, nonatomic) NSString *fileURL;
@property (strong, nonatomic) NSDictionary<NSString *, id> *attributes;

- (instancetype)initWithResponse:(NSDictionary<NSString *, id> *)response;

@end

NS_ASSUME_NONNULL_END
