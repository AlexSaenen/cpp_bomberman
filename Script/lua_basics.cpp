#include "../Includes/lua_basics.hh"

// int my_function(lua_State *L)
// {
//   int argc = lua_gettop(L);

//   std::cout << "-- my_function() called with " << argc
//     << " arguments:" << std::endl;

//   for ( int n=1; n<=argc; ++n ) {
//     std::cout << "-- argument " << n << ": "
//       << lua_tostring(L, n) << std::endl;
//   }
//   lua_pushnumber(L, 123); // return value
//   return 1; // number of return values
// }

LuaScript::LuaScript()
{
  _luaVM = luaL_newstate();
  if (_luaVM == NULL)
    {
      std::cout << "initialization error" << std::endl;
      return ;
    }
  luaL_openlibs(_luaVM);
  // lua_register(_luaVM, "my_function", my_function);
  // luaL_dofile(_luaVM, SCRIPT);
}

LuaScript::~LuaScript()
{
  lua_close(_luaVM);
}

void	LuaScript::PullFunc(std::string const & string)
{
  const char* func_name = string.c_str();
  lua_getglobal(_luaVM, func_name);
  std::cout << "push func: " << string << std::endl;
}

// void	LuaScript::PushFunc(std::string const & string)
// {
//   const char* func_name = string.c_str();
//   lua_register(_luaVM, func_name, pointeur sur fonction);
//   std::cout << "push func: " << string << std::endl;
// }

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
