//
// PlayerOne.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Sun Jun 14 06:03:11 2015 Alexander Saenen
//

#include <PlayerTwo.hh>

PlayerTwo::PlayerTwo()
  : Player() {
  _keyForBomb = SDLK_SPACE;
  _rotationMap.insert(std::pair<int, int>(SDLK_z, 0));
  _rotationMap.insert(std::pair<int, int>(SDLK_s, 180));
  _rotationMap.insert(std::pair<int, int>(SDLK_q, 90));
  _rotationMap.insert(std::pair<int, int>(SDLK_d, 270));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_z, glm::vec3(0, 0, 1)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_s, glm::vec3(0, 0, -1)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_q, glm::vec3(1, 0, 0)));
  _translationMap.insert(std::pair<int, glm::vec3>(SDLK_d, glm::vec3(-1, 0, 0)));
}

PlayerTwo::~PlayerTwo() { }
