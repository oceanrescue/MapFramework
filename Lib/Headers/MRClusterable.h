//
//  MRClusterable.h
//  GeoController
//
//  Created by submarine on 9/5/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

enum {
    kAnnotationTypeUnknown         = 1 << 0,
    kAnnotationTypeUserPosition    = 1 << 1,
};
typedef NSUInteger VNAnnotationType;

/*!
 @protocol MRClusterable
 @abstract clustering an <MKAnnotation> object protocol.
 @discussion Use this protocol for implementation of the clustering annotations.
 */

@protocol MRClusterable <NSObject>
/*!
 @property clustered
 @abstract YES if object is clustered, NO otherwise.
 */
@property (nonatomic) BOOL clustered;
@property (nonatomic) BOOL clusterable;
@property (nonatomic) BOOL clusterWithOtherAnnotationTypes;
@property (nonatomic) VNAnnotationType type;

@end
