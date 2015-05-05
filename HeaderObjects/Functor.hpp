//
// Functor.hpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:53:48 2015 Alexander Saenen
// Last update Tue May  5 13:03:28 2015 Alexander Saenen
//

#ifndef FUNCTOR_HPP_
# define FUNCTOR_HPP_

# include "IFunctor.hh"

template<class ME>
class Functor : public IFunctor
{
  typedef void (ME::*handler)(Event *);
  ME	*_instance;
  handler _handle;

public:
  Functor(ME *instance, handler what): _instance(instance), _handle(what) { }
  ~Functor() { }

  void operator()(Event *e) {
    (this->_instance->*_handle)(e);
  }
};

#endif /* Functor.hpp */ 
