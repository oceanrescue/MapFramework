//
//  GCMapAnnotationProtocol.h
//  GeoController
//
//  Created by Valeriy Nikitin on 11/29/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MRReusable, MKAnnotation;
@class MRAnnotationView;
@protocol GCMapAnnotationProtocol <NSObject>

/*!
 @property annotations
 @abstract The complete list of annotations associated with the receiver. (read-only)
 @discussion The objects in this array must adopt the MKAnnotation protocol. If no annotations are associated with the map view, the value of this property is nil.
 */
@property (nonatomic, readonly) NSArray *annotations;
/*!
 @property visibleAnnotations
 @abstract The complete list of visible annotations for current map scale and region. (read-only)
 @discussion The objects in this array must adopt the MKAnnotation protocol. If no annotations are associated with the map view, the value of this property is nil.
 */
@property (nonatomic, readonly) NSArray *visibleAnnotations;
/*!
 @method addAnnotation:
 @abstract Adds the specified annotation to the map view.
 @param annotation The annotation object to add to the receiver. This object must conform to the MKAnnotation protocol. The map view retains the specified object.
 */
- (void)addAnnotation:(id <MKAnnotation>)annotation;
/*!
 @method addAnnotations:
 @abstract Adds an array of annotation objects to the map view.
 @param annotations An array of annotation objects. Each object in the array must conform to the MKAnnotation protocol. The map view retains the individual annotation objects.
 */
- (void)addAnnotations:(NSArray *)annotations;

/*!
 @method removeAnnotation:
 @abstract Removes the specified annotation object from the map view.
 @param annotation The annotation object to remove. This object must conform to the MKAnnotation protocol.
 @discussion Removing an annotation object disassociates it from the map view entirely, preventing it from being displayed on the map. Thus, you would typically call this method only when you want to hide or delete a given annotation.
 */
- (void)removeAnnotation:(id <MKAnnotation>)annotation;
/*!
 @method removeAnnotations:
 @abstract Removes an array of annotation objects from the map view.
 @param annotations The array of annotations to remove. Objects in the array must conform to the MKAnnotation protocol.
 @discussion Removing annotation objects disassociates them from the map view entirely, preventing them from being displayed on the map. Thus, you would typically call this method only when you want to hide or delete the specified annotations.
 */
- (void)removeAnnotations:(NSArray *)annotations;
/*!
 @method removeAllAnnotations
 @abstract Removes all annotation objects from the map view.
 */
- (void)removeAllAnnotations;
/*!
 @method dequeueReusableObjectWithIdentifier
 @abstract Returns a reusable object located by its identifier.
 @param identifier A string identifying the object view to be reused. This string is the same one you specify when initializing the object view using the initWith.....:reuseIdentifier: method.
 @return An object with the specified identifier, or nil if no such object exists in the reuse queue.
 */
- (id)dequeueReusableObjectViewWithIdentifier:(id)identifier;
- (void)queueReusableItem:(id <MRReusable>)item;

/*!
 @method viewForAnnotation:
 @abstract Returns the annotation view associated with the specified annotation object, if any.
 @param annotation The annotation object whose view you want.
 @return The annotation view or nil if the view has not yet been created. This method may also return nil if the annotation is not in the visible map region and therefore does not have an associated annotation view.
 */
- (MRAnnotationView *)viewForAnnotation:(id <MKAnnotation>)annotation;

/*!
 @property selectedAnnotations
 @abstract The annotations that are currently selected.
 @discussion Currently not used.
 */
@property (nonatomic, readonly) NSArray *selectedAnnotations;
/*!
 @method selectAnnotation:animated:
 @abstract Selects the specified annotation.
 @param annotation The annotation object to select.
 @param animated Currently not used.
 @discussion Currently not used.
 */
- (void)selectAnnotation:(id <MKAnnotation>)annotation animated:(BOOL)animated;
/*!
 @method deselectAnnotation:animated:
 @abstract Deselects the specified annotation.
 @param annotation The annotation object to deselect.
 @param animated Currently not used.
 @discussion Currently not used.
 */
- (void)deselectAnnotation:(id <MKAnnotation>)annotation animated:(BOOL)animated;


@end
