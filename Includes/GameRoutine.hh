//
// GameRoutine.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 15:08:07 2015 Alexander Saenen
// Last update Mon Jun  8 16:43:23 2015 Alexander Saenen
//

#ifndef GAMEROUTINE_HH_
# define GAMEROUTINE_HH_

# include <vector>
# include <Game.hh>
# include <BasicShader.hh>
# include <Cube.hh>
# include <AModule.hh>
# include <ModulesManager.hpp>
# include <EventModule.hh>
# include <GameObject.hh>
# include <map>

class	GameRoutine : public AModule, public gdl::Game
{
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::map<GameObject::ObjectType, std::vector<GameObject *> >	_objects;

public:
  GameRoutine();
  virtual ~GameRoutine();

  bool	initialize();
  void	_update(Event *);
  void	_draw(Event *);
  void		pushGObject(GameObject *GObject);
  void		popGObject(GameObject *GObject);
  std::vector<GameObject *>	getGObjects(const GameObject::ObjectType type);
  gdl::BasicShader	*getShader();
  gdl::Clock		*getClock();
  gdl::Input		*getInput();
  gdl::SdlContext	*getContext();

private:
  bool	update();
  void	draw();
};

#endif /* GameRoutine.hh */
