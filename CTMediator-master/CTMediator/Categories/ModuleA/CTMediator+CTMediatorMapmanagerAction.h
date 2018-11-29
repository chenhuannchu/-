//
//  CTMediator+CTMediatorMapmanagerAction.h
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import "CTMediator.h"

NS_ASSUME_NONNULL_BEGIN

@interface CTMediator (CTMediatorMapmanagerAction)

@property (nonatomic, strong)NSDictionary *locationMessage;

//高德Key设置
- (void)CTMediator_ServiceKey;


//打开定位
- (void)CTMediator_startContinuousLocation;


//关闭定位
- (void)CTMediator_stopContinuousLocation;

//获取定位点
- (NSDictionary *)CTMediator_locationMessage;



//高德：附近运力
- (void)CTMediator_configNearbyCarController;
- (void)CTMediator_removeNearbyCarController;
- (void)CTMediator_resetNearbyCarController;


//高德：附近上车点
- (void)CTMediator_configHotSpotController;
- (void)CTMediator_removeHotSpotController;



@end

NS_ASSUME_NONNULL_END
