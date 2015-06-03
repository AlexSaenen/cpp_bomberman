//
// Button.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 14:59:43 2015 Alexander Saenen
// Last update Wed Jun  3 18:32:57 2015 Alexander Saenen
//

#include <Button.hh>

Button::Button(const MenuModule::MenuPage linkedPage, const bool isSelected)
  : _isSelected(isSelected), _linkedPage(linkedPage) { }

Button::~Button() { }

void	Button::configure(const std::string &) { }

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
  if (input.getKey(SDLK_RETURN))
    activate();
}

void	Button::draw(gdl::AShader &, const gdl::Clock &) {
  /* if isSelected then draw a cursor next to it */
}
