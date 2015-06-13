//
// GameRoutine.hh for  in /home/vividy/rendu/cpp_bomberman
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sun Jun 14 01:29:24 2015 Vividy
// Last update Sun Jun 14 01:29:26 2015 Vividy
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
# include <Camera.hh>
# include <map>
# include <SaveMap.hh>

class	GameRoutine : public AModule, public gdl::Game
{
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::map<GameObject::ObjectType, std::vector<GameObject *> >	_objects;
  double		_lastSaved;

public:
  GameRoutine();
  virtual ~GameRoutine();

  bool	initialize();
  void	_update(Event *);
  void	_draw(Event *);
  void		pushGObject(GameObject *GObject);
  void		popGObject(GameObject *GObject);
  std::vector<GameObject *>	getGObjects(const GameObject::ObjectType type);
  bool				getGOStatus(const GameObject::ObjectType type, std::vector<GameObject *> &);
  gdl::BasicShader	*getShader();
  gdl::Clock		*getClock();
  gdl::Input		*getInput();
  gdl::SdlContext	*getContext();

private:
  bool	update();
  void	draw();
};

#endif /* GameRoutine.hh */
