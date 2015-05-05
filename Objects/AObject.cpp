//
// AObject.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:42:02 2015 Alexander Saenen
// Last update Mon Apr 27 14:53:39 2015 Alexander Saenen
//

#include "AObject.hh"

AObject::AObject()
  : _position(0, 0, 0), _rotation(0, 0, 0), _scale(1, 1, 1) { }

AObject::~AObject() { }

bool	AObject::initialize() {
  return (true);
}

void	AObject::update(gdl::Clock const &clock, gdl::Input &input) {
  if (sizeof(clock) || sizeof(input)) {;}
}

void	AObject::translate(glm::vec3 const &v) {
  _position += v;
}

void	AObject::rotate(glm::vec3 const &axis, const float angle) {
  _rotation += axis * angle;
}

void	AObject::scale(glm::vec3 const &scale) {
  _scale *= scale;
}

glm::mat4	AObject::getTransformation() {
  glm::mat4 transform(1);

  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, _position);
  transform = glm::scale(transform, _scale);
  return (transform);
}
