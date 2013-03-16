//
//  CrossPlatformController.cpp
//  CrossPlatformLib
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "XPController.h"
#include "GPSHelper.h"
#include "GPSHelperNative.h"
#include "XPView.h"
#include "XPLocation.h"

XPController::XPController()
{
    // Create an instance of the Native GPSHelper
    _gpsHelper = new GPSHelperNative(this);
}

XPController::~XPController()
{
    delete _gpsHelper;
}

void XPController::getLocation()
{
    _gpsHelper->startUpdating();
}

void XPController::locationUpdated(const XPLocation &location)
{
    _gpsHelper->stopUpdating();
    
    // Do some super secret algorithm on GPS coordinates
    
    // Call back the view
    _view->updateGPSCoordinates(location.latitude, location.longitude);
}

/*
 This method sets the controller's active View
 */
void XPController::setView(XPView *view)
{
    _view = view;
}



