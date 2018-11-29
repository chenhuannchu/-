//
//  MAHotSpotInfo.h
//  MACarCall
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///上车点信息对象
@interface MAHotSpotInfo : NSObject

///距离，单位米
@property (nonatomic, assign) int distance;
///上车点经纬度坐标
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
///上车点名称
@property (nonatomic, strong) NSString *name;

@end
