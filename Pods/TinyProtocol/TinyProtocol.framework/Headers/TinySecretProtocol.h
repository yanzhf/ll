//
//  TinySecretProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/9/18.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//
/* AES/RSA加密模块(TinySecretCenter)对外提供的方法集
 * 使用者可以通过获取服务的方式，实现对数据体的加密和解密
 * 目前仅支持string和data
 * 入参和出参的类型一致（string->string, data->data, other->other）
 */
#ifndef TinySecretProtocol_h
#define TinySecretProtocol_h

#import <Foundation/Foundation.h>
#import "TinyBaseProtocol.h"

typedef NS_ENUM(NSInteger,SignatureType){
    SignatureTypeNone = 1 << 0,
    SignatureTypeSHA256 = 1 << 1,
    SignatureTypeMD5 = 1 << 2
};

typedef NS_ENUM(NSInteger,EncryptType){
    EncryptTypeNone = 0,
    EncryptTypeAESCBC = 1 << 0,
    EncryptTypeAESGCM = 1 << 1,
    EncryptTypeAESRANDOM = 1 << 2,
    EncryptTypeRSA = 1 << 3
};

@protocol TinySecretProtocol <TinySingletonProtocol>

@property (nonatomic, copy) void(^initRequestBlock)(NSDictionary *info);

@optional
/**
 加密数据
 
 @param value 数据体
 @return 加密后的数据
 */
- (id)encryptParamterValue:(id)value type:(EncryptType)type;

/**
 解密数据
 
 @param value 数据体
 @return 解密后的数据
 */
- (id)decryptParamterValue:(id)value type:(EncryptType)type;

/**
 请求秘钥
 
 @param baseUrl 基础域名
 */
-(void)resetEncryption:(NSString *)baseUrl;

@end
#endif /* TinySecretProtocol_h */
