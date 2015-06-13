//
// MapGenerator.cpp for  in /home/vividy/test/Generator
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Fri Jun 12 16:22:03 2015 Vividy
// Last update Sat Jun 13 17:06:30 2015 Vividy
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(int const size, int const nbPlayers, int const nbIa)
{
  srand (time(NULL));
    this->file = new std::filebuf();
    if (this->file->open("Maps/random.map", std::ios::out))
      this->is = new std::ostream(this->file);
    else
      throw ArgException("Cannot open the file : Maps/random.map");
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

int	checkPerso(int x, int y, std::vector<MapGenerator::Coor> player)
{
  int	z;

  for (z = 0; z < (int)player.size(); z++)
    {
      if (player[z].x == x && player[z].y == y)
	return (z);
      if (player[z].x == x - 1 && player[z].y == y)
	return (z);
      if (player[z].x == x + 1 && player[z].y == y)
	return (z);
      if (player[z].x == x && player[z].y == y + 1)
	return (z);
      if (player[z].x == x && player[z].y == y - 1)
	return (z);
    }
  return (-1);
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
		string << "\nrandomralouf 5\n$IA%" << player[mm].x * 2.5 << " " << player[mm].y * 2.5 << " 5 0 0 0 0.1 0.1 0.1 ia" << (rand() % 4) + 1 << "\n@";
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
	    string << "\nrandomralouf 5\n$IA%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 5 0 0 0 0.1 0.1 0.1 ia" << (rand() % 4) + 1 << "\n@";
	  player[y].u = 0;
	}
    }
  for (x = 0; x < (int)player.size(); x++)
    if (player[x].u != -1)
      player[x].u += ((player[x].x == 0 || player[x].x + 1 == this->size) ? 1 : 0) + ((player[x].y == 0 || player[x].y + 1 == this->size) ? 1 : 0);
  for (x = 0; x < this->size; x++)
    for (y = 0; y < this->size; y++) // Si, je mettrais le "this"!
      if (x % 2 != 1 && y % 2 != 1)
	{
	  z = checkPerso(x, y, player);
	  if ((z == -1 || player[z].u != 2 || (player[z].x == x && player[z].y == y && player[z].u != -1)) && rand() % 10 > 3)
	    {
	      string << "\nWall 1\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
	      if (z != -1 && player[z].u != -1)
		player[z].u += 1;
	    }
	}
  str = string.str();
  this->is->write(str.c_str(), str.size());
  return (0);
}
