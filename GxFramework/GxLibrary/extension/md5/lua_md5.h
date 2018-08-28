
#ifndef __LUA_MD5_H_
#define __LUA_MD5_H_

#include "cocos2d.h"
#include <string>
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

using namespace std;
using namespace cocos2d;

class LUA_MD5
{
public:
	static const int MD5_BUFFER_LENGTH = 16;

	/** @brief Calculate MD5, get MD5 code (not string) */
	static void MD5(void* input, int inputLength,
		unsigned char* output);

	static void MD5File(const char* path, unsigned char* output);

	static const std::string MD5String(void* input, int inputLength);

	/** @brief Calculate MD5, return MD5 string */
	static LUA_STRING MD5Lua(const char* input, bool isRawOutput);

	static LUA_STRING MD5FileLua(const char* path);

	static char* bin2hex(unsigned char* bin, int binLength);

	// register
	static int tolua_MD500(lua_State* tolua_S);
	static int tolua_MD5File00(lua_State* tolua_S);
	static int register_md5_module(lua_State* tolua_S);
};





#endif // __LUA_MD5_H_