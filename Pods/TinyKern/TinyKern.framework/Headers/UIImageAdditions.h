/******************************************************************
 文件名称: UIImageAdditions.h
 系统名称: 移动平台
 模块名称: 客户端
 类 名 称: UIImageAdditions
 软件版权: 杭州长亮金融信息服务有限公司
 功能说明: 
 系统版本: 
 开发人员: 
 开发时间: 12-4-19
 审核人员:
 相关文档:
 修改记录: 需求编号 修改日期 修改人员 修改说明
        S1.1.6 20120423  修改图片的分辨率
 ******************************************************************/


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define kRetinaWidth 640
#define kRetinaHeight 960
#define kNoRetinaWidth 320
#define kNoRetinaHeight 480
#define kOnePx 1


@interface UIImage(zoom)
+ (UIImage *)originImage:(UIImage *)image scaleToSize:(CGSize)size;

+(UIImage *)fixOrientation:(UIImage *)aImage;

@end
