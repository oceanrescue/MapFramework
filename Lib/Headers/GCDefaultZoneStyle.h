//
//  GCDefaultZoneStyle.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCDefaultZoneStyle.h
 @abstract Zone style class definition.
 */

#import <UIKit/UIKit.h>
#import "GCZoneStyle.h"

/*!
 @class GCDefaultZoneStyle
 @abstract Zone style class interface.
 @discussion Provides concrete GCZoneStyle protocol implementation. 
 */
@interface GCDefaultZoneStyle : NSObject <GCZoneStyle> {

    float *pattern;
    int count;
}
//FIXME: delete part of below - inherirs from GCZoneStyle
/*!
 @property defaultColor
 @abstract Color of zone in default state.
 */
@property (nonatomic, retain) UIColor *defaultColor;
/*!
 @property selectedColor
 @abstract Color of zone in selected state.
 */
@property (nonatomic, retain) UIColor *selectedColor;
/*!
 @property highlightedColor
 @abstract Color of zone in highlighted state.
 */
@property (nonatomic, retain) UIColor *highlightedColor;
/*!
 @property lineWidth
 @abstract Zone line width.
 */
@property (nonatomic) CGFloat lineWidth;
/*!
 @property strokeAlpha
 @abstract Zone line color transparency.
 */
@property (nonatomic) CGFloat strokeAlpha;
/*!
 @property fillAlpha
 @abstract Zone fill color transparency.
 */
@property (nonatomic) CGFloat fillAlpha;

/*!
 @method setLineDash:count:
 @abstract Sets line dash pattern array of given length.
 */
- (void)setLineDash:(float *)pattern count:(NSInteger)count;

/*!
 @method zoneStyle
 @abstract Creates and returns autoreleased zone style object.
 */
+ (GCDefaultZoneStyle *)zoneStyle;

@end
