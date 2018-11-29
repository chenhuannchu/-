#import <UIKit/UIKit.h>
#import "MANbCarHistory.h"

@interface MANbCarVehicle : NSObject

@property (nonatomic, strong) NSArray<MANbCarHistory*> * history;
@property (nonatomic, strong) NSString * location;
@property (nonatomic, assign) NSInteger uploadTime;
@property (nonatomic, strong) NSString * vehicleID;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end
