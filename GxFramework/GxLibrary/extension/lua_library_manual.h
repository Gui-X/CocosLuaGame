#ifndef __LIBRARY_LUA_LIBRARY_MANUAL__
#define __LIBRARY_LUA_LIBRARY_MANUAL__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"

#include "lua.h"
#include "lauxlib.h"
#include "scripting/lua-bindings/manual/Lua-BindingsExport.h"

	int lua_library_register(lua_State* L);

#ifdef __cplusplus
}
#endif

#endif  // __LIBRARY_LUA_LIBRARY_MANUAL__