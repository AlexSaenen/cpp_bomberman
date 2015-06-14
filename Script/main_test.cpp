#include "lua_basics.hh"

int	luaCall(lua_State* luaVM)
{
  static int	index = 0;
  // std::cout << "checkbomb" << "index: " << index << std::endl;
  if (index == 3)
    {
      lua_pushinteger(luaVM, 3);
      lua_pushinteger(luaVM, 10);
      lua_pushinteger(luaVM, 0);
    }
  else
    {
      lua_pushinteger(luaVM, 8);
      lua_pushinteger(luaVM, 4);
      lua_pushinteger(luaVM, 2);
    }
  index++;
  return (3);
}

int	main()
{
  LuaScript	*lua;
  void		*object;

  lua = new LuaScript();
  lua->DoScript();
  lua_register(lua->getLua(), "luaCall", luaCall);
  lua->PullFunc("run");
  lua_pushlightuserdata(lua->getLua(), object);
  lua->PushInteger(1);
  lua->PushInteger(2);
  lua->PushInteger(3);
  lua->PushInteger(30);
  lua->Pcall(5, 0, 0);
  delete lua;
  return (0);
}
