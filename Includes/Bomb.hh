//
// Bomb.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 16:26:32 2015 Alexander Saenen
// Last update Wed Jun  3 17:34:27 2015 Alexander Saenen
//

#ifndef BOMB_HH_
# define BOMB_HH_

# include <ObjModel.hh>

class	Bomb : public ObjModel
{
  double	_timeBeforeIgnition;
  bool		_hasExplosion;

public:
  Bomb(const double timeBeforeIgnition, const bool hasExplosion = true);
  ~Bomb();

  virtual void	update(const gdl::Clock &clock, gdl::Input &input);
};

#endif /* Bomb.hh */
