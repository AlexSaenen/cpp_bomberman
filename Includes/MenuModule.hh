//
// MenuModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Wed Jun  3 17:46:52 2015 Alexander Saenen
//

#ifndef MENUMODULE_HH_
# define MENUMODULE_HH_

# include <AModule.hh>
# include <GameObject.hh>
# include <ModulesManager.hpp>
# include <LogicException.hh>
# include <ArgException.hh>
# include <iostream>
# include <RuntimeException.hh>
# include <map>

class	MenuModule : public AModule
{
public:
  enum	MenuPage {
    HOME,
    NEW,
    CONTINUE,
    OPTIONS,
    CONTROLS,
    SCORE,
    EXIT
  };

private:
  std::map<MenuPage, GameObject *>	_pages;
  bool					_isActive;
  GameObject				*_activePage;
  
private:
  void	_update(Event *);
  void	_draw(Event *);

public:
  MenuModule();
  virtual ~MenuModule();

  void	initialize(Event *);
  void	toggle(const bool status);
  void	activatePage(const MenuPage page);
  bool	isActive() const;
};

#endif /* MenuModule.hh */
