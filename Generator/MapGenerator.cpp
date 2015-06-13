//
// MapGenerator.cpp for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Fri Jun 12 16:22:03 2015 Vividy
// Last update Sat Jun 13 13:40:14 2015 Vividy
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(int const size, int const nbPlayers, int const nbIa)
{
  // try {
  srand (time(NULL));
    this->file = new std::filebuf();
    // if (this->file->open("random.map", std::ios::out))
    if (this->file->open("../Maps//default.map", std::ios::out))
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
  int			z;
  std::stringstream	string;
  std::string		str;
  std::vector<MapGenerator::Coor>	player;
  int			nb;
  int			se;
  int			mm;

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
	    player.push_back(MapGenerator::Coor(x, y, -1));
      } else {
	for(y = 0; y < size; y++)
	  if ((y + 2) % 4 == 0)
	    player.push_back(MapGenerator::Coor(x, y, -1));
      }
    }
  }
  se = player.size();
  nb = nbPlayers + nbIa;
  if (se < nb)
    {
      nb = se;
      nbIa = nb - nbPlayers;
    }
  for (x = 0; x < nb; x++)
    {
      y = 0;
      z = 0;
      std::cout << x << std::endl;
      while (y == z && y < 5)
	{
	  z = y;
	  y++;
	  mm = rand() % se;
	  if (player[mm].u == -1)
	    {
	      if (x == 0)
		string << "\nfirstralouf 3\n$PlayerOne%" << player[mm].x * 2.5 << " " << player[mm].y * 2.5 << " 3 0 0 0 0.1 0.1 0.1 player1\n@";
	      else if (x == 1 && nbPlayers == 2)
		string << "\nfirstralouf 4\n$PlayerTwo%" << player[mm].x * 2.5 << " " << player[mm].y * 2.5 << " 4 0 0 0 0.1 0.1 0.1 player2\n@";
	      else
		string << "\nrandomralouf 5\n$IA%" << player[mm].x * 2.5 << " " << player[mm].y * 2.5 << " 5 0 0 0 0.1 0.1 0.1 ia\n@";
	      player[mm].u = 0;
	    }
	  else
	    z++;
	}
      if (y == z)
	{
	  std::cout << "pb: " << x << std::endl;
	  for (y = 0; player[y].u != -1 && (int)y < (int)player.size(); y++);
	  if (x == 0)
	    string << "\nfirstralouf 3\n$PlayerOne%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 3 0 0 0 0.1 0.1 0.1 player1\n@";
	  else if (x == 1 && nbPlayers == 2)
	    string << "\nfirstralouf 4\n$PlayerTwo%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 4 0 0 0 0.1 0.1 0.1 player2\n@";
	  else
	    string << "\nrandomralouf 5\n$IA%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 5 0 0 0 0.1 0.1 0.1 ia\n@";
	  player[y].u = 0;
	}
    }
  str = string.str();
  this->is->write(str.c_str(), str.size());
  return (0);
}
