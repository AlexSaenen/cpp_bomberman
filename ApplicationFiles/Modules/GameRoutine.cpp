//
// GameRoutine.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 18:01:41 2015 Alexander Saenen
// Last update Thu Jun 11 22:04:35 2015 Alexander Saenen
//

#include <GameRoutine.hh>
#include <ArgException.hh>
#include <LogicException.hh>
#include <RuntimeException.hh>
#include <RangeException.hh>

GameRoutine::GameRoutine() {}

GameRoutine::~GameRoutine() {
  for (int it = 0; it < 9; ++it) {
    GameObject::ObjectType i = static_cast<GameObject::ObjectType>(it);
    while (!_objects[i].empty()) {
      delete _objects[i].back();
      _objects[i].pop_back();
    }
  }
}

#include <PlayerOne.hh>
#include <GameObject.hh>
#include <GameModule.hh>

bool	GameRoutine::initialize() {
  glm::mat4	projection;
  glm::mat4	transformation;

  if (!_context.start(1280, 720, "Bomb the House")) {
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
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("Display.update"), new Functor<GameRoutine>(this, &GameRoutine::_update), 1000)
    ->observe(std::string("Display.draw"), new Functor<GameRoutine>(this, &GameRoutine::_draw), 1000);
  return (true);
}

void	GameRoutine::_update(Event *) {
  this->update();
}

void	GameRoutine::_draw(Event *) {
  this->draw();
}

std::vector<GameObject *>	GameRoutine::getGObjects(const GameObject::ObjectType type) {
  if (_objects.find(type) == _objects.end())
    throw RangeException("Couldn't find the GObjects for this type");
  return (_objects[type]);
}

void	GameRoutine::pushGObject(GameObject *GObject) {
  _objects[GObject->getType()].push_back(GObject);
}

void	GameRoutine::popGObject(GameObject *GObject) {
  std::vector<GameObject *>	typedObjects = _objects[GObject->getType()];
  std::vector<GameObject *>::iterator it = typedObjects.begin();

  while (it != typedObjects.end() && (*it) != GObject)
    ++it;
  if ((*it) != GObject) {
    throw LogicException("Can't pop an element that isn't stacked");
  }
  typedObjects.erase(it);
}

gdl::BasicShader	*GameRoutine::getShader() {
  return (&_shader);
}

gdl::Clock	*GameRoutine::getClock() {
  _context.updateClock(_clock);
  return (&_clock);
}

gdl::Input	*GameRoutine::getInput() {
  _context.updateInputs(_input);
  return (&_input);
}

gdl::SdlContext	*GameRoutine::getContext() {
  return (&_context);
}

bool	GameRoutine::update() {
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT)) {
    ModulesManager::getInstance()->get<EventModule>()->trigger("Bomberman.quit", 1000);
    return (false);
  }
  try {
    for (int it = 0; it < 9; ++it) {
      GameObject::ObjectType ot = static_cast<GameObject::ObjectType>(it);
      for (size_t i = 0; i < _objects[ot].size(); ++i)
	_objects[ot][i]->update(_clock, _input);
    }
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
  for (int it = 0; it < 9; ++it) {
    GameObject::ObjectType ot = static_cast<GameObject::ObjectType>(it);
    for (size_t i = 0; i < _objects[ot].size(); ++i)
      _objects[ot][i]->draw(_shader, _clock);
  }
  _context.flush();
}
