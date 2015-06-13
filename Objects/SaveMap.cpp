//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sat Jun 13 22:32:37 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap()
{
  this->i = 42;
  std::cout << "Construction" << std::endl;
}

SaveMap::~SaveMap()
{
  std::cout << "Deconstruction" << std::endl;
}

void	SaveMap::execute()
{
  std::cout << "je fonctionne" << std::endl;
}

