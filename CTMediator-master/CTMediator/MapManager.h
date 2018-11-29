//
//  MapManager.h
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <AMapFoundationKit/AMapFoundationKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MapManager : NSObject



@property (nonatomic, strong)NSMutableDictionary *locationDic;


@property (nonatomic, assign)CLLocationCoordinate2D annoCoordinate;




+ (MapManager *)defaultManager;

//高德KEY配置
- (void)mapServiceSetting;

//开始定位
- (void)startContinuousLocation;

//停止连续定位
- (void)stopContinuousLocation;


//高德：附近运力
- (void)configNearbyCarController;

- (void)removeNearbyCarController;

- (void)resetNearbyCarController;


//高德：附近上车点
- (void)configHotSpotController;

- (void)removeHotSpotController;




@end

NS_ASSUME_NONNULL_END
