#include "lua_library_manual.h"
#include "random/lua_seedrandom.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "lua/cjson/lua_cjson.h"
#include "md5/lua_md5.h"

CC_LUA_DLL int lua_library_register(lua_State * L)
{
	luaopen_seedrandom(L);
	luaopen_cjson(L);
	LUA_MD5::register_md5_module(L);

	return 1;
}
