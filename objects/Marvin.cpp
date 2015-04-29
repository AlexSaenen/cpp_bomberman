//
// Marvin.cpp for  in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue Apr 28 14:47:58 2015 Alexander Saenen
// Last update Wed Apr 29 16:19:24 2015 Alexander Saenen
//

#include "Marvin.hh"

Marvin::Marvin() { }

Marvin::~Marvin() { }

bool	Marvin::initialize() {
  _speed = 10.0f;
  _scale.x = 0.01;
  _scale.y = 0.01;
  _scale.z = 0.01;
  if (_model.load("./LibBomberman_linux_x64/assets/marvin.fbx") == false) {
    std::cerr << "Cannot load the marvin model" << std::endl;
    return (false);
  }
  if (_texture.load("./LibBomberman_linux_x64/assets/marvin.fbm/Main_texture_diffuse2.tga") == false) {
    std::cerr << "Cannot load the marvin texture" << std::endl;
    return (false);
  }
  return (true);
}

void	Marvin::update(gdl::Clock const &clock, gdl::Input &input) {
  if (input.getKey(SDLK_SPACE))
    translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    rotate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed, 4);
  if (input.getKey(SDLK_RIGHT))
    rotate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * _speed, 4);
}

void	Marvin::draw(gdl::AShader &shader, gdl::Clock const &clock) {
  (void)clock;
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
