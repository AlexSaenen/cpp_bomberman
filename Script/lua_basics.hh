#ifndef LUA_BASICS_HH_
# define LUA_BASICS_HH_

#include <iostream>
#include <string>

extern "C"
{
#include "./lualib/src/lua.h"
#include "./lualib/src/lauxlib.h"
#include "./lualib/src/lualib.h"
}

# define SCRIPT "./ia.lua"

class	LuaScript
{
public:
  LuaScript();
  ~LuaScript();

private:
  lua_State*	_luaVM;
};

#endif /*LUA_BASICS_HH_*/
