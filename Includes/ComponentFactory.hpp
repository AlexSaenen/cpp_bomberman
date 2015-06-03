#ifndef _COMPONENT_FACTORY_HPP_
# define _COMPONENT_FACTORY_HPP_

# include "IComponent.hpp"

class	ComponentFactory
{
public:
  ComponentFactory(){};
  ~ComponentFactory(){};

  template <typename T> T*getComponent()
  {
    return (new T);
  }; 
};

#endif
