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
# include <LuaLoader.hh>
# include <Bomb.hh>

class	IA : public Player
{
private:
  class		Coor
  {
  public:
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
  GameRoutine		*_gameRoutine;
  //  Coor			_me;
  std::list<Coor>	_map;
  std::list<Coor>	_players;
  std::list<Coor>	_bombs;
  std::list<Coor>	_bonus;
  LuaLoader		*_luaLoader;
  lua_State*		_luaVM;
  void			*_this;
  
public:
  Action		_ac;

public:
  IA();
  ~IA();

  void		_initialize();
  virtual void	update(const gdl::Clock &clock, gdl::Input &input);

private:
  int		_found(lua_State *ls, const int i, const int j, const int find);
  int		_lookForPlayer(std::list<GameObject::ObjectType> &types);
  int		_radar(lua_State *ls);
  int		_checkBomb(lua_State *ls);
  int		_checkCase(lua_State *ls);
  int		_command(lua_State *ls);
  int		_checkRange(int x, int y, std::vector<GameObject *> bombs);
  
public:
  static int	luaCall(lua_State *ls);
};

#endif /* IA.hh */
