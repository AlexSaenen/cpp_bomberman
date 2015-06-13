#include "../Includes/lua_basics.hh"

int	main()
{
  LuaScript	*lua;

  lua = new LuaScript();
  lua->DoScript();
  lua->PullFunc("run_ia");
  lua->PushInteger(1);
  lua->PushInteger(2);
  lua->PushInteger(3);
  lua->Pcall(3, 1, 0);
  delete lua;
  return (0);
}
