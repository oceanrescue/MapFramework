//
//  GCGeoControllerDataSource.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCMapControllerDataSource.h
 @abstract Map controller data source.
 */

#import <Foundation/Foundation.h>

@class GCMapController;
@class GCZoneContentInfo;
@class MRAnnotationView;
@class MROverlayView;
@protocol GCZoneStyle;

/*!
 @protocol GCMapControllerDataSource
 @abstract Map controller data source protocol.
 @discussion The GCMapControllerDataSource protocol defines a set of required methods need to zone overlays presenttion.
 */
@protocol GCMapControllerDataSource <NSObject>
/*!
 @method mapController:viewForAnnotation:
 @abstract Returns the view associated with the specified annotation object.
 @param mapController The map controller that requested the annotation view.
 @param The object representing the annotation that is about to be displayed. In addition to your custom annotations, this object could be an MRUserLocation object representing the user’s current location.
 @return The annotation view to display for the specified annotation or nil if you want to display a standard annotation view.
 @discussion Rather than create a new view each time this method is called, you should use the dequeueReusableAnnotationViewWithIdentifier: method of the MRMapView class to see if an existing annotation view of the desired type already exists. If one does exist, you should update the view to reflect the attributes of the specified annotation and return it. If a view of the appropriate type does not exist, you should create one, configure it with the needed annotation data, and return it.
 
 If the object in the annotation parameter is an instance of the MKUserLocation class, you can provide a custom view to denote the user’s location. To display the user’s location using the default system view, return nil.
 
 If you do not implement this method, or if you return nil from your implementation for annotations other than the user location annotation, the map view uses a standard pin annotation view.
 */
- (MRAnnotationView *)mapController:(GCMapController *)mapController viewForAnnotation:(id <MKAnnotation>)annotation;
/*!
 @method mapController:viewForOverlay:
 @abstract Asks the datasource for the overlay view to use when displaying the specified overlay object.
 @param mapController The map controller that requested the overlay view.
 @param overlay - The object representing the overlay that is about to be displayed.
 @ReturnValue
 The view to use when presenting the specified overlay on the map. If you return nil, no view is displayed for the specified overlay object.
 @discussion If you support the presentation of overlays, you must implement this method and provide the views for your overlay objects.
 */
- (MROverlayView *)mapController:(GCMapController *)mapController viewForOverlay:(id <MKOverlay>)anOverlay;

@optional
//new methods to configure map zones
/*!
 @method zonesForMapController:
 @abstract Returns the array of zones objects (GCZone)  that have to be presented on map.
 @param mapController The map controller that requires array of GCZones objects.
 @return Array of zones.
 @discussion Use this method to provide array of zones that have to be presented on the map for current map view zoom scale and coordinate location. Use map controller's properties zoomScale, zoomLevel, centerCoordinate to retrive current zoom scale and location. Map controller asks the data source for zones array after the map center coordinate and/or zoom changes finished (i.e. corresponding animation is finished).
 */
- (NSArray *)zonesForMapController:(GCMapController *)mapController;

//zoneIDsForMapController - old method to configure map zones
/*!
 @method zoneIDsForMapController:
 @abstract Returns the array of zone ID that have to be presented on map.
 @param mapController The map controller that requires array of zone ID.
 @return Array of zone ID.
 @discussion Use this method to provide array of zone ID that have to be presented on the map for current map view zoom scale and coordinate location. Use map controller's properties zoomScale, zoomLevel, centerCoordinate to retrive current zoom scale and location. Map controller asks the data source for zone ID array after the map center coordinate and/or zoom changes finished (i.e. corresponding animation is finished).  
 */
- (NSArray *)zoneIDsForMapController:(GCMapController *)mapController __attribute__((deprecated));
/*!
 @method mapController:levelForZoneWithID:
 @abstract Returns the level of the zone with the specified ID.
 @param mapController The map controller that requires level for zone ID.
 @param zoneID ID of the zone the level is asked for
 @param index index of zone in array of last time requested zone identifiers.
 @return Level of the zone with specified ID.
 @discussion Map controller asks the data source to provide the level of the zone once for every ID ever provided by data source's method zoneIDsForMapController:. Use map controller's method reloadZones to remove all loaded zones and force zone reload.
 */
- (NSInteger)mapController:(GCMapController *)mapController levelForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index;
/*!
 @method mapController:contentForZoneWithID:
 @abstract Returns the text & graphic item array of the zone with the specified ID.
 @param mapController The map controller that requires text & graphic information for zone ID.
 @param zoneID ID of the zone the text & graphic information is asked for.
 @param index index of zone in array of last time requested zone identifiers.
 @return text & graphic item array of the zone with specified ID.
 @discussion Map controller asks the data source to provide the text & graphic information of the zone once for every ID ever provided by data source's method zoneIDsForMapController:. Use map controller's method reloadZones to remove all loaded zones and force zone reload.
 */
- (NSArray *)mapController:(GCMapController *)mapController contentForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index;
/*!
 @method mapController:colorForZoneWithID:
 @abstract Returns the zone style object of the zone with the specified ID.
 @param mapController The map controller that requires style information for zone ID.
 @param zoneID ID of the zone the zone style object is asked for
 @param index index of zone in array of last time requested zone identifiers.
 @return zone style object of the zone with specified ID.
 @discussion Map controller asks the data source to provide the style object of the zone once for every ID ever provided by data source's method zoneIDsForMapController:. Use map controller's method reloadZones to remove all loaded zones and force zone reload. Zone style specifies the appearance of the corresponding zone, including default/selection/highlighting color, line width, alpha. Each zone may have it's own style. 
 
 If you return nil from your implementation, the map view uses a standard zone style.
 */
- (id <GCZoneStyle>)mapController:(GCMapController *)mapController styleForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index;
@end
