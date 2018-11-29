//
//  CTMediator+CTMediatorMapmanagerAction.m
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import "CTMediator+CTMediatorMapmanagerAction.h"

#import "objc/runtime.h"



NSString * const kCTMediatorTargetMapManager = @"MapManager";

NSString * const kCTMediatorServiceKey = @"ServiceKey";

NSString * const kCTMediatorActionContinuousLocation = @"ContinuousLocation";
NSString * const kCTMediatorActionStopContinuousLocation = @"StopContinuousLocation";
NSString * const kCTMediatorLocationMessage = @"LocationMessage";


NSString * const kCTMediatorConfigNearbyCarController = @"ConfigNearbyCarController";
NSString * const kCTMediatorRemoveNearbyCarController = @"RemoveNearbyCarController";
NSString * const kCTMediatorResetNearbyCarController = @"ResetNearbyCarController";


NSString * const kCTMediatorConfigHotSpotController = @"ConfigHotSpotController";
NSString * const kCTMediatorRemoveHotSpotController = @"RemoveHotSpotController";





static NSString *locationMessageKey = @"locationMessageKey"; //locationMessage的key

@implementation CTMediator (CTMediatorMapmanagerAction)

//高德Key配置
- (void)CTMediator_ServiceKey{
    [self performTarget:kCTMediatorTargetMapManager
                 action:kCTMediatorServiceKey
                 params:nil
      shouldCacheTarget:NO
     ];
}

- (void)CTMediator_startContinuousLocation
{
    [self performTarget:kCTMediatorTargetMapManager
                 action:kCTMediatorActionContinuousLocation
                 params:@{@"key":@"value"}
      shouldCacheTarget:NO
     ];
    

}

- (void)CTMediator_stopContinuousLocation {

    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorActionStopContinuousLocation params:@{@"key":@"value"} shouldCacheTarget:NO];
}



- (NSDictionary *)CTMediator_locationMessage
{
    return [self performTarget:kCTMediatorTargetMapManager
                 action:kCTMediatorLocationMessage
                 params:@{@"key":@"value"}
      shouldCacheTarget:NO
     ];
    
    
}

- (void)CTMediator_configNearbyCarController {
    
    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorConfigNearbyCarController params:@{} shouldCacheTarget:NO];
}

- (void)CTMediator_removeNearbyCarController {
    
    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorRemoveNearbyCarController params:@{} shouldCacheTarget:NO];
}

- (void)CTMediator_resetNearbyCarController {
    
    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorResetNearbyCarController params:@{} shouldCacheTarget:NO];
}


- (void)CTMediator_configHotSpotController {
    
    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorConfigHotSpotController params:@{} shouldCacheTarget:NO];
}

- (void)CTMediator_removeHotSpotController {
    
    [self performTarget:kCTMediatorTargetMapManager action:kCTMediatorRemoveHotSpotController params:@{} shouldCacheTarget:NO];
}





#pragma mark -- locationMessage GET SET

- (void)setLocationMessage:(NSDictionary *)locationMessage {
    objc_setAssociatedObject(self, &locationMessageKey, locationMessage, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSDictionary *)locationMessage {
    return objc_getAssociatedObject(self, &locationMessageKey);
}


@end
