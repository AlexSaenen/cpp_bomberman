//
// GameObject.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:06:51 2015 Alexander Saenen
// Last update Thu Jun 11 17:23:42 2015 Alexander Saenen
//

#ifndef GAMEOBJECT_HH_
# define GAMEOBJECT_HH_

# include <SdlContext.hh>
# include <IComponent.hpp>

class	GameObject
{
public:
  enum	ObjectType
    {
      CUBE,
      CUBEDESTR,
      BOMB,
      PLAYER1,
      PLAYER2,
      IA,
      BONUS,
      INTRO,
      MENUPAGE,
      GAMEWIN,
      GAMEOVER
    };

private:
  std::list<IComponent *>	_gameComponents;
  ObjectType			_type;
  std::string			_name;
  bool				_hasPressed;

public:
  GameObject(const ObjectType type, const std::string &name);
  ~GameObject();
  GameObject(const GameObject &other);

  GameObject &operator=(const GameObject &other);
  void	pushComponent(IComponent *);
  void	popComponent(IComponent *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
  std::string	getName() const;
  ObjectType	getType() const;
  std::list<IComponent *>	getComponents() const;
};

#endif /* GameObject.hh */
