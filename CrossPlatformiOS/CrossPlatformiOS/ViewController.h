//
//  ViewController.h
//  CrossPlatformiOS
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <UIKit/UIKit.h>
#include "XPView.h"

@class AppDelegate;

@interface ViewController : UIViewController
@property (weak, nonatomic) AppDelegate *appDelegate;
@property XPView *viewInterface;
@property (weak, nonatomic) IBOutlet UILabel *latLabel;
@property (weak, nonatomic) IBOutlet UILabel *longLabel;

- (IBAction)getGPS:(id)sender;

- (void)gotGPSCoordinates:(double)latitude longitude:(double)longitude;

@end

class MyView : public XPView
{
private:
    ViewController *_viewController;
public:
    MyView(ViewController *);
    ~MyView();
    void updateGPSCoordinates(double latitude, double longitude);
};
