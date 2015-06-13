#include "lua_basics.hh"

int my_function(lua_State *L)
{
  int argc = lua_gettop(L);

  std::cout << "-- my_function() called with " << argc
    << " arguments:" << std::endl;

  for ( int n=1; n<=argc; ++n ) {
    std::cout << "-- argument " << n << ": "
	      << lua_tostring(L, n) << std::endl;
  }
  lua_pushnumber(L, 123); // return value
  return 1; // number of return values
}

LuaScript::LuaScript()
{
  _luaVM = luaL_newstate();
  if (_luaVM == NULL)
    {
      std::cout << "initialization error" << std::endl;
      return ;
    }
  luaL_openlibs(_luaVM);
  lua_register(_luaVM, "my_function", my_function);
  std::cerr << "-- Loading file: " << std::endl;
  luaL_dofile(_luaVM, SCRIPT);
}

LuaScript::~LuaScript()
{
  lua_close(_luaVM);
}
