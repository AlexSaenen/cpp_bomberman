//
// AObject.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:35:25 2015 Alexander Saenen
// Last update Mon Apr 27 15:06:41 2015 Alexander Saenen
//

#ifndef AOBJECT_HH_
# define AOBJECT_HH_

# include <SdlContext.hh>
# include <AShader.hh>
# include <Texture.hh>
# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>

class AObject
{
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

public:
  AObject();
  virtual ~AObject();

  virtual bool	initialize();
  virtual void	update(gdl::Clock const &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;

  void	translate(glm::vec3 const &v);
  void	rotate(glm::vec3 const& axis, const float angle);
  void	scale(glm::vec3 const& scale);

  glm::mat4 getTransformation();
};

#endif /* AObject.hh */
