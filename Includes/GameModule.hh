//
// GameModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 10:58:39 2015 Alexander Saenen
// Last update Sat Jun 13 22:11:44 2015 Alexander Saenen
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
  void	handle(GameObject *object);
  std::list<GameObject::ObjectType>	&getObject(int x, int y);
  void	pushOnMap(GameObject *object);
  void  pushOnMap(const double x, const double y, const GameObject::ObjectType type);
  void	popOnMap(GameObject *object);
  void  popOnMap(const double x, const double y, const GameObject::ObjectType type);
  
private:
  void	_onCleanup(Event *);
};

#endif /* GameModule.hh */
