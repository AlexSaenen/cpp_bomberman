//
// GameOver.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sun Jun 14 05:43:48 2015 Vividy
// Last update Sun Jun 14 21:05:17 2015 Alexander Saenen
//

#include "GameOver.hh"

GameOver::GameOver() : isPlayerOne(true), isPlayerTwo(true), isIa(true) {
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
}

GameOver::~GameOver() { }

void	GameOver::execute(Event *) {
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
	std::cout << "The Artificial Intelligence Won !!" << std::endl;
      else
	std::cout << "Player " << ((isPlayerOne) ? "One" : "Two") << " is the Winner!!" << std::endl;
      Event *ev = new Event("Bomberman.quit", 1002);
      ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
    }
}
