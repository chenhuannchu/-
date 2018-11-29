#import <UIKit/UIKit.h>
#import "MANbCarNearestVehicle.h"
#import "MANbCarVehicle.h"

@interface MANbCarData : NSObject

@property (nonatomic, assign) NSInteger count;
@property (nonatomic, strong) NSString * customerDeviceID;
@property (nonatomic, strong) MANbCarNearestVehicle * nearestVehicle;
@property (nonatomic, strong) NSArray<MANbCarVehicle*> * vehicles;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end
