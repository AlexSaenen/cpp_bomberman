//
// Cube.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Sat Jun 13 10:26:00 2015 Alexander Saenen
//

#ifndef CUBE_HH_
# define CUBE_HH_

# include <AShader.hh>
# include <IComponent.hpp>
# include <Texture.hh>
# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <ModulesManager.hpp>
# include <TexturesModule.hh>
# include <Shape.hh>

class	Cube : public IComponent, public Shape
{
  gdl::Texture	*_texture;
  gdl::Geometry	*_geometry;
  float		_speed;

public:
  Cube();
  virtual ~Cube();

  Cube		*setTexture(const std::string &texturePath);
  void		initialize(Event *);
  void		update(const gdl::Clock &clock, gdl::Input &input);
  void		draw(gdl::AShader &shader, const gdl::Clock &clock);
  void		configure(const std::string &conf);
};

#endif /* Cube.hh */
