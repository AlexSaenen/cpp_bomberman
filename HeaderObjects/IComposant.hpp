//
// IComposant.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 10:31:42 2015 Alexander Saenen
// Last update Tue May 12 11:10:45 2015 Alexander Saenen
//

#ifndef ICOMPOSANT_HH_
# define ICOMPOSANT_HH_

# include <SdlContext.hh>
# include <Event.hh>
# include <AShader.hh>

class	IComposant
{
public:
  virtual ~IComposant() { }
  
  virtual bool	initialize(Event *) = 0;
  virtual void	update(const gdl::Clock &clock, gdl::Input &input) = 0;
  virtual void	draw(gdl::AShader &shader, const gdl::Clock &clock) = 0;
};

#endif /* IComposant.hh */
