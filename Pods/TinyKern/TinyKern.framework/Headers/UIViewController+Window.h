//
//  UIViewController+window.h
//  Tiny
//
//  Created by xiangfp on 15/6/19.
//  Copyright (c) 2015年 xiangfp. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController(Window)

+ (UIViewController *)windowRootViewController;

+ (UIViewController*)viewControllerByView:(UIView *)view;

@end
