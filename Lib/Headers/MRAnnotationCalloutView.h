//
//  MRAnnotationCalloutView.h
//  GeoController
//
//  Created by submarine on 9/11/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//



#import <UIKit/UIKit.h>
#import "MRCallout.h"
@class MRAnnotationView;

@interface MRAnnotationCalloutView : UIView <MRCallout> {
    MRAnnotationView *_parentAnnotationView;
	CGRect _endFrame;
	UIView *_contentView;
	CGFloat _yShadowOffset;
	CGPoint _offsetFromParent;
	CGFloat _contentHeight;
    UIButton *_accessory;
}


@end
