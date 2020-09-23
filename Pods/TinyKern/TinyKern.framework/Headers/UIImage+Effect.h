//
//  UIImage+Effect.h
//  TinyKern
//
//  Created by gxl on 2020/4/2.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Effect)

+ (UIImage *)cropScreenInView;
+ (UIImage *)coreBlurImage:(UIImage *)image withBlurNumber:(CGFloat)blur;
+ (UIImage *)configWithImage:(UIImage*)inImage withColorMatrix:(float) mLumValue;

@end

NS_ASSUME_NONNULL_END
