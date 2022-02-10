//
//  AmityImagePostBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 6/18/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityImageData.h>

@import UIKit.UIImage;

NS_ASSUME_NONNULL_BEGIN

@interface AmityImagePostBuilder : NSObject <AmityPostBuilder>

/**
Sets the text for this post.
*/
- (void)setText: (NSString *)text;

/**
 Sets the Image data for this Post. Image should be uploaded using AmityFileRepository. Those uploaded image data
 should be set here. This will automatically link that uploaded files to your post.
*/
- (void)setImageData: (NSArray<AmityImageData *> *)imageData;

@end

NS_ASSUME_NONNULL_END
