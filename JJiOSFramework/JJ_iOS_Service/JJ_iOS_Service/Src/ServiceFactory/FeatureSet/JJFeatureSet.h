//
//  JJFeatureSet.h
//  JJ_iOS_Service
//
//  Created by JJ on 12/2/15.
//  Copyright © 2015 JJ. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JJRequest;
@class JJService;

@interface JJFeatureSet : NSObject

@property (nonatomic, weak) JJService *service;

+ (NSString *)featureSetName;

- (void)featureSetWillLoad;
- (void)featureSetDidLoad;

- (void)featureSetWillUnload;
- (void)featureSetDidUnload;

- (void)startRequest:(JJRequest *)request
         requestType:(NSString *)requestType
           parameter:(id)parameter
           otherInfo:(id)otherInfo
       successAction:(void (^)(id object, NSString *responseString, JJRequest *request))successAction
          failAction:(void (^)(NSError *error, JJRequest *request))failAction;

- (void)startRequest:(JJRequest *)request
         requestType:(NSString *)requestType
           parameter:(id)parameter
           otherInfo:(id)otherInfo;

- (void)startRequest:(JJRequest *)request
           otherInfo:(id)otherInfo
       successAction:(void (^)(id object, NSString *responseString, JJRequest *request))successAction
          failAction:(void (^)(NSError *error, JJRequest *request))failAction;

- (void)startRequest:(JJRequest *)request
           otherInfo:(id)otherInfo;

- (id)cacheModelWithParameters:(NSDictionary *)parameters
                  requestClass:(Class)requestClass
                   requestType:(NSString *)requestType
                    modelClass:(Class)modelClass
                  isSaveToDisk:(BOOL)isSaveToDisk;

- (void)requestWithParameters:(NSDictionary *)parameters
                 requestClass:(Class)requestClass
                  requestType:(NSString *)requestType
                   modelClass:(Class)modelClass
                 isSaveToDisk:(BOOL)isSaveToDisk
       networkSuccessResponse:(void(^)(id object, NSString *responseString, id otherinfo))networkSuccessResponse
          networkFailResponse:(void (^)(NSError *error, id otherinfo))networkFailResponse;

- (void)actionAfterLogin;
- (void)actionAfterLogout;

@end
