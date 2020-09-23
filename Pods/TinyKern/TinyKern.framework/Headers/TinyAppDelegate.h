//
//  TinyAppDelegate.h
//  TinyPart
//
//  Created by peanut on 2019/8/5.
//  Copyright © 2019 peanut. All rights reserved.
//

#import <UIKit/UIKit.h>


#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 100000
#import <UserNotifications/UserNotifications.h>
@interface TinyAppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate>
#else
@interface TinyAppDelegate : UIResponder <UIApplicationDelegate>
#endif

@end

