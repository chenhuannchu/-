//
//  MAHotSpotAnnotationView.h
//  MACarCall
//
//  Created by shaobin on 2017/6/8.
//  Copyright © 2017年 Amap. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <MAMapKit/MAAnnotationView.h>

@interface MAHotSpotAnnotationView : MAAnnotationView

///名字标签
@property (nonatomic, strong) UILabel *nameLabel;

///nameLabel距离左边间距, 默认2
@property (nonatomic, assign) CGFloat nameLabelLeftMargin;

///nameLabel的最大允许宽度，默认90
@property (nonatomic, assign) CGFloat nameLabelMaxWidth;

///图片、名字占有的矩形区域大小
@property (nonatomic, assign, readonly) CGRect boundingRect;

///心跳动画的圆形图片
@property (nonatomic, strong) UIImage *animatingCircleImage;

///中心点图片
@property (nonatomic, strong) UIImage *centerDotImage;

/**
 * @brief 设置上车点显示名字
 * @param text 文字
 * @param textSide 文字所在边，0右边，1左边
 */
- (void)setNameTextWith:(NSString *)text textSide:(int)textSide;

/**
 * @brief 开启上车点选中动画
 */
- (void)startAbsorbAnimation;

/**
 * @brief 开启上车点心跳动画
 */
- (void)startPulseAnimation;

/**
 * @brief 停止上车点心跳动画
 */
- (void)stopPulseAnimation;

@end
