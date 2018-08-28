#ifndef PBC_LUA_H
#define PBC_LUA_H
//  

//  pbc-lua.h  

//  pbc  

//  

//  Created by ArcherPeng on 15/7/21.  

//  Copyright (c) 2015ๅนด ztgame. All rights reserved.  

//  




#if defined(_USRDLL)  

#define LUA_EXTENSIONS_DLL     __declspec(dllexport)  

#else         /* use a DLL library */  

#define LUA_EXTENSIONS_DLL  

#endif  



#if __cplusplus  

extern "C" {

#endif  
	//#include "lauxlib.h"



	int LUA_EXTENSIONS_DLL luaopen_protobuf_c(lua_State *L);



#if __cplusplus  

}

#endif  



#endif/* pbc_pbc_lua_h */
