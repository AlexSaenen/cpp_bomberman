//
// Application.cpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:51:46 2015 Alexander Saenen
// Last update Wed May  6 23:06:38 2015 Alexander Saenen
//

#include "Application.hh"

Application::Application(const int , const char **):
  _run(true)
{
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.quit"), new Functor<Application>(this, &Application::_onQuit), 1000);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.init"), new Functor<Application>(this, &Application::_initialize), 1000);
}

Application::~Application() {
  ModulesManager	*manager;

  if (ModulesManager::hasInstance()) {
    manager = ModulesManager::getInstance();
    delete manager;
  }
}

void Application::run()
{
  EventModule *ev = ModulesManager::getInstance()->get<EventModule>();

  ev->trigger("Application.init")->handle();
  while (this->_run) {
    ev->trigger("Application.update", 500)
      ->trigger("Application.draw", 400)
      ->handle();
  }  
}

void	Application::_initialize(Event *) {
  GameRoutine	*gr = new GameRoutine;

  gr->initialize();
}

void Application::_onQuit(Event *ev) {
  std::cout << "\t\t_onQuit()" << std::endl;
  this->_run = false;
  ev->stop();
  ModulesManager::getInstance()->get<EventModule>()->flush();
}
