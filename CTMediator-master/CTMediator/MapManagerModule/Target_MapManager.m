//
//  Target_MapManager.m
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import "Target_MapManager.h"

#import "Mapmanager.h"

@implementation Target_MapManager

- (void )Action_ContinuousLocation:(NSDictionary *)param {
    
    [[MapManager defaultManager] startContinuousLocation];
}

- (void )Action_StopContinuousLocation:(NSDictionary *)param {
    [[MapManager defaultManager] stopContinuousLocation];
}


- (NSDictionary *)Action_LocationMessage:(NSDictionary *)param{
//    NSLog(NSString * _Nonnull format, ...)
    return [[MapManager defaultManager].locationDic copy];
}


- (void)Action_ServiceKey:(NSDictionary *)param{
    [[MapManager defaultManager] mapServiceSetting];
}




//高德：附近运力
- (void)Action_ConfigNearbyCarController:(NSDictionary *)param{
    [[MapManager defaultManager] configNearbyCarController];
}

- (void)Action_RemoveNearbyCarController:(NSDictionary *)param{
    [[MapManager defaultManager] removeNearbyCarController];
}

- (void)Action_ResetNearbyCarController:(NSDictionary *)param{
    [[MapManager defaultManager] resetNearbyCarController];
  
}

//高德：附近上车点
- (void)Action_configHotSpotController:(NSDictionary *)param {
    [[MapManager defaultManager] configHotSpotController];
}

- (void)Action_removeHotSpotController:(NSDictionary *)param {
    [[MapManager defaultManager] removeHotSpotController];
}
@end
