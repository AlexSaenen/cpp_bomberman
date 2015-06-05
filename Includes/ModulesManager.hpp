//
// ModulesManager.hpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May  5 13:08:10 2015 Alexander Saenen
// Last update Fri Jun  5 15:50:32 2015 Alexander Saenen
//

#ifndef MODULESMANAGER_HPP_
# define MODULESMANAGER_HPP_

# include <cstddef>
# include <string>
# include <map>
# include <typeinfo>
# include <iostream>
# include "Functor.hpp"
# include "AModule.hh"
# include "GameRoutine.hh"

class ModulesManager
{
  static ModulesManager			*_instance;
  std::map<std::string, AModule *>	_instances;
  static bool				_isInstantiated;

public:  
  ModulesManager();
  ~ModulesManager();

public:
  static ModulesManager *getInstance();
  static bool		hasInstance();

public:
  template <typename T> T *get(const std::string &name) {
    if (this->_instances.find(name) == this->_instances.end())
      this->_instances.insert(std::make_pair(name, new T));
    return (reinterpret_cast<T *>(this->_instances[name]));
  }

  template <typename T> T *get() {
    return (this->get<T>(typeid(T).name()));
  }
};

#endif /* ModulesManager.hpp */
