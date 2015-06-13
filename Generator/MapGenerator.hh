//
// MapGenerator.hh for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Wed Jun 10 16:32:58 2015 Vividy
// Last update Sat Jun 13 12:45:05 2015 Vividy
//

#ifndef MAPGENERATOR
# define MAPGENERATOR

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class		MapGenerator
{
private:
  std::ostream	*is;
  std::filebuf	*file;
  int		size;
  int		nbPlayers;
  int		nbIa;
public:
  struct	Coor
  {
    int	x;
    int	y;
    int	u;
    Coor(int const, int const, int const);
    ~Coor() {};
  };
public:
  MapGenerator(int const, int const, int const);
  ~MapGenerator();
  int		generate();
};

#endif //!MAPGENERATOR
