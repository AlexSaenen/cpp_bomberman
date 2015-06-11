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
  _gameRoutine = ModulesManager::getInstance()->get<GameRoutine>();
  _model.createSubAnim(0, "Run", 0, 30);
  playSubAnim("Run");
  _model.pause(true);
  _isInitialized = true;
}

void	IA::update(const gdl::Clock &, gdl::Input &) {
  if (!_isInitialized)
    _initialize();
  _gameModule->popOnMap(_position.x, _position.y, _type);
  // _lastMovement = 0;
  // for (std::map<int, int>::const_iterator it = _rotationMap.begin();
  //      it != _rotationMap.end() && !hasTranslated; ++it)
  //   if (input.getKey((*it).first)) {
  //     hasTranslated = true;
  //     _rotation.y = _rotationMap[(*it).first];
  //     translate(_translationMap[(*it).first] * static_cast<float>(clock.getElapsed()) * _speed);
  //     if (!_isMoving) {
  // 	_model.pause(false);
  // 	_isMoving = true;
  //     }
  //     _lastMovement = (*it).first;
  //   }
  // if (!_lastMovement) {
  //   _isMoving = false;
  //   _model.pause(true);
  // }
  _gameModule->pushOnMap(_position.x, _position.y, _type);
}

int	IA::_lookForPlayer(std::list<GameObject::ObjectType> &types)
{
  if (find(types.begin(), types.end(), GameObject::PLAYER1) != types.end() || find(types.begin(), types.end(), GameObject::PLAYER1) != types.end() || find(types.begin(), types.end(), GameObject::PLAYER1) != types.end())
    return (1);
  return (0);
}

IA::Coor			IA::_radar(IA::Coor &) {
  IA::Coor			result;
  // std::vector<GameObject *>	players;
  // int				min;
  int				i;
  int				j;
  int				incr;
  int				find = 0;
  // players = _gameRoutine->getGObjects(static_cast<GameObject::ObjectType>(5));
  // players.push_back(_gameRoutine->getGObjects(static_cast<GameObject::ObjectType>(3)).front());
  // players.push_back(_gameRoutine->getGObjects(static_cast<GameObject::ObjectType>(4)).front());

  // min = *(players.begin());
  //   for(std::vector<GameObject *>::iterator it = players.begin() ; it != players.end(); ++it)
  //     {
  // 	// if (
  //     }

  i = _position.x;
  j = _position.y;
  incr = 1;
  while(find == 0) {
    if (incr % 2 == 1) {
      for(int a = 0; a < incr; a++) {
	i++;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
      for(int a = 0; a < incr; a++) {
	j--;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
    } else {
      for(int a = 0; a < incr; a++) {
	i--;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
      for(int a = 0; a < incr; a++) {
	j++;
	find = _lookForPlayer(_gameModule->getObject(i, j));
      }
    }
    incr++;
  }  
  return (result);
}
