//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Thu Jun 11 20:29:59 2015 Alexander Saenen
//

#include <ObjModel.hh>
#include <GameObject.hh>
#include <MapModule.hh>

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
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _model.draw(shader, getTransformation(), clock.getElapsed());
}

void	ObjModel::configure(const std::string &conf) {
  std::stringstream     *stream = new std::stringstream(conf);
  int			type;
  std::string		model;

  *stream >> _position.x;
  *stream >> _position.z;
  *stream >> type;
  *stream >> _rotation.x;
  *stream >> _rotation.y;
  *stream >> _rotation.z;
  *stream >> _scale.x;
  *stream >> _scale.y;
  *stream >> _scale.z;
  *stream >> model;
  MapModule	*map = ModulesManager::getInstance()->get<MapModule>();
  if (!map->isLoaded())
    map->loadMapValues();
  configure(map->getTexturePath(model), static_cast<GameObject::ObjectType>(type));
  if (_model.load(_modelName) == false)
    throw ArgException("Cannot load the model : " + _modelName);
  _isLoaded = true;
  delete stream;
}
