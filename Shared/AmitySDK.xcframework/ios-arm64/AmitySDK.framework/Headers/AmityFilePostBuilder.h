//
//  AmityFilePostBuilder.h
//  AmitySDK
//
//  Created by Nishan Niraula on 6/18/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityBuilder.h>
#import <AmitySDK/AmityFileData.h>


NS_ASSUME_NONNULL_BEGIN

@interface AmityFilePostBuilder : NSObject <AmityPostBuilder>

/**
 Sets the text for this post.
 */
- (void)setText:(NSString *)text;

/**
 Sets the file data for this Post. Files should be uploaded using AmityFileRepository. Those uploaded files data
 should be set here. This will automatically link that uploaded files to your post.
*/
- (void)setFileData:(NSArray<AmityFileData *> *)fileData;


@end

NS_ASSUME_NONNULL_END
