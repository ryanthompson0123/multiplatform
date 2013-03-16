LOCAL_PATH := $(call my-dir)

# PointSync Connect wrapper
include $(CLEAR_VARS)

LOCAL_MODULE    := crossplatformex
LOCAL_CPP_EXTENSION := .cxx .cpp
LOCAL_CFLAGS += -x c++ -std=c++0x
LOCAL_CPPFLAGS += -fexceptions
LOCAL_SRC_FILES := ../XPView.cpp \
	../XPController.cpp \
	../GPSHelperAndroid.cpp \
	../GPSHelper.cpp \
	../AndroidView.cpp \
	../Android_wrap.cxx
	
include $(BUILD_SHARED_LIBRARY)