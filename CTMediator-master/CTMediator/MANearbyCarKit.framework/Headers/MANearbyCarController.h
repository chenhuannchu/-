//
//  MANearbyCarController.h
//  MANearbyCar
//
//  Created by shaobin on 2017/6/8.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MAMapKit/MAMapKit.h>

@class MANearbyCarController;

@protocol MANearbyCarControllerDelegate <NSObject>

@optional
//如果返回NO，则不重新请求。centerCoord: 这次请求的中心点坐标; preCoord: 上次请求的中心点坐标; prevDate: 上次请求时间
- (BOOL)shouldSendNearbyCarRequest:(CLLocationCoordinate2D)centerCoord
                          preCoord:(CLLocationCoordinate2D)preCoord
                          prevDate:(NSDate*)prevDate
                        controller:(MANearbyCarController *)controller;

///获取发送请求时基于的中心点坐标，如果不实现，则取地图的中心点坐标
- (CLLocationCoordinate2D)getCenterCoordinate:(MANearbyCarController *)controller;

@end

@interface MANearbyCarController : NSObject

///地图对象
@property (nonatomic, weak, readonly) MAMapView *mapView;

///代理
@property (nonatomic, weak, readonly) id<MANearbyCarControllerDelegate> delegate;

///是否开启log，默认NO
@property (nonatomic, assign) BOOL enableDebugLog;

///key，默认为[AMapServices sharedServices].apiKey
@property (nonatomic, strong) NSString *key;

///移动超过多少距离才尝试更新周边运力,单位米,默认50
@property (nonatomic, assign) NSInteger requestThreshold;

///请求半径，单位公里，默认2。最小值2，数字需为2的倍数。最大值以服务端为准，目前20
@property (nonatomic, assign) NSInteger radius;

///最大请求数，默认5，取值范围1-20
@property (nonatomic, assign) NSInteger maxCounts;

///车辆类型 0：所有分类, 1：出租车, 2：新能源, 3：舒适型, 4：豪华型, 5：商务型. 必填
@property (nonatomic, assign) NSInteger vehicleType;

///刷新间隔，单位秒，默认10
@property (nonatomic, assign) NSTimeInterval refreshInterval;

///小车图片
@property (nonatomic, strong) UIImage *carImage;

///是否暂停附近车辆拉取，默认NO
@property (nonatomic, assign) BOOL paused;


/**
 * @brief 构造方法
 * @param mapView 地图对象
 * @param delegate 代理对象
 * @return 返回MANearbyCarController实例
 */
- (id)initWithMapView:(MAMapView *)mapView delagate:(id<MANearbyCarControllerDelegate>)delegate;

/**
 * @brief 是否属于内部维护annotation
 * @param annotation annotation
 * @return YES/NO
 */
- (BOOL)isInternalAnnotation:(id<MAAnnotation>)annotation;

/**
 * @brief 清空周边车辆
 */
- (void)clearCars;

/**
 * @brief 在对应的地图delegate方法中调用此方法
 * @param mapView 地图
 * @param wasUserAction 是否用户触发
 */
- (void)mapView:(MAMapView *)mapView mapWillMoveByUser:(BOOL)wasUserAction;

/**
 * @brief 在对应的地图delegate方法中调用此方法
 * @param mapView 地图
 * @param wasUserAction 是否用户触发
 */
- (void)mapView:(MAMapView *)mapView mapDidMoveByUser:(BOOL)wasUserAction;


/**
 * @brief 在对应的地图delegate方法中调用此方法
 * @param mapView 地图 
 * @param wasUserAction 是否用户触发
 */
- (void)mapView:(MAMapView *)mapView mapDidZoomByUser:(BOOL)wasUserAction;


/**
 * @brief 地图区域即将改变时会调用此接口
 * @param mapView 地图View
 * @param animated 是否动画
 */
- (void)mapView:(MAMapView *)mapView regionWillChangeAnimated:(BOOL)animated;

/**
 * @brief 地图区域改变完成后会调用此接口
 * @param mapView 地图View
 * @param animated 是否动画
 */
- (void)mapView:(MAMapView *)mapView regionDidChangeAnimated:(BOOL)animated;

/**
 * @brief 在对应的地图delegate方法中调用此方法
 * @param mapView 地图
 * @param views annotationView
 */
- (void)mapView:(MAMapView *)mapView didAddAnnotationViews:(NSArray *)views;

/**
 * @brief 在对应的地图delegate方法中调用此方法
 * @param mapView 地图
 * @param annotation 标注
 * @return 返回上车点功能需要的annotationview，一类是上车点，一类是大头针锚点
 */
- (MAAnnotationView *)mapView:(MAMapView *)mapView viewForAnnotation:(id <MAAnnotation>)annotation;

@end
