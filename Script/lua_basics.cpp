<<<<<<< HEAD
#include "lua_basics.hh"
=======
#include "../Includes/lua_basics.hh"

// int my_function(lua_State *L)
// {
//   int argc = lua_gettop(L);

//   std::cout << "-- my_function() called with " << argc
//     << " arguments:" << std::endl;

<<<<<<< HEAD
  for ( int n=1; n<=argc; ++n ) {
    // std::cout << "-- argument " << n << ": "
    // 	      << lua_tostring(L, n) << std::endl;
  }
  lua_pushnumber(L, 123); // return value
  return 1; // number of return values
}
=======
//   for ( int n=1; n<=argc; ++n ) {
//     std::cout << "-- argument " << n << ": "
//       << lua_tostring(L, n) << std::endl;
//   }
//   lua_pushnumber(L, 123); // return value
//   return 1; // number of return values
// }
>>>>>>> 2949d62327a0d032622a047209a1efeef82c1126
>>>>>>> 8d8c804aa568756275f2e630e3b5e338744b6761

LuaScript::LuaScript()
{
  _luaVM = luaL_newstate();
  if (_luaVM == NULL)
    {
      std::cout << "initialization error" << std::endl;
      return ;
    }
  luaL_openlibs(_luaVM);
}

LuaScript::~LuaScript()
{
  lua_close(_luaVM);
}

lua_State*	LuaScript::getLua()
{
  return (_luaVM);
}

void	LuaScript::PullFunc(std::string const & string)
{
  const char* func_name = string.c_str();
  lua_getglobal(_luaVM, func_name);
  std::cout << "push func: " << string << std::endl;
}

void	LuaScript::PushString(std::string const & string)
{
  const char* str = string.c_str();
  lua_pushstring(_luaVM, str);
  std::cout << "push string: " << string << std::endl;
}

void	LuaScript::PushInteger(int nb)
{
  lua_pushinteger(_luaVM, nb);
  std::cout << "push int: " << nb << std::endl;
}

int	LuaScript::Pcall(int nargs, int nres, int errfunc)
{
  return (lua_pcall(_luaVM, nargs, nres, errfunc));
}

int	LuaScript::DoScript()
{
  std::cout << "Loading Script: " << SCRIPT << std::endl;
  return (luaL_dofile(_luaVM, SCRIPT));
}
