//
//  TinyServiceMacro.h
//  TinyPart
//
//  Created by peanut on 2019/8/5.
//  Copyright © 2019 peanut. All rights reserved.
//

#ifndef TinyServiceMacro_h
#define TinyServiceMacro_h

#import "TinyService.h"

#define TINY_LOAD_NAME_SERVICE(servicename,impclass) \
+ (void)load { \
    Class clz = NSClassFromString(impclass); \
    if (clz == nil) { \
        return; \
    }\
    TinyService *service = [TinyService sharedInstance]; \
    [service registerServiceWithName:servicename impClass:clz];\
}

#define TINY_LOAD_PROTOCOL_SERVICE(protocolname,impclass) \
+ (void)load { \
    Class clz = NSClassFromString(impclass); \
    if (clz == nil) { \
        return; \
    }\
    Protocol *protocl = NSProtocolFromString(name); \
    if (protocl == nil) { \
        return; \
    } \
    TinyService *service = [TinyService sharedInstance]; \
    [service registerService:protocol impClass:clz]; \
}

#define MEDIATOR_PROTOCOL_INSATNCE(protocolname) \
{ \
    Protocol *protocl = NSProtocolFromString(name); \
    if (protocl == nil) { \
    return nil; \
    } \
    TinyService *service = [TinyService sharedInstance]; \
    return [service instanceWithProtocol:protocol]; \
}

#define MEDIATOR_NAME_INSATNCE(servicename) \
{ \
    TinyService *service = [TinyService sharedInstance]; \
    return [service instanceWithServiceName:servicename]; \
}

#define MEDIATOR_NAME_IMPCLASS(servicename) \
{ \
    TinyService *service = [TinyService sharedInstance]; \
    return [service impClassWithServiceName:servicename]; \
}

#define MEDIATOR_PROTOCOL_IMPCLASS(protocolname) \
{ \
    Protocol *protocol = NSProtocolFromString(name); \
    if (protocol == nil) { \
        return nil; \
    } \
    return [[TinyService sharedInstance] impClassWithProtocol:protocol]; \
}

#define TinyPerformSelectorLeakWarning(block) \
do { \
    _Pragma("clang diagnostic push") \
    _Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
    block; \
    _Pragma("clang diagnostic pop") \
} while (0)

#ifndef __OPTIMIZE__
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...){}
#endif

#endif /* TinyServiceMacro_h */


