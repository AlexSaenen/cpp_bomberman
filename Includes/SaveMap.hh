//
// SaveMap.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:05:28 2015 Vividy
// Last update Sun Jun 14 01:06:01 2015 Vividy
//

#ifndef SAVEMAP_HH_
# define SAVEMAP_HH_

#include <iostream>
#include "ModulesManager.hpp"
#include "MapModule.hh"
#include "GameRoutine.hh"

class	GameRoutine;

class	SaveMap
{
private:
  GameRoutine			*gr;
  bool				multiplayer;
  bool				isIa;
  std::vector<GameObject *>	playerone;
  std::vector<GameObject *>	playertwo;
  std::vector<GameObject *>	ia;
public:
  SaveMap();
  ~SaveMap();
public:
  void	execute();
};

#endif //!SAVEMAP_HH_
