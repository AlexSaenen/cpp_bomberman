//
// TexturesModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Thu Jun 11 16:34:07 2015 Alexander Saenen
//

#ifndef TEXTURESMODULE_HH_
# define TEXTURESMODULE_HH_

# include <ModulesManager.hpp>
# include <Texture.hh>
# include <ArgException.hh>
# include <RuntimeException.hh>
# include <LogicException.hh>

class	TexturesModule : public AModule
{
  std::map<std::string, gdl::Texture *>	_textureInstances;

public:
  TexturesModule();
  virtual ~TexturesModule();

  gdl::Texture	*getInstance(const std::string &texture);
};

#endif /* TexturesModule.hh */
