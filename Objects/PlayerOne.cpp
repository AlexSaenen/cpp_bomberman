//
// PlayerOne.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Tue Jun  2 17:17:28 2015 Alexander Saenen
//

#include <PlayerOne.hh>

PlayerOne::PlayerOne()
  : Player() {
  _rotationMap.insert(std::pair<int, int>(SDLK_UP, 0));
  _rotationMap.insert(std::pair<int, int>(SDLK_DOWN, 180));
  _rotationMap.insert(std::pair<int, int>(SDLK_LEFT, 90));
  _rotationMap.insert(std::pair<int, int>(SDLK_RIGHT, 270));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_UP, glm::vec3(0, 0, 1)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_DOWN, glm::vec3(0, 0, -1)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_LEFT, glm::vec3(1, 0, 0)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_RIGHT, glm::vec3(-1, 0, 0)));
}

PlayerOne::~PlayerOne() { }
