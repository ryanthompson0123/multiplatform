//
//  AndroidView.cpp
//  CrossPlatformLib
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "AndroidView.h"
#include <jni.h>

extern JavaVM *globalVM;

AndroidView::AndroidView()
{
    
}

AndroidView::~AndroidView()
{
    
}

void AndroidView::updateGPSCoordinates(double latitude, double longitude)
{
    JNIEnv *env;
    globalVM->GetEnv((void**)&env, JNI_VERSION_1_6);
    
    jclass clazz = env->FindClass("com/crossplatform/example/MainActivity");
    
    jmethodID update = env->GetStaticMethodID(clazz, "gotGPSCoordinates",
                                        "(DD)V");
    
    env->CallStaticVoidMethod(clazz, update, (jdouble)latitude, (jdouble)longitude);
}

