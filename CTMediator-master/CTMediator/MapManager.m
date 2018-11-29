//
//  MapManager.m
//  CTMediator
//
//  Created by 陈欢 on 2018/11/15.
//  Copyright © 2018 casa. All rights reserved.
//

#import "MapManager.h"

#import <AMapLocationKit/AMapLocationKit.h>

#import <MANearbyCarKit/MANearbyCarKit.h>
#import <MAMapKit/MAMapKit.h>
#import <MACarCallKit/MACarCallKit.h>

@interface MapManager()<AMapLocationManagerDelegate,MANearbyCarControllerDelegate,MAMapViewDelegate,MAHotSpotControllerDelegate>

@property (nonatomic,strong)AMapLocationManager *locationManager;

//附近运力控制器
@property (nonatomic,strong)MANearbyCarController *nearbyCarController;

@property (nonatomic, strong)MAMapView *mapView;

//推荐点控制器
@property (nonatomic,strong)MAHotSpotController *hotSpotController;





@end

@implementation MapManager


+ (MapManager *)defaultManager {
    static MapManager *manager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        manager = [[MapManager alloc] init];
        
    });
    return manager;
}

- (instancetype)init
{
    self = [super init];
    if (self) {
        _locationDic = [NSMutableDictionary dictionary];

    }
    return self;
}


//高德KEY配置
- (void)mapServiceSetting {
    [AMapServices sharedServices].apiKey = @"f374c1e98c82605bced14ed06b3c0aec";//企业版
    [AMapServices sharedServices].enableHTTPS = YES;
}

//开始定位
- (void)startContinuousLocation {
    
    [self.locationManager startUpdatingLocation];
}


//停止连续定位
- (void)stopContinuousLocation {
    
    [self.locationManager stopUpdatingLocation];
}




//连续定位回调
- (void)amapLocationManager:(AMapLocationManager *)manager didUpdateLocation:(CLLocation *)location reGeocode:(AMapLocationReGeocode *)reGeocode{
    
    self.locationDic[@"location"] = location;
    
}


//高德：附近运力
- (void)configNearbyCarController {
    self.nearbyCarController.paused = NO;
    self.nearbyCarController.enableDebugLog = true;
}

- (void)removeNearbyCarController {
    
    [self.nearbyCarController clearCars];
    self.nearbyCarController.paused = YES;
    self.nearbyCarController = nil;

}

- (void)resetNearbyCarController {
    [self removeNearbyCarController];
    [self configNearbyCarController];
}


//高德：附近上车点
- (void)configHotSpotController {
    if (![MAHotSpotManager sharedInstance].accessKey) {
        return;
    }
    
    if (self.hotSpotController == nil) {
        self.hotSpotController = [[MAHotSpotController alloc] initWithMapView:self.mapView delagate:self];
        
    }
}

- (void)removeHotSpotController {
    if (self.hotSpotController) {
        [self.mapView removeAnnotations:self.hotSpotController.spotAnnoArray];
        [self.mapView removeAnnotation:self.hotSpotController.pinAnnotation];
        self.hotSpotController.delegate = nil;
        self.hotSpotController = nil;
    }
}






#pragma 附近上车点代理
- (void)hotSpotController:(MAHotSpotController *)controller didFailWithError:(NSError *)error {
    NSString *idfv = [UIDevice currentDevice].identifierForVendor.UUIDString;
    NSLog(@"error: %@ [IDFV] = %@",error,idfv);
}


- (void)didAnchorPinAbsorbedToAnnotation:(MAHotSpotAnnotation *)anno controller:(MAHotSpotController *)controller {
    
    MAHotSpotInfo *spotInfo = anno.spotInfo;
    CLLocationCoordinate2D coordinate = spotInfo.coordinate;
    self.annoCoordinate = coordinate;
    
    
}

- (BOOL)shouldSendSpotQueryRequest:(CLLocationCoordinate2D)centerCoord preCoord:(CLLocationCoordinate2D)preCoord absorbedAnno:(MAHotSpotAnnotation *__autoreleasing *)absorbedAnno clearPrevAnnos:(BOOL *)clearPrevAnnos controller:(MAHotSpotController *)controller {
    return YES;
}

- (BOOL)shouldAutoAbsorbedToAnnotation:(MAHotSpotAnnotation *)anno controller:(MAHotSpotController *)controller {
    return YES;
}

- (MAHotSpotAnnotationView *)createHotSpotViewWith:(MAHotSpotAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier controller:(MAHotSpotController *)controller {
    
    MAHotSpotAnnotationView *annotationView = [[MAHotSpotAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:reuseIdentifier];
    annotationView.animatingCircleImage = [UIImage imageNamed:@""];
    annotationView.centerDotImage = [UIImage imageNamed:@""];
    annotationView.nameLabel.font = [UIFont fontWithName:@"PingFangSC-Medium" size:15];
    annotationView.nameLabel.textColor = [UIColor redColor];
    annotationView.nameLabelMaxWidth = 120;
    return annotationView;
    
    
}

- (MAAnnotationView *)createAnchorPinViewWith:(MAPointAnnotation *)annotation reuseIdentifier:(NSString *)reuseIdentifier controller:(MAHotSpotController *)controller {
    MAPinAnnotationView *pinAnnotationView = [[MAPinAnnotationView alloc] initWithFrame:CGRectZero];
    return pinAnnotationView;
}


#pragma 附近运力代理
//如果返回NO，则不重新请求。centerCoord: 这次请求的中心点坐标; preCoord: 上次请求的中心点坐标; prevDate: 上次请求时间
- (BOOL)shouldSendNearbyCarRequest:(CLLocationCoordinate2D)centerCoord
                          preCoord:(CLLocationCoordinate2D)preCoord
                          prevDate:(NSDate*)prevDate
                        controller:(MANearbyCarController *)controller {
    return YES;
}

- (CLLocationCoordinate2D)getCenterCoordinate:(MANearbyCarController *)controller {
    return self.mapView.centerCoordinate;
}



- (MAMapView *)mapView {
    if (!_mapView) {
        
        _mapView = [[MAMapView alloc] initWithFrame:CGRectZero];
        _mapView.delegate = self;
        _mapView.zoomLevel = 17;
        _mapView.allowsBackgroundLocationUpdates = YES;
        _mapView.customizeUserLocationAccuracyCircleRepresentation = YES;
        _mapView.rotateEnabled = NO;
        _mapView.rotateCameraEnabled = NO;
        _mapView.showsCompass = NO;
        _mapView.showsScale = NO;
        _mapView.showsBuildings = NO;
        _mapView.showsUserLocation = NO;
        _mapView.userTrackingMode = MAUserTrackingModeNone;
    }
    return _mapView;
}


- (MANearbyCarController *)nearbyCarController {
    if (!_nearbyCarController) {
        _nearbyCarController = [[MANearbyCarController alloc] initWithMapView:self.mapView delagate:self];
        _nearbyCarController.carImage = [UIImage imageNamed:@""];
        _nearbyCarController.maxCounts = 20;
        _nearbyCarController.vehicleType = 1;
    }
    
    return _nearbyCarController;
}

- (AMapLocationManager *)locationManager{
    
    if (!_locationManager) {
        _locationManager = [[AMapLocationManager alloc]init];
        _locationManager.delegate = self;
        _locationManager.desiredAccuracy = kCLLocationAccuracyNearestTenMeters;//定位精度
        _locationManager.locationTimeout = 2;//定位超时
        _locationManager.reGeocodeTimeout = 5;//逆地理超时
        _locationManager.allowsBackgroundLocationUpdates = YES;//是否允许后台定位
        _locationManager.locatingWithReGeocode = YES;//连续定位返回逆地理信息
        _locationManager.detectRiskOfFakeLocation = YES;//是否检测有虚拟定位
        _locationManager.distanceFilter = kCLDistanceFilterNone;
    }
    return _locationManager;
}

@end
