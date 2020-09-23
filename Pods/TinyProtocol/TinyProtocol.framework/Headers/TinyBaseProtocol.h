//
//  TinyProtocol.h
//  TinyPart
//
//  Created by peanut on 2019/8/5.
//  Copyright © 2019 peanut. All rights reserved.
//

#ifndef TinyProtocol_h
#define TinyProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JavaScriptCore/JavaScriptCore.h>

typedef NS_ENUM(NSUInteger,TinyPluginType) {
    TinyPluginType_UI = 0, // Embed
    TinyPluginType_TP   // TP
};

@protocol TinySingletonProtocol <NSObject>
@optional
+ (BOOL)singleton;
+ (instancetype)sharedInstance;
@end

@protocol TinyServiceProtocol <TinySingletonProtocol>
@optional
+ (NSString *)makeInstance:(NSDictionary *)params;
- (void)initParams:(NSDictionary *)params;
- (void)serviceHandleWithArguments:(NSArray *)arguments;
@end

// 插件模块必须实现的协议
@protocol TinyPlugsProtocol <TinyServiceProtocol>
@optional
+ (TinyPluginType)pluginType;
@end

#endif /* TinyProtocol_h */
