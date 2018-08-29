#include "lua_library_manual.h"
#include "cjson/lua_cjson.h"
#include "md5/lua_md5.h"
#include "random/lua_seedrandom.h"

static luaL_Reg luax_gx_library_regs[] = {
	{ "cjson", luaopen_cjson },
	{ NULL, NULL }
};


int lua_library_register(lua_State * L)
{
	// load extensions
	luaL_Reg* lib = luax_gx_library_regs;
	lua_getglobal(L, "package");
	lua_getfield(L, -1, "preload");
	for (; lib->func; lib++)
	{
		lua_pushcfunction(L, lib->func);
		lua_setfield(L, -2, lib->name);
	}
	lua_pop(L, 2);

	luaopen_seedrandom(L);
	register_md5_module(L);

	return 1;
}
