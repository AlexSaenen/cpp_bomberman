//
// Player.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 16:26:32 2015 Alexander Saenen
// Last update Tue Jun  2 17:11:16 2015 Alexander Saenen
//

#ifndef PLAYER_HH_
# define PLAYER_HH_

# include <ObjModel.hh>
# include <GameModule.hh>

class	Player : public ObjModel
{
protected:
  enum  BonusType
    {
      BOMB,
      SPEED,
      RANGE,
    };
  
protected:
  GameModule	*_gameModule;
  bool		_isMoving;
  double	_animLocked;
  int		_lastMovement;
  bool		_isInitialized;
  std::map<int, int>		_rotationMap;
  std::map<int, glm::vec3>	_translationMap;
  std::map<BonusType, int>	_inventory;

protected:
  void	_initialize();

public:
  Player();
  ~Player();

  virtual void	update(const gdl::Clock &clock, gdl::Input &input);

  void  playAnimation(const std::string &animation, bool loop = true);
  void  playAnimation(int stack, bool loop = true);
  void  playSubAnim(const std::string &subAnimation, bool loop = true);

  int	getLevel(const BonusType&);
  void	incrLevel(const BonusType&);
};

#endif /* Player.hh */
