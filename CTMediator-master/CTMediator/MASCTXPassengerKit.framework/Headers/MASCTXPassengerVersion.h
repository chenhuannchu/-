//
//  MASCTXPassengerVersion.h
//  MAMapKit
//
//  Created by hanxiaoming on 2017/11/24.
//  Copyright © 2017年 Amap. All rights reserved.
//

#ifndef MASCTXPassengerVersion_h
#define MASCTXPassengerVersion_h

#import <MAMapKit/MAMapVersion.h>

#define MASCTXPassengerVersionNumber 10300
#define MASCTXMinRequiredMapVersion 50600

// 依赖库版本检测
#if MAMapVersionNumber < MASCTXMinRequiredMapVersion
#error "The MAMapKit version is less than minimum required, please update! Any questions please to visit http://lbs.amap.com"
#endif

#endif /* MASCTXPassengerVersion_h */
