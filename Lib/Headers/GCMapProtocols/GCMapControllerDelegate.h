//
//  GCGeoControllerDelegate.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCMapControllerDelegate.h
 @abstract Map controller delegate.
 */

#import <Foundation/Foundation.h>

@class GCMapController, MRAnnotationView, MRMapView, MKOverlayView, MROverlayView, GCRoute, GCRouteSegment, GCWayPoint;
@protocol MKOverlay;

/*!
 @protocol GCMapControllerDelegate
 @abstract Map controller delegate protocol.
 @discussion The GCMapControllerDelegate protocol defines a set of required methods that you can use to receive map-related update messages. The map view also uses these methods to request annotation and overlay views and to manage interactions with those views.
 */
@protocol GCMapControllerDelegate <NSObject>
@optional
- (void)mapController:(GCMapController *)mapController regionWillChangeAnimated:(BOOL)animated;

- (void)mapController:(GCMapController *)mapController regionDidChangeAnimated:(BOOL)animated;

- (void)mapController:(GCMapController *)mapController didSelectAnnotationView:(MRAnnotationView *)annotationView;

- (void)mapController:(GCMapController *)mapController didDeselectAnnotationView:(MRAnnotationView *)annotationView;

- (void)mapController:(GCMapController *)mapController didSelectOverlayView:(MROverlayView *)overlayView;

- (void)mapController:(GCMapController *)mapController didDeselectOverlayView:(MROverlayView *)overlayView;

- (void)mapController:(GCMapController *)mapController annotationView:(MRAnnotationView *)annotationView calloutAccessoryControlTapped:(UIControl *)aControl;

/*!
 @method mapController:didSelectZoneWithId:
 @abstract Tells the delegate that one of its zone views was selected.
 @param mapController The map view controller managing the zone with specified ID.
 @param zoneID ID of the zone that was selected.
 @param index index of zone in array of last time requested zone identifiers.
 @discussion You can use this method to track changes in the selection state of the zone views.
 */
- (void)mapController:(GCMapController *)mapController didSelectZoneWithId:(NSNumber *)zoneId atIndex:(NSInteger)index;
/*!
 @method mapController:didDeselectZoneWithId:
 @abstract Tells the delegate that one of its zone views was deselected.
 @param mapController The map view controller managing the zone with specified ID.
 @param zoneID ID of the zone that was deselected.
 @param index index of zone in array of last time requested zone identifiers.
 @discussion You can use this method to track changes in the selection state of the zone views.
 */
- (void)mapController:(GCMapController *)mapController didDeselectZoneWithId:(NSNumber *)zoneId atIndex:(NSInteger)index;
@end
