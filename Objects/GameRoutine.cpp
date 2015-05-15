//
// GameRoutine.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 13:52:34 2015 Alexander Saenen
// Last update Fri May 15 09:49:16 2015 Alexander Saenen
//

#include "GameRoutine.hh"


#include <ObjModel.hh>

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
  GameObject	*cube = new GameObject(GameObject::CUBE, "cubedetest");
  GameObject	*marvin = new GameObject(GameObject::PLAYER1, "marvin");
  GameObject	*ralouf = new GameObject(GameObject::PLAYER2, "ralouf");

  if (!_context.start(800, 600, "Bomb the House")) {
    std::cerr << "Error while trying to start the openGL context" << std::endl;
    return (false);
  }
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./GraphicsLib/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./GraphicsLib/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build()) {
    std::cerr << "Error while trying to load the shaders" << std::endl;
    return (false);
  }
  projection = glm::perspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  if (cube->pushComponent(new Cube) == false) {
    std::cerr << "Couldn't initialize a cube" << std::endl;
    return (false);
  }
  if (marvin->pushComponent(new ObjModel("./GraphicsLib/assets/marvin.fbx", marvin->getType())) == false) {
    std::cerr << "Couldn't initialize a model" << std::endl;
    return (false);    
  }
  if (ralouf->pushComponent(new ObjModel("./GraphicsLib/assets/death_knight/deathknight.fbx", marvin->getType())) == false) {
    std::cerr << "Couldn't initialize a model" << std::endl;
    return (false);    
  }
  _objects.push_back(cube);
  _objects.push_back(marvin);
  // _objects.push_back(ralouf);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.update"), new Functor<GameRoutine>(this, &GameRoutine::_update), 1000);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Application.draw"), new Functor<GameRoutine>(this, &GameRoutine::_draw), 1000);
  return (true);
}

void	GameRoutine::_update(Event *) {
  this->update();
}

void	GameRoutine::_draw(Event *) {
  this->draw();
}

bool	GameRoutine::update() {
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT)) {
    ModulesManager::getInstance()->get<EventModule>()->trigger("Application.quit", 1000);
    return (false);
  }
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
