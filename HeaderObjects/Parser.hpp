

#ifndef _Parser_HPP_
# define _Parser_HPP_

#include <list>
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>


#include "GameObject.hh"
#include "Constructor.hpp"
#include "Cube.hh"
#include "Event.hh"

class Parser
{
private:
  std::istream *_is;
  std::map<std::string, IConstructor *> _constructor;

public:
  Parser();
  Parser(const Parser & other);
  ~Parser() {}

  void execute(Event *);
  Parser &operator=(const Parser &other);
};

#endif
