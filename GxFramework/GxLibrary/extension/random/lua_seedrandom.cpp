#include "lua_seedrandom.h"
#include "SeedRandom.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

static int gameSeedRandom(lua_State *L)
{
	int index = luaL_checkint(L, 1);
	int seed = luaL_checkint(L, 2);

	if (index == 1)
		SeedRandom::getInstance(1)->Reset(seed);
	else
		SeedRandom::getInstance(2)->Reset(seed);

	return 1;
}

static int gameRandom(lua_State *L)
{
	int index = luaL_checkint(L, 1);
	int min = luaL_checkint(L, 2);
	int max = luaL_checkint(L, 3);

	if (index == 1)
		tolua_pushnumber(L, SeedRandom::getInstance(1)->Value1(min, max));
	else
		tolua_pushnumber(L, SeedRandom::getInstance(2)->Value1(min, max));

	return 1;
}

int luaopen_seedrandom(lua_State * L)
{

	lua_register(L, "gameSeedRandom", gameSeedRandom);
	lua_register(L, "gameRandom", gameRandom);

	return 1;
}
