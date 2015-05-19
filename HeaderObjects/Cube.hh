//
// Cube.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Fri May 15 14:52:51 2015 Alexander Saenen
//

#ifndef CUBE_HH_
# define CUBE_HH_

# include <AShader.hh>
# include <IComposant.hpp>
# include <Texture.hh>
# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <Shape.hh>

class	Cube : public IComposant, public Shape
{
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;

public:
  Cube();
  virtual ~Cube();

  void	initialize(Event *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
};

#endif /* Cube.hh */
