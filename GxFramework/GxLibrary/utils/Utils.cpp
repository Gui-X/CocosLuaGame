#include "Utils.h"

#include "platform/CCPlatformConfig.h"
#include "base/ccConfig.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "pbc-lua.h"

#include "cocos/platform/CCFileUtils.h"

static int read_protobuf_file(lua_State *L) {
	const char *buff = luaL_checkstring(L, -1);
	Data data = cocos2d::FileUtils::getInstance()->getDataFromFile(buff);
	lua_pushlstring(L, (const char*)data.getBytes(), data.getSize());
	return 1;
}


static luaL_Reg luax_func_regs[] = {
	{ "read_protobuf_file_c", read_protobuf_file },
	{ NULL, NULL }
};

TOLUA_API int luaopen_gx_utils(lua_State* L)
{
	lua_getglobal(L, "_G");
	if (lua_istable(L, -1))//stack:...,_G,
	{
		luaL_Reg* lib = luax_func_regs;

		for (; lib->func; lib++)
		{
			lua_register(L, lib->name, lib->func);
		}
	}
	lua_pop(L, 1);

	//lua_register(L, "read_protobuf_file_c", read_protobuf_file);
	return 1;
}