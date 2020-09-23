//
//  MySKScene.h
//  NewTest
//
//  Created by 兖志飞 on 2020/7/14.
//  Copyright © 2020 yanzf. All rights reserved.
//
#import <SpriteKit/SpriteKit.h>
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN



typedef void(^MySKSceneClick)(NSString *);

@interface MySKScene : SKScene

@property(nonatomic,strong) SKLabelNode *label;
@property(nonatomic,strong) SKAction *ac;
@property(nonatomic,strong) SKSpriteNode *brid;
@property(nonatomic,strong) SKSpriteNode *node;
@property(nonatomic,assign) NSInteger score;
@property(nonatomic,strong) NSMutableArray *topPipe;
@property(nonatomic,strong) NSMutableArray *bottomPipe;
@property(nonatomic,strong) MySKSceneClick block;
@property(nonatomic,assign) BOOL isStart;

-(void)bridSetLocationL:(CGFloat)number;

- (void)startGame;

@end
NS_ASSUME_NONNULL_END
