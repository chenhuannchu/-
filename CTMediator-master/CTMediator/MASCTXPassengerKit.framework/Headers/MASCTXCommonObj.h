//
//  MASCTXCommonObj.h
//  MAMapKit
//
//  Created by hanxiaoming on 2017/8/2.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

///MASCTXErrorDomain
extern NSString * const MASCTXErrorDomain;

///司乘同显错误码
typedef NS_ENUM(NSInteger, MASCTXErrorCode)
{
    MASCTXErrorOK = 0,
    MASCTXErrorNoOrderID = 2001, ///<OrderID不存在
    MASCTXErrorRequestError = 2002, ///<请求错误
    MASCTXErrorOrderStatusNotMatch = 2003, ///<订单状态不匹配
    MASCTXErrorSuborderInfoNotReady = 2004, ///<无法获取子订单信息
};

///司机行驶信息
@interface MASCTXDriverInfo : NSObject<NSCopying>

///位置
@property (nonatomic, assign) CLLocationCoordinate2D position;

///方向
@property (nonatomic, assign) double direction;

///剩余距离(米）
@property (nonatomic, assign) double distance;

///预计时间（秒）
@property (nonatomic, assign) double duration;

///位置更新时间
@property (nonatomic, copy) NSString *uploadtime;

///是否是降级模式
@property (nonatomic, assign) BOOL isDownMode;

@end

///路线信息
@interface MASCTXRouteInfo : NSObject

///路线坐标点字符串 x,y;x1,y1;x2,y2;...
@property (nonatomic, copy) NSString *points;

///历史路线坐标点字符串，偏航后会有数据（add 20180123）。此数组为每一次偏航的已走过路径点坐标字符串。
@property (nonatomic, readonly) NSArray<NSString *> *historyPathArray;

///links原始坐标字符串, 用于上传和请求原始数据。 id_idx;id_idx;id_idx;...
@property (nonatomic, copy) NSString *linkString __attribute((deprecated("已废弃")));

///数据版本
@property (nonatomic, copy) NSString *dataVersion;

///总里程(米）
@property (nonatomic, assign) NSInteger mileage;

///links id 数组
@property (nonatomic, readonly) NSArray<NSString *> *links __attribute((deprecated("已废弃")));

///link 所对应坐标点的索引 数组
@property (nonatomic, readonly) NSArray<NSNumber *> *indices;

/// 更新historyPathString，输入为服务返回原始字符串， 用“|”分隔每一次偏航数据。
- (void)updateHistoryPathWithOriginString:(NSString *)historyPath;

@end


///路径link，用于更新路况
@interface MAETALink : NSObject

///状态
@property (nonatomic, assign) int state;

///长度
@property (nonatomic, assign) int length;

///旅行时间
@property (nonatomic, assign) int time;


@end

///路径path
@interface MAETAPath : NSObject

@property (nonatomic, strong) NSArray<MAETALink *> *links;

@end
