//
//  Target_B.m
//  CTMediator
//
//  Created by 陈欢 on 2018/11/13.
//  Copyright © 2018 casa. All rights reserved.
//

#import "Target_B.h"
#import <SliderViewController.h>

@implementation Target_B

- (UIViewController *)Action_nativeFetchSliderViewController:(NSDictionary *)params {
    // 因为action是从属于ModuleA的，所以action直接可以使用ModuleA里的所有声明
    SliderViewController *viewController = [[SliderViewController alloc] init];
    viewController.nameArray = params[@"key"];
    return viewController;
}


@end
