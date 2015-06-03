//
// ModulesManager.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:08:24 2015 Alexander Saenen
// Last update Tue May 19 11:08:25 2015 Alexander Saenen
//

#include "ModulesManager.hpp"

ModulesManager *ModulesManager::_instance = NULL;
bool		ModulesManager::_isInstantiated = false;

ModulesManager::ModulesManager() {
  _instance = NULL;
  _componentFactory = new ComponentFactory;
}

ModulesManager::~ModulesManager() {
  for (std::map<std::string, AModule *>::iterator it = _instances.begin(); it != _instances.end(); ++it)
    delete (*it).second;
  _isInstantiated = false;
  delete _componentFactory;
}

ModulesManager	*ModulesManager::getInstance() {
  ModulesManager::_isInstantiated = true;
  if (ModulesManager::_instance == NULL)
    ModulesManager::_instance = new ModulesManager;
  return ModulesManager::_instance;
}

bool		ModulesManager::hasInstance() {
  return (_isInstantiated);
}

