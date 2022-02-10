//
//  AmityCommentEditor.h
//  AmitySDK
//
//  Created by Michael Abadi on 04/06/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityComment.h>

@class AmityMessage;

/**
   A editor encapsulates methods for managing comment.
 */
@interface AmityCommentEditor : NSObject

/**
   The context used to create the instance.
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The comment identifier associated with the instance.
 */
@property (nonnull, strong, readonly, nonatomic) AmityComment *comment;

/**
   Designated intializer.
   @param client A valid context instance.
   @param comment AmityComment instance which you want to edit
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                               comment:(nonnull AmityComment *)comment NS_DESIGNATED_INITIALIZER;

/**
   Edits the text message.
   @param text The new text
   @param completion A block executed when the request has completed.
 */
- (void)editText:(nonnull NSString *)text
      completion:(AmityRequestCompletion _Nullable)completion;

/**
   Block call of `init` and `new` because this object cannot be created directly.
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

