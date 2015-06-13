//
// IA.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Tue Jun  2 17:53:06 2015 Alexander Saenen
//

#include <IA.hh>

IA::IA()
  : Player() {
  _rotationMap.insert(std::pair<int, int>(UP, 0));
  _rotationMap.insert(std::pair<int, int>(DOWN, 180));
  _rotationMap.insert(std::pair<int, int>(LEFT, 90));
  _rotationMap.insert(std::pair<int, int>(RIGHT, 270));
  _translationMap.insert(std::pair<int, glm::vec3>(UP, glm::vec3(0, 0, 1)));
  _translationMap.insert(std::pair<int, glm::vec3>(DOWN, glm::vec3(0, 0, -1)));
  _translationMap.insert(std::pair<int, glm::vec3>(LEFT, glm::vec3(1, 0, 0)));
  _translationMap.insert(std::pair<int, glm::vec3>(RIGHT, glm::vec3(-1, 0, 0)));
  _luaLoader = new LuaLoader("ia.lua");
  _this = static_cast<void *>(this);
}

IA::~IA() {
  delete _luaLoader;
}

void	IA::_initialize() {
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _mapModule = ModulesManager::getInstance()->get<MapModule>();
  _model.createSubAnim(0, "Run", 0, 30);
  playSubAnim("Run");
  _model.pause(true);
  _isInitialized = true;
}

void	IA::update(const gdl::Clock &clock, gdl::Input &) {
  if (!_isInitialized)
    _initialize();

  try {
    _gameModule->popOnMap(_position.x, _position.y, _type);

    std::cout << "IA update" << std::endl;
    _luaLoader->lunchScript(_this, 1, 1, 1);//_inventory[Player::RANGE]);
    // _lastMovement = 0;
    // for (std::map<int, int>::const_iterator it = _rotationMap.begin();
    //      it != _rotationMap.end() && !hasTranslated; ++it)
    //   if (input.getKey((*it).first)) {
    //     hasTranslated = true;
    if (_ac != BOMB) {
      _rotation.y = _rotationMap[_ac];
      translate(_translationMap[_ac] * static_cast<float>(clock.getElapsed()) * _speed);
    }
    //     if (!_isMoving) {
    // 	_model.pause(false);
    // 	_isMoving = true;
    //     }
    //     _lastMovement = (*it).first;
    //   }
    // if (!_lastMovement) {
    //   _isMoving = false;
    //   _model.pause(true);
    // }
    _gameModule->pushOnMap(_position.x, _position.y, _type);
  } catch(RuntimeException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Lua.error", 1001)
      ->handle();
  }
}

int	IA::_lookForPlayer(std::list<GameObject::ObjectType> &types) {
  if (find(types.begin(), types.end(), GameObject::PLAYER1) != types.end() || find(types.begin(), types.end(), GameObject::PLAYER1) != types.end() || find(types.begin(), types.end(), GameObject::PLAYER1) != types.end())
    return (1);
  // else if (find(types.begin(), types.end(), GameObject::)
  return (0);
}

int	IA::_radar(lua_State *) {
  int	i;
  int	j;
  int	incr;
  int	find = 0;

  i = _position.x;
  j = _position.y;
  incr = 1;
  while(find == 0 && incr < _mapModule->getSize() * 2) {
    if (incr % 2 == 1) {
      for(int a = 0; a < incr; a++) {
	i++;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
      for(int a = 0; a < incr; a++) {
	j--;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
    } else {
      for(int a = 0; a < incr; a++) {
	i--;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
      for(int a = 0; a < incr; a++) {
	j++;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
    }
    incr++;
  }
  return (3);
}

int          IA::_checkBomb(lua_State *) {
  return (3);
}

int					IA::_checkCase(lua_State *ls) {
  std::list<GameObject::ObjectType>	objects;
  int					x;
  int					y;
  
  x = lua_tointeger(ls, 2);
  y = lua_tointeger(ls, 3);
  objects = _gameModule->getObject(x, y);
  for(std::list<GameObject::ObjectType>::iterator it = objects.begin(); it != objects.end(); it++) {
    if (*it == GameObject::CUBE) {
      lua_pushinteger(ls, CUBE);
      return (1);
    }
    if (*it == GameObject::CUBEDESTR) {
      lua_pushinteger(ls, CUBEDESTR);
      return (1);
    }
  }
  lua_pushinteger(ls, EMPTY);
  return (1);
}

int	IA::_command(lua_State *ls) {
  std::cout << "toto !!!!" << std::endl;
  if (_toto < 1)
    _ac = static_cast<Action>(lua_tonumber(ls, 3));
  else if (_toto < 2)
    _ac = RIGHT;
  else if (_toto < 3)
    _ac = DOWN;
  else if (_toto < 4)
    _ac = LEFT;
  else
    _toto = -1;
  _toto++;
  return (0);
}

int    IA::luaCall(lua_State *ls) {
  std::cout << "luaCall" << std::endl;
  std::map <std::string, int (IA::*)(lua_State *)> _func;
  _func["command"] = &IA::_command;
  return ((static_cast<IA *>(const_cast<void *>(lua_topointer(ls, 1)))->*(_func[lua_tostring(ls, 2)]))(ls));
};
