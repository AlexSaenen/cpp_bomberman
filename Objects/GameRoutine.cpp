//
// GameRoutine.cpp for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon Apr 27 13:52:34 2015 Alexander Saenen
// Last update Fri May 29 16:07:16 2015 Alexander Saenen
//

#include <GameRoutine.hh>
#include <ArgException.hh>
#include <LogicException.hh>

#include <Player.hh>

GameRoutine::GameRoutine() {}

GameRoutine::~GameRoutine() {
  while (!_objects.empty()) {
    delete popGObject();
  }
}

bool	GameRoutine::initialize() {
  glm::mat4	projection;
  glm::mat4	transformation;
  GameObject	*marvin = new GameObject(GameObject::PLAYER1, "marvin");

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
  transformation = glm::lookAt(glm::vec3(0, 10, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
  try {
    marvin->pushComponent(new Player("./GraphicsLib/assets/warrior.fbx", marvin->getType()));
  } catch (ArgException e) {
    std::cerr << e.getMessage() << std::endl;
    return (false);
  }
  _objects.push_back(marvin);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Display.update"), new Functor<GameRoutine>(this, &GameRoutine::_update), 1000);
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Display.draw"), new Functor<GameRoutine>(this, &GameRoutine::_draw), 1000);
  return (true);
}

void	GameRoutine::_update(Event *) {
  this->update();
}

void	GameRoutine::_draw(Event *) {
  this->draw();
}

void	GameRoutine::pushGObject(GameObject *GObject) {
  _objects.push_back(GObject);
}

void	GameRoutine::popGObject(GameObject *GObject) {
  std::vector<GameObject *>::iterator it = _objects.begin();

  while (it != _objects.end() && (*it) != GObject)
    ++it;
  if ((*it) != GObject) {
    throw LogicException("Can't pop an element that isn't stacked");
  }
  _objects.erase(it);
}

GameObject	*GameRoutine::popGObject() {
  GameObject	*GObject;

  GObject = _objects.back();
  _objects.pop_back();
  return (GObject);
}

bool	GameRoutine::update() {
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT)) {
    ModulesManager::getInstance()->get<EventModule>()->trigger("Bomberman.quit", 1000);
    return (false);
  }
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  try {
    for (size_t i = 0; i < _objects.size(); ++i)
      _objects[i]->update(_clock, _input);
  } catch (LogicException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1000)->handle();
  } catch (RuntimeException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1000)->handle();
  }
  return (true);
}

void	GameRoutine::draw() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _context.flush();
}
