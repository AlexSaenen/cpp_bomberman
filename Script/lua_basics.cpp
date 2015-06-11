#include "lua_basics.hh"

LuaScript::LuaScript()
{
  _luaVM = luaL_newstate();
  if (_luaVM == NULL)
    {
      std::cout << "initialization error" << std::endl;
      return ;
    }
  luaL_openlibs(_luaVM);
  ua_register(_luaVM, "HostVisible", function_visible);
  luaL_dofile(_luaVM, "./test.lua");
}

LuaScript::~LuaScript()
{
  lua_close(_luaVM);
}

int	function_visible(lua_State* luaVM)
{
  lua_pushstring(_luaVM, "helloworld");
  return (1);
  // luabridge::LuaRef	getDirection = luabridge::getGlobal(L, "getDirection");
  // luabridge::LuaRef	getBb = luabridge::getGlobal(L, "getBomb");//charge les fonction dans
  // lua
  // int	res = getDirection(5, 0);//call functions and send arguments
  // int	bb = getBb(B, 5);
}

// int	lua_basics()
// {
//   lua_State*	luaVM;
//   std::string	str;

//   luaVM = luaL_newstate();
//   if (luaVM == NULL)
//     {
//       std::cout << "initialization error" << std::endl;
//       return (-1);
//     }
//   luaL_openlibs(luaVM);
//   ua_register(luaVM, "HostVisible", function_visible);
//   luaL_dofile(luaVM, SCRIPT);
//   lua_close(luaVM);
//   return (0);
// }
