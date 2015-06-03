//
// Bomb.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 14:59:53 2015 Alexander Saenen
// Last update Wed Jun  3 17:36:50 2015 Alexander Saenen
//

#include "Bomb.hh"

Bomb::Bomb(const double timeBeforeIgnition, const bool hasExplosion)
  : ObjModel(), _timeBeforeIgnition(timeBeforeIgnition), _hasExplosion(hasExplosion) { }

Bomb::~Bomb() { }

void	Bomb::update(const gdl::Clock &clock, gdl::Input &) {
  if (_hasExplosion)
    _timeBeforeIgnition -= clock.getElapsed();
  if (_hasExplosion && _timeBeforeIgnition <= 0) {
    /* launch explosion event */
  }
}
