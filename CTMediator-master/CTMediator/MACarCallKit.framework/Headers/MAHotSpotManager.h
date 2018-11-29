//
//  MAHotSpotManager.h
//  MACarCall
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAHotSpotQueryRequest.h"
#import "MAHotSpotQueryResponse.h"

@interface MAHotSpotManager : NSObject

///服务授权的key
@property (nonatomic, copy) NSString *accessKey;

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
- (NSOperation *)queryHotSpotsWith:(MAHotSpotQueryRequest *)request callback:(void(^)(MAHotSpotQueryResponse *response, NSError* error))callback;

@end
