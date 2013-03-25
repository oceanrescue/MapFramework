//
//  MRCallout.h
//  GeoController
//
//  Created by submarine on 9/12/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

enum {
    kCalloutTypeCustom              = 1, //just UIView
    kCalloutTypeSystemStandart      = 2, //analogue system callout buble
};
typedef NSUInteger MRCalloutType;



#import "MRReusable.h"

@class MRAnnotationView, MRMapView, MRMapTileView;
@protocol MRReusable, MRCallout;

@protocol MRCalloutDelegate <NSObject>
- (UIView *) contentViewForCallout:(id <MRCallout>)aCallout;
@end

@protocol MRCallout <MRReusable>
- (id) initWithAnnotationView:(MRAnnotationView *)anAnnotationView reuseIdentifier:(NSString *)aReuseIdentifier;
@property (nonatomic, assign) __unsafe_unretained id <MRCalloutDelegate> calloutDelegate;
@property (nonatomic, retain, readonly) MRAnnotationView *annotationView;
@property (nonatomic) MRCalloutType type;
@property (nonatomic, assign, readonly) MRMapView *mapView;
@property (nonatomic, retain, readonly) UIView *contentView;
@property (nonatomic) CGPoint centerOffset;

- (void) showCalloutAnimated:(BOOL) animated;
- (void) destroyCalloutAnimated:(BOOL) animated;
- (void) updateCallout;

- (BOOL)containsMapPoint:(MKMapPoint)mapPoint;
- (void)checkAccessoriesForTouchAtPoint:(MKMapPoint)mapPoint;

- (void)setAnnotationViewAndAdjustMap:(MRAnnotationView *)anAannotationView;

@end
