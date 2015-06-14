//
// ObjModel.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Sun Jun 14 17:43:56 2015 Vividy
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
# include <list>
# include <map>
# include <GameObject.hh>
# include <LogicException.hh>
# include <RuntimeException.hh>

class	ObjModel : public IComponent, public Shape
{
protected:
  gdl::Model	_model;
  std::string	_modelName;
  float		_speed;
  bool		_isLoaded;
  GameObject::ObjectType	_type;

public:
  ObjModel();
  virtual ~ObjModel();

  void	initialize(Event *);
  virtual void	update(const gdl::Clock &clock, gdl::Input &input) = 0;
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);
  void	playAnimation(const std::string &animation, bool const loop = true);
  void	playAnimation(int const stack, bool const loop = true);
  void	playSubAnim(const std::string &subAnimation, bool const loop = true);
  void	configure(const std::string &model, const GameObject::ObjectType type);
  void	configure(const std::string &conf);
  std::string	getModelName() const;
};

#endif /* ObjModel.hh */
