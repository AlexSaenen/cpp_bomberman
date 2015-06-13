//
// MapModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Sat Jun 13 11:17:08 2015 Alexander Saenen
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
  int					_ia;
  bool					_isMultiplayer;

public:
  MapModule();
  virtual ~MapModule();

  void		loadMapValues();
  std::string	getTexturePath(const std::string &textureType) const;
  int		getSize() const;
  void		setSize(const int size);
  int		getIA() const;
  void		setIA(const int ia);
  bool		isLoaded() const;
  void		setGameMode(Event *e);
  bool		isMultiplayer() const;
};

#endif /* MapModule.hh */
