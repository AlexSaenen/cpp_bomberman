//
// Bomberman.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:04:34 2015 Alexander Saenen
// Last update Tue May 19 13:16:12 2015 Alexander Saenen
//

#ifndef BOMBERMAN_HH_
# define BOMBERMAN_HH_

# include "ModulesManager.hpp"
# include "EventModule.hh"
# include "GameModule.hh"
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
