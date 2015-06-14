//
// GameOver.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sun Jun 14 05:43:48 2015 Vividy
// Last update Sun Jun 14 06:15:29 2015 Vividy
//

#include "GameOver.hh"

GameOver::GameOver() {
  this->ev = new Event("Bomberman.quit");

  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
  std::cout << "Handle victory" << std::endl;
}

GameOver::~GameOver()
{
  std::cout << "endvictory" << std::endl;
}

void	GameOver::execute(Event *)
{
  std::vector<GameObject *>     Mem;

  if (isPlayerOne)
    this->isPlayerOne = gr->getGOStatus(GameObject::PLAYER1, Mem);
  if (isPlayerTwo)
    this->isPlayerTwo = gr->getGOStatus(GameObject::PLAYER2, Mem);
  if (isIa)
    this->isIa = gr->getGOStatus(GameObject::IA, Mem);
  if (isPlayerOne ^ isPlayerTwo ^ isIa)
    {
      if (isIa)
	std::cout << "ia won!!" << std::endl;
      else
	std::cout << "Player " << ((isPlayerOne) ? "One" : "Two") << " is the Winner!!" << std::endl;
      ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
    }
  std::cout << "executevictory" << std::endl;
}

