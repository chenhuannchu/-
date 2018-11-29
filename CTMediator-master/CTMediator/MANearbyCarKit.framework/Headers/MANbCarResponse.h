#import <UIKit/UIKit.h>
#import "MANbCarData.h"

@interface MANbCarResponse : NSObject

@property (nonatomic, strong) MANbCarData * data;
@property (nonatomic, assign) NSInteger errcode;
@property (nonatomic, strong) NSObject * errdetail;
@property (nonatomic, strong) NSString * errmsg;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end