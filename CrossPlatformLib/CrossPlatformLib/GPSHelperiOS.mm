//
//  GPSHelperiOS.cpp
//  CrossPlatformExample
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "GPSHelper.h"
#include "GPSHelperiOS.h"
#include "XPController.h"
#include <Foundation/Foundation.h>
#include <CoreLocation/CoreLocation.h>
#include "XPLocation.h"

// Objective-C delegate class to hand to CLLocationManager
@implementation MyLocationDelegate

// This method is called by CLLocationManager when it receives a location update
- (void)locationManager:(CLLocationManager *)manager didUpdateToLocation:(CLLocation *)newLocation fromLocation:(CLLocation *)oldLocation
{
    // Create C++ Location struct and populate it with the GPS data point
    XPLocation nextLoc;
    
    nextLoc.latitude = newLocation.coordinate.latitude;
    nextLoc.longitude = newLocation.coordinate.longitude;
    nextLoc.altitude = newLocation.altitude;
    nextLoc.heading = newLocation.course;
    nextLoc.speed = newLocation.speed;
    
    // Call the C++ GPSDelegate
    self.controller->locationUpdated(nextLoc);
}

@end

GPSHelperiOS::GPSHelperiOS(XPController *controller) : GPSHelper(controller)
{
    // Build new location manager
    _locationManager = [[CLLocationManager alloc] init];
    _locationManager.desiredAccuracy = kCLLocationAccuracyBest;
    
    // Assign Objective-C delegate to it
    _locationDelegate = [[MyLocationDelegate alloc] init];
    _locationManager.delegate = _locationDelegate;
}

GPSHelperiOS::~GPSHelperiOS(void)
{
    // We don't need to delete anything here, ARC will take care of Objective-C objects
}

void GPSHelperiOS::startUpdating(void)
{
    // Set the iOS LocationManagerDelegate to use the C++ generic delegate
    _locationDelegate.controller = _controller;
    
    // Start updating
    [_locationManager startUpdatingLocation];
}

void GPSHelperiOS::stopUpdating(void)
{
    [_locationManager stopUpdatingLocation];
}