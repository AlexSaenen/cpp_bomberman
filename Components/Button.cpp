//
// Button.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 14:59:43 2015 Alexander Saenen
// Last update Thu Jun 11 17:44:49 2015 Alexander Saenen
//

#include <Button.hh>

Button::Button(const MenuModule::MenuPage linkedPage, const bool isSelected)
  : _isSelected(isSelected), _linkedPage(linkedPage), _buttonPressed(true), _cursor(0) { }

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
  ModulesManager::getInstance()->get<MenuModule>()
    ->activatePage(_linkedPage);
}

void	Button::initialize(Event *) { }

void	Button::update(const gdl::Clock &, gdl::Input &input) {
  if (input.getKey(SDLK_RETURN)) {
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
      strm << " 2 270 0 90 0.028 0.028 0.028";
      _cursor->configure(strm.str());
    }
    _cursor->draw(shader, clock);
  }
}
