//
// ObjModel.hh for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 14:54:27 2015 Alexander Saenen
// Last update Thu May 21 11:58:22 2015 Alexander Saenen
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
  gdl::Model	_model;
  std::string	_modelName;
  float		_speed;
  bool		_isLoaded;
  bool		_isMoving;
  double	_animDuration;
  int		_lastMovement;
  std::map<int, int>		_movementMap;
  std::map<int, int>		_animationMap;
  GameObject::ObjectType	_type;

public:
  ObjModel(const std::string &model, const GameObject::ObjectType type);
  virtual ~ObjModel();

  void	initialize(Event *);
  void	update(const gdl::Clock &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, const gdl::Clock &clock);

  void	playAnimation(const std::string &animation, bool loop = true);
  void	playAnimation(int stack, bool loop = true);
  void	playSubAnim(const std::string &subAnimation, bool loop = true);
};

#endif /* ObjModel.hh */
