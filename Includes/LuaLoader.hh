#ifndef _LUALOADER_HH_
# define _LUALOADER_HH_

# include <iostream>
# include <RuntimeException.hh>

extern "C"
{
# include <lua.h>
# include <lauxlib.h>
# include <lualib.h>
}

# define DIR "Script/"

class		LuaLoader
{
  lua_State*	_luaVM;
  
public:
  explicit LuaLoader(const std::string &namefile);
  ~LuaLoader();
  void lunchScript(void *object, int x, int y, int range, int size);

};

#endif
