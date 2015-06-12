//
// MenuModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 12:02:05 2015 Alexander Saenen
// Last update Fri Jun 12 16:09:13 2015 Thibaud PEAUGER
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
  if (!status && _isActive) {
    ModulesManager::getInstance()->get<EventModule>()
      ->abandon("Display.update", 1001)
      ->abandon("Display.draw", 1001);
    Event   *ev = new Event("Music.play");
    std::string     name("GraphicsLib/assets/GameMusic/cirno.mp3");
    std::string     music("MUSIC");
    ev->set<std::string>(std::string("FILE"), name);
    ev->set<std::string>(std::string("TYPE"), music);
    ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();

    ModulesManager::getInstance()->get<Camera>()
      ->setLookAt(glm::vec3(0, 10, -10))
      ->set3Dimension()
      ->confirm();
  }
  else if (status && !_isActive) {
    ModulesManager::getInstance()->get<EventModule>()
      ->observe("Display.update", new Functor<MenuModule>(this, &MenuModule::_update), 1001)
      ->observe("Display.draw", new Functor<MenuModule>(this, &MenuModule::_draw), 1001);
    ModulesManager::getInstance()->get<Camera>()
      ->setLookAt(glm::vec3(0, 1.57, 0))
      ->set3Dimension(false)
      ->confirm();
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
    MenuPage	hButtons[4] = { NEW, NSCORE, NOPTIONS, EXIT };
    _activePage = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_home_new.tga", hButtons, 4);
    _pages[HOME] = _activePage;
    MenuPage	oButtons[3] = { MVOLUME, SVOLUME, HOME };
    _pages[NOPTIONS] = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_options.tga", oButtons, 3);
    MenuPage	cButtons[2] = { SINGLEPLAYER, MULTIPLAYER };
    _pages[NEW] = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_type.tga", cButtons, 2);
    MenuPage	mButtons[2] = { DEFAULT, RANDOM };
    _pages[SINGLEPLAYER] = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_map.tga", mButtons, 2);
    _pages[MULTIPLAYER] = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_map.tga", mButtons, 2);
    MenuPage	rButtons[4] = { PLAY, NIA, SIZE, HOME };
    _pages[RANDOM] = spawn.createMenuPage("./GraphicsLib/assets/Textures/menu_random.tga", rButtons, 4);
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
