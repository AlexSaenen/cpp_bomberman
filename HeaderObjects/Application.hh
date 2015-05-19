//
// Application.hh for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:52:14 2015 Alexander Saenen
// Last update Tue May  5 18:00:55 2015 Alexander Saenen
//

#ifndef APPLICATION_HH_
# define APPLICATION_HH_

# include "ModulesManager.hpp"
# include "EventModule.hh"
# include "Functor.hpp"
# include "Event.hh"
# include "Parser.hpp"

class Application
{
private:
  bool	_run;

public:
  Application(const int ac, const char **av);
  ~Application();

public:
  void run ();

private:
  void	_initialize(Event *);
  void	_onQuit(Event *);
};

#endif /* Application.hh */
