//
//  CTMediator+NetworkAction.h
//  TinyPart
//
//  Created by peanut on 2019/7/24.
//  Copyright © 2019 peanut. All rights reserved.
//

#import "CTMediator.h"

// 自签证书
static NSString *const kNetworkSslPinned_TargetName = @"NotFound";
static NSString *const kNetworkSslPinned_ActionName = @"NotFound";

// 客户端证书
static NSString *const kNetworkSslClientCer_TargetName = @"NotFound";
static NSString *const kNetworkSslClientCerData_ActionName = @"NotFound";
static NSString *const kNetworkSslClientCerPassword_ActionName = @"NotFound";

// 网络请求默认配置<target,params,headers>
static NSString *const kNetworkDefaultConfig_TargetName = @"NotFound";
static NSString *const kNetworkDefaultParams_ActionName = @"NotFound";
static NSString *const kNetworkDefaultHeaders_ActionName = @"NotFound";
static NSString *const kNetworkRequestUri_KeyName = @"request_uri";

// host 白名单控制
static NSString *const kNetworkRequestHost_TargetName = @"NotFound";
static NSString *const kNetworkRequestHost_ActionName = @"NotFound";
static NSString *const kNetworkRequestHost_ValueKey = @"tiny_host";

// signature & encrypt
static NSString *const kNetworkRequestSecurity_TargetName = @"NotFound";
static NSString *const kNetworkRequestSignature_ActionName = @"NotFound";
static NSString *const kNeteorkRequestEncrypt_ActionName = @"NotFound";
static NSString *const kNetworkRequestSecuruty_BodyKey = @"requestBody";

// response decode
static NSString *const kNetworkResponseDecode_TargetName = @"NotFound";
static NSString *const kNetworkResponseDecode_ActionName = @"NotFound";
static NSString *const kNetworkResponseDecode_DataName = @"response-data";
static NSString *const kNetworkResponseDecode_KeyName = @"decode-type";

// 网络统计数据信息
static NSString *const kNetworkMetrics_TargetName = @"NotFound";
static NSString *const kNetworkMetrics_ActionName = @"NotFound";
static NSString *const kNetworkMetrics_TimeKey = @"duration";
static NSString *const kNetworkMetrics_StatusKey = @"status";
static NSString *const kNetworkMetrics_ByteKey = @"byte";
static NSString *const kNetworkMetrics_UriKey = @"uri";

// 网络数据缓存相关
static NSString *const kNetworkDiskCache_TargetName = @"NotFound";
static NSString *const kNetworkStoreDiskCache_ActionName = @"NotFound";
static NSString *const kNetworkRemoveDiskCache_ActionName = @"NotFound";
static NSString *const kNetworkReadDiskCache_ActionName = @"NotFound";
static NSString *const kNetworkDiskCache_Key = @"network_disk_cache_key";
static NSString *const kNetworkDiskCache_Value = @"network_disk_cache_value";

// 非远程的请求处理（request加载本地数据）
static NSString *const kNetworkUnremoteRequest_TargetName = @"TinyFileOperator";
static NSString *const kNetworkUnremoteRequest_ActionName = @"handleForwardRequestWithParams";
static NSString *const kNetworkUnremoteRequest_UriKey = @"req_url";
static NSString *const kNetworkUnremoteRequest_ParamterKey = @"req_paramter";
static NSString *const kNetworkUnremoteRequest_CompleteBlockKey = @"req_complete";


@interface CTMediator (NetworkAction)

/**
 自签证书
 */
- (id)mediator_sslPinnedCertificates;

/**
 https 双向认证客户端证书
 */
- (id)mediator_clientCertificatesData;

/**
 https 双向认证客户端证书密码
 */
- (id)mediator_clientCertificatrsPassword;

/**
 http host 白名单验证
 */
- (id)mediator_validHostName:(NSString *)host;

/**
 http request signature

 @param httpBody 加签体
 */
- (id)mediator_signatureRequestWithData:(NSData *_Nullable)httpBody;

/**
 http request encrypt

 @param httpBody 加密体
 */
- (id)mediator_encryptRequestWithData:(NSData *_Nullable)httpBody;

/**
 http response decode

 @param data 解密数据
 @param type 解密方式
 */
- (id)mediator_decodeResponseWithData:(NSData * _Nonnull)data type:(NSString *_Nonnull)type;

/**
 http request default params

 @param uri uri of request
 @return perform return NSDictionary
 */
- (id)mediator_defaultRequestParamsWithUri:(NSString *)uri;

/**
 http request default headers

 @param uri uri of request
 @return perform return NSDictionary
 */
- (id)mediator_defaultRequestHttpHeadersWithUri:(NSString *)uri;


/**
 派发请求相关数据

 @param duration 时间
 @param status 状态码
 @param bytes 数据流量
 @param uri 访问地址
 return any object you want
 */
- (id)mediator_dispatchNetworkMetricsWithDuration:(NSTimeInterval)duration status:(NSUInteger)status bytes:(NSUInteger)bytes uri:(NSString * _Nullable)uri;

/**
 写入Disk缓存
 @return if return nil, data should be restore in NSUserDefaults
 */
- (id)mediator_storeNetworkDiskCacheWithKey:(NSString *)key value:(NSData *)data;

/**
 读取Disk缓存

 @param key key
 @return if return nil, should reread from NSUserDefaults;
 */
- (id)mediator_readNetworkDiskCacheWithKey:(NSString *)key;

/**
 移除Disk缓存
 */
- (id)mediator_removeNetworkDiskCacheWithKey:(NSString *)key;

/**
 本地请求的响应者

 @param url 请求地址
 @param complete 完成事件
 @return value
 */
- (id)mediator_forwardUri:(NSURL *_Nonnull)url paramters:(NSDictionary *_Nullable)paramters complete:(nullable void(^)(NSData *_Nullable data, NSError *_Nullable error))complete;

@end


