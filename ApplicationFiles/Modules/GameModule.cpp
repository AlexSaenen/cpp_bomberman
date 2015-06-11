//
// GameModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:00:44 2015 Alexander Saenen
// Last update Fri Jun  5 14:53:27 2015 Alexander Saenen
//

#include <GameModule.hh>

GameModule::GameModule() { }

GameModule::~GameModule() { }

void	GameModule::initialize() {
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Game.cleanup"), new Functor<GameModule>(this, &GameModule::_onCleanup), 1000);
}

void	GameModule::handle(GameObject *object, const bool isLaunchable) {
  ModulesManager			*gr = ModulesManager::getInstance();

  gr->get<GameRoutine>()
    ->pushGObject(object);
  if (isLaunchable) { ; }
  //   object->launch();
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

std::list<GameObject::ObjectType>	&GameModule::getObject(int x, int y) {
  return ((_gameMap[x])[y]);
}

void					GameModule::pushOnMap(GameObject *object) {
  Shape                                 *shape = NULL;
  std::list<IComponent *>               gameComponents;
  std::list<IComponent *>::iterator     it;
  
  try {
    gameComponents = object->getComponents();
    it = gameComponents.begin();
    while (it != gameComponents.end()) {
      shape = dynamic_cast<Shape *>(*it);
      it++;
    }
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
    if (_gameMap.find(shape->getPosX()) == _gameMap.end())
      _gameMap[shape->getPosX()] = std::map<int, std::list<GameObject::ObjectType> >();
    ((_gameMap[shape->getPosX()])[shape->getPosY()]).push_back(object->getType());
  } catch(LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
  }
}

void                                    GameModule::pushOnMap(int x, int y, GameObject::ObjectType type) {

  if (_gameMap.find(x) == _gameMap.end())
    _gameMap[x] = std::map<int, std::list<GameObject::ObjectType> >();
  ((_gameMap[x])[y]).push_back(type);
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
    if (shape == NULL)
      throw LogicException("GameObject hasn't got a shape.");
    if (_gameMap.find(shape->getPosX()) == _gameMap.end())
      throw LogicException("GameObject isn't in the map.");
    typeIt = ((_gameMap[shape->getPosX()])[shape->getPosY()]).begin();
    while (typeIt != ((_gameMap[shape->getPosX()])[shape->getPosY()]).end()) {
      if (*typeIt == object->getType()) {
	((_gameMap[shape->getPosX()])[shape->getPosY()]).erase(typeIt);
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

void                                            GameModule::popOnMap(int x, int y, GameObject::ObjectType type) {
  std::list<GameObject::ObjectType>             types;
  std::list<GameObject::ObjectType>::iterator   typeIt;

  try {
    if (_gameMap.find(x) == _gameMap.end())
      throw LogicException("GameObject isn't in the map.");
    typeIt = ((_gameMap[x])[y]).begin();
    while (typeIt != ((_gameMap[x])[y]).end()) {
      if (*typeIt == type) {
	((_gameMap[x])[y]).erase(typeIt);
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
