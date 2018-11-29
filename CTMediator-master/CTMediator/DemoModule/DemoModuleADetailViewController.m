//
//  DemoModuleADetailViewController.m
//  CTMediator
//
//  Created by casa on 16/3/13.
//  Copyright © 2016年 casa. All rights reserved.
//

#import "DemoModuleADetailViewController.h"
#import <HandyFrame/UIView+LayoutMethods.h>

@interface DemoModuleADetailViewController ()

@property (nonatomic, strong, readwrite) UILabel *valueLabel;
@property (nonatomic, strong, readwrite) UIImageView *imageView;

@property (nonatomic, strong) UIButton *returnButton;

@end

@implementation DemoModuleADetailViewController

#pragma mark - life cycle
- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor grayColor];
    
    [self.view addSubview:self.valueLabel];
    [self.view addSubview:self.imageView];
    [self.view addSubview:self.returnButton];
}

- (void)viewWillLayoutSubviews
{
    [super viewWillLayoutSubviews];
    
    [self.valueLabel sizeToFit];
    [self.valueLabel topInContainer:70 shouldResize:NO];
    [self.valueLabel centerXEqualToView:self.view];
    
    
    // 1. 用一个临时变量保存返回值。
    CGRect temp = self.imageView.bounds;
    // 2. 给这个变量赋值。因为变量都是L-Value，可以被赋值
    temp.size = CGSizeMake(100, 100);
    // 3. 修改frame的值
    self.imageView.bounds = temp;
    
    [self.imageView centerEqualToView:self.view];
    
    
    // 1. 用一个临时变量保存返回值。
    CGRect temp1 = self.returnButton.bounds;
    // 2. 给这个变量赋值。因为变量都是L-Value，可以被赋值
    temp1.size = CGSizeMake(100, 100);
    // 3. 修改frame的值
    self.returnButton.bounds = temp1;
    
//    self.returnButton.bounds.size = CGSizeMake(100, 100);
    [self.returnButton bottomInContainer:0 shouldResize:NO];
    [self.returnButton centerXEqualToView:self.view];
}

#pragma mark - event response
- (void)didTappedReturnButton:(UIButton *)button
{
    if (self.navigationController == nil) {
        [self dismissViewControllerAnimated:YES completion:nil];
    } else {
        [self.navigationController popViewControllerAnimated:YES];
    }
}

#pragma mark - getters and setters
- (UILabel *)valueLabel
{
    if (_valueLabel == nil) {
        _valueLabel = [[UILabel alloc] init];
        _valueLabel.font = [UIFont systemFontOfSize:30];
        _valueLabel.textColor = [UIColor blackColor];
    }
    return _valueLabel;
}

- (UIImageView *)imageView
{
    if (_imageView == nil) {
        _imageView = [[UIImageView alloc] init];
        _imageView.contentMode = UIViewContentModeScaleAspectFit;
    }
    return _imageView;
}

- (UIButton *)returnButton
{
    if (_returnButton == nil) {
        _returnButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [_returnButton addTarget:self action:@selector(didTappedReturnButton:) forControlEvents:UIControlEventTouchUpInside];
        [_returnButton setTitle:@"return" forState:UIControlStateNormal];
        [_returnButton setTitleColor:[UIColor blueColor] forState:UIControlStateNormal];
    }
    return _returnButton;
}

@end