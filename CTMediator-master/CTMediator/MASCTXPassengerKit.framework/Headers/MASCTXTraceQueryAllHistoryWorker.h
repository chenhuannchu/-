//
//  MASCTXTraceQueryAllHistoryWorker.h
//  MASCTXPassengerKit
//
//  Created by shaobin on 2018/3/6.
//  Copyright © 2018年 Amap. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MASCTXHistoryTraceRequest.h"
#import "MASCTXHistoryTraceResponse.h"

typedef void(^MASCTXHistoryTraceRequestOnePageCallback)(MASCTXHistoryTraceResponse *response, NSError* error, MASCTXHistoryTraceRequest* request);

typedef void(^MASCTXHistoryTraceRequestAllResultCallback)(NSArray<MASCTXHistoryTraceResponse*> *responseArr, NSUInteger maxPageNum);

@interface MASCTXTraceQueryAllHistoryWorker : NSObject

///默认3
@property (nonatomic, assign) NSUInteger retryCountOnFailure;

@property (nonatomic, assign, readonly) BOOL isCancelled;

- (void)queryAllHistoryTraceWithKey:(NSString *)key
                                sid:(NSString *)sid
                            orderId:(NSString *)orderId
                          startTime:(long long)startTime
                            endTime:(long long)endTime
                           pageSize:(NSUInteger)pageSize
                       pageCallback:(MASCTXHistoryTraceRequestOnePageCallback)pageCallback
                        allCallback:(MASCTXHistoryTraceRequestAllResultCallback)allCallback;

- (void)cancel;

@end
