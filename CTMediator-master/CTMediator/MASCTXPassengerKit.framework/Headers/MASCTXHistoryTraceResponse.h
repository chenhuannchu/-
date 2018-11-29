//
//  MASCTXHistoryTraceResponse.h
//  MASCTXPassengerKit
//
//  Created by shaobin on 2018/3/9.
//  Copyright © 2018年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>

///Point定位点类
@interface MASCTXTracePointObject : NSObject

///坐标信息
@property (nonatomic, assign) CLLocationCoordinate2D location;

///Point的自定义字段
@property (nonatomic, strong) NSDictionary *props;

///此经纬度的定位时间 Unix时间戳,需要精准到毫秒 此字段可能为空，则代表为纠偏后的点
@property (nonatomic, assign) long long locateTime;

///速度，单位km/h 此字段可能为空，则代表为纠偏后的点
@property (nonatomic, assign) double speed;

///取值范围：[0,359]，0代表正 北方，采用顺时针方向取值 此字段可能为空，则代表为纠偏后的点
@property (nonatomic, assign) double direction;

///高度，单位米，此字段可能为空，则代表为纠偏后的点
@property (nonatomic, assign) double height;

///定位精度 此字段可能为空，则代表为纠偏后的点
@property (nonatomic, assign) double accuracy;

- (id)initWithDict:(NSDictionary *)dict;

@end

///BasicTrack轨迹类
@interface MASCTXTraceTraceObject : NSObject

///轨迹id
@property (nonatomic, assign) NSUInteger trid;

///订单号
@property (nonatomic, copy) NSString *trname;

///距离长度 单位：米
@property (nonatomic, assign) NSUInteger distance;

///轨迹持续时间 单位：毫秒
@property (nonatomic, assign) long long time;

///points 个数
@property (nonatomic, assign) int counts;

///轨迹点数组
@property (nonatomic, strong) NSArray<MASCTXTracePointObject *> *points;

- (id)initWithDict:(NSDictionary *)dict;

@end

@interface MASCTXHistoryTraceResponse : NSObject

@property (nonatomic, assign, readonly) int errcode; //0 失败，1 成功
@property (nonatomic, strong, readonly) NSString *errdetail;
@property (nonatomic, strong, readonly) NSString *errmsg;

@property (nonatomic, assign) int counts;

@property (nonatomic, assign) NSUInteger page;
@property (nonatomic, assign) NSUInteger totalCount;
///轨迹数据
@property (nonatomic, strong) NSArray<MASCTXTraceTraceObject *> *tracks;

- (id)initWithResposeData:(NSData *)data;

@end

