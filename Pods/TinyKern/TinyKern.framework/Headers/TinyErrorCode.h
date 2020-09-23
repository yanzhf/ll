//
//  TinyErrorCode.h
//  TinyKern
//
//  Created by 徐涛 on 2020/6/3.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#define RDLocalizedString(key)  [[TinyErrorCode bundle] localizedStringForKey:(key) value:@"" table:@"RDLocalizable"]

#define RDLanguageKey @"userLanguage"

@interface TinyErrorCode : NSObject
/**
 *  获取当前资源文件
 */
+ (NSBundle *)bundle;

+ (void)setUserlanguage:(NSString *)language;

+(void)logErrorMsgWithCode:(NSString *)code extraMsg:(NSString *)extramsg;
@end

NS_ASSUME_NONNULL_END
