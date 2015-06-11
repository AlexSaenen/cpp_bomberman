//
// MenuModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 12:02:05 2015 Alexander Saenen
// Last update Thu Jun 11 17:27:47 2015 Alexander Saenen
//

#include <MenuModule.hh>
#include <MenuSpawner.hh>
#include <Button.hh>

MenuModule::MenuModule()
  : _isActive(false), _activePage(0) {
}

MenuModule::~MenuModule() {
  for (std::map<MenuPage, GameObject *>::iterator it = _pages.begin(); it != _pages.end(); ++it) {
    delete (*it).second;
  }
}

void	MenuModule::toggle(const bool status) {
  gdl::BasicShader	*shader;
  glm::mat4		transformation;

  shader = ModulesManager::getInstance()->get<GameRoutine>()->getShader();
  if (!status && _isActive) {
    ModulesManager::getInstance()->get<EventModule>()
      ->abandon("Display.update", 1001)
      ->abandon("Display.draw", 1001);
    transformation = glm::lookAt(glm::vec3(0, 10, -10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
    shader->bind();
    shader->setUniform("view", transformation);
  }
  else if (status && !_isActive) {
    ModulesManager::getInstance()->get<EventModule>()
      ->observe("Display.update", new Functor<MenuModule>(this, &MenuModule::_update), 1001)
      ->observe("Display.draw", new Functor<MenuModule>(this, &MenuModule::_draw), 1001);
    transformation = glm::lookAt(glm::vec3(0, 1.57, 0), glm::vec3(0, 0, 0), glm::vec3(-1, 0, 0));
    shader->bind();
    shader->setUniform("view", transformation);
  }
  _isActive = status;
}

bool	MenuModule::isActive() const {
  return (_isActive);
}

void	MenuModule::initialize(Event *) {
  ModulesManager::getInstance()->get<EventModule>()
    ->observe("Display.update", new Functor<MenuModule>(this, &MenuModule::_update), 1001)
    ->observe("Display.draw", new Functor<MenuModule>(this, &MenuModule::_draw), 1001);
  try {
    MenuSpawner	spawn;
    MenuModule::MenuPage	homeButtons[4] = { NEW, NSCORE, NOPTIONS, EXIT };
    _activePage = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_home_new.tga", homeButtons, 4);
    _pages.insert(std::make_pair<MenuPage, GameObject *>(HOME, _activePage));
    MenuModule::MenuPage	optionsButtons[3] = { MVOLUME, SVOLUME, HOME };
    _pages.insert(std::make_pair<MenuPage, GameObject *>
		  (OPTIONS, spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_options.tga",
						 optionsButtons, 3)));
  } catch (ArgException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1000)->handle();
    return ;
  }
  toggle(true);
}

void	MenuModule::_update(Event *ev) {
  GameRoutine	*gr;
  gdl::Input	*input;
  gdl::Clock	*clock;

  gr = ModulesManager::getInstance()->get<GameRoutine>();
  input = gr->getInput();
  clock = gr->getClock();
  ev->stop();
  if (input->getKey(SDLK_ESCAPE) || input->getInput(SDL_QUIT)) {
    ModulesManager::getInstance()->get<EventModule>()->trigger("Bomberman.quit", 1000);
    return ;
  }
  try {
    for (std::map<MenuPage, GameObject *>::iterator it = _pages.begin(); it != _pages.end(); ++it)
      if ((*it).second == _activePage)
  	(*it).second->update(*clock, *input);
  } catch (LogicException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1000)->handle();
  } catch (RuntimeException e) {
    std::cerr << e.getMessage() << std::endl;
    ModulesManager::getInstance()->get<EventModule>()
      ->trigger("Engine.error", 1000)->handle();
  }
}

void	MenuModule::_draw(Event *ev) {
  gdl::BasicShader	*shader;
  gdl::Clock		*clock;
  gdl::SdlContext	*context;
  GameRoutine		*gr;

  gr = ModulesManager::getInstance()->get<GameRoutine>();
  shader = gr->getShader();
  clock = gr->getClock();
  context = gr->getContext();
  ev->stop();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader->bind();
  for (std::map<MenuPage, GameObject *>::iterator it = _pages.begin(); it != _pages.end(); ++it)
    if ((*it).second == _activePage)
      (*it).second->draw(*shader, *clock);
  context->flush();
}

void	MenuModule::activatePage(const MenuPage page) {
  if (_pages.find(page) != _pages.end())
    if (_activePage != _pages[page])
      _activePage = _pages[page];
}
