
#ifndef _LOADER_HH_
# define _LOADER_HH_

# include <list>
# include <iostream>
# include <istream>
# include <sstream>
# include <fstream>
# include <iomanip>
# include <string>
# include "GameObject.hh"
# include "Constructor.hpp"
# include "Cube.hh"
# include "Event.hh"
# include "ModulesManager.hpp"
# include "ComponentFactory.hpp"
# include "GameModule.hh"
# include "MapModule.hh"
# include "PlayerOne.hh"
# include "PlayerTwo.hh"
# include "IA.hh"

class Loader
{
private:
  std::istream *_is;
  std::map<std::string, IComponent *(ComponentFactory::*)(void)> _constructor;
  std::filebuf *_file;

public:
  explicit Loader(const std::string &filename);
  ~Loader();
  void	execute();

private:
  void	_loadTexture(IComponent *component, const GameObject *go) const;
  std::istream Loader::*_init(const std::string &file);
};

#endif
