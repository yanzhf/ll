//
//  TYAppInfo.h
//  TinyKern
//
//  Created by 兖志飞 on 2019/8/1.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface TYAppInfo : NSObject

+(NSString *)appVersion;

+(NSString *)appResourceVersion;

+(NSString *)appName;

+(NSString *)appPackageName;

+(NSString *)getDocumentsPath;

+(NSString *)GMTDate;

+(void)openPermission;

+(BOOL)hasPermission:(NSArray *)array;

@end

