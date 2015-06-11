//
// MapModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Fri Jun  5 15:37:06 2015 Alexander Saenen
//

#ifndef MAPMODULE_HH_
# define MAPMODULE_HH_

# include <ModulesManager.hpp>
# include <MapValues.hh>
# include <ArgException.hh>
# include <RuntimeException.hh>
# include <LogicException.hh>
# include <fstream>

class	MapModule : public AModule
{
  std::map<std::string, std::string>	_textureMap;
  bool					_hasTextures;
  int					_size;

public:
  MapModule();
  virtual ~MapModule();

  void		loadMapValues();
  std::string	getTexturePath(const std::string &textureType) const;
  int		getSize() const;
  void		setSize(const int size);
};

#endif /* MapModule.hh */
