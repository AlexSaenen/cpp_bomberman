//
// IA.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Sun Jun 14 11:05:30 2015 Alexander Saenen
// Last update Sun Jun 14 11:05:30 2015 Alexander Saenen
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
  _gameRoutine = ModulesManager::getInstance()->get<GameRoutine>();
  _model.createSubAnim(0, "Run", 0, 30);
  playSubAnim("Run");
  _model.pause(false);
  _isInitialized = true;
}

void	IA::update(const gdl::Clock &clock, gdl::Input &) {
  if (!_isInitialized)
    _initialize();

  try {
    _gameModule->popOnMap(_position.x, _position.z, _type);

    //    std::cout << "IA update" << std::endl;
    _luaLoader->lunchScript(_this, (int)(_position.x / 2.5), (int)(_position.z / 2.5), _inventory[Player::RANGE], _mapModule->getSize());//_inventory[Player::RANGE]);
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
  _gameModule->pushOnMap(_position.x, _position.z, _type);
  } catch(RuntimeException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Lua.error", 1001)
      ->handle();
  }
}

int	IA::_lookForPlayer(std::list<GameObject::ObjectType> &types) {
  if (find(types.begin(), types.end(), GameObject::PLAYER1) != types.end()
      || find(types.begin(), types.end(), GameObject::PLAYER2) != types.end()
      || find(types.begin(), types.end(), GameObject::IA) != types.end())
    return (1);
  }
  else if (find(types.begin(), types.end(), GameObject::BONUS) != types.end()) {
    return (2);
  }
  return (0);
}

int	IA::_found(lua_State *ls, const int i, const int j, const int find) {
  lua_pushinteger(ls, i);
  lua_pushinteger(ls, j);
  lua_pushinteger(ls, find);
  return (3);
}

int	IA::_radar(lua_State *ls) {
  int	i;
  int	j;
  int	incr;
  int	find = 0;

  std::cout << "radar cpp" << std::endl;
  i = (_position.x / 2.5);
  j = (_position.z / 2.5);
  incr = 1;
  while(find == 0 && incr < _mapModule->getSize() * 2) {
    if (incr % 2 == 1) {
      for(int a = 0; a < incr; a++) {
	i++;
	if ((find = _lookForPlayer(_gameModule->getObject(i, j))) != 0)
	  return (_found(ls, i, j , find));
      }
      for(int a = 0; a < incr; a++) {
	j--;
	if ((find = _lookForPlayer(_gameModule->getObject(i, j))) != 0)
	  return (_found(ls, i, j , find));}
    } else {
      for(int a = 0; a < incr; a++) {
	i--;
	if ((find = _lookForPlayer(_gameModule->getObject(i, j))) != 0)
	  return (_found(ls, i, j , find));      }
      for(int a = 0; a < incr; a++) {
	j++;
	if ((find = _lookForPlayer(_gameModule->getObject(i, j))) != 0)
	  return (_found(ls, i, j , find));
      }
    }
    incr++;
  }
  return (_found(ls, i, j ,0));
}

int	IA::_checkRange(int x, int y, std::vector<GameObject *> bombs) {
  Bomb                                 *bomb = NULL;
  std::list<IComponent *>               gameComponents;
  double				vx;
  double				vy;
  
  try {
    for(std::vector<GameObject *>::iterator it = bombs.begin(); it != bombs.end(); it++) {
      gameComponents = (*it)->getComponents();
      for (std::list<IComponent *>::iterator it = gameComponents.begin(); it != gameComponents.end(); it++) {
	if ((bomb = dynamic_cast<Bomb *>(*it)) != NULL)
	  break;
	if (bomb == NULL)
	  throw LogicException("Bomb hasn't got a shape.");
	vx = bomb->getPosX();
	vy = bomb->getPosY();
	vx = vx / 2.5;
	vy = vy / 2.5;
	if ((int)vx == x && (int)vy == y)
	  return (bomb->getRange());
      }
    }
  } catch (LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Lua.error", 1001)
      ->handle();
    return (0);
  }
  return (0);
}

int					IA::_checkBomb(lua_State *ls) {
  int					range;
  int					x;
  int					y;
  std::list<GameObject::ObjectType>	types;

  std::cout << "checkBomb" << std::endl;
  x = lua_tointeger(ls, 3);
  y = lua_tointeger(ls, 4);
  for(int i = 1; i < 12; i++) {
    types = _gameModule->getObject(x + i, y);
    if (find(types.begin(), types.end(), GameObject::BOMB) != types.end()
	&& (range = _checkRange(x + i, y, _gameRoutine->getGObjects(GameObject::BOMB))) >= i)
      return (_found(ls, x + i, y, range));
    types = _gameModule->getObject(x, y + i);
    if (find(types.begin(), types.end(), GameObject::BOMB) != types.end()
	&& (range = _checkRange(x, y + i, _gameRoutine->getGObjects(GameObject::BOMB))) >= i)
      return (_found(ls, x, y + i, range));
    types = _gameModule->getObject(x, y - i);
    if (find(types.begin(), types.end(), GameObject::BOMB) != types.end()
	&& (range = _checkRange(x, y - i, _gameRoutine->getGObjects(GameObject::BOMB))) >= i)
      return (_found(ls, x, y - i, range));
    types = _gameModule->getObject(x - i, y);
    if (find(types.begin(), types.end(), GameObject::BOMB) != types.end()
	&& (range = _checkRange(x - i, y, _gameRoutine->getGObjects(GameObject::BOMB))) >= i)
      return (_found(ls, x - i, y + i, range));
  }
  return (_found(ls, x, y, 0));
}

int					IA::_checkCase(lua_State *ls) {
  std::list<GameObject::ObjectType>	objects;
  int					x;
  int					y;
  
  x = lua_tointeger(ls, 3);
  y = lua_tointeger(ls, 4);
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
  _ac = static_cast<Action>(lua_tonumber(ls, 3));
  return (0);
}

int    IA::luaCall(lua_State *ls) {
  std::cout << "luaCall cpp" << std::endl;
  std::map <std::string, int (IA::*)(lua_State *)> _func;
  _func["command"] = &IA::_command;
  _func["checkBomb"] = &IA::_checkBomb;
  _func["radar"] = &IA::_radar;
  _func["checkCase"] = &IA::_checkCase;
  return ((static_cast<IA *>(const_cast<void *>(lua_topointer(ls, 1)))->*(_func[lua_tostring(ls, 2)]))(ls));
};
