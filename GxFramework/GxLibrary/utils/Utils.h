#ifndef __LIBRARY_UTILS_H__
#define __LIBRARY_UTILS_H__

#include "cocos2d.h"

USING_NS_CC;

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"

#ifdef __cplusplus
}
#endif

#include "lua.h"
#include "lauxlib.h"
#include "scripting/lua-bindings/manual/Lua-BindingsExport.h"

TOLUA_API int luaopen_gx_utils(lua_State* L);

#endif // __LIBRARY_UTILS_H__