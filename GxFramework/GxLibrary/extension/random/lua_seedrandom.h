#ifndef __LIBRARY_LUA_SEEDRANDOM__
#define __LIBRARY_LUA_SEEDRANDOM__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"

#include "lua.h"
#include "scripting/lua-bindings/manual/Lua-BindingsExport.h"

CC_LUA_DLL  int  luaopen_seedrandom(lua_State* L);

#ifdef __cplusplus
}
#endif

#endif  // __LIBRARY_LUA_SEEDRANDOM__