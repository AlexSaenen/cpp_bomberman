//
// ComponentFactory.hpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 15:51:26 2015 Alexander Saenen
// Last update Sun Jun 14 12:28:46 2015 Alexander Saenen
//

#ifndef COMPONENT_FACTORY_HPP_
# define COMPONENT_FACTORY_HPP_

# include <IComponent.hpp>
# include <AModule.hh>

class	ComponentFactory : public AModule
{
public:
  ComponentFactory() { };
  ~ComponentFactory() { };

  template <typename T> IComponent*	getComponent() {
    return (new T());
  };
};

#endif /* ComponentFactory.hpp */
