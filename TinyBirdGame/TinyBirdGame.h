//
//  TinyBirdGame.h
//  TinyBirdGame
//
//  Created by 兖志飞 on 2020/7/15.
//  Copyright © 2020 yanzf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>

@protocol TinyBirdGameDelegate <JSExport>

@property(nonatomic,strong)JSValue *endGame;
@property(nonatomic, strong) JSValue *error;
-(void)playGame;
@end

@interface TinyBirdGame : NSObject<TinyBirdGameDelegate>

@end

