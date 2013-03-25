//
//  GCWayPoint.h
//  GeoController
//
//  Created by Nikitin Valeriy on 6/3/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MRDraggable.h"
#import "GCWaypointAnnotation.h"
#import "MRClusterable.h"

@class GCWayPoint, GCRoute;
@protocol GCWaypointAnnotation;

@protocol GCWayPointDelegate <NSObject>
- (void) updateWayPointPosition:(GCWayPoint *)aWayPoint;
@end

@interface GCWayPoint : NSObject <MKAnnotation, MKReverseGeocoderDelegate, GCWaypointAnnotation, MRClusterable> {
    CLLocation *_coordinateCL;
    NSDictionary *_addressDictionary;
    NSString *_title;
    NSInteger _index;
}
@property (nonatomic) VNAnnotationType type;
/*!
 @property route
 @abstract route is the parent object of waypoint
 */
@property (nonatomic, retain) GCRoute *route;

/*!
 @property delegate
 @abstract the delegate object which is responsible for route updating
 */
@property (nonatomic, assign) id <GCWayPointDelegate> delegate;
/*!
 @property index
 @abstract index of wayPoint in route
 */
@property (nonatomic) NSInteger index;

/*!
 @property coordinate
 @abstract Coordinate CLLocation define coordinate of waypoint
 */
@property (nonatomic, retain) CLLocation *coordinateCL;

/*!
 @property addressDictionary
 @abstract addressDictionary contains place specifics of waypoint. Uses CLGeocoder to define place address
 */
@property (nonatomic, retain) NSDictionary *addressDictionary;
/*!
 @property title
 @abstract title is NSString object with title (name) of place for waypoint with particular coordinates. Uses CLGeocoder to define place name. 
 */
@property (nonatomic, copy) NSString *title;

/*!
 @property distance
 @abstract distance is CLLocationDistance from previouse waypoint. if particular waypoint starts route than distance is 0. 
 */
@property (nonatomic) CLLocationDistance distance;

/*!
 @property course
 @abstract course is CLLocationDirection from previouse waypoint. if particular waypoint starts route than course is -1000. 
 */
@property (nonatomic) CLLocationDirection course;


- (id) initWithLocation:(CLLocation *) coordinate;

- (void) changeCoordinate:(CLLocation *)newCoordinate;
@end
