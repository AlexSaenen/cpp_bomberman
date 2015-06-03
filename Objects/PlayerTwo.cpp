//
// PlayerOne.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Mon Jun  1 17:11:48 2015 Alexander Saenen
//

#include <PlayerTwo.hh>

PlayerTwo::PlayerTwo()
  : Player() {
  _movementMap.insert(std::pair<int, int>(SDLK_z, 0));
  _movementMap.insert(std::pair<int, int>(SDLK_s, 180));
  _movementMap.insert(std::pair<int, int>(SDLK_q, 90));
  _movementMap.insert(std::pair<int, int>(SDLK_d, 270));
}

PlayerTwo::~PlayerTwo() { }
