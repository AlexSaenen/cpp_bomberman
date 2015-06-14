#include "Bonus.hh"

Bonus::Bonus(BonusType &bt) : _bt(bt) {
  Event *ev = new Event("Music.play");
  std::string name("GraphicsLib/assets/GameSounds/bonus1.mp3");
  std::string type("SOUND");
  ev->set<std::string>(std::string("FILE"), name);
  ev->set<std::string>(std::string("TYPE"), type);
  ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
  _gameModule = ModulesManager::getInstance()->get<GameModule>();
  _gameRoutine = ModulesManager::getInstance()->get<GameRoutine>();
  std::map<BonusType, std::string>	_textureMap;
  _textureMap[SPEED] = "bonus1";
  _textureMap[RANGE] = "bonus2";
  _textureMap[BOMB] = "bonus0";
}

Bonus::~Bonus() { }

void	Bonus::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 2.5;
  _scale.y = 2.5;
  _scale.z = 2.5;
  _position.y = 1.2;
  _geometry = ModulesManager::getInstance()->get<TexturesModule>()
    ->getGeoInstance("Cube");
}

void	Bonus::configure(const std::string &conf) {
  std::stringstream     stream(conf);
  int			type;

  stream >> _position.x;
  stream >> _position.z;
  stream >> type;
  stream.str("");
  stream.clear();
  stream << "bonus" << type;
  _x = _position.x / 2.5;
  _y = _position.z / 2.5;
  MapModule	*map = ModulesManager::getInstance()->get<MapModule>();
  if (!map->isLoaded())
    map->loadMapValues();
  std::string	texturePath = ModulesManager::getInstance()->get<MapModule>()
    ->getTexturePath(stream.str());
  _texture = ModulesManager::getInstance()->get<TexturesModule>()
    ->getTextInstance(texturePath);
}

void	Bonus::update(const gdl::Clock &, gdl::Input &) {
  std::list<GameObject::ObjectType> types;
  Player *player;

  types = _gameModule->getObject(_x, _y);
  if (!_gameModule->tryGetObject(_x, _y, types))
    return ;
  if (find(types.begin(), types.end(), GameObject::PLAYER1) != types.end()
      || find(types.begin(), types.end(), GameObject::PLAYER2) != types.end()
      || find(types.begin(), types.end(), GameObject::IA) != types.end()) {
    std::vector<GameObject *>	objects;
    if (_gameRoutine->getGOStatus(GameObject::PLAYER1, objects) && (player = _checkPlayer(objects)) != NULL)
      player->incrLevel(_bt);
    else if (_gameRoutine->getGOStatus(GameObject::PLAYER2, objects) && (player = _checkPlayer(objects)) != NULL)
      player->incrLevel(_bt);
    else {
      if (_gameRoutine->getGOStatus(GameObject::IA, objects)) {
	player = _checkPlayer(_gameRoutine->getGObjects(GameObject::IA));
	if (player)
	  player->incrLevel(_bt);
      }
    }
    std::vector<GameObject *> bonus = _gameRoutine->getGObjects(GameObject::BONUS);
    GameObject	*model;
    Bonus	*bon;
    for (std::vector<GameObject *>::iterator it = bonus.begin(); it != bonus.end(); ++it) {
      model = (*it);
      std::list<IComponent *> comp = model->getComponents();
      bon = dynamic_cast<Bonus *>(comp.front());
      if (bon == this) {
  	_gameModule->markForCleanup(model);
  	break;
      }
    }
  }
}

void	Bonus::draw(gdl::AShader &shader, const gdl::Clock &) {
  _texture->bind();
  _geometry->draw(shader, getTransformation(), GL_QUADS);
}

Player	*Bonus::_checkPlayer(std::vector<GameObject *> const players) {
  std::list<IComponent *>               gameComponents;
  Player                                *player = NULL;
  int                                vx;
  int                                vy;

  try {
    for(std::vector<GameObject *>::const_iterator it = players.begin(); it != players.end(); it++) {
      gameComponents = (*it)->getComponents();
      for (std::list<IComponent *>::iterator it = gameComponents.begin(); it != gameComponents.end(); it++) {
	if ((player = dynamic_cast<Player *>(*it)) != NULL)
	  break;
      }
      if (player == NULL)
	throw LogicException("Player hasn't got a shape.");
      vx = player->getPosX() / 2.5;
      vy = player->getPosY() / 2.5;
      if (vx == _x && vy == _y)
	return (player);
    }
  }catch (LogicException e) {
    std::cerr<< e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1001)
      ->handle();
    return (NULL);
  }
  return (NULL);
}
