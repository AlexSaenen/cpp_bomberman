//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Thu May 28 11:01:31 2015 Alexander Saenen
//

#include <ObjModel.hh>
#include <GameObject.hh>

#include <Input.hh>

ObjModel::ObjModel(const std::string &model, const GameObject::ObjectType type)
  : _modelName(model), _isLoaded(false), _type(type) { }

ObjModel::~ObjModel() { }

void	ObjModel::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 0.004;
  _scale.y = 0.004;
  _scale.z = 0.004;
  if (_model.load(_modelName) == false) {
    throw ArgException("Cannot load the model : " + _modelName);
  }
  _isLoaded = true;
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
