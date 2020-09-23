//
//  NSString+PathExtension.h
//  TinyKern
//
//  Created by peanut on 2020/3/20.
//  Copyright © 2020 hz.sunline.cn. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (PathExtension)

- (instancetype)fullResourcePath;

- (instancetype)bundleResourcePath;

- (instancetype)documentResourcePath;

- (instancetype)removeDocumentPath;
- (instancetype)removeBundlePath;

@end

NS_ASSUME_NONNULL_END
