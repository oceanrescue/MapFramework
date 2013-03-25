//
//  MROverlayViewNonScalable.h
//  GeoController
//
//  Created by submarine on 9/24/12.
//  Copyright (c) 2012 Mistral, LLC. All rights reserved.
//


#import "MROverlayView.h"

/*!
 @class MROverlayViewNonScalable
 @abstract Map non scalable overlay view class.
 @discussion The MROverlayViewNonScalable class defines the basic behavior associated with all NONSCALABLE overlay views. An overlay view provides the visual representation of an overlay object—that is, an object that conforms to the MKOverlay protocol. This class defines the drawing infrastructure used by the map view and DOES do all actual drawing. Subclasses are expected to override the drawMapRect:zoomScale:inContext: method in order to draw the contents of the overlay view.
    
 */
@interface MROverlayViewNonScalable : MROverlayView {

}

@end
