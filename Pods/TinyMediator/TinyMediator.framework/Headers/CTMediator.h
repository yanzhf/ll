//
//  CTMediator.h
//  CTMediator
//
//  Created by casa on 16/3/13.
//  Copyright © 2016年 casa. All rights reserved.
//

/* 需要在 mediator 和 target 中重新添加每一个接口，模块化时代码较为繁琐
 * 在category 中仍然引入了字符串硬编码
 * 可能会创建过多的 target 类
 */
/* 使用说明
 * 模块构建对外的mediator method(CTMediator+Category)
 * 模块实现performSelector的action(Module_Target)
 */

#import <UIKit/UIKit.h>

extern NSString * const kCTMediatorParamsKeySwiftTargetModuleName;

@interface CTMediator : NSObject

+ (instancetype)sharedInstance;

// 远程App调用入口
- (id)performActionWithUrl:(NSURL *)url completion:(void(^)(NSDictionary *info))completion;
// 本地组件调用入口
- (id)performTarget:(NSString *)targetName action:(NSString *)actionName params:(NSDictionary *)params shouldCacheTarget:(BOOL)shouldCacheTarget;
- (void)releaseCachedTargetWithTargetName:(NSString *)targetName;

@end
