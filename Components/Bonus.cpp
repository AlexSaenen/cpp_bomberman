#include "Bonus.hh"

Bonus::Bonus(BonusType &bt, const std::string &texturePath) : _bt(bt) {
  Event *ev = new Event("Music.play");
  std::string name("GraphicsLib/assets/GameSounds/bonus1.mp3");
  std::string type("SOUND");
  ev->set<std::string>(std::string("FILE"), name);
  ev->set<std::string>(std::string("TYPE"), type);
  ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();

  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _gameRoutine = ModulesManager::getInstance()->get<GameRoutine>();
  _x = (_position.x / 2.5);
  _y = (_position.y / 2.5);
  _geometry = ModulesManager::getInstance()->get<TexturesModule>()
    ->getGeoInstance("Wall");
  _texture = ModulesManager::getInstance()->get<TexturesModule>()
    ->getTextInstance(texturePath);
  
}

Bonus::~Bonus() {
  Event *ev = new Event("Music.play");
  std::string name("GraphicsLib/assets/GameSounds/bonus2.mp3");
  std::string type("SOUND");
  ev->set<std::string>(std::string("FILE"), name);
  ev->set<std::string>(std::string("TYPE"), type);
  ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
}

void	Bonus::update(const gdl::Clock &, gdl::Input &) {
  std::list<GameObject::ObjectType> types;
  Player *player;
  
  types = _gameModule->getObject(_x, _y);
  if (find(types.begin(), types.end(), GameObject::PLAYER1) != types.end()
      || find(types.begin(), types.end(), GameObject::PLAYER2) != types.end()
      || find(types.begin(), types.end(), GameObject::IA) != types.end()) {
    if ((player = _checkPlayer(_gameRoutine->getGObjects(GameObject::PLAYER1))) != NULL)
      player->incrLevel(_bt);
    else if ((player = _checkPlayer(_gameRoutine->getGObjects(GameObject::PLAYER2))) != NULL)
      player->incrLevel(_bt);
    else if ((player = _checkPlayer(_gameRoutine->getGObjects(GameObject::IA))) != NULL)
      player->incrLevel(_bt);
  }
}

Player	*Bonus::_checkPlayer(std::vector<GameObject *> players) {
  std::list<IComponent *>               gameComponents;
  Player                                *player = NULL;
  double                                vx;
  double                                vy;
  try {
    for(std::vector<GameObject *>::iterator it = players.begin(); it != players.end(); it++) {
      gameComponents = (*it)->getComponents();
      for (std::list<IComponent *>::iterator it = gameComponents.begin(); it != gameComponents.end(); it++) {
	if ((player = dynamic_cast<Player *>(*it)) != NULL)
	  break;
	if (player == NULL)
	  throw LogicException("Player hasn't got a shape.");
	vx = player->getPosX();
	vy = player->getPosY();
	vx = vx / 2.5;
	vy = vy / 2.5;
	if ((int)vx == _x && (int)vy == _y)
	  return (player);
      }
    }
  }catch (LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Bonus.error", 1001)
      ->handle();
    return (NULL);
  }
  return (NULL);
}
