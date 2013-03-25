//
//  MRSelectable.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MRReusable.h
 @abstract Selectable object protocol definition
 */

#import <Foundation/Foundation.h>

/*!
 @protocol MRSelectable
 @abstract Selectable object protocol.
 @discussion Use this protocol for implementation of the selectable class.
 */
@protocol MRSelectable <NSObject>

/*!
 @property highlighted
 @abstract YES if object is highlighted, NO otherwise.
 */
@property (nonatomic) BOOL highlighted;
/*!
 @property selected
 @abstract YES if object is selected, NO otherwise.
 */
@property (nonatomic) BOOL selected;
/*!
 @property updated
 @abstract YES if object updates it's own geometry and needs to display updated overlay, NO otherwise.
 */
@property (nonatomic) BOOL updated;

@optional
/*!
 *  IN GENERAL - USE OBSERVER FOR CHANGING PROPERTIES ABOVE
 *  lazy methods below
 */
//- (void) showCalloutAnimated:(BOOL)animated;
//- (void) hideCalloutAnimated:(BOOL)animated ;
//- (void) highlight ;
//- (void) deHighlight;
@end
