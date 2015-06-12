#ifndef LUA_BASICS_HH_
# define LUA_BASICS_HH_

#include <iostream>
#include <string>

extern "C"
{
#include "../LuaLib/src/lua.h"
#include "../LuaLib/src/lauxlib.h"
#include "../LuaLib/src/lualib.h"
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
