//
//  TYDeviceInfo.h
//  TinyKern
//
//  Created by 兖志飞 on 2019/8/1.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TYDeviceInfo : NSObject

+(NSString *)deviceName;

+(NSString *)deviceModel;

+(NSString *)deviceSystemName;

+(NSString *)deviceSystemVersion;

+(NSString *)deviceID;

+(NSString *)deviceHeight;

+(NSString *)deviceWidth;

+(NSString *)deviceIDFA;

+(NSString *)deviceIP;

+(BOOL)deviceScreenCapturingState;

@end

NS_ASSUME_NONNULL_END
