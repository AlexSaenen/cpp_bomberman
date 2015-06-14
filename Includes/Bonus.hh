#ifndef _BONUS_HH_
# define _BONUS_HH_

# include <algorithm>
# include <Player.hh>

class	Bonus : public ObjModel
{
public:
    enum  BonusType
      {
	BOMB,
	SPEED,
	RANGE,
      };

private:
  GameModule	*_gameModule;
  GameRoutine	*_gameRoutine;
  int		_x;
  int		_y;
  BonusType	_bt;
  gdl::Texture  *_texture;
  gdl::Geometry *_geometry;
  
public:
  explicit Bonus(BonusType &bt, const std::string &texturePath);
  ~Bonus();

  virtual void  update(const gdl::Clock &clock, gdl::Input &input);

private:
  Player  *_checkPlayer(std::vector<GameObject *> players);
};

#endif
