//
//  GCZoneStyle.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header GCZoneStyle.h
 @abstract Zone style protocol definition
 */

#import <Foundation/Foundation.h>

/*!
 @protocol GCZoneStyle
 @abstract Zone style protocol.
 @discussion Use this protocol for implementation of the class defining zone style. As an example of the particular zone style protocol implementation see GCDefaultZoneStyle class. Style is used for zone rendering, it defines line width, color and dash pattern, fill color for each zone state (default/highlighted/selected).
 */
@protocol GCZoneStyle <NSObject>

/*!
 @property defaultColor
 @abstract Color of zone in default state.
 */
@property (nonatomic, retain, readonly) UIColor *defaultColor;
/*!
 @property selectedColor
 @abstract Color of zone in selected state.
 */
@property (nonatomic, retain, readonly) UIColor *selectedColor;
/*!
 @property highlightedColor
 @abstract Color of zone in highlighted state.
 */
@property (nonatomic, retain, readonly) UIColor *highlightedColor;
/*!
 @property lineWidth
 @abstract Zone line width.
 */
@property (readonly) CGFloat lineWidth;
/*!
 @property strokeAlpha
 @abstract Zone line color transparency.
 */
@property (readonly) CGFloat strokeAlpha;
/*!
 @property fillAlpha
 @abstract Zone fill color transparency for normal state.
 */
@property (readonly) CGFloat normalFillAlpha;
/*!
 @property fillAlpha
 @abstract Zone fill color transparency for selected state.
 */
@property (readonly) CGFloat selectedFillAlpha;
/*!
 @property fillAlpha
 @abstract Zone fill color transparency for highlited state.
 */
@property (readonly) CGFloat highlitedFillAlpha;

/*!
 @property lineDashPattern
 @abstract The dash pattern applied to the zone’s path when stroked.
 @discussion The dash pattern is specified as an array of floats that specify the lengths of the painted segments and unpainted segments, respectively, of the dash pattern.
 
 For example, passing an array with the values [2,3] sets a dash pattern that alternates between a 2-user-space-unit-long painted segment and a 3-user-space-unit-long unpainted segment. Passing the values [1,3,4,2] sets the pattern to a 1-unit painted segment, a 3-unit unpainted segment, a 4-unit painted segment, and a 2-unit unpainted segment.
 
 Default is NULL, a solid line.
 */
@property (readonly) float *lineDashPattern;
/*!
 @property lineDashPatternCount
 @abstract lineDashPattern array length.
 */
@property (readonly) int lineDashPatternCount;


@end
