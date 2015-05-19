//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Tue May 19 10:36:09 2015 Alexander Saenen
//

#include <ObjModel.hh>
#include <GameObject.hh>

ObjModel::ObjModel(const std::string &model, const GameObject::ObjectType type)
  : _modelName(model), _type(type) { }

ObjModel::~ObjModel() { }

void	ObjModel::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 0.01;
  _scale.y = 0.01;
  _scale.z = 0.01;
  _rotation.y = 180;
  if (_model.load(_modelName) == false) {
    throw ArgException("Cannot load the model : " + _modelName);
  }
}

void	ObjModel::update(const gdl::Clock &clock, gdl::Input &input) {
  if (_type != GameObject::PLAYER2) {
    if (input.getKey(SDLK_UP))
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_DOWN))
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_LEFT))
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_RIGHT))
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  }
  if (_type != GameObject::PLAYER1) {
    if (input.getKey(SDLK_z))
      translate(glm::vec3(0, 0, 1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_s))
      translate(glm::vec3(0, 0, -1) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_q))
      translate(glm::vec3(1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
    if (input.getKey(SDLK_d))
      translate(glm::vec3(-1, 0, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  }
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
