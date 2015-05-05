//
// Application.cpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:51:46 2015 Alexander Saenen
// Last update Tue May  5 17:25:26 2015 Alexander Saenen
//

#include "Application.hh"

Application::Application(int ac, char **av):
  _run(true)
{
  // TODO : save ac and av somewhere... look for something named design pattern Registry...
  ac = ac;
  av = av;
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.quit"), new Functor<Application>(this, &Application::_onQuit), 1000);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.init"), new Functor<Application>(this, &Application::_initialize), 1000);
}

Application::~Application() {
  ModulesManager	*manager;

  manager = ModulesManager::getInstance();
  delete manager;
}

void Application::run()
{
  EventModule *ev = ModulesManager::getInstance()->get<EventModule>();

  ev->trigger("Application.init")->handle();
  while (this->_run) {
    ev->trigger("Application.loop.pre", 1000)
      ->trigger("Application.loop.main", 500)
      ->trigger("Application.loop.post")
      ->handle();
    ev->trigger("Application.quit")->handle();
  }
}

void	Application::_initialize(Event *) {
  std::cout << "\t\t_initialize()" << std::endl;
}

void Application::_onQuit(Event *ev) {
  std::cout << "\t\t_onQuit()" << std::endl;
  this->_run = false;
  ev->stop();
}
