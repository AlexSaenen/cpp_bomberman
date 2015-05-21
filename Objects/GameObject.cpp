//
// GameObject.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:20:59 2015 Alexander Saenen
// Last update Wed May 20 17:34:49 2015 Alexander Saenen
//

#include <GameObject.hh>

GameObject::GameObject(const ObjectType type, const std::string &name)
  : _type(type), _name(name) {
  
}

GameObject::~GameObject() {
  IComponent	*component;

  while (!_gameComponents.empty()) {
    component = _gameComponents.front();
    _gameComponents.pop_front();
    delete component;
  }
}

GameObject::GameObject(const GameObject &other) 
  : _gameComponents(other._gameComponents), _type(other._type), _name(other._name) { }

GameObject &GameObject::operator=(const GameObject &other) {
  if (this != &other) {
    _type = other._type;
    _name = other._name;
    _gameComponents = other._gameComponents;
  }
  return (*this);
}

#include <iostream>

void	GameObject::pushComponent(IComponent *component) {
  _gameComponents.push_front(component);
  component->initialize(NULL);
}

void	GameObject::popComponent(IComponent *component) {
  _gameComponents.remove(component);
}

void	GameObject::update(const gdl::Clock &clock, gdl::Input &input) {
  for (std::list<IComponent *>::iterator it = _gameComponents.begin();
       it != _gameComponents.end(); ++it) {
    (*it)->update(clock, input);
  }
}

void	GameObject::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _gameComponents.front()->draw(shader, clock);
}

std::string	GameObject::getName() const {
  return (this->_name);
}

GameObject::ObjectType	GameObject::getType() const {
  return (_type);
}

void	GameObject::handle() const { }
