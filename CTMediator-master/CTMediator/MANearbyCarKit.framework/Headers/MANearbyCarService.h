//
//  MANearbyCarService.h
//  MANearbyCar
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MANbCarRequest.h"
#import "MANbCarResponse.h"

@interface MANearbyCarService : NSObject

/**
 * @brief 单例方法
 * @return 单例对象
 */
+ (instancetype)sharedInstance;

/**
 * @brief 查询周围上车点
 * @param request 请求
 * @param callback 结果回调
 * @return NSOperation 对象
 */
- (NSOperation *)queryNearbyCarsWith:(MANbCarRequest *)request callback:(void(^)(MANbCarResponse *response, NSError* error))callback;

@end
