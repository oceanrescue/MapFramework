//
//  MRAnnotationView.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MRAnnotationView.h
 @abstract Map annotation view class definition
 */

#import <Foundation/Foundation.h>
#import "MRReusable.h"
#import "MRSelectable.h"
#import "MRDraggable.h"
#import "MRClusterable.h"
#import "MRAnnotationCalloutView.h"

@protocol MKAnnotation;
@class MRMapView, MRAnnotationCalloutView;
/*!
 @protocol MRAnnotationView
 @abstract Map annotation view class.
 @discussion The MKAnnotationView class is responsible for presenting annotations visually in a map view. Annotation views are loosely coupled to a corresponding annotation object, which is an object that corresponds to the MKAnnotation protocol.
 */
@interface MRAnnotationView : UIView <MRReusable, MRSelectable, MRDraggable, MRCalloutDelegate> {

    @private
    VNAnnotationType _type;
    NSString *_reuseIdentifier;
    
    id <MKAnnotation> _annotation;
    
    BOOL highlighted;
    BOOL selected;
    
    BOOL isMoving;
    CGPoint _oldCenter;
    MRAnnotationCalloutView *_calloutView;
    MRMapView *mapView;
}

/*!
 @method initWithAnnotation:reuseIdentifier:
 @abstract Initializes and returns a new annotation view.
 @param annotation The annotation object to associate with the new view.
 @param reuseIdentifier FOR FUTURE: If you plan to reuse the annotation view for similar types of annotations, pass a string to identify it. Although you can pass nil if you do not intend to reuse the view, reusing annotation views is generally recommended.
 @result The initialized annotation view or nil if there was a problem initializing the object.
 @discussion FOR FUTURE: The reuse identifier provides a way for you to improve performance by recycling annotation views as they are scrolled on and off of the map. As views are no longer needed, they are moved to a reuse queue by the map view. When a new annotation becomes visible, your application can request a view for that annotation by passing the appropriate reuse identifier string to the dequeueReusableAnnotationViewWithIdentifier: method of MRMapView. 
 */
- (id)initWithAnnotation:(id <MKAnnotation>)annotation reuseIdentifier:(NSString *)reuseIdentifier;

- (BOOL)containsMapPoint:(MKMapPoint)mapPoint;

- (MRAnnotationCalloutView *) calloutView;

@property (nonatomic) VNAnnotationType type;


@property (nonatomic, assign) MRMapView *mapView;

/*!
 @property annotation
 @abstract The annotation object currently associated with the view.
 */
@property (nonatomic, retain) id <MKAnnotation> annotation;

/*!
 @property image
 @abstract The image to be displayed by the annotation view.
 @discussion Assigning a new image to this property also changes the size of the view’s frame so that it matches the width and height of the new image. The position of the view’s frame does not change. 
 */
@property (nonatomic, retain, readonly) UIImage *image;

- (void) setImage:(UIImage *)image;

/*!
 @property imageView
 @abstract The imageView to be displayed by the annotation view.
 @discussion Use imageView property to manage imageView frame and center.
 */
@property (nonatomic, retain, readonly) UIImageView *imageView;

/*!
 @property canShowCallout
 @abstract A Boolean value indicating whether the annotation view is able to display extra information in a callout bubble.
 @discussion If YES, a special callout bubble is shown when the user taps a selected annotation view. The callout uses the text and images from the associated annotation object. (If the annotation’s title method returns an empty string, the annotation view is treated as if its enabled property is set to NO.) The callout also displays any custom callout views stored in the properties.
 */
@property (nonatomic) BOOL canShowCallout;
/*!
 @property leftCalloutAccessoryView
 @abstract The view to display on the left side of the standard callout bubble.
 @discussion The default value of this property is nil. The left callout view is typically used to display information about the annotation or to link to custom information provided by your application. The height of your view should be 32 pixels or less.
 If the view you specify is also a descendant of the UIControl class, you can use the map view’s delegate to receive notifications when your control is tapped. If it does not descend from UIControl, your view is responsible for handling any touch events within its bounds.
 */
@property (retain, nonatomic) UIView *leftCalloutAccessoryView;
/*!
 @property rightCalloutAccessoryView
 @abstract The view to display on the right side of the standard callout bubble.
 @discussion This property is set to nil by default. The right callout view is typically used to link to more detailed information about the annotation. The height of your view should be 32 pixels or less. A common view to specify for this property is UIButton object whose type is set to UIButtonTypeDetailDisclosure.
 If the view you specify is also a descendant of the UIControl class, you can use the map view’s delegate to receive notifications when your control is tapped. If it does not descend from UIControl, your view is responsible for handling any touch events within its bounds.
 */
@property (retain, nonatomic) UIView *rightCalloutAccessoryView;

/*!
 @property centerOffset
 @abstract The offset (in pixels) at which to display the view.
 @discussion By default, the center point of an annotation view is placed at the coordinate point of the associated annotation. You can use this property to reposition the annotation view as needed. This x and y offset values are measured in pixels. Positive offset values move the annotation view down and to the right, while negative values move it up and to the left.
 */

@property (nonatomic) CGPoint centerOffset;
/*!
 @property (nonatomic) CGPoint calloutOffset
 @discussion
 This property determines the additional distance by which to move the callout bubble. When this property is set to (0, 0), the anchor point of the callout bubble is placed on the top-center point of the annotation view’s frame. Specifying positive offset values moves the callout bubble down and to the right, while specifying negative values moves it up and to the left.
 */
@property (nonatomic) CGPoint calloutOffset;

- (void) highlightAnnotationViewAnimated:(BOOL)animated;
- (void) deHighlightAnnotationViewAnimated:(BOOL)animated;
- (void) checkAccessoriesForTouchAtPoint:(MKMapPoint)mapPoint;

//    to be overriden by subclass
- (void) annotationViewWasSelected;
- (void) annotationViewWasDeselected;
@end
