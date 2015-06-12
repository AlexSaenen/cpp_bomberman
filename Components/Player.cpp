//
// Player.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 14:59:53 2015 Alexander Saenen
// Last update Thu Jun 11 20:13:37 2015 Alexander Saenen
//

#include "Player.hh"
#include "ModulesManager.hpp"

Player::Player()
  : ObjModel(), _isMoving(false), _animLocked(0), _lastMovement(0), _isInitialized(false) {
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _inventory[BOMB] = 1;
  _inventory[SPEED] = 10;
  _inventory[RANGE] = 2;
}

Player::~Player() { }

void	Player::_initialize() {
  playAnimation(0);
  _model.pause(true);
  _isInitialized = true;
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

      // Event	*ev = new Event("Music.play");
      // std::string	param("GraphicsLib/assets/MenuSamples/beepmenu2.mp3");
      // std::string	name("FILE");
      // std::string	music;
      // std::string	type;

      // ev->set<std::string>(name, param);
      // music = "MUSIC";
      // type = "TYPE";
      // ev->set<std::string>(type, music);
      // ModulesManager::getInstance()->get<EventModule>()
      // 	->trigger(ev)
      // 	->handle();

      hasTranslated = true;
      _rotation.y = _rotationMap[(*it).first];
      translate(_translationMap[(*it).first] * static_cast<float>(clock.getElapsed()) * _speed);
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
  _inventory[bt]++;
}