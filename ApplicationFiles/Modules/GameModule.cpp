//
// GameModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:00:44 2015 Alexander Saenen
// Last update Sat Jun 13 22:59:37 2015 Alexander Saenen
//

#include <GameModule.hh>

GameModule::GameModule() { }

GameModule::~GameModule() { }

void	GameModule::initialize() {
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Game.cleanup"), new Functor<GameModule>(this, &GameModule::_onCleanup), 1000);
}

void	GameModule::handle(GameObject *object) {
  ModulesManager	*gr = ModulesManager::getInstance();

  gr->get<GameRoutine>()
    ->pushGObject(object);
  if (object->getType() < 6) {
    pushOnMap(object);
  }
}

void	GameModule::_onCleanup(Event *) {
  GameObject	*GObject;
  GameRoutine	*gr;

  gr = ModulesManager::getInstance()->get<GameRoutine>();
  while (!_garbage.empty()) {
    GObject = _garbage.front();
    gr->popGObject(GObject);
    delete GObject;
  }
}

void	GameModule::markForCleanup(GameObject *object) {
  _garbage.push_back(object);
}

std::list<GameObject::ObjectType>	&GameModule::getObject(const int x, const int y) {
  return ((_gameMap[x])[y]);
}

void					GameModule::pushOnMap(GameObject *object) {
  Shape                                 *shape = NULL;
  std::list<IComponent *>               gameComponents;
  std::list<IComponent *>::iterator     it;
  
  try {
    gameComponents = object->getComponents();
    it = gameComponents.begin();
    while (it != gameComponents.end() && !shape) {
      shape = dynamic_cast<Shape *>(*it);
      it++;
    }
    double	x = shape->getPosX();
    double	y = shape->getPosY();
    x = x > 0 ? ((x + 2.5) / 2.5) : x / 2.5;
    y = y > 0 ? ((y + 2.5) / 2.5) : y / 2.5;
    std::cout << "PUSH " << x << " " << y << " " << shape->getPosX() << " " << shape->getPosY() << std::endl;
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
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
  int	_x = x > 0 ? (x + 2.5) / 2.5 : x / 2.5;
  int	_y = y > 0 ? (y + 2.5) / 2.5 : y / 2.5;
  std::cout << "PUSH " << _x << " " << _y << " " << x << " " << y << std::endl;
  // int _x = x;
  // int _y = y;
  if (_gameMap.find(_x) == _gameMap.end())
    _gameMap[_x] = std::map<int, std::list<GameObject::ObjectType> >();
  ((_gameMap[_x])[_y]).push_back(type);
}

void						GameModule::popOnMap(GameObject *object) {
  Shape						*shape = NULL;
  std::list<IComponent *>			gameComponents;
  std::list<IComponent *>::iterator		it;
  std::list<GameObject::ObjectType>		types;
  std::list<GameObject::ObjectType>::iterator	typeIt;
  
  try {
    gameComponents = object->getComponents();
    it = gameComponents.begin();
    while (it != gameComponents.end()) {
      shape = dynamic_cast<Shape *>(*it);
      it++;
    }
    double	x = shape->getPosX();
    double	y = shape->getPosY();
    x = x > 0 ? ((x + 2.5) / 2.5) : x / 2.5;
    y = y > 0 ? ((y + 2.5) / 2.5) : y / 2.5;
    std::cout << "POP " << x << " " << y << " " << shape->getPosX() << " " << shape->getPosY() << std::endl;
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
    if (_gameMap.find(x) == _gameMap.end())
      throw LogicException("GameObject isn't in the map.");
    std::list<GameObject::ObjectType>	objects =
      ((_gameMap[x])[y]);
    typeIt = objects.begin();
    while (typeIt != objects.end()) {
      if (*typeIt == object->getType()) {
	objects.erase(typeIt);
	break;
	typeIt++;
      }
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

  try {
    if (_gameMap.find(x) == _gameMap.end())
      throw LogicException("GameObject isn't in the map.");
    std::list<GameObject::ObjectType>	objects =
      (_gameMap[x])[y];
      // (_gameMap[x > 0 ? ((x + 2.5) / 2.5) : x / 2.5])[y > 0 ? ((y + 2.5) / 2.5) : y / 2.5];
    typeIt = objects.begin();
    while (typeIt != objects.end()) {
      if (*typeIt == type) {
	objects.erase(typeIt);
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
