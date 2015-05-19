//
// GameModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 10:58:39 2015 Alexander Saenen
// Last update Tue May 19 13:21:00 2015 Alexander Saenen
//

#ifndef GAMEMODULE_HH_
# define GAMEMODULE_HH_

# include <AModule.hh>
# include <GameObject.hh>
# include <ModulesManager.hpp>

class	GameModule : public AModule
{
  std::list<GameObject *>	_garbage;

public:
  virtual ~GameModule();
  GameModule();

  void	initialize();
  void	markForCleanup(GameObject *object);
  void	handle(GameObject *object, const bool isLaunchable = false) const;
  void	_onCleanup(Event *);
};

#endif /* GameModule.hh */
