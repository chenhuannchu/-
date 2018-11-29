#import <UIKit/UIKit.h>

@interface MANbCarNearestVehicle : NSObject

@property (nonatomic, assign) NSInteger distance;
@property (nonatomic, assign) NSInteger time;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end