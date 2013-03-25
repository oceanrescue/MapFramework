//
//  MRUserLocationView.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MRUserLocationView.h
 @abstract User location annotation view class definition
 */

#import "MRAnnotationView.h"

/*!
 @protocol MRUserLocationView
 @abstract User location annotation view class.
 @discussion User location view is concrete subclass of MRAnnotationView. Use to shows user location on the map.
 */
@interface MRUserLocationView : MRAnnotationView
- (void) updatePosition:(CLLocationCoordinate2D)coordinate;
@end
