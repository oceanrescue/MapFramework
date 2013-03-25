//
//  GCWaypointAnnotation.h
//  GeoController
//
//  Created by Nikitin Valeriy on 6/6/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @protocol GCWaypointAnnotation
 @abstract Object that conform GCWaypointAnnotation protocol provide methods to get coordinates, distance and course information (usualy from waypoints) .
 @discussion Object that conform GCWaypointAnnotation protocol provide methods to get coordinates, distance and course information (usualy from waypoints). There are four parameters could recieve:
     Latitude - string from latitude
     Longitude - string from longitude
     Distance - string from distance
     Course - string from course
 */
@protocol GCWaypointAnnotation <NSObject> 
- (NSString *) anLatitudeString;
- (NSString *) anLongitudeString;
- (NSString *) anDistanceString;
- (NSString *) anCourseString;
- (NSString *) anGeoNameString;
@end
