//
//  MAHotSpotQueryResponse.h
//  MACarCall
//
//  Created by shaobin on 2017/6/7.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MAHotSpotInfo.h"

///周围上车点响应
@interface MAHotSpotQueryResponse : NSObject

///中心点经纬度
@property (nonatomic, assign) CLLocationCoordinate2D centerCoord;

///错误码，10000表示成功。
@property (nonatomic, assign) int errorcode;
///错误信息
@property (nonatomic, strong) NSString *errmsg;

///服务端返回上车点个数
@property (nonatomic, assign) int spotsCount;
///上车点信息数组
@property (nonatomic, strong) NSArray<MAHotSpotInfo*> *spots;


/**
 * @brief 根据网络请求返回构建response对象
 * @param dict json字典
 * @return 对象
 */
- (id)initWithDictionary:(NSDictionary *)dict;

@end
