//
// GameRoutine.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 13:52:34 2015 Alexander Saenen
// Last update Tue Apr 28 14:32:45 2015 Alexander Saenen
//

#include "GameRoutine.hh"
#include "Geometry.hh"


#include "Model.hh"

gdl::Model		ralouf;

GameRoutine::GameRoutine() {}

GameRoutine::~GameRoutine() {
  size_t	listSize;

  for (listSize = 0; listSize < _objects.size(); ++listSize) {
    delete _objects[listSize];
  }
}

bool	GameRoutine::initialize() {
  glm::mat4	projection;
  glm::mat4	transformation;
  // AObject	*cube = new Cube;

  if (!_context.start(800, 600, "Bomb the House")) {
    std::cerr << "Error while trying to start the openGL context" << std::endl;
    return (false);
  }
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./LibBomberman_linux_x64/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./LibBomberman_linux_x64/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build()) {
    std::cerr << "Error while trying to load the shaders" << std::endl;
    return (false);
  }
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  // if (cube->initialize() == false) {
  //   std::cerr << "Couldn't initialize a cube" << std::endl;
  //   return (false);
  // }
  // _objects.push_back(cube);
  ralouf.load("./LibBomberman_linux_x64/assets/marvin.fbx");
  // _objects.push_back(ralouf);
  return (true);
}

bool	GameRoutine::update() {
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (false);
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  // for (size_t i = 0; i < _objects.size(); ++i)
  //   _objects[i]->update(_clock, _input);
  return (true);
}

void	GameRoutine::draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  glm::mat4 transform(1);
  glm::vec3 position(0, 0, 0);
  glm::vec3 n(0, 0, 100);
  transform = glm::rotate(transform, position.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, position.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, position.z, glm::vec3(0, 0, 1));
  transform = glm::translate(transform, n);
  ralouf.draw(_shader, transform, _clock.getElapsed());
  // for (size_t i = 0; i < _objects.size(); ++i)
  //   _objects[i]->draw(_shader, _clock);
  _context.flush();  
}
