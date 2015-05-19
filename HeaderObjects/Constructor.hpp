//
// Constructor.hpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:53:48 2015 Alexander Saenen
// Last update Tue May 12 18:07:45 2015 Alexander Saenen
//

#ifndef CONSTRUCTOR_HPP_
# define CONSTRUCTOR_HPP_

# include "IConstructor.hh"

template<class ME>
class Constructor : public IConstructor
{
public:
  Constructor() { }
  virtual ~Constructor() { }

  virtual void *operator()() {
    return (reinterpret_cast<void *>(new ME));
  }
};

#endif /* Constructor.hpp */ 