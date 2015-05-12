//
// AObject.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:35:25 2015 Alexander Saenen
// Last update Tue May 12 11:38:01 2015 Alexander Saenen
//

#ifndef AOBJECT_HH_
# define AOBJECT_HH_

# include <SdlContext.hh>
# include <AShader.hh>
# include <Texture.hh>
# include <IComposant.hpp>
# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <iostream>

class AObject : virtual public IComposant
{
protected:
  glm::vec3 _position;
  glm::vec3 _rotation;
  glm::vec3 _scale;

public:
  AObject();
  virtual ~AObject();

  bool	initialize(Event *);
  virtual void	update(const gdl::Clock &clock, gdl::Input &input) = 0;
  virtual void	draw(gdl::AShader &shader, const gdl::Clock &clock) = 0;

  void	translate(const glm::vec3 &v);
  void	rotate(const glm::vec3 &axis, const float angle);
  void	scale(const glm::vec3 &scale);

  glm::mat4 getTransformation();
};

#endif /* AObject.hh */
