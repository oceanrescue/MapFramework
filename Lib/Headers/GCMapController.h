//
//  GCMapController.h
//  GeoController
//
//  Created on 11/13/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCMapController.h
 @abstract Map Controller class definition.
 */

#import "GCMapManageProtocol.h"
#import "GCMapAnnotationProtocol.h"
#import "GCMapConversion.h"
#import "GCMapOverlayProtocol.h"
#import "GCMapUserLocationProtocol.h"

@class MRMapView;
@protocol MRTileProvider;

@protocol GCMapControllerDataSource;
@protocol GCMapControllerDelegate;

@class GCZoneController;
@class GCRouteController;

/*!
 @class GCMapController
 @abstract Map controller class interface.
 @discussion An GCMapController object provides the interface for manage an embeddable map interface (RMMapView), similar to the one provided by the Maps application. You use this class as-is to display map information and to manipulate the map contents from your application. You can center the map on a given coordinate, specify the zoom scale and level of the area you want to display, and annotate the map with custom information (overlays and annotations).
 */
@interface GCMapController : UIViewController <GCMapManageProtocol, GCMapConversionProtocol, GCMapAnnotationProtocol, GCMapOverlayProtocol, GCMapUserLocationProtocol> {

@private
    id<MRTileProvider> tileProvider;
    
    id<GCMapControllerDataSource>   _dataSource;
    id<GCMapControllerDelegate>     _delegate;
    
    CLLocationCoordinate2D initialCenter;
    CGFloat initialZoomScale;
    
    CLLocationCoordinate2D defaultCenterCoordinate;
    NSUInteger defaultZoomLevel;
    
    GCZoneController *_zoneController;
    GCRouteController *_routeController;
}

+ (void) setSharedController:(GCMapController*)mapController;
+ (GCMapController *) sharedMapController;
+ (void)destroySharedMapController;
+ (GCMapController*)createGeoControllerWithDefaultMap;

/*!
 @property mapView
 @abstract Map presentation view.
 */
@property (nonatomic, retain) IBOutlet MRMapView *mapView;

/*!
 @property dataSource
 @abstract The receiver’s data source.
 @discussion Data source is used for retriving information necessary for map presentation from external module (i.e. information about zones).
 */
@property (nonatomic, assign) IBOutlet id<GCMapControllerDataSource> dataSource;
/*!
 @property delegate
 @abstract The receiver’s delegate.
 @discussion A map view sends messages to its delegate regarding the changes in the portion of the map being displayed. The delegate also manages the zone views used to select points of interest on the map. 
 */
@property (nonatomic, assign) IBOutlet id<GCMapControllerDelegate> delegate;

/*!
 @method reloadZones
 @abstract Remove all zone overlays from the map view and forces zone overlays loading.
 @discussion You don't need to use this method for displaying zone overlays. Map view automatically retrives zones need to be displayed for current map zoom scale and position from data source. Use this method to display chancges when zones modified after they were displayed in map view. This operation possibly may be computational cost expensive, use it accurately.
 */
- (void)reloadZones;

/*!
 @method setMapExcludeList:
 @abstract Specifies the set of map tags ignored by map rasterize.
 @param dictionary Dictionary of map tags and it's values.
 @discussion Objects specified in dictionary by tags and values are not presented in the map.
 */
- (void)setMapExcludeList:(NSDictionary *)dictionary;
/*!
 @method clearCache:
 @abstract Remove all chached map tiles.
 @discussion Clear chache results to removing all prerendered and cached map tile images. Tile images will be re-created and re-cached as they required for map presentation. The opration of map tile rasterization may be computational cost expensive. Use this method carefully only if the map data chanched and need to be represented (for ex. after the call of the method setMapExcludeList: with new set of tags). 
 */
- (void)clearCache;

/*!
 @method clearMap:
 @abstract Remove all zones, routes, annotations in mapView.
 @discussion Clear map results to removing all present zones, routes, annotations in mapView. Method uses to clear all images on map to represent fresh map. 
 */
- (void)clearMap;

@end
