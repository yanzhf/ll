//
//  TinyMvvmProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/9/19.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

/* TinyCompilerElementProtocol
 * 描述了compiler的eElement 应该持有哪些属性 实现哪些方法
 * 应该被传入的参数遵守
 */

/* TinyMvvmCacheProtocol
 * 描述了数据绑定模块需要缓存中心提供的服务，具体见方法列表
 */

#ifndef TinyMvvmProtocol_h
#define TinyMvvmProtocol_h

#import <Foundation/Foundation.h>

@protocol TinyCompilerElementProtocol <NSObject>

@property (nonatomic, copy) NSArray<id<TinyCompilerElementProtocol>> *subElements;

@property (nonatomic, copy, readonly) NSDictionary *attributes;
@property (nonatomic, copy, readonly) NSArray *nodes;
@property (nonatomic, copy) NSString *tag;

/**
 update attributes
 */
- (void)setAttribute:(id)value forName:(NSString *)name;


/**
 bind watcher to name, name maybe xml attribute key value or xml found charater created key
 */
- (void)appendWatcher:(id)watcher forName:(NSString *)name;

@end

@protocol TinyMvvmCacheProtocol <NSObject>

/**
 绑定数据度缓存
 loc: 0=pub 1=local
 */
- (NSString *)dataFromCacheByKey:(NSString *)key location:(int)loc;

/**
 绑定数据写缓存
 loc: 0=pub 1=local
 */
- (void)cacheDataWithKey:(NSString *)key value:(NSString *)value location:(int)loc;

@end

#endif /* TinyMvvmProtocol_h */
