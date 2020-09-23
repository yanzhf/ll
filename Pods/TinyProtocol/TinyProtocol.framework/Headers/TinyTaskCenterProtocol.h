//
//  TinyTaskCenterProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2020/8/5.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#ifndef TinyTaskCenterProtocol_h
#define TinyTaskCenterProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 资源更新任务请求服务
 */
@protocol TinyTaskCenterResourceProtocol <NSObject>

/*
 app 更新
 */
- (void)performResourceTask:(void(^)(void))result;

@end

/*
 行为分析对外提供的服务
 */
@protocol TinyTracePublicProtocol <NSObject>

- (void)traceTaskDidBereadyWithInfo:(NSDictionary **)info;

@end

#endif /* TinyTaskCenterProtocol_h */
