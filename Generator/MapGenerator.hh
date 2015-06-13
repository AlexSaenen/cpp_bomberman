//
// MapGenerator.hh for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Wed Jun 10 16:32:58 2015 Vividy
// Last update Fri Jun 12 18:10:57 2015 Vividy
//

#ifndef MAPGENERATOR
# define MAPGENERATOR

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

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
