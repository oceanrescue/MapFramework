//
//  GCMapUserLocationProtocol.h
//  GeoController
//
//  Created by Valeriy Nikitin on 11/29/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol MKAnnotation;

/*
 *  General user location map protocol
 */
@protocol GCMapUserLocationProtocol <NSObject>
/*!
 @property showsUserLocation
 @abstract A Boolean value indicating whether the map may display the user location.
 @discussion This property does not indicate whether the user’s position is actually visible on the map, only whether the map view is allowed to display it. To determine whether the user’s position is visible, use the userLocationVisible property. The default value of this property is NO.
 */
@property (nonatomic) BOOL showsUserLocation;
/*!
 @property userLocation
 @abstract The annotation object representing the user’s current location. (read-only)
 */
@property (nonatomic, readonly) id <MKAnnotation> userLocation;
/*!
 @property userLocationVisible
 @abstract A Boolean value indicating whether the user current location is visible in the map view. (read-only)
 */
@property (nonatomic, readonly) BOOL isUserLocationVisible;

/*!
 @method updateUserLocation:
 @abstract Updates current user location.
 @param userLocation New user location.
 @discussion Map view does not has build-in module for user location tracking. This is the method for altering the user location position on the map.
 */
- (void)updateUserLocation:(CLLocation *)userLocation;
/*!
 @method updateUserLocationWithCoordinate:
 @abstract Updates current user location.
 @param userLocation New user location coordinate.
 @discussion Map view does not has build-in module for user location tracking. This is the method for altering the user location position on the map.
 */
- (void)updateUserLocationWithCoordinate:(CLLocationCoordinate2D)coordinate;

@end
