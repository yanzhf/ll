//
//  TinyDataAnalysisProtocol.h
//  TinyCore
//
//  Created by peanut on 2019/8/12.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#ifndef TinyDataAnalysisProtocol_h
#define TinyDataAnalysisProtocol_h

#import <Foundation/Foundation.h>
#import "TinyBaseProtocol.h"

@protocol TinyDataAnalysisProtocol <NSObject>
@optional
/**
 序列化数据

 @param value 数据体
 @return 新数据体
 */
- (id)serializeData:(id)value;

/**
 序列化数据

 @param data 原始数据
 @param protocolName 协议的名称
 @return 新的数据体
 */
- (NSData *)serializeData:(NSData *)data withProtocol:(NSString *)protocolName;

@end


#endif /* TinyDataAnalysisProtocol_h */
