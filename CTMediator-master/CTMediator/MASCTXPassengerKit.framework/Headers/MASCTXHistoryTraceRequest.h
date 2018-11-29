//
//  MASCTXHistoryTraceRequest.h
//  MASCTXPassengerKit
//
//  Created by shaobin on 2018/3/9.
//  Copyright © 2018年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MASCTXHistoryTraceRequest : NSObject

///订单号
@property (nonatomic, copy) NSString *trname;

///开始时间，Unix时间戳（轨迹点的定位时间）,需要精准到毫秒
@property (nonatomic, assign) long long startTime;

///结束时间，Unix时间戳（轨迹点的定位时间）,需要精准到毫秒.结束时间不能大于当前时间，且距离开始时间不能超过24小时。若轨迹较多，建议将时间段进行拆分。
@property (nonatomic, assign) long long endTime;

///denoise =0：不去噪 denoise =1：去噪
@property (nonatomic, copy) NSString *denoise;

///mapmatch=0：不绑路 mapmatch=1：绑路
@property (nonatomic, copy) NSString *mapmatch;

///定位精度过滤，用于过滤掉定位精度较差的轨迹点，示例： threshold=0：不过滤 threshold=100：过滤掉定位精度 Radius 大于100的点
@property (nonatomic, copy) NSString *threshold;

///交通方式，鹰眼将根据不同交通工具选择不同的纠偏策略，目前支持驾车示例：mode=driving mode=riding（当前不生效） mode=walking（当前不生效）
@property (nonatomic, copy) NSString *mode;

///是否返回tracks的points内容，默认为返回（1），可以设置为不返回（0）。分页当前仅对id查询轨迹信息和分段查询轨迹信息生效。（仅对查询单条轨迹生效）
@property (nonatomic, copy) NSString *ispoints;

///需要第几页数据，若仅需要返回起点、终点的经纬度，请指定此参数为1
@property (nonatomic, assign) NSUInteger page;

///每页返回点的个数，必须说明page=1的时候起点、终点的个数不计算在内。pagesize必须小于1000
@property (nonatomic, assign) NSUInteger pagesize;

- (NSDictionary*)jsonDictionary;

@end
