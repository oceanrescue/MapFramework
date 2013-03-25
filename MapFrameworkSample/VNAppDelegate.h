//
//  VNAppDelegate.h
//  MapFrameworkSample
//
//  Created by Valeriy Nikitin on 3/25/13.
//  Copyright (c) 2013 Valeriy Nikitin. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GTMapController;

@interface VNAppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) GTMapController *viewController;

@end
