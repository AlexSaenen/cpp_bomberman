
#ifndef _LOADER_HH_
# define _LOADER_HH_

# include <list>
# include <iostream>
# include <istream>
# include <sstream>
# include <fstream>
# include <iostream>
# include <iomanip>
# include <string>


# include "GameObject.hh"
# include "Constructor.hpp"
# include "Cube.hh"
# include "Event.hh"
# include "ModulesManager.hpp"
# include "GameModule.hh"

class Loader
{
private:
  std::istream *_is;
  std::map<std::string, IConstructor *> _constructor;
  std::filebuf *_file;

public:
  Loader();
  ~Loader();
  void execute(Event *);
};

#endif
