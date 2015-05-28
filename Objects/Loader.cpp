
#include "Loader.hh"

Loader::Loader() {
  try {
    _file = new std::filebuf();
    if (_file->open("test.conf", std::ios::in))
      _is = new std::istream(_file);
    else
      throw ArgException("Cannot open the file : test.conf");
    _constructor["Cube"] = new Cube;
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
  delete _constructor["Cube"];
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

  gameModule = ModulesManager::getInstance()->get<GameModule>();
  while (!_is->eof() && std::getline(*_is, buff, '@')) {
    content = new std::istringstream(buff);
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    std::istringstream *verif = new std::istringstream(buff);
    *verif >> type;
    go = new GameObject(static_cast<GameObject::ObjectType>(type), name);
    while (!content->eof())
      {
	std::getline(*content, buff, '%');
	component = reinterpret_cast<IComponent *>((*_constructor[buff])());
	std::getline(*content, args, '\n');
	if (args == "")
	  component = reinterpret_cast<IComponent *>((*_constructor[buff])());
	else
	  component = reinterpret_cast<IComponent *>((*_constructor[buff])()->configure(buff));
	go->pushComponent(component);
      }
    if (name == "intro")
      gameModule->handle(go, true);
    else
      gameModule->handle(go);
    std::getline(*content, buff, '\n');
  }
}
