//
//  MAHotSpotAnnotation.h
//  MACarCall
//
//  Created by shaobin on 2017/6/8.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import "MAHotSpotInfo.h"
#import <MAMapKit/MAMapKit.h>

@interface MAHotSpotAnnotation : MAPointAnnotation

///是否是吸附点
@property (nonatomic, assign) BOOL isAbsorbed;
///是否隐藏
@property (nonatomic, assign) BOOL isHidden;
///文字所在边，0右边，1左边
@property (nonatomic, assign) int textSide;

///上车点信息
@property (nonatomic, strong) MAHotSpotInfo *spotInfo;

///用户数据
@property (nonatomic, strong) id userData;

@end
