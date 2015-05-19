
#include "Parser.hpp"

Parser::Parser() {
  _file = new std::filebuf();
  if (_file->open("test.conf", std::ios::in))
    _is = new std::istream(_file);
  else
    throw ArgException("Cannot open the file : test.conf");
  _constructor["Cube"] = new Constructor<Cube>;
  // _constructor["ObjModel"] = new Constructor<ObjModel>;
}

Parser::~Parser() {
  delete _is;
  delete _file;
  delete _constructor["Cube"];
}

void Parser::execute(Event *)
{
  std::list<GameObject *>	objectList;
  std::string			buff;
  std::string			name;
  int				type;
  GameObject			*go;
  std::istringstream		*content;

  while (_is->eof() && std::getline(*_is, buff, '@')) {
    std::cout << "trognon " << buff << std::endl;
    content = new std::istringstream(buff);
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    std::istringstream *verif = new std::istringstream(buff);
    *verif >> type;
    go = new GameObject(static_cast<GameObject::ObjectType>(type), name);
    while (!content->eof())
      {
	std::getline(*content, buff, '\n');
	std::cout << "buff " << buff << std::endl;
	go->pushComponent(reinterpret_cast<IComponent *>((*_constructor[buff])()));
	// (*(reinterpret_cast<Constructor<Cube> *>((_constructor[buff]))))();
      }
    objectList.push_back(go);
    //delete go; /// ?
  }
}
