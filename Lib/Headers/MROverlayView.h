//
//  MROverlayView.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MROverlayView.h
 @abstract Map overlay view class definition
 */

#import "MRReusable.h"
#import "MRSelectable.h"

@class MRMapTileView;

/*!
 @protocol MROverlayView
 @abstract Map overlay view class.
 @discussion The MKOverlayView class defines the basic behavior associated with all overlay views. An overlay view provides the visual representation of an overlay object—that is, an object that conforms to the MKOverlay protocol. This class defines the drawing infrastructure used by the map view but does not do any actual drawing. Subclasses are expected to override the drawMapRect:zoomScale:inContext: method in order to draw the contents of the overlay view.
 */
@interface MROverlayView : UIView <MRSelectable, MRReusable> {
    @private
    id <MKOverlay> overlay;
    NSString *_reuseIdentifier;
    
    BOOL highlighted;
    BOOL selected;
    MRMapTileView *mapTileView;
}

/*!
 @property mapTileView
 @abstract mapTileView uses for unit conversion.
 */
@property (nonatomic, assign) MRMapTileView *mapTileView;

/*!
 @property overlay
 @abstract The overlay object containing the data for drawing. (read-only)
 */
@property (nonatomic, retain) id <MKOverlay> overlay;

/*!
 @method initWithOverlay:
 @abstract Initializes and returns the overlay view and associates it with the specified overlay object.
 @param overlay The overlay object to use when drawing the overlay on the map. This object provides the data needed to draw the overlay’s shape. This object is retained by the overlay view.
 @result An initialized overlay object.
 @discussion Upon initialization, the frame of the overlay view is set to CGRectZero. The map view sets the size and position of the view at display time, and you should not change those values yourself. 
 */
- (id)initWithOverlay:(id <MKOverlay>)overlay;

/*!
 @method drawMapRect:zoomScale:inContext:
 @abstract Draws the contents of the overlay view.
 @param mapRect The map rectangle that needs to be updated. You can use this rectangle to limit drawing to only the portion of the view that changed.
 @param zoomScale The current scale factor applied to the map content. You can use this value for configuring the stroke width of lines or other attributes that might be affected by the scale of the view’s content.
 @param context The graphics context to use for drawing the view’s content.
 @discussion The default implementation of this method does nothing. Subclasses are expected to override this method (instead of the drawRect: method) and use it to draw the contents of the view.
 
 In your drawing code, you should specify the position of any rendered content relative to the map itself and not relative to the view’s bounds or frame. In other words, compute the position and size of any overlay content using map points and map rectangles, convert those values to CGPoint and CGRect types (using the methods of this class), and then use the converted points to build paths or specify the rendering location for items.
 */
- (void)drawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale inContext:(CGContextRef)context;
/*!
 @method pointForCoordinate:
 @abstract Returns the point in the overlay view that corresponds to specified coordinate.
 @param coordinate A CLLocationCoordinate2D point on the two-dimensional map projection.
 @result The point in the receiver’s coordinate system that corresponds to the coordinate.
 */
- (CGPoint) pointForCoordinate:(CLLocationCoordinate2D) coordinate;
/*!
 @method pointForMapPoint:
 @abstract Returns the point in the overlay view that corresponds to specified point on the map.
 @param mapPoint A point on the two-dimensional map projection. If you have a coordinate value (latitude and longitude), you can use the MRMapPointForCoordinate function to convert that coordinate to a map point.
 @result The point in the receiver’s coordinate system that corresponds to the map point.
 */
- (CGPoint)pointForMapPoint:(MKMapPoint)mapPoint;
/*!
 @method rectForMapRect:
 @abstract Returns the rectangle in the overlay view that corresponds to the specified rectangle on the map.
 @param mapRect A rectangle on the two-dimensional map projection.
 @result The rectangle specified in the receiver’s coordinate system.
 */
- (CGRect)rectForMapRect:(MKMapRect)mapRect;
/*!
 @method mapPointForPoint:
 @abstract Returns the map point that corresponds to the specified point in the overlay view.
 @param point The point in the view’s coordinate system that you want to convert.
 @result The point on the two-dimensional map projection corresponding to the specified point.
 */
- (MKMapPoint)mapPointForPoint:(CGPoint)point;
/*!
 @method mapRectForRect:
 @abstract Returns the map rectangle that corresponds to the rectangle in the overlay view’s coordinate system.
 @param rect The rectangle specified in the receiver’s coordinate system.
 @result The rectangle on the two-dimensional map project that corresponds to the specified view rectangle.
 */
- (MKMapRect)mapRectForRect:(CGRect)rect;

/*!
 @method containsMapPoint:
 @abstract Determs whether the overlay contains a given mapPoint.
 @param mapPoint A point on the two-dimensional map projection. If you have a coordinate value (latitude and longitude), you can use the MRMapPointForCoordinate function to convert that coordinate to a map point.
 @result YES if overlay contains given map point,  NO otherwise
 */
- (BOOL)containsMapPoint:(MKMapPoint)mapPoint;
/*!
 @method canDrawMapRect:zoomScale:
 @abstract Returns a Boolean value indicating whether the overlay view is ready to draw its content.
 @param mapRect. The map rectangle that needs to be updated.
 @param zoomScale. The current scale factor applied to the map.
 @return value. YES if this view is ready to draw its contents or NO if it is not.
 @discussion Overlay views can override this method in situations where they may depend on the availability of other information to draw their contents. For example, an overlay view showing traffic information might want to delay drawing until it has all of the traffic data it needs. In such a case, it can return NO from this method to indicate that it is not ready.
    If you return NO from this method, your application is responsible for calling the setNeedsDisplayInMapRect:zoomScale: method when the overlay view subsequently becomes ready to draw its contents.
    The default implementation of this method returns YES.
 */
- (BOOL)canDrawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale;
/*!
 @method setNeedsDisplayInMapRect:
 @abstract. Invalidates the view in the given map rectangle at all zoom scales.
 @param mapRect. The portion of the overlay that needs to be updated. This value is specified using a map rectangle and not view coordinates. You can convert from a view rectangle to a map rectangle using the mapRectForRect: method.
 @Discussion. Marking a rectangle as invalid causes that portion of the view to be redrawn during the next update cycle. This method invalidates the overlay regardless of the current zoom scale associated with the map.
 */
- (void)setNeedsDisplayInMapRect:(MKMapRect)mapRect;
/*!
 @method  setNeedsDisplayInMapRect:zoomScale:
 @abstract Invalidates the view in the given map rectangle but only at the specified zoom scale.
 @param mapRect
    The portion of the overlay that needs to be updated. This value is specified using a map rectangle and not view coordinates. You can convert from a view rectangle to a map rectangle using the mapRectForRect: method.
 @param zoomScale
    The zoom scale for which you want to invalidate the overlay.
 @Discussion
 Marking a rectangle as invalid causes that portion of the view to be redrawn during the next update cycle. This method invalidates the overlay only when it is drawn at the specified zoom scale.
*/
- (void)setNeedsDisplayInMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale;


@end
