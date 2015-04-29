//
// GameRoutine.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 13:52:34 2015 Alexander Saenen
// Last update Wed Apr 29 09:04:09 2015 Alexander Saenen
//

#include "GameRoutine.hh"

#include "Marvin.hh"

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
  AObject	*marvin = new Marvin;
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
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  if (marvin->initialize() == false) {
    std::cerr << "Couldn't initialize a cube" << std::endl;
    return (false);
  }
  // if (cube->initialize() == false) {
  //   std::cerr << "Couldn't initialize a cube" << std::endl;
  //   return (false);
  // }
  // _objects.push_back(cube);
  _objects.push_back(marvin);
  return (true);
}

bool	GameRoutine::update() {
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return (false);
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->update(_clock, _input);
  return (true);
}

void	GameRoutine::draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
