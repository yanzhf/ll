//
//  TinyUINetworkProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/10/18.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#ifndef TinyUINetworkProtocol_h
#define TinyUINetworkProtocol_h

#import <Foundation/Foundation.h>
#import "TinyBaseProtocol.h"

@protocol TinyUINetworkProtocol <TinyServiceProtocol>

// 获取图片
- (id)imageRequestWithUri:(NSString *)uri completion:(void (^)(NSData * _Nullable, NSError *_Nullable error))compeltion;

// post data
- (id)postRequestWithUri:(NSString *)uri header:(NSDictionary *)header body:(id)body completion:(void (^)(NSData * _Nullable, NSError *_Nullable error))compeltion;
                                                      
- (void)cancelRequest:(id)request;

- (NSString *_Nonnull)currentNetworkStatus;

// 下载文件
- (id _Nullable)downloadRequestWithUri:(NSString *_Nonnull)uri header:(NSDictionary *)header paramters:(NSDictionary *)paramters destination:(NSString *_Nonnull)path progress:(void(^)(long long current, long long total))progress completion:(void(^)(NSURL *_Nullable, NSError * _Nullable))completion;

// 上传文件
/* files 需要上传的文件集合
 * NSDictionary 用来表征上传的对象，包含以下字段
 * data: 上传的数据体，可为空
 * fileURL: 上传文件的路径file:// ,与data互斥
 * name: 名字
 * fileName: 文件名
 * mimeType: 文件类型
 */
- (id _Nullable)uploadRequestWithUri:(NSString *)uri header:(NSDictionary *)header paramters:(NSDictionary *)paramters file:(NSArray<NSDictionary *> *)files progress:(void(^)(long long current, long long total))progress completion:(void (^)(NSData * _Nullable, NSError *_Nullable error))compeltion;

@end


#endif /* TinyUINetworkProtocol_h */
