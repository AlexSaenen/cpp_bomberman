//
// GameModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:00:44 2015 Alexander Saenen
// Last update Sun Jun 14 20:05:04 2015 Alexander Saenen
//

#include <GameModule.hh>
#include <Bonus.hh>
#include <GameOver.hh>

GameModule::GameModule() { }

GameModule::~GameModule() { }

void	GameModule::initialize() {
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Game.cleanup"), new Functor<GameModule>(this, &GameModule::_onCleanup), 1000)
    ->observe(std::string("Bomb.explosion"), new Functor<GameModule>(this, &GameModule::_handleExplosion), 1000);
}

void	GameModule::_killPlayers(const Bomb *bomb, const double x, const double y) {
  int	range = bomb->getRange();
  bool	_hasKilled = false;
  std::vector<GameObject *>    players;
  GameObject::ObjectType it = GameObject::PLAYER1;
  while (it <= GameObject::PLAYER2) {
    if (ModulesManager::getInstance()->get<GameRoutine>()->getGOStatus(it, players)) {
      Shape	*shape = dynamic_cast<Shape *>(players.front()->getComponents().front());
      double	_x = static_cast<int>(shape->getPosX() / 2.5) * 2.5;
      double	_y = static_cast<int>(shape->getPosY() / 2.5) * 2.5;
      if (x == _x && ((y + (range * 2.5) >= _y && _y >= y) || (y - (2.5 * range) <= _y && _y <= y))) {
	_hasKilled = true;
	markForCleanup(players.front());
      }
      else if (y == _y && ((x + (range * 2.5) >= _x && _x >= x) || (x - (2.5 * range) <= _x && _x <= x))) {
	_hasKilled = true;
	markForCleanup(players.front());
      }
    }
    if (_hasKilled && players.size() == 1)
      ModulesManager::getInstance()->get<GameOver>()->execute(0);
    it = static_cast<GameObject::ObjectType>(it + 1);
  }
  if (ModulesManager::getInstance()->get<GameRoutine>()->getGOStatus(GameObject::IA, players)) {
    for (std::vector<GameObject *>::iterator it = players.begin(); it != players.end(); ++it) {
      Shape	*shape = dynamic_cast<Shape *>((*it)->getComponents().front());
      double	_x = static_cast<int>(shape->getPosX() / 2.5) * 2.5;
      double	_y = static_cast<int>(shape->getPosY() / 2.5) * 2.5;
      std::cout << x << " " << y << " " << _x << " " << _y << std::endl;
      if (x == _x && ((y + (range * 2.5) >= _y && _y >= y) || (y - (2.5 * range) <= _y && _y <= y))) {
	_hasKilled = true;
	markForCleanup((*it));
      }
      else if (y == _y && ((x + (range * 2.5) >= _x && _x >= x) || (x - (2.5 * range) <= _x && _x <= x))) {
	_hasKilled = true;
	markForCleanup((*it));
      }
    }
    if (_hasKilled && players.size() == 1) {
      std::cout << "IA are dead" << std::endl;
      ModulesManager::getInstance()->get<GameOver>()->execute(0);
    }
  }
}

void	GameModule::_deleteDestroyables(const Bomb *bomb, const double x, const double y) {
  int	closest[4] = { 13, 13, 13, 13 };
  GameObject	*nearest[4] = { 0, 0, 0, 0 };
  int	range = bomb->getRange();
  std::vector<GameObject *>	cubes;
  if (ModulesManager::getInstance()->get<GameRoutine>()->getGOStatus(GameObject::CUBEDESTR, cubes)) {
    for (std::vector<GameObject *>::iterator it = cubes.begin(); it != cubes.end(); ++it) {
      Shape	*shape = dynamic_cast<Shape *>((*it)->getComponents().front());
      double	_x = static_cast<int>(shape->getPosX() / 2.5) * 2.5;
      double	_y = static_cast<int>(shape->getPosY() / 2.5) * 2.5;
      if (x == _x && ((y + (range * 2.5) >= _y && _y >= y) || (y - (2.5 * range) <= _y && _y <= y))) {
	if (_y >= y && closest[0] > _y - y) {
	  closest[0] = _y - y;
	  nearest[0] = (*it);
	}
	else if (_y <= y && closest[1] > y - _y) {
	  closest[1] = y - _y;
	  nearest[1] = (*it);
	}
      }
      else if (y == _y && ((x + (2.5 * range) >= _x && _x >= x) || (x - (2.5 * range) <= _x && _x <= x))) {
	if (_x >= x && closest[2] > _x - x) {
	  closest[2] = _x - x;
	  nearest[2] = (*it);
	}
	else if (_x <= x && closest[3] > x - _x) {
	  closest[3] = x - _x;
	  nearest[3] = (*it);
	}	
      }
    }
  }
  _popBonuses(nearest);
}

void	GameModule::_popBonuses(GameObject **nearest) {
  std::map<int, int>	_bonusLotto;
  Bonus *bonus = 0;
  _bonusLotto[rand() % 10] = 0;
  int	value = rand() % 10;
  while ((_bonusLotto.find(value)) != _bonusLotto.end())
    value = rand() % 10;
  _bonusLotto[value] = 1;
  while ((_bonusLotto.find(value)) != _bonusLotto.end())
    value = rand() % 10;;
  _bonusLotto[value] = 2;
  for (size_t i = 0; i < 4; ++i)
    if (nearest[i]) {
      markForCleanup(nearest[i]);
      value = rand() % 10;
      if (_bonusLotto.find(value) != _bonusLotto.end()) {
	GameObject	*go = new GameObject(GameObject::BONUS, "bonus");
	Bonus::BonusType	type = static_cast<Bonus::BonusType>(_bonusLotto[value]);
	bonus = new Bonus(type);
	bonus->initialize(0);
	std::stringstream	strm;
	Shape	*shape = dynamic_cast<Shape *>(nearest[i]->getComponents().front());
	strm << shape->getPosX() << " " << shape->getPosY() << " " << type;
	bonus->configure(strm.str());
	go->pushComponent(bonus);
	handle(go);
      }
    }  
}

void	GameModule::_handleExplosion(Event *ev) {
  std::stringstream	strm(ev->get<std::string>("Position"));
  double x, y;
  strm >> x;
  strm >> y;
  Event	*mv = new Event("Music.play");
  std::string	name("GraphicsLib/assets/GameSounds/explosion.mp3");
  std::string	music("SOUND");
  mv->set<std::string>(std::string("FILE"), name);
  mv->set<std::string>(std::string("TYPE"), music);
  ModulesManager::getInstance()->get<EventModule>()->trigger(mv)->handle();
  std::vector<GameObject *> bombs = ModulesManager::getInstance()->get<GameRoutine>()
    ->getGObjects(GameObject::BOMB);
  Bomb	*bomb = 0;
  GameObject	*model = 0;
  for (std::vector<GameObject *>::iterator it = bombs.begin(); it != bombs.end(); ++it) {
    model = (*it);
    std::list<IComponent *> comp = model->getComponents();
    bomb = dynamic_cast<Bomb *>(comp.front());
    if (bomb && bomb->hasExploded() && bomb->getPosX() == x && bomb->getPosY())
      break;
  }
  if (model && bomb)
    markForCleanup(model);
  x = (bomb->getPosX() / 2.5) * 2.5;
  y = (bomb->getPosY() / 2.5) * 2.5;
  _deleteDestroyables(bomb, x, y);
  _killPlayers(bomb, x, y);
  /* if persons are killed -> call GameOver and check */
}

void	GameModule::handle(GameObject *object) {
  ModulesManager	*gr = ModulesManager::getInstance();

  gr->get<GameRoutine>()->pushGObject(object);
  if (object->getType() < 7) {
    pushOnMap(object);
  }
}

void	GameModule::_onCleanup(Event *) {
  GameObject	*GObject;

  while (!_garbage.empty()) {
    GObject = _garbage.front();
    _garbage.pop_front();
    delete GObject;
  }
}

void	GameModule::markForCleanup(GameObject *object) {
  GameRoutine	*gr;
  gr = ModulesManager::getInstance()->get<GameRoutine>();
  for (std::list<GameObject *>::const_iterator it = _garbage.begin(); it != _garbage.end(); ++it) {
    if ((*it) == object)
      return ;
  }
  _garbage.push_back(object);
  popOnMap(object);
  gr->popGObject(object);
}

std::list<GameObject::ObjectType>	&GameModule::getObject(const int x, const int y) {
  return ((_gameMap[x])[y]);
}

bool			GameModule::tryGetObject(const int x, const int y, std::list<GameObject::ObjectType> &objects) {
  if (_gameMap.find(x) == _gameMap.end() || _gameMap[x].find(y) == _gameMap[x].end())
    return (false);
  objects = _gameMap[x][y];
  return (true);
}

void					GameModule::pushOnMap(GameObject *object) {
  Shape                                 *shape = NULL;
  std::list<IComponent *>               gameComponents;
  
  try {
    try {
    gameComponents = object->getComponents();
    } catch (ArgException e) {
      std::cerr << e.getMessage() << std::endl;
    }
    for (std::list<IComponent *>::iterator it = gameComponents.begin(); it != gameComponents.end(); it++) {
      if ((shape = dynamic_cast<Shape *>(*it)) != NULL)
	break;
    }
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
    double	x = shape->getPosX();
    double	y = shape->getPosY();
    x = x / 2.5;
    y = y / 2.5;
    if (_gameMap.find(x) == _gameMap.end())
      _gameMap[x] = std::map<int, std::list<GameObject::ObjectType> >();
    ((_gameMap[x])[y]).push_back(object->getType());
  } catch(LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
  }
}

void                                    GameModule::pushOnMap(const double x, const double y, const GameObject::ObjectType type) {
  int	_x = x / 2.5;
  int	_y = y / 2.5;
  if (_gameMap.find(_x) == _gameMap.end())
    _gameMap[_x] = std::map<int, std::list<GameObject::ObjectType> >();
  ((_gameMap[_x])[_y]).push_back(type);
}

void						GameModule::popOnMap(GameObject *object) {
  Shape						*shape = NULL;
  std::list<IComponent *>			gameComponents;
  std::list<GameObject::ObjectType>		types;
  std::list<GameObject::ObjectType>::iterator	typeIt;
  
  try {
    gameComponents = object->getComponents();
    for (std::list<IComponent *>::iterator it = gameComponents.begin(); it != gameComponents.end(); it++)
      if ((shape = dynamic_cast<Shape *>(*it)) != NULL)
	break;
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
    double	x = shape->getPosX();
    double	y = shape->getPosY();
    x = x / 2.5;
    y = y / 2.5;
    if (_gameMap.find(x) == _gameMap.end() || _gameMap[x].find(y) == _gameMap[x].end())
      throw LogicException("GameObject isn't in the map.");
    std::list<GameObject::ObjectType>	objects =
      ((_gameMap[x])[y]);
    typeIt = objects.begin();
    while (typeIt != objects.end()) {
      if (*typeIt == object->getType()) {
	objects.erase(typeIt);
	((_gameMap[x])[y]) = objects;
	break;
      }
      typeIt++;
    }
  } catch(LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
  }
}

void                                            GameModule::popOnMap(const double x, const double y, const GameObject::ObjectType type) {
  std::list<GameObject::ObjectType>             types;
  std::list<GameObject::ObjectType>::iterator   typeIt;

  double _x = x / 2.5;
  double _y = y / 2.5;
  try {
    if (_gameMap.find(_x) == _gameMap.end())
      throw LogicException("GameObject isn't in the map.");
    std::list<GameObject::ObjectType>	objects =
      (_gameMap[_x])[_y];
    typeIt = objects.begin();
    while (typeIt != objects.end()) {
      if (*typeIt == type) {
	objects.erase(typeIt);
	_gameMap[_x][_y] = objects;
	break;
      }
      typeIt++;
    }
  } catch(LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
  }
}
