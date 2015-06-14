//
// Constructor.hpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:53:48 2015 Alexander Saenen
// Last update Sun Jun 14 17:02:36 2015 Vividy
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

  ME *operator()() {
    return (new ME);
  }
};

#endif /* Constructor.hpp */
