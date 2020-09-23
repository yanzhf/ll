//
//  TinyNetConnectMonitor.h
//  TinyKern
//
//  Created by peanut on 2020/7/2.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString* kNetConnectMonitorOfStatusKey;
extern NSString* kNetConnectMonitorOfNetworkTypeKey;
extern NSString* kNetConnectMonitorOfNetProviderKey;

@interface TinyNetConnectMonitor : NSObject

- (instancetype)init
__attribute__((unavailable("you are not meant to initialise TinyNetConnectMonitor")));

+ (instancetype)sharedInstance;

/*
 当前连接的网络信息
 */
- (NSDictionary *)currentNetConnectInfo;

@end

NS_ASSUME_NONNULL_END
