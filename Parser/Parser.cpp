
#include "Parser.hpp"

Parser::Parser()
{
  std::filebuf file;

  if (file.open("test.conf", std::ios::in))
    _is = new std::istream(&file);
  _constructor["Cube"] = new Constructor<Cube>;
  // _constructor["ObjModel"] = new Constructor<ObjModel>;
}

Parser::Parser(const Parser & other)
{
  _is = other._is;
}

Parser &Parser::operator=(const Parser &other)
{
  if (this != &other)
    _is = other._is;
  return (*this);
}

void Parser::execute(Event *)
{
  std::list<GameObject *>	objectList;
  std::string			buff;
  std::string			name;
  int				type;
  GameObject			*go;
  std::istringstream		*content;

  while (std::getline(*_is, buff, '@')) {
    content = new std::istringstream(buff);
    std::getline(*content, name, ' ');
    std::getline(*content, buff, '\n');
    std::istringstream verif(buff);
    verif >> type;
    go = new GameObject(static_cast<GameObject::ObjectType>(type), name);
    while (!content->eof())
      {
	std::getline(*content, buff, '\n');
	go->pushComponent(reinterpret_cast<IComponent *>((*_constructor[buff])()));
	// (*(reinterpret_cast<Constructor<Cube> *>((_constructor[buff]))))();
      }
    objectList.push_back(go);
    //delete go; /// ?
  }
}
