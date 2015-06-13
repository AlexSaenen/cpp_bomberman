//
// MapGenerator.cpp for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Fri Jun 12 16:22:03 2015 Vividy
// Last update Sat Jun 13 11:13:35 2015 Vividy
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(int const size, int const nbPlayers, int const nbIa)
{
  // try {
    this->file = new std::filebuf();
    if (this->file->open("random.map", std::ios::out))
      this->is = new std::ostream(this->file);
    else
      std::cout << "ca marche pas" << std::endl;
      // throw ArgException("Cannot open the file : loool");
  // } catch (ArgException e) {
  //   std::cerr << e.getMessage() << std::endl;
  //   ModulesManager::getInstance()->get<EventModule>()
  //     ->trigger("MapGenerator.error", 1001)
  //     ->handle();
  // }
 this->size = size;
 this->nbPlayers = nbPlayers;
 this->nbIa = nbIa;
}

MapGenerator::~MapGenerator()
{
  delete this->is;
  delete this->file;
}

MapGenerator::Coor::Coor(int const _x, int const _y, int const _u)
{
  this->x = _x;
  this->y = _y;
  this->u = _u;
}

int			MapGenerator::generate()
{
  int			x;
  int			y;
  std::stringstream	string;
  std::string		str;
  std::list<MapGenerator::Coor>	player;
  std::list<MapGenerator::Coor>::iterator sv;
  float			nb;
  int			inter;
  float			in;

  y = 0;
  for (x = 0; x < size; x++) {
      if (x % 2 == 1){
	  for (y = 0; y < size; y++)
	    if (y % 2 == 1)
	      string << "\nWall 0\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
      } else {
	if (x % 4 == 0) {
	  for(y = 0; y < size; y++)
	    if (y % 4 == 0)
	      {
		player.push_back(MapGenerator::Coor(x, y, -1));
		std::cout << x << " " << y << std::endl;
	      }
	} else {
	  for(y = 0; y < size; y++)
	    if ((y + 2) % 4 == 0)
	      {
		player.push_back(MapGenerator::Coor(x, y, -1));
		std::cout << x << " " << y << std::endl;
	      }
	}
      }
  }
  nb = static_cast<float>(nbPlayers + nbIa - 1);
  string << "\nfirstralouf 3\n$PlayerOne%0 0 3 0 0 0 0.1 0.1 0.1 player1\n@";
  if (player.size() < (nb + 1))
    {
      nb = player.size() - 1;
      nbIa = (nb + 1) - nbPlayers;
    }
  if (nb > 0)
    {
      in = ((player.size() / nb)) - 1.00;
      inter = static_cast<int>(in);
      inter += (inter < in) ? 1 : 0;
      std::cout << "nb: " << nb << " in: " << inter << std::endl;
      x = 0;
      y = 0;
      for (std::list<MapGenerator::Coor>::iterator it = player.begin(); it != player.end(); ++it)
	{
	  if (x % inter == 0 && x != 0 && y < nbIa)
	    {
	      string << y <<  "\nrandomralouf 5\n$IA%" << (*it).x * 2.5 << " " << (*it).y * 2.5 << " 5 0 0 0 0.1 0.1 0.1 ia\n@";
	      y++;
	    }
	  x++;
	  sv = it;
	}
    }
  if (nbPlayers == 2)
    string << "\nfirstralouf 4\n$PlayerTwo%" << (*sv).x * 2.5 << " " << (*sv).y * 2.5 << " 4 0 0 0 0.1 0.1 0.1 player2\n@";
  str = string.str();
  this->is->write(str.c_str(), str.size());
  return (0);
}
