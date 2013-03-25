//
//  GCZone.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCZone.h
 @abstract Zone class definition.
 */

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@protocol GCZoneStyle;

/*!
 @class GCZone
 @abstract Zone class interface.
 @discussion Model object, overlay, used for zone description. 
 */
@interface GCZone : NSObject <MKOverlay> {
    @private
    NSString *title;
    NSString *sybtitle;
    CLLocationCoordinate2D coordinate;
    MKMapRect boundingMapRect;

    NSNumber *ID;
    NSArray *nodes;
    NSArray *content;
    NSInteger level;
    BOOL selected;
    BOOL fixed;
    
    NSObject <GCZoneStyle> *style;
    UIBezierPath *path;
}

/*!
 @property title
 @abstract Zone title.
 */
@property (nonatomic, copy) NSString *title;
/*!
 @property subtitle
 @abstract Zone subtitle  (currently not used).
 */
@property (nonatomic, copy) NSString *subtitle;
/*!
 @property coordinate
 @abstract Zone bounding box center location coordinate.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;
/*!
 @property boundingMapRect
 @abstract Zone bounding rect.
 */
@property (nonatomic, readonly) MKMapRect boundingMapRect;

/*!
 @property ID
 @abstract Zone identificator.
 */
@property (nonatomic, retain) NSNumber *ID;
/*!
 @property nodes
 @abstract Zone nodes coordinate array.
 */
@property (nonatomic, retain) NSArray *nodes;
/*!
 @property content
 @abstract Zone TGI items array.
 */
@property (nonatomic, retain) NSArray *content;
/*!
 @property level
 @abstract Zone level.
 */
@property (nonatomic) NSInteger level;
/*!
 @property selected
 @abstract YES if zone selected and NO otherwise.
 */
@property (nonatomic) BOOL selected;   
/*!
 @property style
 @abstract Zone style.
 */
@property (nonatomic, retain) NSObject <GCZoneStyle> *style;
/*!
 @property fixed
 @abstract YES if zone crosses 180-th meridian and NO otherwise.
 */
@property (nonatomic) BOOL fixed;

/*!
 @property path
 @abstract Path in map points.
 */
@property (nonatomic, retain, readonly) UIBezierPath *path;

/*!
 @method emptyZone
 @abstract Creates and returns autoreleased zone object filled with default values.
 */
+ (id)emptyZone;

@end
