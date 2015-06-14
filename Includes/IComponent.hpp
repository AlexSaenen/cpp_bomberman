//
// IComposant.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:31:42 2015 Alexander Saenen
// Last update Sun Jun 14 17:29:44 2015 Vividy
//

#ifndef ICOMPONENT_HH_
# define ICOMPONENT_HH_

# include <SdlContext.hh>
# include <Event.hh>
# include <AShader.hh>

class	IComponent
{
public:
  virtual ~IComponent() { }

  virtual void	initialize(Event *) = 0;
  virtual void	update(const gdl::Clock &clock, gdl::Input &input) = 0;
  virtual void	draw(gdl::AShader &shader, const gdl::Clock &clock) = 0;
  virtual void	configure(const std::string &conf) = 0;
};

#endif /* IComponent.hh */
