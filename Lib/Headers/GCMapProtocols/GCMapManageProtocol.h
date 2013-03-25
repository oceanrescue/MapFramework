//
//  GCMapManageProtocol.h
//  GeoController
//
//  Created by Valeriy Nikitin on 11/29/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@protocol GCMapManageProtocol <NSObject>
/*
 * manage map view and visibile map rect
 */

/*!
 @property centerCoordinate
 @abstract The map coordinate at the center of the map view.
 @discussion Changing the value in this property centers the map on the new coordinate without changing the current zoom level.
 
 Changing the value of this property updates the map view immediately. If you want to animate the change, use the setCenterCoordinate:animated: method instead.
 */
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;
/*!
 @method setCenterCoordinate:animated:
 @abstract Changing the map's coordinate at the center of the map view and animates changes if needed.
 @param zoomLevel New center coordinate at the center of the map view.
 @param animated Specify YES if you want the map view to animate zoom changes and NO otherwise.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;
/*!
 @property region
 @abstract The area currently displayed by the map view.
 @discussion The region encompasses both the latitude and longitude point on which the map is centered and the span of coordinates to display. The span values provide an implicit zoom value for the map. The larger the displayed area, the lower the amount of zoom. Similarly, the smaller the displayed area, the greater the amount of zoom.
 
 Changing only the center coordinate of the region can still cause the span to change implicitly. The span might change because the distances represented by a span change at different latitudes and longitudes and the map view may need to adjust the span to account for the new location. If you want to change the center coordinate without changing the zoom level, use the centerCoordinate instead.
 */
@property(nonatomic) MKCoordinateRegion region;
/*!
 @method setRegion:animated:
 @param region. The new region to display in the map view.
 @param animated. Specify YES if you want the map view to animate the transition to the new region or NO if you want the map to center on the specified region immediately.
 @abstract Changes the currently visible region and optionally animates the change.
 @discusion Changing just the center coordinate of the region can still cause the span values to change implicitly. The span values might change because that the distances represented by a span change at different latitudes and longitudes and the map view may need to adjust the span to account for the new location. If you want to change the center coordinate without changing the zoom level, use the setCenterCoordinate:animated: instead.
 */
- (void) setRegion:(MKCoordinateRegion)region animated:(BOOL)animated;
/*!
 @property zoomScale
 @abstract A floating-point value that specifies the current scale factor applied to the map view's content.
 @discussion This value determines how much the content is currently scaled. The default value is minimumZoomScale.
 
 Changing the value of this property updates the map view immediately. If you want to animate the change, use the setZoomScale:animated: method instead.
 */
@property (nonatomic) float zoomScale;
/*!
 @method setZoomScale:animated:
 @abstract Changing the map's zoom scale and animates changes if needed.
 @param zoomLevel New map zoom scale.
 @param animated Specify YES if you want the map view to animate zoom changes and NO otherwise.
 */
- (void)setZoomScale:(float)zoomScale animated:(BOOL)animated;

/*!
 @property zoomLevel
 @abstract A integer value that specifies the current scale level the map view uses to render content.
 @discussion Changing the value of this property updates the map view immediately. If you want to animate the change, use the setZoomScale:animated: method instead.
 */
@property (nonatomic) int zoomLevel;
/*!
 @method setZoomLevel:animated:
 @abstract Changing the map's zoom level and animates changes if needed.
 @param zoomLevel New map zoom level.
 @param animated Specify YES if you want the map view to animate zoom changes and NO otherwise.
 */
- (void)setZoomLevel:(int)zoomLevel animated:(BOOL)animated;

/*!
 @property minZoomLevel
 @abstract Minimum allowable zoom level
 */
@property (nonatomic) int minZoomLevel;
/*!
 @property maxZoomLevel
 @abstract Maximum allowable zoom level
 */
@property (nonatomic) int maxZoomLevel;

/*!
 @property visibleMapRect
 @abstract The area currently displayed by the map view. (readonly)
 */
@property (nonatomic, readonly) MKMapRect visibleMapRect;

/*!
 @method setMapFixed:
 @abstract prevent map for scrolling.
 @discussion Usualy you need to prevent map scrolling to show fixed region in view. In this mode user can zoom, but unable to scroll map.
 */
- (void) setMapFixed:(BOOL) flag;

/*!
 @method - (BOOL) isMapFixed
 @abstract isMapFixed tell the mode of  map scrolling.
 @discussion return TRUE if scrolling map is unable and FALSE otherwise.
 */

- (BOOL) isMapFixed;
/*!
 @method - (BOOL) clusterizeAnnotations
 @abstract mapView uses clusterizeAnnotations flag to manage clusters of annotations.
 @discussion TRUE if map clusterize annotations and FALSE otherwise.
 */

@property (nonatomic, getter = isAnnotationsClusterize, setter = setAnnotationsClusterize:) BOOL clusterizeAnnotations;

@optional
/*!
 @property defaultCenterCoordinate
 @abstract Default map coordinate at the center of the map view.
 @discussion Use this property to define the map coordinate at the center of the map view after reset the map position by method resetMapPositionAnimated:.
 */
@property (nonatomic) CLLocationCoordinate2D defaultCenterCoordinate;
/*!
 @property defaultZoomLevel
 @abstract Default map zoomLevel.
 @discussion Use this property to define the map zoom level after reset the map position by method resetMapPositionAnimated:.
 */
@property (nonatomic) NSUInteger defaultZoomLevel;

/*!
 @method resetMapPositionAnimated:
 @abstract Changes zoom level and map coordinate at the center of map view to default values and optionaly animates changes.
 @param animated Specify YES if you want the map view to zoom in or zoom out and centers to the new values or NO if you want the map to display the new zoom scale and new center coordinate immediately.
 @discussion Changes zoom level and map coordinate at the center of the map view to new values defined by defaultZoomLevel and defaultCenterCoordinate values.
 */
- (void)resetMapPositionAnimated:(BOOL)animated;
/*!
 @property multipleSelections
 @abstract Can select several zones (overlays) or annotation abjects.
 @discussion if TRUE several objects could be selected/highlighted. If FALSE - previouse highlighted object dehighlight.
 */
@property (nonatomic) BOOL multipleSelections;

@end
