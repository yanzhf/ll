//
//  TinyPasteboardProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2020/7/1.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#ifndef TinyPasteboardProtocol_h
#define TinyPasteboardProtocol_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger,TinyPasteboardScope) {
    TinyPasteboardGeneral = 0,
    TinyPasteboardPrivate = 1,
};

@protocol TinyPasteboardProtocol <NSObject>

// 往剪贴板里面存内容
- (void)setString:(NSString *_Nullable)string atScope:(TinyPasteboardScope)scope;

// 从剪贴板里面取内容
- (NSString *_Nullable)getString;

@end


#endif /* TinyPasteboardProtocol_h */
