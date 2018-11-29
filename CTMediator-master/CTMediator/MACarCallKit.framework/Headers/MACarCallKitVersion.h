//
//  MACarCallVersion.h
//  MACarCall
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#ifndef MACarCallVersion_h
#define MACarCallVersion_h
#import <Foundation/Foundation.h>
#import <AMapFoundationKit/AMapFoundationVersion.h>

#define MACarCallVersionNumber                 10100
#define MACarCallMinRequiredFoundationVersion  10400

// 依赖库版本检测
#if AMapFoundationVersionNumber < MACarCallMinRequiredFoundationVersion
#error "The AMapFoundationKit version is less than minimum required, please update! Any questions please to visit http://lbs.amap.com"
#endif

FOUNDATION_EXTERN NSString * const MACarCallVersion;
FOUNDATION_EXTERN NSString * const MACarCallName;

#endif /* MACarCallVersion_h */
