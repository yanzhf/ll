TinyMediator 
提供基于运行时夸模块的访问的能力

Example:

// method should call by other model

@interface CTMediator (NetworkAction)
- (id)mediator_forwardUri:(NSURL *_Nonnull)url 
                paramters:(NSDictionary *_Nullable)paramters 
                complete:(nullable void(^)(NSData *_Nullable data, NSError *_Nullable error))complete;
@end

@implementation
- (id)mediator_forwardUri:(NSURL *)url paramters:(NSDictionary *)paramters complete:(void (^)(NSData * _Nullable, NSError * _Nullable))complete {
    if (!url) {
        return nil;
    }
    NSMutableDictionary *params = [NSMutableDictionary dictionaryWithCapacity:2];
    [params setObject:url forKey:kNetworkUnremoteRequest_UriKey];
    if (complete) {
        [params setObject:complete forKey:kNetworkUnremoteRequest_CompleteBlockKey];
    }
    if (paramters) {
        [params setObject:paramters forKey:kNetworkUnremoteRequest_ParamterKey];
    }
    return [self performTarget:kNetworkUnremoteRequest_TargetName action:kNetworkUnremoteRequest_ActionName params:params shouldCacheTarget:NO];
}

kNetworkUnremoteRequest_TargetName: 响应者的类名
kNetworkUnremoteRequest_ActionName: 响应的方法名
@end

@interface CTMediator (NetworkTarget)
- (id)handleForwardRequestWithParam:(NSDictionary *)params;
@end
@implementation
- (id)handleForwardRequestWithParam:(NSDictionary *)params {
    // do something......
}
