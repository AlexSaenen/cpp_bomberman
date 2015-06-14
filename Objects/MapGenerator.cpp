//
// MapGenerator.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Sun Jun 14 11:03:04 2015 Alexander Saenen
// Last update Sun Jun 14 16:07:29 2015 Bozo
//

#include "MapGenerator.hh"

MapGenerator::MapGenerator(int const size, int const nbPlayers, int const nbIa)
{
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

int	checkPerso(int const x, int const y, std::vector<MapGenerator::Coor> const &player)
{
  int	z;

  for (z = 0; z < (int)player.size(); z++)
    if ((player[z].x == x && player[z].y == y) ||
	(player[z].x == x - 1 && player[z].y == y) ||
	(player[z].x == x + 1 && player[z].y == y) ||
	(player[z].x == x && player[z].y == y + 1) ||
	(player[z].x == x && player[z].y == y - 1))
      return (z);
  return (-1);
}

std::vector<MapGenerator::Coor> fillPlayer(std::vector<MapGenerator::Coor> &player, int const size)
{
  int	x;
  int	y;

  for (x = 0; x < size; x++) {
    if (x % 2 != 1) {
      if (x % 4 == 0) {
	for (y = 0; y < size; y++)
	  if (y % 4 == 0)
	    player.push_back(MapGenerator::Coor(x, y, -1));
      } else {
	for (y = 0; y < size; y++)
	  if ((y + 2) % 4 == 0)
	    player.push_back(MapGenerator::Coor(x, y, -1));
      }
    }
  }
  return (player);
}

void	algoPutAll(int const nbPlayers, int const size, int const se, int const nb, std::vector<MapGenerator::Coor> &player, int const nbIa, std::ostream *is)
{
  std::stringstream	string;
  std::string		str;
  int			x = 0;
  int			y = 0;
  int			z = 0;
  int			mem;

  string << size << " " << nbIa << "\n@";
  for (x = 0; x < nb; x++)
    {
      y = 0;
      z = 0;
      while (y == z && y < 5)
	{
	  z = y;
	  y++;
	  mem = rand() % se;
	  if (player[mem].u == -1)
	    {
	      if (x == 0)
		string << "\nfirstralouf 3\n$PlayerOne%" << player[mem].x * 2.5 << " " << player[mem].y * 2.5 << " 3 0 0 0 0.034 0.034 0.034 player1\n@";
	      else if (x == 1 && nbPlayers == 2)
		string << "\nfirstralouf 4\n$PlayerTwo%" << player[mem].x * 2.5 << " " << player[mem].y * 2.5 << " 4 0 0 0 0.034 0.034 0.034 player2\n@";
	      else
    string << "\nrandomralouf 5\n$IA%" << player[mem].x * 2.5 << " " << player[mem].y * 2.5 << " 5 0 0 0 0.034 0.034 0.034 ia" << (rand() % 4) + 1 << "\n@";
  player[mem].u = 0;
	    }
	  else
	    z++;
	}
      if (y == z)
	{
	  for (y = 0; player[y].u != -1 && (int)y < (int)player.size(); y++);
	  if (x == 0)
	    string << "\nfirstralouf 3\n$PlayerOne%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 3 0 0 0 0.034 0.034 0.034 player1\n@";
	  else if (x == 1 && nbPlayers == 2)
	    string << "\nfirstralouf 4\n$PlayerTwo%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 4 0 0 0 0.034 0.034 0.034 player2\n@";
	  else
	    string << "\nrandomralouf 5\n$IA%" << player[y].x * 2.5 << " " << player[y].y * 2.5 << " 5 0 0 0 0.034 0.034 0.034 ia" << (rand() % 4) + 1 << "\n@";
	  player[y].u = 0;
	}
    }
  for (x = 0; x < (int)player.size(); x++)
    if (player[x].u != -1)
      player[x].u += ((player[x].x == 0 || player[x].x + 1 == size) ? 1 : 0) + ((player[x].y == 0 || player[x].y + 1 == size) ? 2 : 0);
  for (x = 0; x < size; x++)
    for (y = 0; y < size; y++)
      if ((x % 2 != 1 || y % 2 != 1) && rand() % 100 < 65)
	{
	  z = checkPerso(x, y, player);
	  if (z == -1 || player[z].u == -1)
	    string << "\nWall 1\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
	  else if (player[z].u != 3 && !(player[z].x == x && player[z].y == y))
	    {
	      if (player[z].u != 2 && player[z].x == x)
		{
		  string << "\nWall 1\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
		  player[z].u += 2;
		}
	      else if (player[z].u != 1 && player[z].y == y)
		{
		  string << "\nWall 1\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
		  player[z].u += 1;
		}
	    }
	}
      else if (x % 2 == 1 && y % 2 == 1)
	string << "\nWall 0\n$Cube%" << x * 2.5 << " " << y * 2.5 << " 0\n@";
  str = string.str();
  is->write(str.c_str(), str.size());
}

int			MapGenerator::generate()
{
  std::vector<MapGenerator::Coor>	player;
  int			nb = 0;
  int			se = 0;

  player = fillPlayer(player, size);
  se = player.size();
  nb = nbPlayers + nbIa;
  if (se < nb)
    {
      nb = se;
      nbIa = nb - nbPlayers;
    }
  algoPutAll(nbPlayers, size, se, nb, player, nbIa, is);
  return (0);
}
