
#include "Bomberman.hh"

int main (const int ac, const char **av)
{
  Bomberman app(ac, av);

  try {
    app.run();
  } catch(std::exception e) {
    std::cout << e.what() << std::endl;
    return (-1);
  }
  return (0);
}
