//
// Button.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 14:47:34 2015 Alexander Saenen
// Last update Sat Jun 13 12:08:25 2015 Alexander Saenen
//

#ifndef BUTTON_HH_
# define BUTTON_HH_

# include <IComponent.hpp>
# include <MenuModule.hh>
# include <Loader.hh>
# include <MusicModule.hh>

class	Button : public IComponent
{
  glm::vec3	_position;
  bool		_isSelected;
  MenuModule::MenuPage	_linkedPage;
  bool		_buttonPressed;
  std::map<MenuModule::MenuPage, std::string>	_actions;
  std::map<MenuModule::MenuPage, double>	_sliderValue;
  std::map<MenuModule::MenuPage, double>	_sliderDelta;
  std::map<MenuModule::MenuPage, void (MapModule::*)(const int)>	_mapSetters;
  std::map<MenuModule::MenuPage, void (MusicModule::*)(double const)>	_musicSetters;
  ObjModel	*_cursor;
  double	_value;

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

private:
  void	_writeSliderValue() const;
};

#endif /* Button.hh */
