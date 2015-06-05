//
// ComponentFactory.hpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 15:51:26 2015 Alexander Saenen
// Last update Fri Jun  5 16:16:57 2015 Alexander Saenen
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
    return (new T);
  };
};

#endif /* ComponentFactory.hpp */
