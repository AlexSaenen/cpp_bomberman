//
// Marvin.hh for  in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue Apr 28 14:45:41 2015 Alexander Saenen
// Last update Tue Apr 28 14:48:27 2015 Alexander Saenen
//

#ifndef MARVIN_HH_
# define MARVIN_HH_

# include "AObject.hh"
# include "Model.hh"

class	Marvin : public AObject
{
  gdl::Texture	_texture;
  gdl::Model	_model;
  float		_speed;

public:
  Marvin();
  virtual ~Marvin();

  bool	initialize();
  void	update(gdl::Clock const &clock, gdl::Input &input);
  void	draw(gdl::AShader &shader, gdl::Clock const &clock);
};

#endif /* Marvin.hh */
