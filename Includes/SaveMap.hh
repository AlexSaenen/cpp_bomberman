//
// SaveMap.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:05:28 2015 Vividy
// Last update Sun Jun 14 03:05:23 2015 Vividy
//

#ifndef SAVEMAP_HH_
# define SAVEMAP_HH_

#include <iostream>
#include "ModulesManager.hpp"
#include "MapModule.hh"
#include "GameRoutine.hh"
#include "GameObject.hh"
#include "ObjModel.hh"

class	GameRoutine;

class	SaveMap
{
private:
  std::ostream  *is;
  std::filebuf  *file;
  std::map<std::string, std::string>	_modelType;
  GameRoutine			*gr;
  std::vector<GameObject *>	playerOne;
  bool				isPlayerOne;
  std::vector<GameObject *>	playerTwo;
  bool				isPlayerTwo;
  std::vector<GameObject *>	ia;
  bool				isIa;
  std::vector<GameObject *>	cube;
  bool				isCube;
  std::vector<GameObject *>	cubeDestr;
  bool				isCubeDestr;
public:
  SaveMap();
  ~SaveMap();
public:
  void	execute();
};

#endif //!SAVEMAP_HH_
