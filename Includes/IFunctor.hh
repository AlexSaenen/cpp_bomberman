//
// IFunctor.hh for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May  5 12:38:40 2015 Alexander Saenen
// Last update Tue May  5 12:47:55 2015 Alexander Saenen
//

#ifndef IFUNCTOR_HH_
# define IFUNCTOR_HH_

# include "Event.hh"

class	IFunctor
{
public:
  virtual	~IFunctor() { }

  virtual void	operator()(Event *) = 0;
};

#endif /* IFunctor.hh */
