//
// IA.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 17:48:36 2015 Alexander Saenen
// Last update Mon Jun  1 17:56:33 2015 Alexander Saenen
//

#ifndef IA_HH_
# define IA_HH_

# include <GameModule.hh>
# include <MapModule.hh>
# include <Player.hh>
# include <GameObject.hh>
# include <algorithm>

class	IA : public Player
{
private:
  class		Coor
  {
    int		x;
    int		y;
    int		type;
  };

  enum		Case
    {
      EMPTY,
      CUBE,
      CUBEDESTR,
    };

  enum		Action
    {
      UP,
      DOWN,
      RIGHT,
      LEFT,
      BOMB,
    };
  
private:
  GameModule		*_gameModule;
  MapModule		*_mapModule;
  //  Coor			_me;
  std::list<Coor>	_map;
  std::list<Coor>	_players;
  std::list<Coor>	_bombs;
  std::list<Coor>	_bonus;

public:
  IA();
  ~IA();

  void		_initialize();
  virtual void	update(const gdl::Clock &clock, gdl::Input &input);

private:
  int		_lookForPlayer(std::list<GameObject::ObjectType> &types);
  Coor		&_radar();
  Coor		&_checkBomb(Coor &);
  Coor		&_checkCase(Coor &);
};

#endif /* IA.hh */
