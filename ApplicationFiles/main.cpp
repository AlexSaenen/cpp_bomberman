//
// main.cpp for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:54:10 2015 Alexander Saenen
// Last update Wed May  6 19:34:38 2015 Alexander Saenen
//

#include "Parser.hpp"

#include "Application.hh"

int main (const int ac, const char **av)
{
  Application app(ac, av);

  app.run();
}