//
//  TinyModuleProtocol.h
//  TinyPart
//
//  Created by peanut on 2019/8/5.
//  Copyright © 2019 peanut. All rights reserved.
//

#ifndef TinyModuleProtocol_h
#define TinyModuleProtocol_h

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, TinyModulePriority) {
    TinyModulePriorityLower = 0,
    TinyModulePriorityNormal,
    TinyModulePriorityHigh,
};

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
#import <UserNotifications/UserNotifications.h>
@protocol TinyModuleProtocol <NSObject, UIApplicationDelegate, UNUserNotificationCenterDelegate>
#else
@protocol TinyModuleProtocol <NSObject, UIApplicationDelegate>
#endif

@optional
+ (BOOL)isAsync;
+ (NSInteger)modulePriority;
+ (TinyModulePriority)moduleLevel;
@end

#endif /* TinyModuleProtocol_h */
