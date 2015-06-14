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
