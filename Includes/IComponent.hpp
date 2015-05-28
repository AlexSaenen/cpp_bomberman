//
// IComposant.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:31:42 2015 Alexander Saenen
// Last update Fri May 15 14:52:07 2015 Alexander Saenen
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
  virtual Icomponent *clone(const std::string &conf) const = 0;
};

#endif /* IComponent.hh */
