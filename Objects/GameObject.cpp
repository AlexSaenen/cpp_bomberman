//
// GameObject.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:20:59 2015 Alexander Saenen
// Last update Tue May 12 11:18:36 2015 Alexander Saenen
//

#include <GameObject.hh>

GameObject::GameObject(const ObjectType type, const std::string &name)
  : _type(type), _name(name) {
  
}

GameObject::~GameObject() {
  IComposant	*composant;

  while (!_gameComponents.empty()) {
    composant = _gameComponents.front();
    _gameComponents.pop_front();
    delete composant;
  }
}

bool	GameObject::pushComponent(IComposant *composant) {
  _gameComponents.push_front(composant);
  return (composant->initialize(NULL));
}

void	GameObject::popComponent(IComposant *composant) {
  _gameComponents.remove(composant);
}

void	GameObject::update(const gdl::Clock &clock, gdl::Input &input) {
  for (std::list<IComposant *>::iterator it = _gameComponents.begin();
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

void	GameObject::handle() const { }
