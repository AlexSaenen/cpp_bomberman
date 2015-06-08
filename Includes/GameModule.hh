//
// GameModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 10:58:39 2015 Alexander Saenen
// Last update Fri Jun  5 10:36:42 2015 Alexander Saenen
//

#ifndef GAMEMODULE_HH_
# define GAMEMODULE_HH_

# include <GameObject.hh>
# include <ModulesManager.hpp>
# include <Shape.hh>
# include <LogicException.hh>

class	GameModule : public AModule
{
  std::list<GameObject *>	_garbage;
  std::map<int, std::map<int, std::list<GameObject::ObjectType> > > _gameMap;

public:
  virtual ~GameModule();
  GameModule();

  void	initialize();
  void	markForCleanup(GameObject *object);
  void	handle(GameObject *object, const bool isLaunchable = false);
  void	_onCleanup(Event *);
  std::list<GameObject::ObjectType>	getObject(int x, int y);
};

#endif /* GameModule.hh */
