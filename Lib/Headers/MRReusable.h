//
//  MRReusableView.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

/*!
 @header MRReusable.h
 @abstract Reusable object protocol definition
 */

#import <UIKit/UIKit.h>

/*!
 @protocol MRReusable
 @abstract Reusable object protocol.
 @discussion Use this protocol for implementation of the reusable class.
 */
@protocol MRReusable <NSObject>

/*!
 @property reuseIdentifier
 @abstract Reuse identifier.
 */
@property (nonatomic, copy) NSString *reuseIdentifier;

/*!
 @method prepareForReuse:
 @abstract Prepares object for reuse.
 @discussion This method is called by reusable objects container every time an object is going to be re-used. 
 */
- (void)prepareForReuse;

@end
