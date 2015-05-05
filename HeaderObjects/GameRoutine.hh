//
// GameRoutine.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 15:08:07 2015 Alexander Saenen
// Last update Mon Apr 27 15:23:29 2015 Alexander Saenen
//

#ifndef GAMEROUTINE_HH_
# define GAMEROUTINE_HH_

# include <vector>
# include <Game.hh>
# include <BasicShader.hh>
# include <Cube.hh>

class	GameRoutine : public gdl::Game
{
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;
  std::vector<AObject*>	_objects;

public:
  GameRoutine();
  ~GameRoutine();

  bool	initialize();
  bool	update();
  void	draw();
};

#endif /* GameRoutine.hh */
