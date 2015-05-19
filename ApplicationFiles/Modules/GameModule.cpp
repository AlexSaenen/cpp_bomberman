//
// GameModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:00:44 2015 Alexander Saenen
// Last update Tue May 19 13:20:48 2015 Alexander Saenen
//

#include <GameModule.hh>

GameModule::GameModule() { }

GameModule::~GameModule() { }

void	GameModule::initialize() {
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Game.cleanup"), new Functor<GameModule>(this, &GameModule::_onCleanup), 1000);  
}

void	GameModule::handle(GameObject *object, const bool isLaunchable) const {
  ModulesManager::getInstance()->get<GameRoutine>()
    ->pushGObject(object);
  /* Arriver à rendre les GameObject launchables => càd qu'il lance ses Components (pas tous) */
  if (isLaunchable) { ; }
    //   object->launch();
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
