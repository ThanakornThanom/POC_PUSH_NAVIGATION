//
//  AmityClient.h
//  AmitySDK
//
//  Created by amity on 1/18/18.
//  Copyright © 2018 amity. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AmitySDK/AmityClientErrorDelegate.h>
#import <AmitySDK/AmityEnums.h>
#import <AmitySDK/AmityObject.h>
#import <AmitySDK/AmityUserNotificationsManager.h>
#import <AmitySDK/AmityMentionConfigurations.h>

@class AmityUser;
@class UIImage;
@class AmityUserUpdateBuilder;

typedef void (^AmityRequestCompletion)(BOOL success, NSError * _Nullable error);
typedef void (^AmityPermissionCompletion)(BOOL hasPermission);

/**
 @abstract SDK entry point.
 @discussion A valid context instance should be used to create other SDK resources.
 @warning An instance of `AmityClient` should be initiated with an Application key and be retained by the caller.
 */
__attribute__((objc_subclassing_restricted))
@interface AmityClient : NSObject

/**
 @abstract Connection status.
 @note This property supports KVO.
 */
@property (readonly, nonatomic) AmityConnectionStatus connectionStatus;

/**
 @abstract The Id of the current user.
 */
@property (nullable, readonly, nonatomic) NSString *currentUserId;

/**
 @abstract The current user object.
 */
@property (nullable, readonly, nonatomic) AmityObject<AmityUser *> *currentUser;

/**
 @abstract User Level Notification Management object.
 */
@property (nonnull, readonly, nonatomic) AmityUserNotificationsManager *notificationManager;

/**
 @abstract Mention configurations object.
 */
@property (nullable, readonly, nonatomic) AmityMentionConfigurations* mentionConfigurations;

/**
 @abstract The (optional) delegate to listen to async errors (force logout, bad sessions, ...).
 */
@property (nullable, weak, nonatomic) id<AmityClientErrorDelegate> clientErrorDelegate;

/**
 @abstract Creates an instance of `AmityClient` with provided API key.
 @param apiKey API key provided by Amity.
 @return A valid client instance or nil on invalid API key.
 */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey;

/**
 @abstract Creates an instance of `AmityClient` with provided API Key.

 @note
 If the provided value for `httptUrl` & `socketUrl` is empty, then default value would be used. You can also use one of the
 regional endpoint provided in `AmityRegionalEndpoint` class.
 
 @param apiKey: API key provided by Amity.
 @param httpUrl: Custom url to be used as base url.
 @param socketUrl: Custom url to be used as base url.
 @return A valid instance of AmityClient
 */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey httpUrl:(nonnull NSString *)httpUrl socketUrl:(nonnull NSString *)socketUrl;

/**
 @abstract Creates an instance of `AmityClient` with provided API Key.
 
 @note
 The provided value for url would be used for both http & socket request. If the provided value for `url` is empty, then default value would be used.
 You can also use one of the regional endpoint provided in `AmityRegionalEndpoint` class.
 
 @param apiKey: API key provided by Amity
 @param url: Custom url to be used as base url for both http & socket request.
 @return A valid instance of AmityClient
  */
+ (nullable AmityClient *)clientWithApiKey:(nonnull NSString *)apiKey url:(nonnull NSString *)url;

/**
 @abstract Registers the the user with the current device.
 @note If the passed userId does not match the current user, the current user will be unregistered.
 @note the `displayName` passed value is ignored if the user has previously registered with this device, use `updateUser:completion:` instead.
 @param userId A user id. Required.
 @param displayName The display name of the user. Required.
 @param authToken: Extra authentication token to be used for secure device registration. This is optional. Please refer to our Authentication documentation for further details.
 @param completion: Completion block to be called when device registration is successful or failed.
 
 @note: Error occurred in this method will not be delivered through `clientErrorDelegate`. 
 */
- (void)registerDeviceWithUserId:(nonnull NSString *)userId
                     displayName:(nullable NSString *)displayName
                       authToken:(nullable NSString *)authToken
                      completion:(nullable AmityRequestCompletion)completion;

/**
 @abstract Unregisters the current user associated with the device.
 @discussion The device will be unregisted from push notifications and data associated with the user will be removed from the device.
 */
- (void)unregisterDevice;

/**
 @abstract Register the current device (and the current logged-in user) to receive
 push notifications.
 @discussion You can call this method as many times as you'd like: the last call
 will always override any precedent state.
 As long as you call this function with a valid token, and after succesfully
 registering the SDK, you're guaranteed to receive only push notifications related
 to the current logged in user.
 Call `unregisterDeviceForPushNotificationForUserId:completion:` to stop receiving
 notifications for this user.
 Succesfully calling this method will override any precedent state: if this device
 was previously registered with a different user, the device will no more get any
 notification related to that user.
 @warning Once succesfully registered, this app will continue to receive
 notifications related to this user until the `unregisterDeviceForPushWithCompletion:`
 or another registration is made.
 @param deviceToken A globally unique token that identifies this device to Apple
 Push Notification service.
 @param completion A block executed when the request has successfully completed.
 */
- (void)registerDeviceForPushNotificationWithDeviceToken:(nonnull NSString *)deviceToken
                                              completion:(nullable AmityRequestCompletion)completion;

/**
 @abstract Unregister the current device to stop receiving any push notifications
 related to the given user userId. If no user is passed, the backend will remove
 any push notification token associated with this device.
 @discussion Call this method when you no longer wish to receive notifications for
 the previously registered user (for example when the user logs out).
 @warning Make sure that the completion block is called with success state, otherwise
 the Amity backend will keep sending push notifications related to the previous user.
 @param userId The userId of the user of which the SDK should no longer receive
 notifications.
 @param completion A block executed when the request has successfully completed.
 */
- (void)unregisterDeviceForPushNotificationForUserId:(nullable NSString *)userId
                                          completion:(nullable AmityRequestCompletion)completion;

/**
 Updates current user
 
 @param builder: Builder class which provides methods to update user information. Only set information which you want to update
 @param completion: Completion handler which gets called after update is success or failure.
 */
- (void)updateUser:(nonnull AmityUserUpdateBuilder *)builder completion:(nullable AmityRequestCompletion)completion;

/**
 Checks whether the current user has permission or not.
 
 @param permission: Permission to check
 */
- (void)hasPermission:(AmityPermission)permission completion:(nonnull AmityPermissionCompletion)completion ;

/**
 Checks whether the current user has permission inside particular channel. This method checks for permission in
 global level as well as channel level.
 
 @param permission: Permission to check
 @param channelId: Id of the channel to check for
 @return: True if permission is granted else returns False
 */
- (void)hasPermission:(AmityPermission)permission forChannel:(nonnull NSString *)channelId completion:(nonnull AmityPermissionCompletion)completion;

/**
 Checks whether the current user has permission inside particular channel. This method checks for permission in
 global level as well as channel level.
 
 @param permission: Permission to check
 @param community: Id of the community to check for
 @return: True if permission is granted else returns False
 */
- (void)hasPermission:(AmityPermission)permission forCommunity:(nonnull NSString *)communityId completion:(nonnull AmityPermissionCompletion)completion;

- (nullable NSDictionary<NSString *, id> *)sendCustomCommand:(nonnull NSString *)command;

/**
 Block call of `init` and `new` because this object cannot be created directly
 **/
- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end
