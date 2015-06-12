//
// Button.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 14:59:43 2015 Alexander Saenen
// Last update Fri Jun 12 14:18:59 2015 Alexander Saenen
//

#include <Button.hh>

Button::Button(const MenuModule::MenuPage linkedPage, const bool isSelected)
  : _isSelected(isSelected), _linkedPage(linkedPage), _buttonPressed(true), _cursor(0) {
  _actions[MenuModule::DEFAULT] = "Maps/default.map";
  _actions[MenuModule::PLAY] = "Maps/random.map";
  _actions[MenuModule::EXIT] = "Bomberman.quit";
}

Button::~Button() {
  delete _cursor;
}

void	Button::configure(const std::string &conf) {
  std::stringstream     *stream = new std::stringstream(conf);
  int                   type;

  *stream >> _position.x;
  *stream >> _position.z;
  *stream >> type;
  delete stream;
}

bool	Button::isSelected() const {
  return (_isSelected);
}

void	Button::select(const bool isSelected) {
  _isSelected = isSelected;
}

void	Button::activate() const {
  std::map<MenuModule::MenuPage, std::string>::const_iterator	it;

  it = _actions.find(_linkedPage);
  if (it != _actions.end()) {
    ModulesManager::getInstance()->get<MenuModule>()
      ->activatePage(MenuModule::HOME);
    std::string	event = (*it).second;
    if (event == "Bomberman.quit") {
      ModulesManager::getInstance()->get<EventModule>()
	->trigger(event)
	->handle();
      return ;
    }
    Loader	ld(event);
    ld.execute();
    ModulesManager::getInstance()->get<MenuModule>()
      ->toggle(false);
  }
  else
    ModulesManager::getInstance()->get<MenuModule>()
      ->activatePage(_linkedPage);
}

void	Button::initialize(Event *) { }

void	Button::update(const gdl::Clock &, gdl::Input &input) {
  if (_isSelected && input.getKey(SDLK_RETURN)) {
    if (!_buttonPressed) {
      _buttonPressed = true;
      activate();
    }
  }
  else
    _buttonPressed = false;
}

void	Button::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  if (_isSelected) {
    if (!_cursor) {
      _cursor = new Bomb(0, false);
      _cursor->initialize(0);
      std::stringstream	strm;
      strm << _position.x;
      strm << " ";
      strm << _position.z;
      strm << " 2 270 0 90 0.028 0.028 0.028 bomb";
      _cursor->configure(strm.str());
    }
    _cursor->draw(shader, clock);
  }
}
