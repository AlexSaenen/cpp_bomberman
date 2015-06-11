#ifndef LUA_BASICS_HH_
# define LUA_BASICS_HH_

#include <iostream>
#include <string>
#include <lunar.h>

// extern "C"
// {
// #include <lua.h>
// #include <lauxlib.h>
// #include <lualib.h>
// }

# define SCRIPT "./script_one.lua"

class	LuaScript
{
public:
  LuaScript();
  ~LuaScript();

  int	function_visible(lua_State*);
private:
  lua_State*	_luaVM;
};

#endif /*LUA_BASICS_HH_*/
