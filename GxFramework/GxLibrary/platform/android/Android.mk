LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gxlibrary_static

LOCAL_MODULE_FILENAME := libgxlibrary

LOCAL_SRC_FILES := ./../extension/lua_library_manual.cpp

#base

#extension
#cjson
LOCAL_SRC_FILES += ../../../cocos2d-x/external/lua/cjson/fpconv.c \
				   ../../../cocos2d-x/external/lua/cjson/lua_cjson.c \
				   ../../../cocos2d-x/external/lua/cjson/strbuf.c

#md5
LOCAL_SRC_FILES += ../../extension/md5/md5.c \
				   ../../extension/md5/lua_md5.cpp

#random
LOCAL_SRC_FILES += ../../extension/random/SeedRandom.cpp \
				   ../../extension/random/lua_seedrandom.cpp
				   
#utils



LOCAL_C_INCLUDES := $(LOCAL_PATH)/../.. \
				 += $(LOCAL_PATH)/../../../cocos2d-x \
				 += $(LOCAL_PATH)/../../../cocos2d-x/cocos \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua/lua \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua/tolua \
				 += $(LOCAL_PATH)/../../../cocos2d-x/extensions \


include $(BUILD_STATIC_LIBRARY)
