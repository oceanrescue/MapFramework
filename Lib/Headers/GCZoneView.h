//
//  GCZoneView.h
//  GeoController
//
//  Created on 11/14/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCZoneView.h
 @abstract Zone view class definition.
 */

#import "MROverlayViewNonScalable.h"

@class GCZone;
@class GCZoneContentView;
@protocol GCZoneStyle;

/*!
 @class GCZoneView
 @abstract Zone view class interface.
 @discussion Zone view is overlay view. Use zone view for displaying zone described by zone overlay.
 */
@interface GCZoneView : MROverlayViewNonScalable {
    @private
    GCZoneContentView *contentView;
    UIBezierPath *path;
    float lastZoomScale;
}

/*!
 @property zone
 @abstract Zone overlay.
 */
@property (nonatomic, readonly) GCZone *zone;
/*!
 @property style
 @abstract Zone style defined in the overlay.
 */
@property (nonatomic, readonly) id <GCZoneStyle> style;

/*!
 @property ID
 @abstract Zone identificator, defined in the overlay.
 */
@property (nonatomic, readonly) NSNumber *ID;
/*!
 @property title
 @abstract Zone title, defined in the overlay.
 */
@property (nonatomic, readonly) NSString *title;
/*!
 @property level
 @abstract Zone level, defined in the overay.
 */
@property (nonatomic, readonly) NSInteger level;

/*!
 @property contentView
 @abstract Zone content view, used for zone TGI displaying.
 */
@property (nonatomic, retain, readonly) GCZoneContentView *contentView;

/*!
 @method initWithZone:
 @abstract Initializes zone view with a given zone.
 @param zone zone overlay.
 */
- (id)initWithZone:(GCZone *)zone;

@end
