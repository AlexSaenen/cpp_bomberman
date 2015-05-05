//
// ModulesManager.cpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May  5 13:07:26 2015 Alexander Saenen
// Last update Tue May  5 13:14:01 2015 Alexander Saenen
//

#include "ModulesManager.hpp"

ModulesManager *ModulesManager::instance = NULL;

ModulesManager::ModulesManager() {
  instance = NULL;
}

ModulesManager::~ModulesManager() {
  for (std::map<std::string, AModule *>::iterator it = _instances.begin(); it != _instances.end(); ++it)
    delete (*it).second;
}

ModulesManager	*ModulesManager::getInstance() {
  if (ModulesManager::instance == NULL)
    ModulesManager::instance = new ModulesManager;
  return ModulesManager::instance;
}
