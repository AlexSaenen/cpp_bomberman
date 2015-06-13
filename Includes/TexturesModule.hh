//
// TexturesModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Sat Jun 13 10:29:43 2015 Alexander Saenen
//

#ifndef TEXTURESMODULE_HH_
# define TEXTURESMODULE_HH_

# include <ModulesManager.hpp>
# include <Texture.hh>
# include <Geometry.hh>
# include <ArgException.hh>
# include <RuntimeException.hh>
# include <LogicException.hh>

class	TexturesModule : public AModule
{
  std::map<std::string, gdl::Texture *>	_textureInstances;
  std::map<std::string, gdl::Geometry *>	_geometryInstances;

public:
  TexturesModule();
  virtual ~TexturesModule();

  gdl::Texture	*getTextInstance(const std::string &texture);
  gdl::Geometry	*getGeoInstance(const std::string &geometry);

private:
  void	_loadCubeGeometry(gdl::Geometry *_geometry) const;
  void	_loadWallGeometry(gdl::Geometry *_geometry) const;
};

#endif /* TexturesModule.hh */
