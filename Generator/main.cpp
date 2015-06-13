//
// main.cpp for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Wed Jun 10 16:29:53 2015 Vividy
// Last update Sat Jun 13 11:20:02 2015 Vividy
//

#include "MapGenerator.hh"

int	main()
{
  MapGenerator	map(11, 2, 6);

  map.generate();
  std::cout << "Ok!" << std::endl;
}
