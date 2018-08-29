#ifndef __LIBRARY_LUA_LIBRARY_MANUAL__
#define __LIBRARY_LUA_LIBRARY_MANUAL__

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

int lua_library_register(lua_State* L);

#endif  // __LIBRARY_LUA_LIBRARY_MANUAL__