//
//  DispatchSerialQueue.h
//  TinyPart
//
//  Created by peanut on 2019/12/18.
//  Copyright © 2019 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TaskStrategy) {
    TaskStrategyFIFO, // 先进先出
    TaskStrategyLIFO  // 后进先出
};

typedef NS_ENUM(NSInteger, DispatchTaskState) {
    DispatchTaskStateSuspend, // 暂停
    DispatchTaskStateWorking, // 工作中
    DispatchTaskStateSuccess, // 成功
    DispatchTaskStateFailure  // 失败
};

@class DispatchSerialQueue;
typedef DispatchSerialQueue*  dispatch_task_queue_t;
dispatch_task_queue_t dispatch_task_queue_create(NSString *_Nullable name);

@protocol TaskControlProtocol <NSObject>

@required
/**
 任务策略
 */
@property (nonatomic, assign) TaskStrategy strategy;

/**
 任务状态
 */
@property (nonatomic, assign) DispatchTaskState state;

/**
 任务重试的次数
 */
@property (nonatomic, assign) NSUInteger tryMaximumLimit;

/**
 任务完成回调到队列的事件
 */
@property (nonatomic, copy) void(^completeNotifyBlock)(id<TaskControlProtocol> task);

/**
 执行任务
 */
- (void)resume;

/**
 取消
 */
- (void)cancel;

@end

@interface DispatchSerialQueue : NSObject

@property (nonatomic, strong, readonly) dispatch_queue_t dispatchQueue;
/**
 最大并发任务数
 默认：INT_MAX
 */
@property (nonatomic, assign) NSUInteger maxConcurrentNumber;

/**
 任务入队
 */
- (void)enqueue:(id<TaskControlProtocol> _Nonnull)task;

/**
 单个任务出队
 */
- (void)dequeue:(id<TaskControlProtocol> _Nonnull)task;

/**
 全部任务出队
 */
- (void)dequeueAll;

@end

NS_ASSUME_NONNULL_END
