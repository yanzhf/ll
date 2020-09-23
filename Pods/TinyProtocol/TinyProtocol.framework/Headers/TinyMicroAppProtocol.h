//
//  TinyMicroAppProtocol.h
//  TinyPart
//
//  Created by peanut on 2020/1/9.
//  Copyright © 2020 peanut. All rights reserved.
//

#ifndef MicroAppProtocol_h
#define MicroAppProtocol_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^openMicroAppBlock) (NSString *_Nullable);

@protocol TinyMicroAppProtocol <NSObject>
@required

/// 打开微应用
/// @param key 微应用唯一标识
/// @param block 回调打开事件
- (void)openMicroAppWithKey:(NSString *_Nonnull)key andBlock:(openMicroAppBlock _Nonnull)block;


/// 获取微应用h5
/// @param key 微应用唯一标识
- (NSString *_Nullable)microAppResourceUrl:(NSString *_Nonnull)key;

/// 获取我的微应用
- (void)ownerMicroAppList:(nonnull void(^)(NSArray *_Nullable, NSError *_Nullable))callBack;

/// 获取所有的微应用
- (void)allMicroAppList:(nonnull void(^)(NSArray *_Nullable, NSError *_Nullable))callBack;

/// 打开微应用
/// @param attributes 参数
- (void)open:(NSDictionary *)attributes;

/// 添加我的微应用
/// @param microKey 微应用的唯一id
- (void)addMicroApp:(NSString *)microKey callback:(nonnull void(^)(NSError *_Nullable))callback;

/// 移除我的微应用
/// @param microKey 微应用的唯一ID
- (void)removeMicroApp:(NSString *)microKey callback:(nonnull void(^)(NSError *_Nullable))callback;

/// 微应用信息回调
/// @param callback 回调信息
- (void)callBackParamsCallback:(nonnull void(^)(NSMutableDictionary *_Nullable))callback;
@end

NS_ASSUME_NONNULL_END

#endif /* MicroAppProtocol_h */
