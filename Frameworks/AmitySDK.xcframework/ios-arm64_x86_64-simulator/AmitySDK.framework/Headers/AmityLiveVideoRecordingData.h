//
//  AmityLiveVideoRecordingData.h
//  AmitySDK
//
//  Created by Nutchaphon Rewik on 21/12/2563 BE.
//  Copyright © 2563 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, AmityLiveVideoRecordingFileFormat) {
    AmityLiveVideoRecordingFileFormatMP4 = 0,
    AmityLiveVideoRecordingFileFormatFLV = 1,
    AmityLiveVideoRecordingFileFormatM3U8 = 2
};

@interface AmityLiveVideoRecordingData : NSObject

/* We will expose this soon in the future.
 
@property (nullable, strong, nonatomic) NSDate *startTime;

@property (nullable, strong, nonatomic) NSDate *stopTime;

@property (assign, nonatomic) NSTimeInterval duration;
 */

- (nullable NSURL *)urlForFileFormat:(AmityLiveVideoRecordingFileFormat)format;

@end

NS_ASSUME_NONNULL_END
