#import <UIKit/UIKit.h>

@interface MANbCarRequest : NSObject

///请求服务权限标识. 必填
@property (nonatomic, strong) NSString * key;

///设备号，IDFA (无IDFA则使用IDFV). 必填
@property (nonatomic, strong) NSString * customerDeviceID;

///订单所在城市, 使用citycode。如: 010. 必填
@property (nonatomic, strong) NSString * orderCity;

///出发地经纬度, 经度在前，纬度在后，用英文半角逗号","分隔, 如: 116.473195,39.993253. 必填
@property (nonatomic, strong) NSString * start;

///出发地名称. 必填
@property (nonatomic, strong) NSString * startName;

///车辆类型 0：所有分类, 1：出租车, 2：新能源, 3：舒适型, 4：豪华型, 5：商务型. 必填
@property (nonatomic, assign) NSInteger vehicleType;

///最大车辆返回数(1-20), 默认5. 非必填
@property (nonatomic, assign) NSInteger maxCount;

///查询半径, 单位公里，范围(2-20)且必须为2的倍数, 默认2。非必填
@property (nonatomic, assign) NSInteger radius;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end
