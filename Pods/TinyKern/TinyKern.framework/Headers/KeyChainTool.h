//
//  KeyChainTool.h
//  TPHTTPS
//
//  Created by peanut on 2019/5/29.
//  Copyright © 2019 peanut.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

// kGenericKey 不影响存储
// kAccountKey kServiceKey 影响存储
static NSString* const kAccountKey = @"kAccountKey";
static NSString* const kGenericKey = @"kGenericKey";
static NSString* const kServiceKey = @"kServiceKey";
static NSString* const kValueKey   = @"kValueKey";

static NSString* const kUserSecAttrServiceKey = @"userSecAttrServiceValue";

NS_ASSUME_NONNULL_BEGIN

@interface KeyChainTool : NSObject

+ (BOOL)store:(NSDictionary *)attributes error:(NSError **)error;
+ (id)read:(NSDictionary *)attributes error:(NSError **)error;
+ (BOOL)remove:(NSDictionary *)attributes error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
