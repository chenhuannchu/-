//
//  Target_MapManager.h
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Target_MapManager : NSObject

- (void)Action_ServiceKey:(NSDictionary *)param;

- (NSDictionary *)Action_LocationMessage:(NSDictionary *)param;

- (void )Action_ContinuousLocation:(NSDictionary *)param;

- (void )Action_StopContinuousLocation:(NSDictionary *)param;


- (void)Action_ConfigNearbyCarController:(NSDictionary *)param;

- (void)Action_RemoveNearbyCarController:(NSDictionary *)param;

- (void)Action_ResetNearbyCarController:(NSDictionary *)param;


//高德：附近上车点
- (void)Action_configHotSpotController:(NSDictionary *)param;

- (void)Action_removeHotSpotController:(NSDictionary *)param;

@end

NS_ASSUME_NONNULL_END
