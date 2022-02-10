//
//  AmityReaction.h
//  AmitySDK
//
//  Created by Nishan Niraula on 5/21/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AmityReactionReferenceType) {
    AmityReactionReferenceTypeMessage,
    AmityReactionReferenceTypePost,
    AmityReactionReferenceTypeComment
};

NS_ASSUME_NONNULL_BEGIN

@interface AmityReaction : NSObject

/**
 Unique Id for this reaction
 */
@property (strong, readonly, nonatomic) NSString *reactionId;

/**
 Unique id for content which contains this reaction. The content can be Post, Comment or Message.
 */
@property (strong, readonly, nonatomic) NSString *referenceId;

/**
 Name of this reaction
 */
@property (strong, readonly, nonatomic) NSString *reactionName;

/**
 This reaction creation time
 */
@property (strong, readonly, nonatomic) NSDate *createdAtDate;

/**
 The reference of reaction type,
 */
@property (readonly, nonatomic) AmityReactionReferenceType referenceType;

/**
 The user id who reacted on this content
 */
@property (strong, readonly, nonatomic) NSString *reactorId;

/**
 The user name for user, who reacted on this content
 */
@property (strong, readonly, nonatomic) NSString *reactorDisplayName;

/**
 Returns the string representation for the Reference Type
 */
+ (NSString *)valueForReferenceType:(AmityReactionReferenceType)type;

/**
 Returns the enum for the string value of reference type
 */
+ (AmityReactionReferenceType)referenceTypeForValue:(NSString *)value;

@end

NS_ASSUME_NONNULL_END
