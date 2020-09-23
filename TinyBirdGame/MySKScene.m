//
//  MySKScene.m
//  NewTest
//
//  Created by 兖志飞 on 2020/7/14.
//  Copyright © 2020 yanzf. All rights reserved.
//

#define WIDTH(view) view.frame.size.width
#define HEIGHT(view) view.frame.size.height


#define OBSTACLE_INTERVAL_SPACE 170
#define FIRST_OBSTACLE_PADDING 300

#define OBSTACLE_INTERVAL_SPPED 1.5

#define X(view) view.frame.origin.x
#define Y(view) view.frame.origin.y

#import "MySKScene.h"
#import <UIKit/UIKit.h>
#import <AudioToolbox/AudioToolbox.h>

static const uint32_t projectileCategory = 0x1 << 0;
static const uint32_t monsterCategory = 0x1 << 1;

@implementation MySKScene{
    int nbObstacles;
    CGFloat bridY;
    CGFloat number;
}

- (instancetype)initWithSize:(CGSize)size{
    if (self = [super initWithSize:size]) {
        self.physicsWorld.gravity = CGVectorMake(0,0);
        self.physicsWorld.contactDelegate = self;
        self.topPipe = [NSMutableArray array];
        self.bottomPipe = [NSMutableArray array];
        _isStart = NO;
        bridY = self.frame.size.height/2;
        self.ac = [SKAction moveBy: CGVectorMake(- OBSTACLE_INTERVAL_SPPED, 0) duration:0.02];
        [self startGame];
    }
    return self;
}

- (void) startGame
{
    _isStart = NO;
    _score = 0;
    number = 0;
    [self.topPipe removeAllObjects];
    [self.bottomPipe removeAllObjects];
    [self removeAllChildren];
    [self createBackground];
    [self createObstacles];
    _isStart = YES;
}


- (void) createBackground
{
    self.label =  [SKLabelNode labelNodeWithFontNamed:@"Helvetica-Bold"];
    _label.text = @"0";
    _label.fontSize = 30;
    _label.fontColor = [UIColor whiteColor];
    _label.position = CGPointMake(CGRectGetMidX(self.frame), HEIGHT(self) - 100);
    _label.alpha = 0.9;
    _label.zPosition = 1;
    [self addChild:_label];
    
    SKTexture* birdTexture1 = [SKTexture textureWithImageNamed:@"TinyBirdGame.bundle/bird_1"];
    self.brid= [SKSpriteNode spriteNodeWithTexture:birdTexture1  size:CGSizeMake(34, 24)];
    [_brid setPosition:CGPointMake(100,CGRectGetMidY(self.frame))];
    [_brid setPhysicsBody:[SKPhysicsBody bodyWithRectangleOfSize:CGSizeMake(28, 20)]];
    [self addChild:_brid];
    _label.zPosition = 1;
    _brid.physicsBody.categoryBitMask = monsterCategory; // 3
    _brid.physicsBody.contactTestBitMask = projectileCategory;
    
}

- (void)createObstacles{
    nbObstacles = ceil(WIDTH(self)/(OBSTACLE_INTERVAL_SPACE))+1;
    CGFloat lastBlockPos = 0;
    for(int i=0;i<nbObstacles;i++){
        SKSpriteNode * topPipe = [SKSpriteNode spriteNodeWithImageNamed:@"TinyBirdGame.bundle/pipe_top"];
        [self addChild:topPipe];
        [_topPipe addObject:topPipe];
        
        SKSpriteNode * bottomPipe = [SKSpriteNode spriteNodeWithImageNamed:@"TinyBirdGame.bundle/pipe_bottom"];
        [self addChild:bottomPipe];
        [_bottomPipe addObject:bottomPipe];
        
        if(0 == i){
            [self place:bottomPipe and:topPipe atX:FIRST_OBSTACLE_PADDING];
        }else{
            [self place:bottomPipe and:topPipe atX:lastBlockPos+OBSTACLE_INTERVAL_SPACE];
        }
        lastBlockPos = topPipe.position.x;
    }
}
-(void)update:(NSTimeInterval)currentTime{
    if(_isStart){
      [self updateObstacles:currentTime];
    }
}

- (void)didBeginContact:(SKPhysicsContact *)contact{
    _label.text = [NSString stringWithFormat:@"游戏结束:%ld分",(long)_score];
    self.isStart = NO;
    AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
    if(self.block != nil){
        self.block(@"1");
    }
}

- (void)didEndContact:(SKPhysicsContact *)contact{
    
}

- (void) place:(SKSpriteNode *) bottomPipe and:(SKSpriteNode *) topPipe atX:(float) xPos
{
    float variance = [self randomFloatBetween:0 and:200];
    bottomPipe.position = CGPointMake(xPos,variance);
    bottomPipe.physicsBody = [SKPhysicsBody bodyWithRectangleOfSize:CGSizeMake( WIDTH(topPipe), HEIGHT(topPipe))];
    
    topPipe.position = CGPointMake(xPos,100 + HEIGHT(bottomPipe) + variance);
    topPipe.physicsBody = [SKPhysicsBody bodyWithRectangleOfSize:CGSizeMake( WIDTH(topPipe), HEIGHT(topPipe))];
}

- (void) updateObstacles:(NSTimeInterval)currentTime
{
    for(int i=0;i<nbObstacles;i++){
        SKSpriteNode *topPipe = (SKSpriteNode *)_topPipe[i];
        SKSpriteNode * bottomPipe = (SKSpriteNode *)_bottomPipe[i];
        [topPipe runAction:self.ac];
        [bottomPipe runAction:self.ac];
        if(topPipe.position.x < - 52){
            topPipe.position = CGPointMake((OBSTACLE_INTERVAL_SPACE + 52) *(nbObstacles - 1) +topPipe.position.x, topPipe.position.y);
            bottomPipe.position = CGPointMake((OBSTACLE_INTERVAL_SPACE + 52) *(nbObstacles - 1) +bottomPipe.position.x, bottomPipe.position.y);
        }
    }
    number = number+1;
    if((number*OBSTACLE_INTERVAL_SPPED) > 200){
        if(( number *OBSTACLE_INTERVAL_SPPED -200)/OBSTACLE_INTERVAL_SPACE > 0){
            _score  = ( number *OBSTACLE_INTERVAL_SPPED -200)/OBSTACLE_INTERVAL_SPACE +1;
            self.label.text = [NSString stringWithFormat:@"%ld",_score];
            if(_score == 100){
                self.label.text = [NSString stringWithFormat:@"游戏结束满分:%ld分",_score];
                self.isStart = NO;
            }
        }else{
            _score = 1;
            self.label.text = [NSString stringWithFormat:@"%ld",_score];
        }
    }
    if(fabs(bridY -  self.brid.position.y) > 0.1){
        SKAction *action = [SKAction moveToY:bridY duration:0.03];
        [self.brid runAction:action];
    }
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event{
    self.paused = !self.paused;
    if(self.paused){
        if(self.block != nil){
            self.block(@"2");
        }
    }
}

- (float) randomFloatBetween:(float) min and:(float) max{
    float random =  ((rand()%RAND_MAX)/(RAND_MAX*1.0))*(max-min)+min;
    return random;
}

- (void)bridSetLocationL:(CGFloat)number{
    if(_isStart){
       bridY = HEIGHT(self)-number;
    }
}

@end
