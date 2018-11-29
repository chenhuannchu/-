//
//  MAHotSpotController.h
//  MACarCall
//
//  Created by shaobin on 2017/6/8.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MAMapKit/MAMapKit.h>
#import <AMapSearchKit/AMapSearchKit.h>
#import "MAHotSpotAnnotation.h"
#import "MAHotSpotAnnotationView.h"

FOUNDATION_EXTERN NSString * const MAHotSpotErrorDomain;

///错误码
typedef NS_ENUM(NSInteger, MAHotSpotError)
{
    MAHotSpotErrorUnknown = 0, ///< 未知错误
    MAHotSpotErrorSpots = 1, ///< 上车点搜索错误
};

@class MAHotSpotController;

@protocol MAHotSpotControllerDelegate <NSObject>
@required

///创建上车点view
- (MAHotSpotAnnotationView *)createHotSpotViewWith:(MAHotSpotAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier controller:(MAHotSpotController *)controller;

///创建大头针锚点view
- (MAAnnotationView *)createAnchorPinViewWith:(MAPointAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier controller:(MAHotSpotController *)controller;

@optional

///如果返回NO，preCoord为上次请求的中心点坐标，absorbedAnno返回指定要自动吸附到的上车点，clearPrevAnnos返回是否删除上次的上车点。如不实现则执行默认策略：zoomLevel<15：不请求，移动超过1000米清空上车点；zoomLevel>=15: 锚点和已有上车点屏幕距离50像素内，自动吸附且不请求新的，否则不清空原来的且请求新的。
- (BOOL)shouldSendSpotQueryRequest:(CLLocationCoordinate2D)centerCoord
                          preCoord:(CLLocationCoordinate2D)preCoord
                      absorbedAnno:(MAHotSpotAnnotation **)absorbedAnno
                    clearPrevAnnos:(BOOL*)clearPrevAnnos
                        controller:(MAHotSpotController *)controller;

///请求返回后，判断要不要自动吸附到最近上车点, 如不实现则执行默认策略：如果地图zoomLevel小于15则返回NO，zoomLevel不小于15且地图中心点距离上车点距离小于50屏幕坐标返回YES。
- (BOOL)shouldAutoAbsorbedToAnnotation:(MAHotSpotAnnotation *)anno controller:(MAHotSpotController *)controller;

///如不实现此代理方法，当做返回YES处理
- (BOOL)shouldSendRegeoQueryRequest:(CLLocationCoordinate2D)centerCoord controller:(MAHotSpotController *)controller;

///如不实现，当做返回formattedAddress处理
- (NSString *)regeoDisplayStringWith:(AMapReGeocodeSearchResponse *)response controller:(MAHotSpotController *)controller;

///错误回调, 如果errorcode==MAHotSpotErrorSpots时为请求上车点错误，其他为逆地理查询错误
- (void)hotSpotController:(MAHotSpotController *)controller didFailWithError:(NSError *)error;

///大头针锚点跳动动画回调, 如不实现则走默认动画效果
- (void)startAnchorPinViewAnimating:(MAAnnotationView *)anchorPinView controller:(MAHotSpotController *)controller;

///大头针吸附到上车点回调
- (void)didAnchorPinAbsorbedToAnnotation:(MAHotSpotAnnotation *)anno controller:(MAHotSpotController *)controller;

///大头针没有触发吸附时,逆地理请求结果回调
- (void)didRegeoResponseReceived:(AMapReGeocodeSearchResponse *)response error:(NSError*)error controller:(MAHotSpotController *)controller;

@end

@interface MAHotSpotController : NSObject

///地图对象
@property (nonatomic, weak, readonly) MAMapView *mapView;

///包含上车点annotation的数组
@property (nonatomic, strong, readonly) NSArray<MAHotSpotAnnotation *> *spotAnnoArray;

///大头针annotation
@property (nonatomic, strong, readonly) MAPointAnnotation *pinAnnotation;

///基于中心点搜索上车点的半径范围，默认200
@property (nonatomic, assign) int spotSearchRadius;

///返回上车点个数，最大支持3个
@property (nonatomic, assign) int spotSearchCount;

///逆地理搜索的半径范围，默认200
@property (nonatomic, assign) int regeoSearchRadius;

///代理
@property (nonatomic, weak) id<MAHotSpotControllerDelegate> delegate;

/**
 *@brief 当地图大小发生改变时调用此方法，如屏幕旋转
 */
- (void)updateLayout;

/**
 * @brief 构造方法
 * @param mapView 地图对象
 * @param delegate 代理对象
 * @return 返回MAHotSpotController实例
 */
- (id)initWithMapView:(MAMapView *)mapView delagate:(id<MAHotSpotControllerDelegate>)delegate;

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
