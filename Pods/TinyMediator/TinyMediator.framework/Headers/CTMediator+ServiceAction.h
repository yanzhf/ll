//
//  CTMediator+ServiceAction.h
//  TinyPart
//
//  Created by peanut on 2019/7/11.
//  Copyright © 2019 peanut. All rights reserved.
//

#import "CTMediator.h"

#pragma mark -- Target & Action
static NSString* const kRegisterServiceActionName = @"registerServiceWithParams";
static NSString* const kInstanceActionName = @"instanceWithParams";
static NSString* const kTargetClassActionName = @"impClassWithParams";
static NSString* const kTinyServiceName = @"TinyService";

#pragma mark -- Parameter Key
static NSString* const kServiceName = @"kServiceName";
static NSString* const kSeriviceProtocol = @"kProtocolName";
static NSString* const kServiceImpClass = @"kServiceImpClass";

NS_ASSUME_NONNULL_BEGIN

@interface CTMediator (ServiceAction)

- (void)mediator_registerService:(NSString *_Nonnull)serviceName impClass:(_Nonnull Class)impClass target:(NSString *_Nullable)target;
- (void)mediator_registerServiceWithProtocol:(Protocol *_Nonnull)protocol impClass:(_Nonnull Class)impClass target:(NSString *_Nullable)target;

- (id)mediator_instanceWithServiceName:(NSString *_Nonnull)serviceName target:(NSString *_Nullable)target;
- (id)mediator_instanceWithProtocol:(Protocol *_Nonnull)protocol target:(NSString *_Nullable)target;

- (Class)mediator_impclassWithServiceName:(NSString *_Nonnull)serviceName target:(NSString * _Nullable)target;
- (Class)mediator_impclassWithProtocol:(Protocol *_Nonnull)protocol target:(NSString *_Nullable)target;

@end

NS_ASSUME_NONNULL_END
