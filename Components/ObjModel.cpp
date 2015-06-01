//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Mon Jun  1 17:12:19 2015 Alexander Saenen
//

#include <ObjModel.hh>
#include <GameObject.hh>

#include <Input.hh>

ObjModel::ObjModel()
  : _isLoaded(false) { }

ObjModel::~ObjModel() { }

void	ObjModel::configure(const std::string &model, const GameObject::ObjectType type) {
  _type = type;
  _modelName = model;
}

void	ObjModel::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 0.04;
  _scale.y = 0.04;
  _scale.z = 0.04;
  if (_model.load(_modelName) == false) {
    throw ArgException("Cannot load the model : " + _modelName);
  }
  _isLoaded = true;
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
