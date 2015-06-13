//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sun Jun 14 01:24:19 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap()
{
  this->multiplayer = ModulesManager::getInstance()->get<MapModule>()->isMultiplayer();
  this->isIa = ModulesManager::getInstance()->get<MapModule>()->getIA() > 0 ? true : false;
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
  this->playerone = gr->getGObjects(GameObject::PLAYER1);
  if (this->multiplayer)
    this->playertwo = gr->getGObjects(GameObject::PLAYER2);
  if (this->isIa)
    this->ia = gr->getGObjects(GameObject::IA);
  std::cout << "Construction" << std::endl;
}

SaveMap::~SaveMap()
{
  std::cout << "Deconstruction" << std::endl;
}

void	SaveMap::execute()
{
  std::cout << "je fonctionne" << std::endl;
}

