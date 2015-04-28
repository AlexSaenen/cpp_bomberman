//
// main.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 12:13:18 2015 Alexander Saenen
// Last update Mon Apr 27 15:31:39 2015 Alexander Saenen
//

#include <OpenGL.hh>
#include <SdlContext.hh>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <cstdlib>
#include "GameRoutine.hh"

/* Au lieu d'envoyer des params en dur, recup les infos a partir du menu */

int	main(void)
{
  GameRoutine	engine;

  if (engine.initialize() == false) {
    std::cerr << "Couldn't Initialize the Engine" << std::endl;
    return (EXIT_FAILURE);
  }
  while (engine.update() == true)
    engine.draw();
  return (EXIT_SUCCESS);
}
