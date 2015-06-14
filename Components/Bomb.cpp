//
// Bomb.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 14:59:53 2015 Alexander Saenen
// Last update Sun Jun 14 08:41:37 2015 Alexander Saenen
//

#include "Bomb.hh"
#include "ModulesManager.hpp"
#include "GameModule.hh"
#include <sstream>

Bomb::Bomb(const double timeBeforeIgnition, const int range, const bool hasExplosion)
  : ObjModel(), _timeBeforeIgnition(timeBeforeIgnition), _range(range), _hasExplosion(hasExplosion), _hasExploded(false) { }

Bomb::~Bomb() { }

void	Bomb::update(const gdl::Clock &clock, gdl::Input &) {
  if (_hasExplosion) {
    _timeBeforeIgnition -= clock.getElapsed();
    if (_timeBeforeIgnition <= 0 && !_hasExploded) {
      Event	*ev = new Event("Bomb.explosion", 900);
      std::stringstream	*strm = new std::stringstream;
      *strm << _position.x << " " << _position.z;
      std::string	argName("Position");
      std::string	argument(strm->str());
      ev->set<std::string>(argName, argument);
      _hasExploded = true;
      ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
    }
  }
}

bool	Bomb::hasExploded() const {
  return (_hasExploded);
}

int	Bomb::getRange() const {
  return (_range);
}
