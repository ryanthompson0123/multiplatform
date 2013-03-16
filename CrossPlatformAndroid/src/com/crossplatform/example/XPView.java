/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.crossplatform.example;

public class XPView {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected XPView(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(XPView obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        CrossPlatformAndroidJNI.delete_XPView(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public XPView() {
    this(CrossPlatformAndroidJNI.new_XPView(), true);
  }

  public void updateGPSCoordinates(double latitude, double longitude) {
    CrossPlatformAndroidJNI.XPView_updateGPSCoordinates(swigCPtr, this, latitude, longitude);
  }

}
