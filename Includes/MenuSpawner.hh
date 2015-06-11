//
// MenuSpawner.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun 10 21:09:06 2015 Alexander Saenen
// Last update Thu Jun 11 11:55:16 2015 Alexander Saenen
//

#ifndef MENUSPAWNER_HH_
# define MENUSPAWNER_HH_

# include <GameObject.hh>
# include <MenuModule.hh>
# include <Button.hh>
# include <map>
# include <list>

class	MenuSpawner
{
  std::map<MenuModule::MenuPage, std::string>	_buttonPositions;
  std::map<MenuModule::MenuPage, MenuModule::MenuPage>	_nextButton;
  std::map<MenuModule::MenuPage, MenuModule::MenuPage>	_prevButton;

public:
  MenuSpawner();
  ~MenuSpawner();

  GameObject	*createMenuPage(const std::string &, const MenuModule::MenuPage *, const size_t);
};

#endif /* MenuSpawner.hh */
