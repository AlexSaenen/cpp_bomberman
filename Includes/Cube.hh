//
// Cube.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Tue May 19 10:44:31 2015 Alexander Saenen
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
# include <Shape.hh>

class	Cube : public IComponent, public Shape
{
  gdl::Texture	_texture;
  gdl::Geometry	_geometry;
  float		_speed;

public:
  Cube();
  virtual ~Cube();

  void		initialize(Event *);
  void		update(const gdl::Clock &clock, gdl::Input &input);
  void		draw(gdl::AShader &shader, const gdl::Clock &clock);
  IComponent	*clone(const std::string &conf) const;
  
private:
  Cube	*_setTexture(const std::string &texturePath);
  void	_configure(const std::string &conf);
};

#endif /* Cube.hh */
