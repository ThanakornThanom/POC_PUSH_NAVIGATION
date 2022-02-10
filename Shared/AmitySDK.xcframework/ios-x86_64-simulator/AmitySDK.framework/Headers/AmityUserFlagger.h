//
//  AmityUserFlagger.h
//  AmitySDK
//
//  Created by Federico Zanetello on 11/28/18.
//  Copyright © 2018 amity. All rights reserved.
//

@import Foundation;

#import <AmitySDK/AmityClient.h>
#import <AmitySDK/AmityCollection.h>
#import <AmitySDK/AmityUser.h>

@class AmityUser;

/**
   A editor encapsulates methods for managing messages
 */
@interface AmityUserFlagger : NSObject

/**
   The context used to create the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityClient *client;

/**
   The user Id associated with the instance
 */
@property (nonnull, strong, readonly, nonatomic) AmityUser *user;

/**
   Designated intializer
   @param client A valid context instance
 */
- (nonnull instancetype)initWithClient:(nonnull AmityClient *)client
                                  user:(nonnull AmityUser *)user NS_DESIGNATED_INITIALIZER;

/**
   Flags user, this is reported to the admin panel for the moderators to see
 */
- (void)flagWithCompletion:(AmityRequestCompletion _Nullable)completion;

/**
   Unflags the user
 */
- (void)unflagWithCompletion:(AmityRequestCompletion _Nullable)completion;

/**
   The callback returns whether the logged-in user has flagged this user
 */
- (void)isFlaggedByMeWithCompletion:(void(^ _Nonnull)(BOOL isFlagByMe))completion;

/// Block call of `init` and `new` because this object cannot be created directly
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
