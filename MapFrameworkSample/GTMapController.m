//
//  GTMapController.m
//  mapViewController
//
//  Created on 10/9/11.
//  Copyright 2011 Mistral, LLC. All rights reserved.
//

#import "GTMapController.h"
#import "GCMapSourceController.h"
#import "MRUserLocation.h"
#import "MRAnnotationView.h"

/*
 *  GTAnnotation and GTZoneStyle
 */
@interface GTAnnotation : NSObject <MKAnnotation>
@end
@interface GTAnnotation ()
@property (nonatomic, readwrite) CLLocationCoordinate2D coordinate;
@end
@implementation GTAnnotation
-(NSString *)title {
    return @"Custom Callout";
}
-(NSString*)subtitle {
    return @"Custom AnnotationView";
}
-(NSString*)description {
    return [NSString stringWithFormat:@"<%@>, coordinate %@", self.title, [NSValue valueWithMKCoordinate:self.coordinate]];
}

@end

#pragma mark - GTZoneStyle
@interface GTZoneStyle : NSObject <GCZoneStyle>
@property (nonatomic, retain, readwrite) UIColor *defaultColor;
@property (nonatomic, retain, readwrite) UIColor *selectedColor;
@property (nonatomic, retain, readwrite) UIColor *highlightedColor;
@property (readwrite) CGFloat lineWidth;
@property (readwrite) CGFloat strokeAlpha;
@property (readwrite) CGFloat normalFillAlpha;
@property (readwrite) CGFloat selectedFillAlpha;
@property (readwrite) CGFloat highlitedFillAlpha;
@property (readwrite) float *lineDashPattern;
@property (readwrite) int lineDashPatternCount;
+(GTZoneStyle*)greyStyle;
@end
@implementation GTZoneStyle
@synthesize defaultColor, selectedColor, highlightedColor;
@synthesize lineWidth, strokeAlpha, normalFillAlpha, selectedFillAlpha, highlitedFillAlpha;
@synthesize lineDashPattern, lineDashPatternCount;

+(GTZoneStyle*) greyStyle {
    GTZoneStyle *style = [[GTZoneStyle alloc] init];
    if (style != nil) {
        [style setDefaultColor:[UIColor grayColor]];
        [style setSelectedColor:[UIColor darkGrayColor]];
        [style setHighlightedColor:[UIColor lightGrayColor]];
        [style setLineWidth:3.0];
        [style setStrokeAlpha:1.0];
        [style setNormalFillAlpha:0.2];
        [style setSelectedFillAlpha:0.4];
        [style setHighlitedFillAlpha:0.4];
    }
    return style;
}
+(GTZoneStyle*) yellowStyle {
    GTZoneStyle *style = [[GTZoneStyle alloc] init];
    if (style != nil) {
        [style setDefaultColor:[UIColor orangeColor]];
        [style setSelectedColor:[UIColor yellowColor]];
        [style setHighlightedColor:[UIColor yellowColor]];
        [style setLineWidth:3.0];
        [style setStrokeAlpha:1.0];
        [style setNormalFillAlpha:0.2];
        [style setSelectedFillAlpha:0.4];
        [style setHighlitedFillAlpha:0.4];
    }
    return style;
}
@end
/*
 *  GTMapController
 */
@interface GTMapController ()
@property (nonatomic, retain) NSArray *zones;
@end

@implementation GTMapController
@synthesize zones = _zones;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        mapController = [GCMapController sharedMapController];
        if (!mapController) {
            mapController = [GCMapController createGeoControllerWithDefaultMap];
            [GCMapController setSharedController:mapController];
        }
        mapController.delegate = self;
        mapController.dataSource = self;
    }
    return self;
}
#pragma mark - Memory management
- (void)dealloc
{
    [GCMapController destroySharedMapController];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    mapController.view.frame = CGRectInset(self.view.bounds, 5, 5);
    mapController.view.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:mapController.view];
    [self.view sendSubviewToBack:mapController.view];
    [self performSelector:@selector(setupStartPosition)];
    [self performSelector:@selector(setupAnnotation)];
    [self performSelector:@selector(setupZones)];
}
-(void)setupAnnotation {
    if (mapController == nil) return;
    GTAnnotation *annotation = [[GTAnnotation alloc] init];
    annotation.coordinate = CLLocationCoordinate2DMake(26.4, -80.3);
    [mapController addAnnotation:annotation];
}
-(void)setupZones {
    GCZone *zone1 = [GCZone emptyZone];
    zone1.ID = @1;
    zone1.nodes = @[[[CLLocation alloc] initWithLatitude:26.8080 longitude:-79.9803],
                    [[CLLocation alloc] initWithLatitude:26.8080 longitude:-79.1803],
                    [[CLLocation alloc] initWithLatitude:26.0900 longitude:-79.0200],
                    [[CLLocation alloc] initWithLatitude:26.1900 longitude:-79.9803],
                    [[CLLocation alloc] initWithLatitude:26.8080 longitude:-79.9803]];
    GCZone *zone2 = [GCZone emptyZone];
    zone2.ID = @2;
    zone2.nodes = @[[[CLLocation alloc] initWithLatitude:26.1900 longitude:-79.9803],
                    [[CLLocation alloc] initWithLatitude:26.0900 longitude:-79.0200],
                    [[CLLocation alloc] initWithLatitude:25.3972 longitude:-79.0203],
                    [[CLLocation alloc] initWithLatitude:25.3500 longitude:-79.3303],
                    [[CLLocation alloc] initWithLatitude:26.1900 longitude:-79.9803],
                    [[CLLocation alloc] initWithLatitude:26.1900 longitude:-79.9803]];
    self.zones = @[zone1, zone2];
    [mapController reloadZones];
}
-(void)setupStartPosition {
    mapController.showsUserLocation = YES;
    mapController.zoomLevel = 9;
    [mapController setCenterCoordinate:CLLocationCoordinate2DMake(26.2, -79.6)];
    [mapController updateUserLocationWithCoordinate:CLLocationCoordinate2DMake(26.1, -80.2)];

}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [mapController updateUserLocation:[[CLLocation alloc] initWithLatitude:26.1 longitude:-80.2]];
}

- (void)viewDidUnload
{
    infoTextView = nil;

    mapController = nil;
    [super viewDidUnload];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
	return YES;
}

#pragma mark - GCMapControllerDataSource
-(NSArray*)zonesForMapController:(GCMapController *)mapViewController {
    if (mapViewController == mapController) {
        return self.zones;
    }
    return nil;
}

- (NSInteger)mapController:(GCMapController *)mapController levelForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index
{
    return [zoneID integerValue];
}

- (BOOL)mapController:(GCMapController *)mapController isSelectedZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index;
{
    return NO;
}

- (NSArray *)mapController:(GCMapController *)mapController contentForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index;
{
    if (index == 0) {
        UIImage *image = [UIImage imageNamed:@"bright_sun_icon.png"];
        NSArray *content = [NSArray arrayWithObjects:image, @"Sunny  :)", @"023mb", @"+1mb/h", @"88°F", @"---",
                            @"No wind", @"123s", image, @"456s", nil];
        
        return content;
    }
    return nil;
}

- (id <GCZoneStyle>)mapController:(GCMapController *)mapController styleForZoneWithID:(NSNumber *)zoneID atIndex:(NSInteger)index
{
    if (index == 0) {
        return [GTZoneStyle yellowStyle];
    }
    return [GTZoneStyle greyStyle];
}
- (MROverlayView *)mapController:(GCMapController *)mapController viewForOverlay:(id <MKOverlay>)anOverlay {
    return nil;
}

-(MRAnnotationView*)mapController:(GCMapController *)mapController viewForAnnotation:(id<MKAnnotation>)annotation {
    MRAnnotationView *annotationView = nil;
    if ([annotation isKindOfClass:[MRUserLocation class]] == NO) {
        annotationView = (MRAnnotationView*) [[MKAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"userAnnotationView"];
        annotationView.frame = CGRectMake(0, 0, 80, 80);
        annotationView = [[MRAnnotationView alloc] initWithAnnotation:annotation reuseIdentifier:@"generalAnnotationView"];
        UIImage *image = [UIImage imageNamed:@"Red_Map_Pin.png"];
        UIImage *icon = [UIImage imageNamed:@"bright_sun_icon.png"];
        [annotationView setImage:icon];
        annotationView.leftCalloutAccessoryView = [[UIImageView alloc] initWithImage:image];
    }
    [annotationView performSelector:@selector(showCalloutAnimated:) withObject:nil afterDelay:2.];
    return annotationView;
}


#pragma mark - GCmapViewControllerDelegate

- (void)mapController:(GCMapController *)mapController didSelectZoneWithId:(NSNumber *)zoneId atIndex:(NSInteger)index
{
    NSLog(@"Select ID: %@, INDEX: %d", zoneId, index);
}

- (void)mapController:(GCMapController *)mapController didDeselectZoneWithId:(NSNumber *)zoneId atIndex:(NSInteger)index
{
    NSLog(@"Deselect ID: %@, INDEX: %d", zoneId, index);
}


- (void)handelUpdateButton:(id)sender{   
}

- (IBAction)zoomOutButtonClicked:(id)sender 
{
    [mapController setZoomLevel:mapController.zoomLevel - 1];
}

- (IBAction)zoomInButtonClicked:(id)sender 
{
    [mapController setZoomLevel:mapController.zoomLevel + 1];
}

@end
