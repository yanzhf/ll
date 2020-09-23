//
//  TinyApiRulerProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/9/19.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

/* TinyApiCompilerParamterProtocol
 * 描述了(TinyApiCompiler)对外接口参数规范
 * 接口入参应当遵守协议
 */

/* TinyApiCompilerProtocol
 * 描述了(TinyApiCompiler,数据&规范验证融合)对外提供的接口服务
 * 使用者可以通TinyService 获取到TinyApiCompiler服务
 */

/* TinyApiRulerProtocol
 * 描述了接口规范(TinyApiRuler)对外提供的服务
 * 使用者可以通TinyService 获取到TinyApiCompiler服务
 */

#ifndef TinyApiRulerProtocol_h
#define TinyApiRulerProtocol_h

#import <Foundation/Foundation.h>
#import "TinyBaseProtocol.h"

@protocol TinyApiCompilerParamterProtocol <NSObject>

@property (nonatomic, copy) NSString *interfaceApiName;

@required
- (id)commonResourceWithAttribute:(NSString *)attribute;
- (id)specialResourceWithAttribute:(NSString *)attribute;
@end

@class TinyParamterAccessory;
@protocol TinyApiCompilerProtocol <TinySingletonProtocol>
/**
 apply http request body
 
 @return new request body, which compiled by api ruler
 */
- (id)compileApiRequestBody:(id<TinyApiCompilerParamterProtocol>)request error:(NSError **)error;


/**
 apply http request header
 
 @return new request header
 */
- (id)compileApiRequestHeader:(id<TinyApiCompilerParamterProtocol>)request error:(NSError **)error;


/**
 apply http response body
 
 @return new response body which compiled from response by api ruler
 */
- (id)compilerApiResponseBody:(id<TinyApiCompilerParamterProtocol>)response error:(NSError **)error;

/**
 apply http response header
 
 @return new response header which compiled from response by api ruler
 */
- (id)compilerApiResponseHeader:(id<TinyApiCompilerParamterProtocol>)response error:(NSError **)error;

/**
 apply data
 
 @param obj 数据体
 @param name 接口唯一标识
 @param accessory 规范
 @param error 错误
 */
- (id)compileApiDataWithObject:(id)obj name:(NSString *)name ruler:(TinyParamterAccessory *)accessory error:(NSError **)error;

/**
 api request path

 @param object 调起对象
 */
- (NSString *)apiPathByObject:(id<TinyApiCompilerParamterProtocol>)object;

/**
 api request version

 @param object 接口版本号
 */
- (NSString *)apiInterfaceVersionByObject:(id<TinyApiCompilerParamterProtocol>)object;

/**
api request network type

@param object 接口对象
*/
- (NSString *)apiNetworkType:(id<TinyApiCompilerParamterProtocol>)object;

@end


@protocol TinyApiRulerProtocol <TinySingletonProtocol>
- (TinyParamterAccessory *)accessoryWithApiName:(NSString *_Nonnull)apiName path:(NSString *_Nullable)path error:(NSError **)error;
@end

#endif /* TinyApiRulerProtocol_h */
