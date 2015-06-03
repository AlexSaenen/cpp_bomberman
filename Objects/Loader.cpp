
#include "Loader.hh"

Loader::Loader() {
  try {
    _file = new std::filebuf();
    if (_file->open("test.conf", std::ios::in))
      _is = new std::istream(_file);
    else
      throw ArgException("Cannot open the file : test.conf");
    _constructor["Cube"] = &ModulesManager::getComponent<Cube>;
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

void Loader::execute(Event *)
{
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

  std::cout << "Ralouf" << std::endl;
  modulesManager = ModulesManager::getInstance();
  gameModule = modulesManager->get<GameModule>();
  while (!_is->eof() && std::getline(*_is, buff, '@')) {
    content = new std::istringstream(buff);
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    std::istringstream *verif = new std::istringstream(buff);
    *verif >> type;
    // std::cout << "Ralouf : " << static_cast<GameObject::ObjectType>(type) << std::endl;
    go = new GameObject(static_cast<GameObject::ObjectType>(type), name);
    while (std::getline(*content, buff, '$') && buff == "")
      {
	std::cout << "/" << content->str() << "/" << std::endl;
	std::cout << "[" << "Ralouf2"<< std::endl;
	std::getline(*content, buff, '%');
	std::cout << "[" << buff << "]" << std::endl;
	component = (modulesManager->*_constructor[buff])();
	std::getline(*content, args, '\n');
	std::cout << "{" << args << "}" << std::endl;
	component->initialize(NULL);
	if (args != "")
	  component->configure(args);
	go->pushComponent(component);
      }
    std::cout << "Ralouf3" << std::endl;
    if (name == "intro")
      gameModule->handle(go, true);
    else
      gameModule->handle(go);
    gdl::BasicShader	input;
    gdl::Clock		clock;
    go->draw(input, clock);
    std::getline(*content, buff, '\n');
  }
  std::cout << "Ralouf4" << std::endl;
}
