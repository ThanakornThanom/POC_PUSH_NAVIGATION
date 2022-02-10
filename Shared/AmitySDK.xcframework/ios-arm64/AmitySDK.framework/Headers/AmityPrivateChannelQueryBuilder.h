//
//  AmityPrivateChannelQueryBuilder.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/4/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityClient.h>

NS_ASSUME_NONNULL_BEGIN
@interface AmityPrivateChannelQueryBuilder : NSObject

@property (nonnull, nonatomic, strong) NSArray<NSString *> *includingTags;
@property (nonnull, nonatomic, strong) NSArray<NSString *> *excludingTags;
@property (assign, nonatomic) BOOL includeDeletedChannels;

- (nonnull instancetype)initWithIncludingTags:(nullable NSArray<NSString *> *)includingTags
                                excludingTags:(nullable NSArray<NSString *> *)excludingTags
                               includeDeleted:(BOOL)includeDeletedChannels NS_DESIGNATED_INITIALIZER;

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;
@end
NS_ASSUME_NONNULL_END
