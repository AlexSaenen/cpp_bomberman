//
// IA.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Jun  1 16:19:45 2015 Alexander Saenen
// Last update Tue Jun  2 17:53:06 2015 Alexander Saenen
//

#include <IA.hh>

IA::IA()
  : Player() { }

IA::~IA() { }

void	IA::_initialize() {
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _model.createSubAnim(0, "Run", 0, 30);
  playSubAnim("Run");
  _model.pause(true);
  _isInitialized = true;
}

void	IA::update(const gdl::Clock &, gdl::Input &) {
  if (!_isInitialized)
    _initialize();

  
}

IA::Coor	IA::_radar() {
  return (IA::Coor());
}
