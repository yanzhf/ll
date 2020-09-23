//
//  TinyEncryptProtocol.h
//  TinyPart
//
//  Created by peanut on 2019/8/2.
//  Copyright © 2019 peanut. All rights reserved.
//

#ifndef TinyEncryptProtocol_h
#define TinyEncryptProtocol_h

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "TinyBaseProtocol.h"


@protocol TinyCryptoProtocol <TinyServiceProtocol,JSExport>
@optional
/**
 rsa encrypt string

 @param str 数据体
 @param pubKey 密钥
 @return string value
 */
JSExportAs(rsaEncode, - (NSString *)rsaEncode:(NSString *)str publicKey:(NSString *)pubKey);

/**
 rsa decrypt string used string key
 
 @param str 数据
 @param privateKey 密钥
 @return string value
 */
JSExportAs(rsaDecode, - (NSString *)rsaDecode:(NSString *)str privateKeyStr:(NSString *)privateKey);

/**
 rsa encrypt data

 @param data 数据
 @param pubKey 密钥
 @return data vlaue
 */
JSExportAs(rsaEncryptData, - (NSData *)rsaEncryptData:(NSData *)data publicKey:(NSString *)pubKey);

/**
 rsa encrypt data with padding

 @param data 数据
 @param pubKey 密钥
 @param padd 填充
 @return string value
 */
- (NSString *)rsaEncryptData:(NSData *)data pubKey:(NSString *)pubKey secPadding:(NSString *)padd;

/**
 rsa decrypt data

 @param data 数据
 @param privateKey 密钥
 @return data value
 */
JSExportAs(rsaDecryptData, - (NSData *)rsaDecryptData:(NSData *)data privateKey:(NSString *)privateKey);

/**
 rsa decrypt string used RSA key

 @param str 数据
 @param privateKey 密钥
 @return string value
 */
- (NSString *)rsaDecryptString:(NSString *)str privateKey:(id)privateKey;

/**
 *  RSA签名
 */
JSExportAs(rsaSign, - (NSString *)rsaSign:(NSString *)plainText privKey:(NSString *)privKey);

/**
 *  RSA验签
 *
 *  @param text    数据
 *  @param pubKey    公钥
 *  @param signature   数据摘要
 *
 *  @return BOOL value
 */
JSExportAs(rsaVerify, - (BOOL)verifyRsaWithText:(NSString *)text pubKey:(NSString *)pubKey signature:(NSString *)signature);

/**
 String MD5

 @param string 原始数据
 @return MD5 string value
 */
JSExportAs(md5, - (NSString *)MD5:(NSString *)string);

/**
 String MD5 and then Base64

 @param string 原始数据
 @return base64 string value
 */
- (NSString *)MD5Base64:(NSString *)string;

/**
 file data MD5

 @param string 文件路径
 @return string value of file
 */
- (NSString *)fileMD5:(NSString *)string;

/**
 NSData MD5

 @param data 数据
 @return data value
 */
- (NSData *)MD5Digest:(NSData *)data;

/**
 NSData MD5

 @param data 数据
 @param uppercase 是否转大写
 @return data value
 */
- (NSString *)MD5Digest:(NSData *)data uppercase:(BOOL)uppercase;

/**
 string base64 encrypt
 */
- (NSString *)base64Encode:(id)value;

/**
 string base64 decrypt
 */
- (NSString *)base64Decode:(NSString *)string;

/**
 NSString 3DES Encrypt

 @param text 加密体
 @param key 密钥
 @return encrypt string value
 */
JSExportAs(threeDesEncode, - (NSString *)encryptStringBy3DES:(NSString *)text key:(NSString *)key);

/**
 NSString 3DES Decrypt

 @param text 解密体
 @param key 密钥
 @return decrypt string value
 */
JSExportAs(threeDesDecode, - (NSString *)decryptStringBy3DES:(NSString *)text key:(NSString *)key);

/**
 NSString DES Encrypt

 @param text 加密体
 @param key 密钥
 @return encrypt string value
 */
JSExportAs(desEncode, - (NSString *)encryptStringByDES:(NSString *)text key:(NSString *)key);

/**
 NSString DES Decrypt

 @param text 解密体
 @param key 密钥
 @return drcrypt string value
 */
JSExportAs(decDecode, - (NSString *)decryptStringByDES:(NSString *)text key:(NSString *)key);

/**
 NSData 3DES Encrypt
 
 @param text 加密体
 @param key 密钥
 @return encrypt data value
 */
JSExportAs(dataThreeDesEncode, - (NSData *)encryptDataBy3DES:(NSData *)text key:(NSString *)key);

/**
 NSData 3DES Decrypt
 
 @param text 解密体
 @param key 密钥
 @return decrypt data value
 */
JSExportAs(dataThreeDesDecode, - (NSData *)decryptDataBy3DES:(NSData *)text key:(NSString *)key);

/**
 String AesGcm Encrypt

 @param text 加密体
 @param key 密钥
 @param iv 偏移
 @return encrypt string value
 */
JSExportAs(aesGcmEncode, - (NSString *)aesGcmEncode:(NSString *)text key:(NSString *)key iv:(NSString *)iv);

/**
 String AesGcm Decrypt

 @param text 解密体
 @param key 密钥
 @param iv 偏移
 @return decrypt string value
 */
JSExportAs(aesGcmDecode, - (NSString *)aesGcmDecode:(NSString *)text key:(NSString *)key iv:(NSString *)iv);

/**
 Data Aes Encrypt

 @param data 加密体
 @param key 密钥
 @param iv 偏移
 @return encrypt base64 string value
 */
JSExportAs(aesEncryptDataToString, - (NSString *)aesEncryptDataToString:(NSData *)data key:(NSString *)key iv:(NSString *)iv);

/**
 string aes decrypt to data

 @param text 解密体
 @param key 密钥
 @param iv 偏移
 @return decrypt data value
 */
JSExportAs(aesDecryptStringToData, - (NSData *)aesDecryptStringToData:(NSString *)text key:(NSString *)key iv:(NSString *)iv);

/**
 Data Aes Encrypt

 @param data 加密体
 @param key 密钥
 @param iv 偏移
 @return encrypt data value
 */
JSExportAs(aesEncryptData, - (NSData *)aesEncryptData:(NSData *)data key:(NSString *)key iv:(NSString *)iv);

/**
 data aes decrypt to data

 @param data 解密体
 @param key 密钥
 @param iv 偏移
 @return decrypt data value
 */
JSExportAs(aesDecryptData, - (NSData *)aesDecryptData:(NSData *)data key:(NSString *)key iv:(NSString *)iv);

/**
 string aes encrypt to data

 @param text 加密体
 @param key 密钥
 @param iv 偏移
 @return encrypt data value
 */
JSExportAs(aesEncryptStringToData, - (NSData *)aesEncryptStringToData:(NSString *)text key:(NSString *)key iv:(NSString *)iv);

/**
 Data Aes Decrypt
 
 @param data 解密体
 @param key 密钥
 @param iv 偏移
 @return decrypt string value
 */
JSExportAs(aesDecryptDataToString, - (NSString *)aesDecryptDataToString:(NSData *)data key:(NSString *)key iv:(NSString *)iv);

/**
 string encrypt to string

 @param text 加密体
 @param key 密钥
 @param iv 偏移
 @return encrypt string value
 */
JSExportAs(aesEncode, - (NSString *)aesEncode:(NSString *)text key:(NSString *)key iv:(NSString *)iv);

/**
 string decrypt to string

 @param text 加密体
 @param key 密钥
 @param iv 偏移
 @return decrypt string value
 */
JSExportAs(aesDecode, - (NSString *)aesDecode:(NSString *)text key:(NSString *)key iv:(NSString *)iv);


/**
 HMAC SHA256 Encrypt

 @param text 加密体
 @param key 密钥
 @return encrypt string  value
 */
JSExportAs(HmacSHA256,
- (NSString *)HmacSHA256:(NSString *)text withKey:(NSString *)key
);

/**
 SHA256 Encrypt

 @param text 加密体
 @return encrypt string value
 */
- (NSString *)SHA256:(NSString *)text;

/**
 SHA256 Encrypt

 @param text 加密体
 @return encrypt base64 string value
 */
- (NSString *)SHA256Base64:(NSString *)text;

- (NSDictionary *)generateSecretKey:(int)size;

//sm2加密
-(NSString *)sm2Encode:(NSString*)data pubkey:(NSString*)publickey;

//sm2解密
-(NSString *)sm2Decode:(NSString*)data privkey:(NSString*)privkey;

//sm3加签
-(NSString*)sm3Encode:(NSString*)data;

//sm4加密
-(NSString *)sm4Encode:(NSString*)data :(NSString*)pubkey;

//sm4解密
-(NSString *)sm4Decode:(NSString*)data :(NSString*)pubkey;

-(NSString *)urlEncode:(NSString *)data;

-(NSString *)urlDecode:(NSString *)data;


@end

#endif /* TinyEncryptProtocol_h */
