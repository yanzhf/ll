//
//  UIImage+Watermark.h
//
//  Created by Yang on 2020/7/14.
//  Copyright © 2020 yangxuran. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Watermark)

/*
 * 添加水印（水印信息配置在TinyBuilder.json）
 */
- (UIImage *)addWaterImage;

/*
 * 图片加文字水印
 * @param image 原始图片
 * @param text 文字
 * @param params {
         @"isTile":@1                         //是否平铺
         @"x":@100,                           //x
         @"y":@100,                           //y
         @"text-alpha":@0.5,                  //透明度（0～1）
         @"text-color": [UIColor redColor],   //文字颜色
         @"text-size": @20,                   //字体大小
         @"rotation":@45,                     //旋转角度
         @"font-family": @"SnellRoundhand-Bold",  //字体
         @"shadow-color": [UIColor blueColor],    //阴影颜色
         @"shadow-radius": @5,                    //阴影圆角
         @"shadowX": @0                           //阴影大小
         @"shadowY": @3                           //阴影大小
         @"horizontalSpace":@50                   //平铺状态下水平间距
         @"verticalSpace":@50                     //平铺状态下垂直间距
         }
 */
+ (UIImage *)addWaterImageWithImage:(UIImage *)image text:(NSString *)text params:(NSDictionary * )params;

/*
* 图片加图片水印
* @param image 原始图片
* @param waterImage 水印图片
* @param rect 水印图片frame
* @param params {
        @"isTile":@1                          //是否平铺
        @"image-alpha":@0.5,                  //透明度（0～1）
        @"rotation":@20,                      //旋转角度
        @"horizontalSpace":@50                //平铺状态下水平间距
        @"verticalSpace":@50                  //平铺状态下垂直间距
        }
*/
+ (UIImage *)addWaterImageWithImage:(UIImage *)image waterImage:(UIImage *)waterImage waterImageRect:(CGRect)rect params:(NSDictionary *)params;

@end

NS_ASSUME_NONNULL_END
