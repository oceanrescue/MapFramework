//
//  MRCacheProvider.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

#define FULL_CACHE_MAX_LEVEL 7

@protocol GCMapObjectDatasourceProvider;
@class GCRasterizer;

@interface GCMapSourceController : NSObject{
    @private
    id<GCMapObjectDatasourceProvider> provider;
}

- (id)initWithResourcePath:(NSString *)path;
- (id<GCMapObjectDatasourceProvider>) getDatasourceProvider;
+ (void) initGlobalWithResourcePath:(NSString*) path;
+(GCMapSourceController*) sharedController;

@end
