//
//  TinyBirdGameViewController.h
//  NewTest
//
//  Created by 兖志飞 on 2020/7/14.
//  Copyright © 2020 yanzf. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void(^TinyBirdGameViewClick)(NSString *);

@interface TinyBirdGameViewController : UIViewController

@property(nonatomic,strong) TinyBirdGameViewClick block;

@end

