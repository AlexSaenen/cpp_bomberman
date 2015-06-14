#ifndef _BONUS_HH_
# define _BONUS_HH_

# include <algorithm>
# include <Player.hh>
# include <Shape.hh>

class	Bonus : public IComponent, public Shape
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
  double	 _speed;
  
public:
  explicit Bonus(BonusType &bt);
  ~Bonus();

  void	initialize(Event *);
  virtual void  update(const gdl::Clock &clock, gdl::Input &input);
  virtual void	configure(const std::string &);
  void	draw(gdl::AShader &shader, const gdl::Clock &);
private:
  Player  *_checkPlayer(std::vector<GameObject *> players);
};

#endif
