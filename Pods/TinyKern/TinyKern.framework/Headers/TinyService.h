//
//  TinyService.h
//  TinyPart
//
//  Created by peanut on 2019/7/11.
//  Copyright © 2019 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <TinyProtocol/TinyProtocol.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSMutableDictionary<NSString*, Class<TinyPlugsProtocol>>* TPlugDictionary;

@interface TinyService : NSObject <TinySingletonProtocol>

@property (nonatomic, strong, readonly) NSMutableDictionary<NSString*,Class> *services;

/**
 注册服务

 @param name 服务名称
 @param impClass 服务实现类
 */
- (void)registerServiceWithName:(NSString *_Nonnull)name impClass:(Class _Nonnull)impClass;


/**
 注册服务

 @param protocol 协议
 @param impClass 协议的实现类
 */
- (void)registerService:(Protocol *_Nonnull)protocol impClass:(Class _Nonnull)impClass;

/**
 获取服务实现类

 @param name 服务名称
 */
- (Class)impClassWithServiceName:(NSString *_Nonnull)name;
- (Class)impClassWithProtocol:(Protocol *_Nonnull)protocol;

/**
 获取简单实例

 @param name 服务名称
 */
- (id)instanceWithServiceName:(NSString *_Nonnull)name;
- (id)instanceWithProtocol:(Protocol *_Nonnull)protocol;

/**
 获取实例
 
 @param params 传入的参数
 */
- (_Nullable id)instanceWithImpClass:(_Nullable Class)clz params:(NSDictionary *_Nullable)params;

/**
 获取TP插件集合
 */
- (TPlugDictionary)TPlugins;
@end

NS_ASSUME_NONNULL_END
