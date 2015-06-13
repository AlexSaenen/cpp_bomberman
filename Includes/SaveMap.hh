//
// SaveMap.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:05:28 2015 Vividy
// Last update Sun Jun 14 00:30:42 2015 Vividy
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
