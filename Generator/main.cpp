//
// main.cpp for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Wed Jun 10 16:29:53 2015 Vividy
// Last update Sat Jun 13 14:03:07 2015 Vividy
//

#include "MapGenerator.hh"

int	main()
{
  MapGenerator	map(11, 2, 188);

  map.generate();
  std::cout << "Ok!" << std::endl;
}
