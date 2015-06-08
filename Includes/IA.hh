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

# include <Player.hh>

class	IA : public Player
{
private:
  class		Coor
  {
    int		_x;
    int		_y;
    int		_type;
  };
  
private:
  Coor			_me;
  std::list<Coor>	_map;
  std::list<Coor>	_players;
  std::list<Coor>	_bombs;
  std::list<Coor>	_bonus;

public:
  IA();
  ~IA();

  void		_initialize();
  virtual void	update(const gdl::Clock &clock, gdl::Input &input);
};

#endif /* IA.hh */
