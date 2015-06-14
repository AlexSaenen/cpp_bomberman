//
// Player.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Sat Jun 13 22:39:18 2015 Alexander Saenen
// Last update Sun Jun 14 10:58:48 2015 Alexander Saenen
//

#include "Player.hh"
#include "ModulesManager.hpp"

Player::Player()
  : ObjModel(), _isMoving(false), _animLocked(0), _lastMovement(0), _isInitialized(false), _keyForBomb(0) {
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _mapModule = ModulesManager::getInstance()->get<MapModule>();
  _inventory[BOMB] = 1;
  _inventory[SPEED] = 10;
  _inventory[RANGE] = 2;
  _limit[BOMB] = 11;
  _limit[SPEED] = 20;
  _limit[RANGE] = 12;
  _hasBombed = 0;
}

Player::~Player() { }

void	Player::_initialize() {
  playAnimation(0);
  _model.pause(true);
  _isInitialized = true;
}

void	Player::_tryMoveCollision(const gdl::Clock &clock, const glm::vec3 &pos) {
  glm::vec3	trip = pos;
  float		elapsed = static_cast<float>(clock.getElapsed());
  int		size = _mapModule->getSize();
  trip = trip * elapsed * _speed;
  trip.x += 1.15;
  trip.z += 1.15;
  trip.x = trip.x > 2.5 ? 2.3 : trip.x; 
  trip.x = trip.x < -2.5 ? -2.3 : trip.x; 
  trip.z = trip.z > 2.5 ? 2.4 : trip.z; 
  trip.z = trip.z < -2.5 ? -2.4 : trip.z; 
  trip += _position;
  if (pos.z > 0)
    trip.z += 2.5;
  int	x = trip.x / 2.5;
  int	y = trip.z / 2.5;
  if ((pos.x != 0 && ((trip.x - 0.1) / 2.5 < 0 || (trip.x + 0.65) / 2.5 > size)) || y < 0 || y  > size)
    return ;
  std::list<GameObject::ObjectType> types = _gameModule->getObject(x, y);
  for (std::list<GameObject::ObjectType>::iterator it = types.begin(); it != types.end(); ++it)
    if ((*it) <= GameObject::CUBEDESTR) {
      if (pos.z > 0) {
	trip.x = pos.x;
	trip.z = ((y - 1) * 2.5) - _position.z;
	_gameModule->popOnMap(_position.x, _position.y, _type);
	translate(trip * elapsed * _speed);
	_gameModule->pushOnMap(_position.x, _position.y, _type);
      }
      return ;
    }
  _gameModule->popOnMap(_position.x, _position.y, _type);
  translate(pos * elapsed * _speed);
  _gameModule->pushOnMap(_position.x, _position.y, _type);
}

void	Player::update(const gdl::Clock &clock, gdl::Input &input) {
  bool	hasTranslated = false;

  if (!_isInitialized)
    _initialize();
  _speed = _inventory[SPEED];
  _lastMovement = 0;
  if (input.getKey(_keyForBomb) && _hasBombed <= 0) {
    GameObject	*model = new GameObject(GameObject::BOMB, "bomb");
    ObjModel	*bomb = new Bomb(2.5, _inventory[RANGE]);
    _hasBombed = 3;
    bomb->initialize(0);
    std::stringstream strm;
    strm << _position.x << " " << _position.z << " 2 0 180 0 0.4 0.4 0.4 bomb";
    bomb->configure(strm.str());
    model->pushComponent(bomb);
    _gameModule->handle(model);
  }
  else if (!input.getKey(_keyForBomb))
    _hasBombed -= clock.getElapsed();
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
