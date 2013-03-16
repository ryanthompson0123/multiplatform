//
//  ViewController.m
//  CrossPlatformiOS
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "ViewController.h"
#import "AppDelegate.h"
#import "XPController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.viewInterface = new MyView(self);
    self.appDelegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    self.appDelegate.controller->setView(self.viewInterface);
    
	
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)getGPS:(id)sender {
    self.appDelegate.controller->getLocation();
}

- (void)gotGPSCoordinates:(double)latitude longitude:(double)longitude
{
    self.latLabel.text = [NSString stringWithFormat:@"%f", latitude];
    
    self.longLabel.text = [NSString stringWithFormat:@"%f", longitude];
}

- (void)dealloc
{
    delete self.viewInterface;
}
@end

MyView::MyView(ViewController *controller)
{
    _viewController = controller;
}

MyView::~MyView()
{
    
}

void MyView::updateGPSCoordinates(double latitude, double longitude)
{
    [_viewController gotGPSCoordinates:latitude longitude:longitude];
}