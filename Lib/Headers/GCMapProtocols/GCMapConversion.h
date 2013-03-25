//
//  GCMapControllerConversion.h
//  GeoController
//
//  Created by Valeriy Nikitin on 11/29/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@protocol GCMapConversionProtocol <NSObject>
/*!
 *
 *      CONVERSION
 *
 */
#pragma mark - Conversion
/*!
 @method convertMapPoint:toPointToView:
 @abstract Converts a map point to a point in the specified view.
 @param mapPoint The map point for which you want to find the corresponding point.
 @param view The view in whose coordinate system you want to locate the specified map point. If this parameter is nil, the returned point is specified in the window’s coordinate system. If view is not nil, it must belong to the same window as the map view.
 @return The point (in the appropriate view or window coordinate system) corresponding to the specified map point.
 */
- (CGPoint)convertMapPoint:(MKMapPoint)mapPoint toPointToView:(UIView *)view;
/*!
 @method convertPoint:toMapPointFromView:
 @abstract Converts a point in the specified view’s coordinate system to a map point.
 @param point The point you want to convert.
 @param view The view that serves as the reference coordinate system for the point parameter.
 @return The map point at the specified point.
 */
- (MKMapPoint)convertPoint:(CGPoint)point toMapPointFromView:(UIView *)view;
/*!
 @method convertCoordinate:toPointToView:
 @abstract Converts a map coordinate to a point in the specified view.
 @param coordinate The map coordinate for which you want to find the corresponding point.
 @param view The view in whose coordinate system you want to locate the specified map coordinate. If this parameter is nil, the returned point is specified in the window’s coordinate system. If view is not nil, it must belong to the same window as the map view.
 @return The point (in the appropriate view or window coordinate system) corresponding to the specified latitude and longitude value.
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(UIView *)view;
/*!
 @method convertRegion:toRectToView:
 @abstract Converts a map region to a rectangle in the specified view.
 @param region The map region for which you want to find the corresponding view rectangle.
 @param view The view in whose coordinate system you want to locate the specified map region. If this parameter is nil, the returned rectangle is specified in the window’s coordinate system. If view is not nil, it must belong to the same window as the map view.
 @return The rectangle corresponding to the specified map region.
 */
- (CGRect)convertRegion:(MKCoordinateRegion)region toRectToView:(UIView *)view;
/*!
 @method convertPoint:toCoordinateFromView:
 @abstract Converts a point in the specified view’s coordinate system to a map coordinate.
 @param point The point you want to convert.
 @param view The view that serves as the reference coordinate system for the point parameter.
 @return The map coordinate at the specified point.
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(UIView *)view;
/*!
 @method convertRect:toRegionFromView:
 @abstract Converts a rectangle in the specified view’s coordinate system to a map region.
 @param rect The rectangle you want to convert.
 @param view The view that serves as the reference coordinate system for the rect parameter.
 @return The map region corresponding to the specified view rectangle.
 */
- (MKCoordinateRegion)convertRect:(CGRect)rect toRegionFromView:(UIView *)view;

- (MKMapPoint) convertCoordinateToMapPoint:(CLLocationCoordinate2D)coordinate;
/*!
 @method convertMapRect:toRectToView:
 @abstract Converts a map rect to a rectangle in the specified view.
 @param mapRect The map rect for which you want to find the corresponding view rectangle.
 @param view The view in whose coordinate system you want to locate the specified map region. If this parameter is nil, the returned rectangle is specified in the window’s coordinate system. If view is not nil, it must belong to the same window as the map view.
 @return The rectangle corresponding to the specified map rect.
 */
- (CGRect)convertMapRect:(MKMapRect)mapRect toRectToView:(UIView *)view;
/*!
 @method convertRect:toMapRectFromView:
 @abstract Converts a rectangle in the specified view’s coordinate system to a map rect.
 @param rect The rectangle you want to convert.
 @param view The view that serves as the reference coordinate system for the rect parameter.
 @return The map rect corresponding to the specified view rectangle.
 */
- (MKMapRect)convertRect:(CGRect)rect toMapRectFromView:(UIView *)view;

- (CGPoint) convertCoordinateToPointToMapView:(CLLocationCoordinate2D)coordinate fromView:(UIView *)aView;
@end
