//
// Loader.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 15:03:33 2015 Alexander Saenen
// Last update Sun Jun 14 12:26:50 2015 Alexander Saenen
//

#include "Loader.hh"

Loader::Loader(const std::string &filename) {
  try {
    _file = new std::filebuf();
    if (_file->open(filename.c_str(), std::ios::in))
      _is = new std::istream(_file);
    else
      throw ArgException("Cannot open the file : " + filename);
    _constructor["Cube"] = &ComponentFactory::getComponent<Cube>;
    _constructor["PlayerOne"] = &ComponentFactory::getComponent<PlayerOne>;
    _constructor["PlayerTwo"] = &ComponentFactory::getComponent<PlayerTwo>;
    _constructor["IA"] = &ComponentFactory::getComponent<IA>;
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

void	Loader::_loadTexture(IComponent *component, const GameObject *go) const {
  std::string	texturePath;
  if (go->getType() == GameObject::CUBE)
    texturePath = ModulesManager::getInstance()->get<MapModule>()->getTexturePath("cube");
  else if (go->getType() == GameObject::CUBEDESTR)
    texturePath = ModulesManager::getInstance()->get<MapModule>()->getTexturePath("destroy");
  else
    return ;
  reinterpret_cast<Cube *>(component)->setTexture(texturePath);
}

void	Loader::execute() {
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
  std::istringstream		*verif;
  
  modulesManager = ModulesManager::getInstance();
  modulesManager->get<MapModule>()
    ->loadMapValues();
  factory = modulesManager->get<ComponentFactory>();
  gameModule = modulesManager->get<GameModule>();
  std::getline(*_is, buff, '@');
  content = new std::istringstream(buff);
  std::getline(*content, buff, ' ');
  verif = new std::istringstream(buff);
  *verif >> type;
  modulesManager->get<MapModule>()->setSize(type);
  std::getline(*content, buff, '\n');
  verif = new std::istringstream(buff);
  *verif >> type;
  modulesManager->get<MapModule>()->setIA(type);
  while (!_is->eof() && std::getline(*_is, buff, '@')) {
    content = new std::istringstream(buff);
    std::getline(*content, buff, '\n');
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    verif = new std::istringstream(buff);
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
	  _loadTexture(component, go);
	go->pushComponent(component);
      }
    gameModule->handle(go);
    std::getline(*content, buff, '\n');
    delete verif;
    delete content;
  }
}
