//
// Player.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 14:59:53 2015 Alexander Saenen
// Last update Fri May 29 17:15:31 2015 Alexander Saenen
//

#include "Player.hh"

Player::Player(const std::string &model, const GameObject::ObjectType type)
  : ObjModel(model, type), _isMoving(false), _animLocked(0), _lastMovement(0), _isInitialized(false) {
  _movementMap.insert(std::pair<int, int>(SDLK_UP, 0));
  _movementMap.insert(std::pair<int, int>(SDLK_DOWN, 180));
  _movementMap.insert(std::pair<int, int>(SDLK_LEFT, 90));
  _movementMap.insert(std::pair<int, int>(SDLK_RIGHT, 270));
}

Player::~Player() { }

void	Player::_initialize() {
  playAnimation(0);
  _model.pause(true);
  _isInitialized = true;
}

void	Player::update(const gdl::Clock &, gdl::Input &input) {
  if (!_isInitialized)
    _initialize();
  _lastMovement = 0;
  for (std::map<int, int>::const_iterator it = _movementMap.begin(); it != _movementMap.end(); ++it)
    if (input.getKey((*it).first)) {
      _rotation.y = _movementMap[(*it).first];
      if (!_isMoving) {
	_model.pause(false);
	_isMoving = true;
      }
      _lastMovement = (*it).first;
    }
  if (!_lastMovement) {
    _isMoving = false;
    _model.pause(true);
  }
}

void    Player::playAnimation(const std::string &animation, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set an Animation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentAnim(animation, loop)) {
    throw RuntimeException("Couldn't launch the animation : " + animation);
  }
}
 
void    Player::playAnimation(int stack, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set an Animation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentAnim(stack, loop)) {
    throw RuntimeException("Couldn't launch the animation");
  }
}
 
void    Player::playSubAnim(const std::string &subAnimation, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set a subAnimation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentSubAnim(subAnimation, loop)) {
    throw RuntimeException("Couldn't launch the subAnimation");
  }
}
