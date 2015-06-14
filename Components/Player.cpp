//
// Player.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Sat Jun 13 22:39:18 2015 Alexander Saenen
// Last update Sun Jun 14 04:00:20 2015 Alexander Saenen
//

#include "Player.hh"
#include "ModulesManager.hpp"

Player::Player()
  : ObjModel(), _isMoving(false), _animLocked(0), _lastMovement(0), _isInitialized(false) {
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _inventory[BOMB] = 1;
  _inventory[SPEED] = 10;
  _inventory[RANGE] = 2;
  _limit[BOMB] = 11;
  _limit[SPEED] = 20;
  _limit[RANGE] = 12;
}

Player::~Player() { }

void	Player::_initialize() {
  playAnimation(0);
  _model.pause(true);
  _isInitialized = true;
}

void	Player::_tryMoveCollision(const gdl::Clock &clock, const glm::vec3 &pos) {
  glm::vec3	destination = _position;
  glm::vec3	trip = pos;
  trip = trip * static_cast<float>(clock.getElapsed()) * _speed;
  trip.x += 1.15;
  trip.z += 1.15;
  trip.x = trip.x > 2.5 ? 2.4 : trip.x; 
  trip.x = trip.x < -2.5 ? -2.4 : trip.x; 
  trip.y = trip.x > 2.5 ? 2.4 : trip.x; 
  trip.y = trip.x < -2.5 ? -2.4 : trip.x; 
  destination += trip;
  if (pos.z > 0)
    destination.z += 2.5;
  int	x = destination.x / 2.5;
  int	y = destination.z / 2.5;
  std::list<GameObject::ObjectType> types = _gameModule->getObject(x, y);
  for (std::list<GameObject::ObjectType>::iterator it = types.begin(); it != types.end(); ++it)
    if ((*it) <= GameObject::CUBEDESTR)
      return ;
  translate(pos * static_cast<float>(clock.getElapsed()) * _speed);
}

void	Player::update(const gdl::Clock &clock, gdl::Input &input) {
  bool	hasTranslated = false;

  if (!_isInitialized)
    _initialize();
  _gameModule->popOnMap(_position.x, _position.y, _type);
  _lastMovement = 0;
  for (std::map<int, int>::const_iterator it = _rotationMap.begin();
       it != _rotationMap.end() && !hasTranslated; ++it)
    if (input.getKey((*it).first)) {
      hasTranslated = true;
      _rotation.y = _rotationMap[(*it).first];
      _tryMoveCollision(clock, _translationMap[(*it).first]);
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
  _gameModule->pushOnMap(_position.x, _position.y, _type);
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

int	Player::getLevel(const BonusType &bt) {
  return (_inventory[bt]);
}

void	Player::incrLevel(const BonusType &bt) {
  if (_inventory[bt] < _limit[bt])
    _inventory[bt]++;
}
