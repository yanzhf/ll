//
//  TinyAutoRegister.h
//  TinyPart
//
//  Created by peanut on 2019/7/17.
//  Copyright © 2019 peanut. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TinyDATA(sectname) __attribute((used, section("__DATA,"#sectname" ")))

#define TINY_MODULE_AUTO_REGISTER(name) \
char * k##name##_mod TinyDATA(TinyModule) = ""#name"";

// 通过协议名字注册，注册的过程当中会有协议检查
#define TINY_PROTOCOL_SERVICE(protocolname,impclass) \
char * k##protocolname##_protocol TinyDATA(TinyProService) = "{ \""#protocolname"\" : \""#impclass"\"}";

// seriveName注册
#define TINY_NAME_SERVICE(servicename,impl) \
char * k##servicename##_service TinyDATA(TinyNameService) = "{ \""#servicename"\" : \""#impl"\"}";

@interface TinyAutoRegister : NSObject

@end


