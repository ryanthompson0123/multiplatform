//
//  CrossPlatformController.h
//  CrossPlatformLib
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef __CrossPlatformLib__XPController__
#define __CrossPlatformLib__XPController__

#include <iostream>
#include "GPSHelper.h"

class XPView;
class XPLocation;
class XPController
{
private:
    XPView *_view;
    GPSHelper *_gpsHelper;
public:
    XPController(void);
    ~XPController(void);
    
    void setView(XPView *view);
    
    // Actions the view can take on the controller
    void getLocation(void);
    
    // Callbacks
    void locationUpdated(const XPLocation &);
};

#endif /* defined(__CrossPlatformLib__XPController__) */
