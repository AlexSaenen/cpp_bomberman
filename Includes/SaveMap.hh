//
// SaveMap.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:05:28 2015 Vividy
// Last update Sun Jun 14 16:44:33 2015 Vividy
//

#ifndef SAVEMAP_HH_
# define SAVEMAP_HH_

#include <time.h>
#include <iostream>
#include "ModulesManager.hpp"
#include "MapModule.hh"
#include "GameRoutine.hh"
#include "GameObject.hh"
#include "ObjModel.hh"

class	GameRoutine;
class	MapModule;

class	SaveMap
{
private:
  std::ostream  *is;
  std::filebuf  *file;
  std::map<std::string, std::string>	_modelType;
  std::map<GameObject::ObjectType, bool>	_isType;
  std::map<GameObject::ObjectType, void (SaveMap::*)()>        _pushType;
  std::stringstream string;
  GameRoutine			*gr;
  MapModule			*mm;
  std::vector<GameObject *>	playerOne;
  std::vector<GameObject *>	playerTwo;
  std::vector<GameObject *>	ia;
  std::vector<GameObject *>	cube;
  std::vector<GameObject *>	cubeDestr;
public:
  SaveMap();
  ~SaveMap();
public:
  void	execute();
private:
  void	pushCube();
  void	pushCubeDestr();
  void	pushIa();
  void	pushPlayerOne();
  void	pushPlayerTwo();
};

#endif //!SAVEMAP_HH_
