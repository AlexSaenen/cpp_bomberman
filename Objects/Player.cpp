//
// Player.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 14:59:53 2015 Alexander Saenen
// Last update Wed May 27 18:41:32 2015 Alexander Saenen
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
  // _model.createSubAnim(0, "Run.start", 0, 40);
  // _model.createSubAnim(0, "Run", 40, 60);
  // _model.createSubAnim(0, "Run.stop", 60, 140);
  _isInitialized = true;
}

void	Player::update(const gdl::Clock &, gdl::Input &) {
  // if (!_isInitialized)
  //   _initialize();
  // if (_lastMovement && !input.getKey(_lastMovement)) {
  //   playSubAnim("Run.stop", false);
  //   _lastMovement = 0;
  //   _isMoving = false;
  // }
  // for (std::map<int, int>::const_iterator it = _movementMap.begin(); it != _movementMap.end(); ++it)
  //   if (input.getKey((*it).first)) {
  //     _rotation.y = _movementMap[(*it).first];
  //     if (input.getKey((*it).first)) {
  // 	if (!_lastMovement) {
  // 	  playSubAnim("Run.start", false);
  //         _animLocked = 40 * _model.getFrameDuration();
  //       }
  //       else if (_animLocked <= 0 && !_isMoving) {
  //         playSubAnim("Run");
  //         _isMoving = true;
  //       }
  //       else
  //         _animLocked -= clock.getElapsed();
  //       _lastMovement = (*it).first;
  //     }
  //   }
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
