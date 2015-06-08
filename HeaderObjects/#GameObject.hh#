//
// GameObject.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:06:51 2015 Alexander Saenen
// Last update Tue May 12 11:11:06 2015 Alexander Saenen
//

#ifndef GAMEOBJECT_HH_
# define GAMEOBJECT_HH_

# include <SdlContext.hh>
# include <IComposant.hpp>

enum	ObjectType
  {
    CUBE,
    CUBEDESTR,
    BOMB,
    ANIM,
    PLAYER1,
    PLAYER2,
    IA,
    INTRO,
    MENU,
    GAMEWIN,
    GAMEOVER
  };

class	GameObject
{
  std::list<IComposant *>	_gameComponents;
  ObjectType			_type;
  std::string			_name;

public:
  GameObject(const ObjectType type, const std::string &name);
  ~GameObject();

  bool	pushComponent(IComposant *);
  void	popComponent(IComposant *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
  std::string	getName() const;
  void	handle() const; /* Unknown use yet */
};

#endif /* GameObject.hh */
