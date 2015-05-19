
#include "Parser.hh"
#include "Application.hh"
#include "Bomberman.hh"

int main (const int ac, const char **av)
{
  Bomberman app(ac, av);
  app.run();
}
