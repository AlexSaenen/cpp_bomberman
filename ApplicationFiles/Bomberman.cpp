//
// Bomberman.cpp for  in /home/vividy/rendu/cpp_bomberman
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 15:55:18 2015 Vividy
// Last update Sun Jun 14 13:12:44 2015 Alexander Saenen
//

#include "Bomberman.hh"
#include "MusicModule.hh"

Bomberman::Bomberman(const int , const char **):
  _run(true)
{
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Bomberman.quit"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 1000)
    ->observe(std::string("Engine.error"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 1000)
    ->observe(std::string("MapGenerator.error"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 1000)
    ->observe(std::string("Loader.error"), new Functor<Bomberman>(this, &Bomberman::_onQuit), 700);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Bomberman.init"), new Functor<Bomberman>(this, &Bomberman::_initialize), 1000)
    ->observe(std::string("Bomberman.init"), new Functor<MenuModule>(ModulesManager::getInstance()->get<MenuModule>(), &MenuModule::initialize), 800)
    ->observe(std::string("Music.play"), new Functor<MusicModule>(ModulesManager::getInstance()->get<MusicModule>(), &MusicModule::addSound), 1000);
  srand(time(0));
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
