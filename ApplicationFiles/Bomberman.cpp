//
// Bomberman.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 18:02:03 2015 Alexander Saenen
// Last update Fri Jun 12 14:07:30 2015 Alexander Saenen
//

#include "Bomberman.hh"
#include "MusicModule.hh"

Bomberman::Bomberman(const int , const char **):
  _run(true)
{
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Bomberman.quit"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 1000)
    ->observe(std::string("Engine.error"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 1000)
    ->observe(std::string("Loader.error"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 700);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Bomberman.init"), new Functor<Bomberman>(this, &Bomberman::_initialize), 1000)
    ->observe(std::string("Bomberman.init"), new Functor<MenuModule>(ModulesManager::getInstance()->get<MenuModule>(), &MenuModule::initialize), 800)
    ->observe(std::string("Bomberman.init"), new Functor<Loader>(new Loader, &Loader::execute), 600)
    ->observe(std::string("Music.play"), new Functor<MusicModule>(new MusicModule, &MusicModule::addSound), 1000);
}

Bomberman::~Bomberman() {
  ModulesManager	*manager;

  if (ModulesManager::hasInstance()) {
    manager = ModulesManager::getInstance();
    delete manager;
  }
}

void Bomberman::run()
{
  EventModule *ev = ModulesManager::getInstance()->get<EventModule>();

  if (this->_run)
    ev->trigger("Bomberman.init")->handle();
  while (this->_run) {
    ev->trigger("Display.update", 500)
      ->trigger("Display.draw", 400)
      ->trigger("Game.cleanup", 300)
      ->handle();
  }
}

void	Bomberman::_initialize(Event *) {
  GameRoutine	*gr = ModulesManager::getInstance()->get<GameRoutine>();

  if (gr->initialize() == false) {
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
  }
  ModulesManager::getInstance()->get<GameModule>()
    ->initialize();
}

void Bomberman::_onQuit(Event *ev) {
  this->_run = false;
  ev->stop();
  ModulesManager::getInstance()->get<EventModule>()->flush();
}
