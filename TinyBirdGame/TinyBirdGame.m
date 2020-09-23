//
//  TinyBirdGame.m
//  TinyBirdGame
//
//  Created by 兖志飞 on 2020/7/15.
//  Copyright © 2020 yanzf. All rights reserved.
//

#import "TinyBirdGame.h"
#import <TinyKern/TinyKern.h>
#import <TinyProtocol/TinyProtocol.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "TinyBirdGameViewController.h"

@interface TinyBirdGame()<TinyPlugsProtocol, TinyModuleProtocol>

@end

@implementation TinyBirdGame
@synthesize endGame;
@synthesize error;

TINY_NAME_SERVICE(TinyBirdGame, TinyBirdGame)

+ (TinyPluginType)pluginType
{
    return TinyPluginType_TP;
}

-(instancetype)init{
   if(self = [super init]) {
       
   }
   return self;
}

- (void)playGame{
     
    [self testingAuthority];
}

- (void)testingAuthority{
    if(@available(iOS 11.0, *)) {
            AVAuthorizationStatus authStatus = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
            if(authStatus == AVAuthorizationStatusRestricted || authStatus == AVAuthorizationStatusDenied){
                [self.error callWithArguments:@[@"请在\"设置 - 隐私 - 相机\"选项中，允许多客访问您的相机"]];
                [self releaseJS];
                return;
            }
            //获取访问相机权限时，弹窗的点击事件获取
            [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
                if (granted) {
                     dispatch_async(dispatch_get_main_queue(), ^{
                         TinyBirdGameViewController *vc = [[TinyBirdGameViewController alloc] init];
                          __weak typeof(self) weakSelf = self;
                         vc.modalPresentationStyle = 0;
                         vc.block = ^(NSString * number){
                             [weakSelf.endGame callWithArguments:@[number]];
                             [self releaseJS];
                         };
                         [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:vc animated:YES completion:nil];
                     });
                } else {
                   [self.error callWithArguments:@[@"请在\"设置 - 隐私 - 相机\"选项中，允许多客访问您的相机"]];
                }
            }];
    }else{
        [self.error callWithArguments:@[@"系统版本太低，不能运行游戏"]];
        [self releaseJS];
    }
}

- (void) releaseJS
{
    self.error = nil;
    self.endGame = nil;
}


@end
