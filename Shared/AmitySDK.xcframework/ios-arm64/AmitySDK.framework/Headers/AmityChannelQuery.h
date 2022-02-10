//
//  AmityChannelQuery.h
//  AmitySDK
//
//  Created by Michael Abadi Santoso on 2/3/20.
//  Copyright © 2020 amity. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityChannel.h>
#import <AmitySDK/AmityClient.h>

NS_ASSUME_NONNULL_BEGIN

@interface AmityChannelQuery : NSObject

@property (nonatomic, assign) AmityClient *client;
@property (nullable, nonatomic, strong) NSSet<NSString *> *types;
@property (nonatomic, assign) AmityChannelQueryFilter filter;
@property (nonnull, nonatomic, strong) NSArray<NSString *> *includingTags;
@property (nonnull, nonatomic, strong) NSArray<NSString *> *excludingTags;
@property (assign, nonatomic) BOOL includeDeletedChannels;

- (nonnull AmityCollection<AmityChannel *> *)query;

@end

NS_ASSUME_NONNULL_END
