//
// Cube.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Mon Apr 27 14:58:47 2015 Alexander Saenen
//

#ifndef CUBE_HH_
# define CUBE_HH_

# include "AObject.hh"

class	Cube : public AObject
{
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;

public:
  Cube();
  virtual ~Cube();

  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* Cube.hh */
