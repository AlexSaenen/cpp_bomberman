//
// Drawable.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 11:44:50 2015 Alexander Saenen
// Last update Fri May 15 15:10:52 2015 Alexander Saenen
//

#ifndef SHAPE_HH_
# define SHAPE_HH_

# include <Geometry.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>
# include <ArgException.hh>

class	Shape
{
protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

public:
  Shape();
  ~Shape();

  void	translate(const glm::vec3 &v);
  void	rotate(const glm::vec3 &axis, const float angle);
  void	scale(const glm::vec3 &scale);

  glm::mat4	getTransformation();
};

#endif /* Shape.hh */
