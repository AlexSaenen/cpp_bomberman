//
// Bomberman.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:04:34 2015 Alexander Saenen
// Last update Fri Jun  5 14:34:47 2015 Alexander Saenen
//

#ifndef BOMBERMAN_HH_
# define BOMBERMAN_HH_

# include "ModulesManager.hpp"
# include "Loader.hh"
# include "EventModule.hh"
# include "GameRoutine.hh"
# include "GameModule.hh"
# include "MenuModule.hh"
# include "Functor.hpp"
# include "Event.hh"

class Bomberman
{
private:
  bool	_run;

public:
  Bomberman(const int ac, const char **av);
  ~Bomberman();

public:
  void run ();

private:
  void	_initialize(Event *);
  void	_onQuit(Event *);
};

#endif /* Bomberman.hh */
