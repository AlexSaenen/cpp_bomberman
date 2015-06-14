#include "LuaLoader.hh"
#include <IA.hh>

LuaLoader::LuaLoader(const std::string &namefile) {
  try {
    if ((_luaVM = luaL_newstate()) == NULL)
      throw RuntimeException("Lua initialization error");
    luaL_openlibs(_luaVM);
    if (luaL_dofile(_luaVM, (DIR + namefile).c_str()) == 1)
      throw RuntimeException("Lua script not found : " + namefile);
    lua_register(_luaVM, "luaCall", IA::luaCall);
  } catch(RuntimeException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Lua.error", 1001)
      ->handle();
  }
}

LuaLoader::~LuaLoader() {
  lua_close(_luaVM);
}

void	LuaLoader::lunchScript(void *object, int x, int y, int range) {
  // std::cout << object << " " << x << " "<< y << " " << range << std::endl;
  lua_getglobal(_luaVM, "run");
  lua_pushlightuserdata(_luaVM, object);
  lua_pushinteger(_luaVM, x);
  lua_pushinteger(_luaVM, y);
  lua_pushinteger(_luaVM, range);
  if (lua_pcall(_luaVM, 4, 0, 0) != 0) {
    throw RuntimeException("Wrong call of lua function");
  }
}
