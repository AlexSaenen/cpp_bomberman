#include "lua_basics.hh"

int	main()
{
  LuaScript	*lua;

  lua = new LuaScript();
  delete lua;
  return (0);
}
