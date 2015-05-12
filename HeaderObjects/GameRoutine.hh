//
// GameRoutine.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 15:08:07 2015 Alexander Saenen
// Last update Tue May 12 11:00:54 2015 Alexander Saenen
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

class	GameRoutine : public gdl::Game, public AModule
{
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<GameObject>	_objects;

public:
  GameRoutine();
  virtual ~GameRoutine();

  bool	initialize();
  bool	update();
  void	draw();
  void	_update(Event *);
  void	_draw(Event *);
};

#endif /* GameRoutine.hh */
