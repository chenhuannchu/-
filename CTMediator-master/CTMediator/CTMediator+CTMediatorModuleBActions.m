//
//  CTMediator+CTMediatorModuleBActions.m
//  CTMediator
//
//  Created by 陈欢 on 2018/11/13.
//  Copyright © 2018 casa. All rights reserved.
//

#import "CTMediator+CTMediatorModuleBActions.h"


NSString * const kCTMediatorTargetB = @"B";

NSString * const kCTMediatorActionNativeFetchSliderViewController = @"nativeFetchSliderViewController";


@implementation CTMediator (CTMediatorModuleBActions)

- (UIViewController *)CTMediator_viewControllerForDetail1 {
    UIViewController *viewController = [self performTarget:kCTMediatorTargetB
                                                    action:kCTMediatorActionNativeFetchSliderViewController
                                                    params:@{@"key":@[@"one",@"two",@"three"]}
                                         shouldCacheTarget:NO
                                        ];
    if ([viewController isKindOfClass:[UIViewController class]]) {
        // view controller 交付出去之后，可以由外界选择是push还是present
        return viewController;
    } else {
        // 这里处理异常场景，具体如何处理取决于产品
        return [[UIViewController alloc] init];
    }
}


@end
