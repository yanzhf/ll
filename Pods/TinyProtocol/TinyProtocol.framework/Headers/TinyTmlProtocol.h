//
//  TinyTmlProtocol.h
//  TinyProtocol
//
//  Created by peanut on 2019/12/4.
//  Copyright © 2019 hz.sunline.cn. All rights reserved.
//

#ifndef TinyTmlProtocol_h
#define TinyTmlProtocol_h

#import "TinyBaseProtocol.h"

@protocol TinyTmlProtocol <TinyServiceProtocol>
@optional
+ (UIView *)buildTmlviewWithXmlData:(NSData *)xml;
- (JSContext *)currentJSContext;
@end

#endif /* TinyTmlProtocol_h */
