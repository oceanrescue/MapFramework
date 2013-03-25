//
//  MRUserLocation.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MRUserLocation.h
 @abstract User location class definition
 */

#import "MRClusterable.h"
/*!
 @protocol MRUserLocation
 @abstract User location class.
 @discussion Concrete implementation of the MKAnnotation protocol. Describes the current user location.
 */
@interface MRUserLocation : NSObject <MKAnnotation> {
    
}
@property (nonatomic) VNAnnotationType type;

@end
