//
// Shape.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 11:47:47 2015 Alexander Saenen
// Last update Tue May 12 11:48:14 2015 Alexander Saenen
//

#include "Shape.hh"

Shape::Shape()
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1) { }

Shape::~Shape() { }

void	Shape::translate(glm::vec3 const &v) {
  _position += v;
}

void	Shape::rotate(glm::vec3 const &axis, const float angle) {
  _rotation += axis * angle;
}

void	Shape::scale(glm::vec3 const &scale) {
  _scale *= scale;
}

glm::mat4	Shape::getTransformation() {
  glm::mat4 transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}
