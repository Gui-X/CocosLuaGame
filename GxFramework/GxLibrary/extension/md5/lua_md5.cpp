
#include "lua_md5.h"

extern "C" {
#include "md5.h"
#include "lua.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
}

void LUA_MD5::MD5(void* input, int inputLength, unsigned char* output)
{
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, input, inputLength);
    MD5_Final(output, &ctx);
}

void LUA_MD5::MD5File(const char* path, unsigned char* output)
{
    FILE *file = fopen(path, "rb");
    if (file == NULL)
        return;
    
    MD5_CTX ctx;
    MD5_Init(&ctx);
    
    int i;
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    while ((i = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        MD5_Update(&ctx, buffer, (unsigned) i);
    }
    
    fclose(file);
    MD5_Final(output, &ctx);
}

const string LUA_MD5::MD5String(void* input, int inputLength)
{
    unsigned char buffer[MD5_BUFFER_LENGTH];
    MD5(static_cast<void*>(input), inputLength, buffer);

    //LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
    //stack->clean();
    
    char* hex = bin2hex(buffer, MD5_BUFFER_LENGTH);
    string ret(hex);
    delete[] hex;
    return ret;
}

LUA_STRING LUA_MD5::MD5Lua(const char* inputStr, bool isRawOutput)
{
    unsigned char buffer[MD5_BUFFER_LENGTH];
    char* input = (char*)inputStr;
    MD5(static_cast<void*>(input), (int)strlen(input), buffer);
    
    LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
    stack->clean();
    
    if (isRawOutput)
    {
        stack->pushString((char*)buffer, MD5_BUFFER_LENGTH);
    }
    else
    {
        char* hex = bin2hex(buffer, MD5_BUFFER_LENGTH);
        stack->pushString(hex);
        delete[] hex;
    }
    
    return 1;
}

LUA_STRING LUA_MD5::MD5FileLua(const char* path)
{
    unsigned char buffer[MD5_BUFFER_LENGTH];
    MD5File(path, buffer);
    
    LuaStack* stack = LuaEngine::getInstance()->getLuaStack();
    stack->clean();
    
    char* hex = bin2hex(buffer, MD5_BUFFER_LENGTH);
    stack->pushString(hex);
    delete[] hex;
    
    return 1;
}

char* LUA_MD5::bin2hex(unsigned char* bin, int binLength)
{
    static const char* hextable = "0123456789abcdef";
    
    int hexLength = binLength * 2 + 1;
    char* hex = new char[hexLength];
    memset(hex, 0, sizeof(char) * hexLength);
    
    int ci = 0;
    for (int i = 0; i < 16; ++i)
    {
        unsigned char c = bin[i];
        hex[ci++] = hextable[(c >> 4) & 0x0f];
        hex[ci++] = hextable[c & 0x0f];
    }
    
    return hex;
}

/* method: MD5Lua of class */
int LUA_MD5::tolua_MD500(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S, 1, "MD5", 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
		!tolua_isboolean(tolua_S, 3, 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S, 4, &tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		char* input = ((char*)tolua_tostring(tolua_S, 2, 0));
		bool isRawOutput = ((bool)tolua_toboolean(tolua_S, 3, 0));
		{
			LUA_MD5::MD5Lua(input, isRawOutput);

		}
	}
	return 1;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'MD5'.", &tolua_err);
	return 0;
#endif
	return 0;
}

/* method: MD5FileLua of class */
int LUA_MD5::tolua_MD5File00(lua_State* tolua_S)
{
#if COCOS2D_DEBUG >= 1
	tolua_Error tolua_err;
	if (
		!tolua_isusertable(tolua_S, 1, "MD5", 0, &tolua_err) ||
		!tolua_isstring(tolua_S, 2, 0, &tolua_err) ||
		!tolua_isnoobj(tolua_S, 3, &tolua_err)
		)
		goto tolua_lerror;
	else
#endif
	{
		const char* path = ((const char*)tolua_tostring(tolua_S, 2, 0));
		{
			LUA_MD5::MD5FileLua(path);

		}
	}
	return 1;
#if COCOS2D_DEBUG >= 1
	tolua_lerror:
	tolua_error(tolua_S, "#ferror in function 'MD5File'.", &tolua_err);
	return 0;
#endif
	return 0;
}

int LUA_MD5::register_md5_module(lua_State * tolua_S)
{
	 tolua_open(tolua_S);
	 tolua_usertype(tolua_S, "MD5");
	 tolua_module(tolua_S,"cc",0);
	 tolua_beginmodule(tolua_S, "cc");
		 tolua_cclass(tolua_S, "MD5", "MD5", "", NULL);
		 tolua_beginmodule(tolua_S, "MD5");
			 tolua_function(tolua_S,"get",LUA_MD5::tolua_MD500);
			 tolua_function(tolua_S, "getFile", LUA_MD5::tolua_MD5File00);
		 tolua_endmodule(tolua_S);
	 tolua_endmodule(tolua_S);
	return 1;
}
