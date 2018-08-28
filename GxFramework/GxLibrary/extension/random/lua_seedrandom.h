#ifndef __LIBRARY_LUA_SEEDRANDOM__
#define __LIBRARY_LUA_SEEDRANDOM__

#include "lua.h"
#include "scripting/lua-bindings/manual/Lua-BindingsExport.h"

CC_LUA_DLL  int  luaopen_seedrandom(lua_State* L);

#endif  // __LIBRARY_LUA_SEEDRANDOM__