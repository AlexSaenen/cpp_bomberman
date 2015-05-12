//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Tue May 12 18:11:45 2015 Alexander Saenen
//

#include "ObjModel.hh"

ObjModel::ObjModel(const std::string &model, const std::string &texture)
  : _modelName(model), _textureName(texture) { }

ObjModel::~ObjModel() { }

bool	ObjModel::initialize(Event *) {
  _speed = 10.0f;
  if (_texture.load(_textureName) == false) {
    std::cerr << "Cannot load the cube texture: " << _textureName << std::endl;
    return (false);
  }
  _scale.x = 1;
  _scale.y = 1;
  _scale.z = 1;
  _rotation.y = 180;
  if (_model.load(_modelName) == false) {
    std::cerr << "Cannot load the model: " << _modelName << std::endl;
    return (false);
  }
  return (true);
}

void	ObjModel::update(const gdl::Clock &clock, gdl::Input &input) {
  if (input.getKey(SDLK_UP))
    translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_DOWN))
    translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_LEFT))
    translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_RIGHT))
    translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);  
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _texture.bind();
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
