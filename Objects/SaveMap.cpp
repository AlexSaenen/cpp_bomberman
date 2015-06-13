//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sun Jun 14 00:43:02 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap()
{
  this->multiplayer = ModulesManager::getInstance()->get<MapModule>()->isMultiplayer();
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
std::cout << "Construction" << std::endl;
}

SaveMap::~SaveMap()
{
  std::cout << "Deconstruction" << std::endl;
}

void	SaveMap::execute()
{
  this->playerone = gr->getGObjects(GameObject::PLAYER1);
  if (this->multiplayer)
    this->playerone = gr->getGObjects(GameObject::PLAYER2);
  std::cout << ModulesManager::getInstance()->get<MapModule>()->getIA() << std::endl;
  std::cout << "je fonctionne" << std::endl;
}

