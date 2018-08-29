#include "lua_library_manual.h"
#include "cjson/lua_cjson.h"
#include "md5/lua_md5.h"
#include "random/lua_seedrandom.h"

int lua_library_register(lua_State * L)
{
	luaopen_seedrandom(L);
	luaopen_cjson(L);
	LUA_MD5::register_md5_module(L);

	return 1;
}
