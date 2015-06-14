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

# define SCRIPT "./script.lua"

class	LuaScript
{
public:
  LuaScript();
  ~LuaScript();

  lua_State*	getLua();
  int	DoScript();
  void	PullFunc(std::string const &);
  void	PushString(std::string const &);
  void	PushInteger(int);
  int	Pcall(int, int, int);
private:
  lua_State*	_luaVM;
};

#endif /*LUA_BASICS_HH_*/
