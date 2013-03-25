//
//  GCMapOverlayProtocol.h
//  GeoController
//
//  Created by Valeriy Nikitin on 11/29/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MROverlayView;
@protocol GCMapOverlayProtocol <NSObject>

/*!
 *
 *  OVERLAYS
 *
 */

/*!
 @property overlays
 @abstract The overlay objects currently associated with the map view. (read-only)
 @discussion The objects in this array must adopt the MKOverlay protocol. If no overlays are associated with the map view, the value of this property is an empty array.
 
 If the regions defined by two overlays intersect one another, the order of the objects in this array determines the z-order of the corresponding overlay views that are displayed in the map. Overlay objects at the beginning of the array are placed behind those that come later in the array. Thus, the view for an overlay at index 0 is displayed behind the view for the overlay at index 1.
 */
@property (nonatomic, readonly) NSArray *overlays;
/*!
 @property visibleOverlays
 @abstract The visible overlay objects currently associated with the map view. (read-only)
 @discussion The objects in this array must adopt the MKOverlay protocol. If no overlays are associated with the map view, the value of this property is an empty array.
 
 If the regions defined by two overlays intersect one another, the order of the objects in this array determines the z-order of the corresponding overlay views that are displayed in the map. Overlay objects at the beginning of the array are placed behind those that come later in the array. Thus, the view for an overlay at index 0 is displayed behind the view for the overlay at index 1.
 */
@property (nonatomic, readonly) NSArray *visibleOverlays;

/*!
 @method addOverlay:
 @abstract Adds a single overlay object to the map.
 @param overlay The overlay object to add. This object must conform to the MKOverlay protocol.
 @discussion The specified overlay is added to the end of the list of overlay objects.By default overlays adds to scalble layer.
 */
- (void)addOverlay:(id <MKOverlay>)overlay;

/*!
 @method addOverlays:
 @abstract Adds an array of overlay objects to the map.
 @param overlays An array of objects, each of which must conform to the MKOverlay protocol.
 @discussion The specified objects are added to the end of the list of overlay objects. By default overlays adds to scalble layer.
 */
- (void)addOverlays:(NSArray *)overlays;

/*!
 @method insertOverlay:atIndex:
 @abstract Inserts an overlay object into the list associated with the map.
 @param overlay The overlay object to insert.
 @param The index at which to insert the overlay object. If this value is greater than the number of objects in the overlays property, this method appends the object to the end of the array. By default overlays inserts to scalble layer.
 */
- (void)insertOverlay:(id <MKOverlay>)overlay atIndex:(NSInteger)index;

/*!
 @method removeOverlay:
 @abstract Removes a single overlay object from the map.
 @param overlay The overlay object to remove.
 @discussion Removing an overlay object removes the corresponding overlay view, if one is currently displayed. If the specified object is not currently associated with the map view, this method does nothing.
 */
- (void)removeOverlay:(id)overlay;

/*!
 @method removeOverlays:
 @abstract Removes one or more overlay objects from the map.
 @param overlays An array of objects, each of which conforms to the MKOverlay protocol.
 @discussion Removing an overlay object removes the corresponding overlay view, if one is currently displayed. If one or more of the overlay objects are not currently associated with the map view, this method removes the objects that are associated with the map and ignores the rest.
 */
- (void)removeOverlays:(NSArray *)overlays;


/*!
 @method removeAllOverlays
 @abstract Removes all overlays objects from the map.
 @discussion Removing an overlay object removes the corresponding overlay view, if one is currently displayed. If one or more of the overlay objects are not currently associated with the map view, this method removes the objects that are associated with the map and ignores the rest.
 */
- (void)removeAllOverlays;

/*!
 @method viewForOverlay:
 @abstract Returns the view associated with the overlay object if any.
 @param overlay The overlay object whose view you want.
 @discussion The view associated with the overlay object or nil if the overlay is not presented.
 */
- (MROverlayView *)viewForOverlay:(id <MKOverlay>)overlay;

/*!
 @property selectedOverlays
 @abstract The overlays that are currently selected.
 */
@property (nonatomic, readonly) NSArray *selectedOverlays;
/*!
 @method selectOverlay:animated:
 @abstract Selects the specified overlay.
 @param overlay The overlay object to select.
 @param animated Currently not used.
 */
- (void)selectOverlay:(id <MKOverlay>)overlay animated:(BOOL)animated;
/*!
 @method deselectOverlay:animated:
 @abstract Deselects the specified overlay.
 @param overlay The overlay object to deselect.
 @param animated Currently not used.
 */
- (void)deselectOverlay:(id <MKOverlay>)overlay animated:(BOOL)animated;

@end
