//
// ObjModel.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Tue May 12 17:37:56 2015 Alexander Saenen
//

#ifndef OBJMODEL_HH_
# define OBJMODEL_HH_

# include <AShader.hh>
# include <Shape.hh>
# include <IComponent.hpp>
# include <Model.hh>
# include <Texture.hh>
# include <glm/glm.hpp>
# include <iostream>

class	ObjModel : public IComponent, public Shape
{
  gdl::Texture	_texture;
  gdl::Model	_model;
  std::string	_modelName;
  std::string	_textureName;
  float		_speed;

public:
  ObjModel(const std::string &model, const std::string &texture);
  virtual ~ObjModel();

  bool	initialize(Event *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
};

#endif /* ObjModel.hh */
