//
// Cube.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 15:35:31 2015 Alexander Saenen
// Last update Sat Jun 13 10:36:33 2015 Alexander Saenen
//

#include "Cube.hh"

Cube::Cube() { }

Cube::~Cube() { }

Cube	*Cube::setTexture(const std::string &texturePath) {
  _texture = ModulesManager::getInstance()->get<TexturesModule>()
    ->getTextInstance(texturePath);
  return (this);
}

void	Cube::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 2.5;
  _scale.y = 2.5;
  _scale.z = 2.5;
  _position.y = 1.2;
  _geometry = ModulesManager::getInstance()->get<TexturesModule>()
    ->getGeoInstance("Cube");
}

void	Cube::update(const gdl::Clock &, gdl::Input &) { }

void	Cube::draw(gdl::AShader &shader, const gdl::Clock &) {
  _texture->bind();
  _geometry->draw(shader, getTransformation(), GL_QUADS);
}

void	Cube::configure(const std::string &conf) {
  std::stringstream	*stream = new std::stringstream(conf);
  
  *stream >> _position.x;
  *stream >> _position.z;
  delete stream;
}
