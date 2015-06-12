//
// GameObject.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun 10 16:07:49 2015 Alexander Saenen
// Last update Fri Jun 12 14:44:44 2015 Thibaud PEAUGER
//

#include <GameObject.hh>
#include <Button.hh>

GameObject::GameObject(const ObjectType type, const std::string &name)
  : _type(type), _name(name), _hasPressed(true) { }

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

void	GameObject::pushComponent(IComponent *component) {
  _gameComponents.push_front(component);
  component->initialize(NULL);
}

void	GameObject::popComponent(IComponent *component) {
  _gameComponents.remove(component);
}

void	GameObject::update(const gdl::Clock &clock, gdl::Input &input) {
  if (_type != MENUPAGE || (!input.getKey(SDLK_UP) && !input.getKey(SDLK_DOWN))) {
    _hasPressed = false;
    for (std::list<IComponent *>::iterator it = _gameComponents.begin();
	 it != _gameComponents.end(); ++it) {
      (*it)->update(clock, input);
    }
  }
  else if (_type == MENUPAGE && !_hasPressed) {
    for (std::list<IComponent *>::iterator it = _gameComponents.begin();
	 it != _gameComponents.end(); ++it) {
      Button	*bt = static_cast<Button *>((*it));
      _hasPressed = true;
      if (bt && bt->isSelected()) {
	Event	*ev = new Event("Music.play");
	std::string	name("GraphicsLib/assets/MenuSamples/beepmenu2.mp3");
	std::string	music("MUSIC");
	ev->set<std::string>(std::string("FILE"), name);
	ev->set<std::string>(std::string("TYPE"), music);
	ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
	if (input.getKey(SDLK_UP)) {
	  std::advance(it, 2);
	  if (it != _gameComponents.end() && static_cast<Button *>(*it) != 0) {
	    std::advance(it, -1);
	    bt->select(false);
	    (static_cast<Button *>(*it))->select(true);
	    return ;
	  }
	  std::advance(it, -2);
	}
	if (input.getKey(SDLK_DOWN) && it != _gameComponents.begin()) {
	  std::advance(it, -1);
	  if (static_cast<Button *>(*it) != NULL) {
	    bt->select(false);
	    (static_cast<Button *>(*it))->select(true);
	    return ;
	  }
	  std::advance(it, 1);
	}
      }
    }
  }
}

void	GameObject::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  for (std::list<IComponent *>::iterator it = _gameComponents.begin(); it != _gameComponents.end(); ++it)
    (*it)->draw(shader, clock);
}

std::string	GameObject::getName() const {
  return (this->_name);
}

GameObject::ObjectType	GameObject::getType() const {
  return (_type);
}

std::list<IComponent *> GameObject::getComponents() const {
  return (_gameComponents);
}
