#include <iostream>
#include <string>

extern "C"
{
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

int fn_visible(lua_State* luaVM)
{
  lua_pushstring(luaVM, "helloworld");
  return (1);
}

int	lua_basics()
{
  lua_State*	luaVM;
  std::string	str;

  luaVM = luaL_newstate();
  if (luaVM == NULL)
    {
      std::cout << "initialization error" << std::endl;
      return (-1);
    }
  luaL_openlibs(luaVM);
  ua_register(luaVM, "HostVisible", fn_visible);
  luaL_dofile(luaVM, "./test.lua");
  lua_close(luaVM);
  return (0);
}
