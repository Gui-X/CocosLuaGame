LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := gxlibrary_static

LOCAL_MODULE_FILENAME := libgxlibrary

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := \

#base

#extension
#cjson
LOCAL_CFLAGS	+= -DENABLE_CJSON_GLOBAL
LOCAL_SRC_FILES += ../../extension/cjson/fpconv.c \
				   ../../extension/cjson/lua_cjson.c \
				   ../../extension/cjson/strbuf.c

#md5
LOCAL_CFLAGS	+= -DHAVE_OPENSSL
LOCAL_SRC_FILES += ../../extension/md5/md5.c \
				   ../../extension/md5/lua_md5.cpp

#random
LOCAL_SRC_FILES += ../../extension/random/SeedRandom.cpp \
				   ../../extension/random/lua_seedrandom.cpp
				   
#utils



LOCAL_SRC_FILES += ../../extension/lua_library_manual.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../.. \
				 += $(LOCAL_PATH)/../../../cocos2d-x \
				 += $(LOCAL_PATH)/../../../cocos2d-x/cocos \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua/lua \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua/tolua \
				 += $(LOCAL_PATH)/../../../cocos2d-x/external/lua/luajit/include \
				 += $(LOCAL_PATH)/../../../cocos2d-x/extensions \

LOCAL_STATIC_LIBRARIES := cocos2d_lua_static

include $(BUILD_STATIC_LIBRARY)

$(call import-module, cocos/scripting/lua-bindings/proj.android)
