//
// Loader.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 15:03:33 2015 Alexander Saenen
// Last update Fri Jun 12 13:43:12 2015 Alexander Saenen
//

#include "Loader.hh"

Loader::Loader() {
  try {
    _file = new std::filebuf();
    if (_file->open("test.conf", std::ios::in))
      _is = new std::istream(_file);
    else
      throw ArgException("Cannot open the file : test.conf");
    _constructor["Cube"] = &ComponentFactory::getComponent<Cube>;
    _constructor["PlayerOne"] = &ComponentFactory::getComponent<PlayerOne>;
  } catch (ArgException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Loader.error", 1001)
      ->handle();
  }
}

Loader::~Loader() {
  delete _is;
  delete _file;
}

void	Loader::loadTexture(IComponent *component, const GameObject *go) const {
  std::string	texturePath;
  if (go->getType() == GameObject::CUBE)
    texturePath = ModulesManager::getInstance()->get<MapModule>()->getTexturePath("cube");
  else if (go->getType() == GameObject::CUBEDESTR)
    texturePath = ModulesManager::getInstance()->get<MapModule>()->getTexturePath("destroy");
  else
    return ;
  reinterpret_cast<Cube *>(component)->setTexture(texturePath);
}

void	Loader::execute(Event *) {
  std::list<GameObject *>	objectList;
  std::string			buff;
  std::string                   args;
  std::string			name;
  int				type;
  GameObject			*go;
  std::istringstream		*content;
  GameModule			*gameModule;
  IComponent			*component;
  ModulesManager		*modulesManager;
  ComponentFactory		*factory;

  modulesManager = ModulesManager::getInstance();
  modulesManager->get<MapModule>()
    ->loadMapValues();
  factory = modulesManager->get<ComponentFactory>();
  gameModule = modulesManager->get<GameModule>();
  while (!_is->eof() && std::getline(*_is, buff, '@')) {
    content = new std::istringstream(buff);
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    std::istringstream *verif = new std::istringstream(buff);
    *verif >> type;
    go = new GameObject(static_cast<GameObject::ObjectType>(type), name);
    while (std::getline(*content, buff, '$') && buff == "")
      {
	std::getline(*content, buff, '%');
	component = (factory->*_constructor[buff])();
	std::getline(*content, args, '\n');
	component->initialize(NULL);
	if (args != "")
	  component->configure(args);
	if (buff == "Cube")
	  loadTexture(component, go);
	go->pushComponent(component);
      }
    gameModule->handle(go);
    std::getline(*content, buff, '\n');
    delete verif;
    delete content;
  }
}
