//
//  MAHotSpotQueryRequest.h
//  MACarCall
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///周围上车点请求
@interface MAHotSpotQueryRequest : NSObject
///中心点经纬度坐标
@property (nonatomic, assign) CLLocationCoordinate2D centerCoord;
///半径范围，单位米，默认200
@property (nonatomic, assign) int radius;
///返回上车点最大个数限制，默认3
@property (nonatomic, assign) int limit;

@end
