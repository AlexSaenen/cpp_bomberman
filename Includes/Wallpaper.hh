//
// Wallpaper.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Sat Jun 13 10:31:27 2015 Alexander Saenen
//

#ifndef WALLPAPER_HH_
# define WALLPAPER_HH_

# include <AShader.hh>
# include <IComponent.hpp>
# include <Texture.hh>
# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>
# include <Shape.hh>
# include <ModulesManager.hpp>

class	Wallpaper : public IComponent, public Shape
{
  gdl::Texture	*_texture;
  gdl::Geometry	*_geometry;
  float		_speed;

public:
  Wallpaper();
  virtual ~Wallpaper();

  Wallpaper	*setTexture(const std::string &texturePath);
  void		initialize(Event *);
  void		update(const gdl::Clock &clock, gdl::Input &input);
  void		draw(gdl::AShader &shader, const gdl::Clock &clock);
  void		configure(const std::string &conf);
};

#endif /* Wallpaper.hh */
