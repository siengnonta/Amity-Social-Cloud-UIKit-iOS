//
//  AmityFileRepository.h
//  AmitySDK
//
//  Created by Nishan Niraula on 7/8/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityMessage.h>
#import <AmitySDK/AmityImageData.h>
#import <AmitySDK/AmityFileData.h>

@class UIImage;
@class AmityUploadableFile;
@class AmityVideoData;

typedef void (^AmityFileUploadCompletion)(AmityFileData * _Nullable fileData, NSError * _Nullable error);
typedef void (^AmityImageUploadCompletion)(AmityImageData * _Nullable imageData, NSError * _Nullable error);
typedef void (^AmityVideoUploadCompletion)(AmityVideoData * _Nullable videoData, NSError * _Nullable error);
typedef void (^AmityUploadProgressHandler)(double progress);
typedef void (^AmityDownloadProgressHandler)(double progress);

NS_ASSUME_NONNULL_BEGIN

@interface AmityFileRepository : NSObject

@property (strong, readonly, nonatomic) AmityClient *client;
/**
 Initializes AmityFileRepository class
 
 @param client: Valid AmityClient instance
 */
- (instancetype)initWithClient:(AmityClient *)client NS_DESIGNATED_INITIALIZER;

/**
 Asynchronously uploads an image to server. This method also allows you to track the progress of the upload.
 
 @discussion
 This method is not suitable for uploading image of large size. We recommend using URL based `uploadImage(withURL:_)` method for uploading image of any size.
 
 @param image: UIImage to be uploaded
 @param progressHandler: Progress block called during upload process. This block can be called mulltiple time and the value of progress range from 0.0 - 1.0
 @param completion: Completion block called once the upload operation is finished. If upload was successful, then uploaded image data is returned else error is returned.
 */
- (void)uploadImage:(UIImage *)image progress:(nullable AmityUploadProgressHandler)progressHandler completion:(AmityImageUploadCompletion)completionBlock;

// FIXME: Add document
- (void)uploadVideoWithUrl:(NSURL *)videoUrl
                  progress:(nullable AmityUploadProgressHandler)progressHandler
                completion:(AmityVideoUploadCompletion)completionBlock;

/**
 Asynchronously Uploads an image to server. This method also allows you to track the progress of the upload.
 
 @discussion
 SDK generates multiple (small, medium & large) versions of images based on `isFullImage` parameter.
 
 @param imageURL: URL of the image to upload. This URL should be from local file system.
 @param isFullImage: If this image is the large sized image. If this parameter is true, server generates images of multiple size.
 @param progressHandler: Progress block called during upload process. This block can be called mulltiple time and the value of progress range from 0.0 - 1.0
 @param completion: Completion block called once the upload operation is finished. If upload was successful, then uploaded image data is returned else error is returned.
 */
- (void)uploadImageWithURL:(NSURL *)imageURL isFullImage:(BOOL)isFullImage progress:(nullable AmityUploadProgressHandler)progressHandler completion:(AmityImageUploadCompletion)completion;

/**
 Asynchronously uploads a file to server. This method also allows you to track the progress of the upload.
 
 @discussion
 This method is not suitable for uploading file of large size. We recommend using URL based `uploadFile(withURL:_)` method for uploading files of any size.
 
 @param file: A file to be uploaded.
 @param progress: Progress block called during upload process. This block can be called mulltiple time and the value of progress range from 0.0 - 1.0
 @param completion: Completion block called once the upload operation is finished. If upload was successful, then uploaded file data is returned else error is returned.
 */
- (void)uploadFile:(AmityUploadableFile *)file progress:(nullable AmityUploadProgressHandler)progressHandler completion:(AmityFileUploadCompletion)completionBlock;

/**
 Asynchronously uploads a file to server. This method also allows you to track the progress of the upload.
 
 @param url: URL of the file in local file system to be uploaded
 @param fileName: Name for the file to be uploaded. If file name is not specified, it is automatically determined from the URL.
 @param progress: Progress block called during upload process. This block can be called mulltiple time and the value of progress range from 0.0 - 1.0
 @param completion: Completion block called once the upload operation is finished. If upload was successful, then uploaded file data is returned else error is returned.
 */
- (void)uploadFileWithURL:(NSURL *)fileURL fileName:(nullable NSString *)fileName progress:(nullable AmityUploadProgressHandler)progressHandler completion:(AmityFileUploadCompletion)completion;

/**
 Downloads image asynchronously from the file server. Once the download is complete, user is notified through completion handler in main thread.
 
 @discussion Image downloaded using AmityFileRepository are not cached by SDK. This method is not suitable for downloading image of large size. We recommend using URL based `downloadImage(withFileId: _)` method.
 
 @param url: The URL of the image to be downloaded.
 @param size: The size in which image is to be downloaded.
 @param completion: Completion block called once download operation is complete. If download was successful, then UIImage is returned else error is returned.
 */
- (void)downloadImageAsDataFromURL:(NSString *)url size:(AmityMediaSize)size completion:(void (^)(UIImage * _Nullable image, AmityMediaSize size, NSError * _Nullable error))completion;

/**
 Downloads image asynchronously from the file server. Once the download is complete, user is notified through completion handler in main thread.
 
 @discussion
 This method downloads the image data and writes it to a file in `Caches` directory in file system. If the download is success, this URL of the downloaded file will be returned. Incase of error, an error object will be returned through completion handler. It is upto the user to consume the file directly from the location provided or move it to any other appropriate location.
 
 @code
 Example:
 let image = UIImage(contentsOfFile: <downloadedURL>.path)
 @endcode
 
 @Note Image downloaded using AmityFileRepository are not cached by SDK. User should maintain their own cache system.
 
 @param url: The URL for the image to be downloaded
 @param size: The size in which image is to be downloaded.
 @param completion: Completion block called once download operation is complete. If download was successful, then URL is returned else error is returned.
 */
- (void)downloadImageFromURL:(NSString *)url size:(AmityMediaSize)size completion:(void (^)(NSURL * _Nullable imageURL, NSError * _Nullable error))completion;

/**
 Downloads file asynchronously from the file server. Once the download is complete, user is notified through completion handler in main thread.
 
 @discussion
 This method is not suitable for downloading file of large size. We recommend using URL based `downloadFile(withFileId: _)` method.
 
 @Note
 Files downloaded using AmityFileRepository are not cached by SDK.
 
 @param url: URL of the file to be downloaded
 @param completion: Returns the downloaded file if success. Else returns error
 */
- (void)downloadFileAsDataFromURL:(NSString *)url completion:(void (^)(NSData * _Nullable file, NSError * _Nullable error))completion;

/**
 Downloads image asynchronously from the file server. Once the download is complete, user is notified through completion handler in main thread.
 
 @discussion
 Files are downloaded directly to file system in `Caches` directory. If the download is success, this URL of the downloaded file will be returned. Incase of error, an error object will be returned through completion handler. It is upto the user to consume the file directly from the location provided or move it to any other appropriate location.
 
 @Note
 Files downloaded using AmityFileRepository are not cached by SDK.
 
 @param url: URL of the file to be downloaded
 @param completion: Block to be executed after download operation is complete. Returns URL of the downloaded file in case of success else returns error
 */
- (void)downloadFileFromURL:(NSString *)url completion:(void (^)(NSURL * _Nullable fileURL, NSError * _Nullable error))completion;

/**
 Notifies user about progress of particular upload.
 
 @discussion Sometimes you would want to observe the progress of particular upload. Example: you are sending an image message and want to show progress indicator for image. This method lets you track the progress of the upload.
 
 @param uploadId: Identifier for particular upload. Example: For message this can be messageId. Refer to documentation for more details
 @param progress: Returns progress value ranging from 0.0 - 1.0. This handler can get called multiple times.
 */
- (void)getUploadProgressForUploadId:(nonnull NSString *)url progress:(nonnull AmityUploadProgressHandler)progressHandler;

/**
 Cancels the download of file from FileService
 
 @param url: URL of the file being downloaded
 */
- (void)cancelFileDownload:(NSString *)url;

/**
 Cancels the download of images from File Service
 
 @param url: URL of the image being downloaded
 @param size: Size of image
 */
- (void)cancelImageDownload:(NSString *)url size:(AmityMediaSize)size;

/**
 Prevent direct initialization of this class.
 */
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
