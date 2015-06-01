//
// Player.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 16:26:32 2015 Alexander Saenen
// Last update Mon Jun  1 17:12:36 2015 Alexander Saenen
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <ObjModel.hh>

class	Player : public ObjModel
{
protected:
  bool		_isMoving;
  double	_animLocked;
  int		_lastMovement;
  bool		_isInitialized;
  std::map<int, int>	_movementMap;

private:
  void	_initialize();

public:
  Player();
  ~Player();

  virtual void	update(const gdl::Clock &clock, gdl::Input &input);

  void  playAnimation(const std::string &animation, bool loop = true);
  void  playAnimation(int stack, bool loop = true);
  void  playSubAnim(const std::string &subAnimation, bool loop = true);
};

#endif /* Player.hh */
