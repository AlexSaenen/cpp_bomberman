//
// ObjModel.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Fri May 15 14:52:59 2015 Alexander Saenen
//

#ifndef OBJMODEL_HH_
# define OBJMODEL_HH_

# include <AShader.hh>
# include <Shape.hh>
# include <IComposant.hpp>
# include <Model.hh>
# include <Texture.hh>
# include <glm/glm.hpp>
# include <iostream>
# include <GameObject.hh>

class	ObjModel : public IComposant, public Shape
{
  gdl::Model	_model;
  std::string	_modelName;
  float		_speed;
  GameObject::ObjectType	_type;

public:
  ObjModel(const std::string &model, const GameObject::ObjectType type);
  virtual ~ObjModel();

  void	initialize(Event *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
};

#endif /* ObjModel.hh */
