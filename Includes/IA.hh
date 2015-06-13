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

extern "C"
{
# include <lua.h>
# include <lauxlib.h>
# include <lualib.h>
}

# define SCRIPT "Script/ia.lua"

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
  //  Coor			_me;
  std::list<Coor>	_map;
  std::list<Coor>	_players;
  std::list<Coor>	_bombs;
  std::list<Coor>	_bonus;
  lua_State*		_luaVM;
public:
  Action		_ac;

public:
  IA();
  ~IA();

  void		_initialize();
  virtual void	update(const gdl::Clock &clock, gdl::Input &input);

private:
  int		_lookForPlayer(std::list<GameObject::ObjectType> &types);
  void		_radar(lua_State *ls);
  void		_checkBomb(lua_State *ls);
  void		_checkCase(lua_State *ls);
  int		_command(lua_State *ls);

public:
  static int	luaCall(lua_State *ls);
};

#endif /* IA.hh */
