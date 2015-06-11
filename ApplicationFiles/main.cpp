//
// main.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 20:26:01 2015 Alexander Saenen
// Last update Thu Jun 11 20:26:02 2015 Alexander Saenen
//

#include "Bomberman.hh"

int main (const int ac, const char **av)
{
  Bomberman app(ac, av);

  try {
    app.run();
  } catch(ArgException e) {
    std::cout << e.getMessage() << std::endl;
    return (-1);
  } catch(LogicException e) {
    std::cout << e.getMessage() << std::endl;
    return (-1);
  } catch(RuntimeException e) {
    std::cout << e.getMessage() << std::endl;
    return (-1);
  } catch(RangeException e) {
    std::cout << e.getMessage() << std::endl;
    return (-1);
  }
  return (0);
}
