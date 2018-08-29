
#ifndef __LUA_MD5_H_
#define __LUA_MD5_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"

USING_NS_CC;
using namespace std;

static const int MD5_BUFFER_LENGTH = 16;
int register_md5_module(lua_State* L);

#endif // __LUA_MD5_H_