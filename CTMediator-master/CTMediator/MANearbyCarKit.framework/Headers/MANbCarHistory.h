#import <UIKit/UIKit.h>

@interface MANbCarHistory : NSObject

@property (nonatomic, assign) CGFloat lat;
@property (nonatomic, assign) CGFloat lng;
@property (nonatomic, assign) NSInteger timestamp;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end