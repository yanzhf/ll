//
//  TinyNetworkProtocol.h
//  TinyPart
//
//  Created by peanut on 2019/8/1.
//  Copyright © 2019 peanut. All rights reserved.
//

#ifndef TinyEncryptProtocol_h
#define TinyEncryptProtocol_h

#import <Foundation/Foundation.h>
#import "TinyBaseProtocol.h"

@protocol NetworkSslCertificateProtocol <TinyServiceProtocol>
@optional
/**
 ssl 证书
 */
- (NSSet *)sslPinnedCertificates;

/**
 https 双向认证客户端证书
 */
- (NSData *)clientCertificatesData;

/**
 https 双向认证客户端证书密码
 */
- (NSString *)clientCertificatrsPassword;

/**
 request host vaild

 @param host name
 @return bool value
 */
- (BOOL)isvalidHost:(NSString *)host;

/**
 http request signature
 
 @param httpBody 加签体
 */
- (id)signatureRequestWithData:(NSData *_Nullable)httpBody;

/**
 http request encrypt
 
 @param httpBody 加密体
 */
- (id)encryptRequestWithData:(NSData *_Nullable)httpBody;

/**
 http response decode
 
 @param data 解密数据
 @param type 解密方式
 */
- (id)decodeResponseWithData:(NSData * _Nonnull)data type:(NSString *_Nonnull)type;

/**
 http request default params
 
 @param uri uri of request
 @return perform return NSDictionary
 */
- (id)defaultRequestParamsWithUri:(NSString *)uri;

/**
 http request default headers
 
 @param uri uri of request
 @return perform return NSDictionary
 */
- (id)defaultRequestHttpHeadersWithUri:(NSString *)uri;


/**
 派发请求相关数据
 
 @param duration 时间
 @param status 状态码
 @param bytes 数据流量
 @param uri 访问地址
 return any object you want
 */
- (id)dispatchNetworkMetricsWithDuration:(NSTimeInterval)duration status:(NSUInteger)status bytes:(NSUInteger)bytes uri:(NSString * _Nullable)uri;

/**
 写入Disk缓存
 @return if return nil, data should be restore in NSUserDefaults
 */
- (id)storeNetworkDiskCacheWithKey:(NSString *)key value:(NSData *)data;

/**
 读取Disk缓存
 
 @param key key
 @return if return nil, should reread from NSUserDefaults;
 */
- (id)readNetworkDiskCacheWithKey:(NSString *)key;

/**
 移除Disk缓存
 */
- (id)removeNetworkDiskCacheWithKey:(NSString *)key;

@end

#endif
