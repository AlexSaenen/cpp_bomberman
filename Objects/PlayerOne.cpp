//
// PlayerOne.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Mon Jun  1 16:52:14 2015 Alexander Saenen
//

#include <PlayerOne.hh>

PlayerOne::PlayerOne()
  : Player() {
  _movementMap.insert(std::pair<int, int>(SDLK_UP, 0));
  _movementMap.insert(std::pair<int, int>(SDLK_DOWN, 180));
  _movementMap.insert(std::pair<int, int>(SDLK_LEFT, 90));
  _movementMap.insert(std::pair<int, int>(SDLK_RIGHT, 270));
}

PlayerOne::~PlayerOne() { }
