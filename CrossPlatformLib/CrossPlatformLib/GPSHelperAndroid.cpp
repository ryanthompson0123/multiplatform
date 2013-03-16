//
//  GPSHelperAndroid.cpp
//  CrossPlatformExample
//
// Copyright (c) 2013 Ryan Thompson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "GPSHelperAndroid.h"
#include "XPController.h"
#include <jni.h>

// Global reference to the JavaVM
JavaVM *globalVM;

/* 
 This gets called by the JVM when it loads the library
 */
JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    // Store a reference to the JVM
    globalVM = vm;
    return JNI_VERSION_1_6;
}

GPSHelperAndroid::GPSHelperAndroid(XPController *controller) : GPSHelper(controller)
{
}

GPSHelperAndroid::~GPSHelperAndroid()
{
}

/*
 Call up to Java and tell it to start updating GPS
 */
void GPSHelperAndroid::startUpdating()
{
    // Get a reference to the JNI Environment for this thread
    JNIEnv *env;
    globalVM->GetEnv((void**)&env, JNI_VERSION_1_6);
    
    // Find the class and method we want to call
    jclass clazz = env->FindClass("com/crossplatform/example/GPSHelper");
    jmethodID startUpdating = env->GetStaticMethodID(clazz, "startUpdating", "()V");    // ()V is method signature
    
    // Call the method
    env->CallStaticVoidMethod(clazz, startUpdating);
}

void GPSHelperAndroid::stopUpdating()
{
    JNIEnv *env;
    globalVM->GetEnv((void**)&env, JNI_VERSION_1_6);
    
    jclass clazz = env->FindClass("com/crossplatform/example/GPSHelper");
    
    jmethodID stopUpdating = env->GetStaticMethodID(clazz, "stopUpdating", "()V");
    
    env->CallStaticVoidMethod(clazz, stopUpdating);
}