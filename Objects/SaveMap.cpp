//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sun Jun 14 02:10:51 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap()
{
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
  this->isPlayerOne = gr->getGOStatus(GameObject::PLAYER1, this->playerOne);
  this->isPlayerTwo = gr->getGOStatus(GameObject::PLAYER2, this->playerTwo);
  this->isIa = gr->getGOStatus(GameObject::IA, this->ia);
  this->isCube = gr->getGOStatus(GameObject::CUBE, this->cube);
  this->isCubeDestr = gr->getGOStatus(GameObject::CUBEDESTR, this->cubeDestr);
  std::cout << "Construction" << std::endl;
}

SaveMap::~SaveMap()
{
  std::cout << "Deconstruction" << std::endl;
}

void	SaveMap::execute()
{
  std::list<IComponent *> comp;

  // std::cout << playerOne.back()->getType() << " " << playerOne.back()->getType() << std::endl;
  comp = playerOne.back()->getComponents();
  std::cout << "je fonctionne" << std::endl;
}

