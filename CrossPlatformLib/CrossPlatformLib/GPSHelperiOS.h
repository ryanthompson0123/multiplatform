//
//  GPSHelperiOS.h
//  CrossPlatformExample
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef CrossPlatformExample_GPSHelperiOS_h
#define CrossPlatformExample_GPSHelperiOS_h

#include "GPSHelper.h"
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

class XPController;
/* 
 Objective-C delegate class to hand to the CLLocationManager to recieve GPS updates
 */
@interface MyLocationDelegate: NSObject <CLLocationManagerDelegate>
@property XPController *controller;
@end

/*
 iOS specific implementation of the GPSHelper class
 */
class GPSHelperiOS : public GPSHelper
{
private:
    CLLocationManager *_locationManager;
    MyLocationDelegate *_locationDelegate;
public:
    GPSHelperiOS(XPController *);
    ~GPSHelperiOS(void);
    
    void startUpdating(void);
    void stopUpdating(void);
};

#endif
