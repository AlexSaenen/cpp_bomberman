//
// Button.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 14:47:34 2015 Alexander Saenen
// Last update Fri Jun 12 14:20:17 2015 Alexander Saenen
//

#ifndef BUTTON_HH_
# define BUTTON_HH_

# include <IComponent.hpp>
# include <MenuModule.hh>
# include <Loader.hh>

class	Button : public IComponent
{
  glm::vec3	_position;
  bool		_isSelected;
  MenuModule::MenuPage	_linkedPage;
  bool		_buttonPressed;
  std::map<MenuModule::MenuPage, std::string>	_actions;
  ObjModel	*_cursor;

public:
  Button(const MenuModule::MenuPage linkedPage, const bool isSelected = false);
  virtual ~Button();

  bool	isSelected() const;
  void	select(const bool isSelected);
  void	activate() const;

  virtual void	configure(const std::string &conf);
  virtual void	initialize(Event *);
  virtual void	update(const gdl::Clock &clock, gdl::Input &input);
  virtual void	draw(gdl::AShader &shader, const gdl::Clock &clock);
};

#endif /* Button.hh */
