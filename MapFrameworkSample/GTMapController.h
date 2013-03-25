//
//  GTMapController.h
//  GeoController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GeoController.h"

@interface GTMapController : UIViewController <GCMapControllerDataSource, GCMapControllerDelegate> {

    IBOutlet GCMapController *mapController;
    IBOutlet UITextView *infoTextView;
    IBOutlet UIButton *updateButton;    
}

-(IBAction)handelUpdateButton:(id)sender;

- (IBAction)zoomOutButtonClicked:(id)sender;
- (IBAction)zoomInButtonClicked:(id)sender;

@end
