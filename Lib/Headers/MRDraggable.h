//
//  MRDraggable.h
//  GeoController
//
//  Created by Nikitin Valeriy on 6/5/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

/*!
 @header MRDraggable.h
 @abstract MRDraggable object protocol definition
 */

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>
/*!
 @protocol MRDraggable 
 @abstract Draggable object protocol.
 @discussion Use this protocol for implementation of the draggable AnnotationView class.
 */

@protocol MRDraggable <NSObject>

/*!
 @property draggable
 @abstract A Boolean indicating whether the annotation view is draggable.
 @discussion Setting this property to YES makes an annotation draggable by the user. If YES, the associated annotation object must also implement the setCoordinate: method. The default value of this property is NO.
 Setting this property to YES, lets the map view know that the annotation is always draggable. In other words, you cannot conditionalize drag operations by attempting to stop an operation that has already been initiated; doing so can lead to undefined behavior. Once begun, the drag operation should always continue to completion..
 */
@property (nonatomic) BOOL draggable;

- (void) setCoordinate:(CLLocationCoordinate2D) coordinate;

@property (nonatomic, readonly) MKAnnotationViewDragState dragState;

- (void)setDragState:(MKAnnotationViewDragState)dragState animated:(BOOL)animated;

@end
