//
// Button.cpp for  in /home/vividy/rendu/cpp_bomberman
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 15:30:42 2015 Vividy
// Last update Sat Jun 13 17:18:21 2015 Alexander Saenen
//

#include <Button.hh>

Button::Button(const MenuModule::MenuPage linkedPage, const bool isSelected)
  : _isSelected(isSelected), _linkedPage(linkedPage), _buttonPressed(true), _cursor(0), _value(-42) {
  _actions[MenuModule::DEFAULT] = "Maps/default";
  _actions[MenuModule::PLAY] = "Maps/random.map";
  _actions[MenuModule::EXIT] = "Bomberman.quit";
  _sliderDelta[MenuModule::MVOLUME] = 0.01;
  _sliderDelta[MenuModule::SVOLUME] = 0.01;
  _sliderDelta[MenuModule::SIZE] = 2;
  _sliderDelta[MenuModule::NIA] = 1;
  _mapSetters[MenuModule::SIZE] = &MapModule::setSize;
  _mapSetters[MenuModule::NIA] = &MapModule::setIA;
  _musicSetters[MenuModule::MVOLUME] = &MusicModule::setMusicVolume;
  _musicSetters[MenuModule::SVOLUME] = &MusicModule::setSoundVolume;
  MusicModule	*music = ModulesManager::getInstance()->get<MusicModule>();
  MapModule	*map = ModulesManager::getInstance()->get<MapModule>();
  if (_sliderDelta.find(linkedPage) != _sliderDelta.end()) {
    _sliderValue[MenuModule::MVOLUME] = music->getMusicVolume();
    _sliderValue[MenuModule::SVOLUME] = music->getSoundVolume();
    _sliderValue[MenuModule::SIZE] = map->getSize();
    _sliderValue[MenuModule::NIA] = map->getIA();
    _value = _sliderValue[_linkedPage];
  }
}

Button::~Button() {
  delete _cursor;
}

void	Button::configure(const std::string &conf) {
  std::stringstream     *stream = new std::stringstream(conf);
  int                   type;

  *stream >> _position.x;
  *stream >> _position.z;
  *stream >> type;
  delete stream;
}

bool	Button::isSelected() const {
  return (_isSelected);
}

void	Button::select(const bool isSelected) {
  _isSelected = isSelected;
}

void	Button::activate() const {
  std::map<MenuModule::MenuPage, std::string>::const_iterator	it;
  it = _actions.find(_linkedPage);
  Event   *ev = new Event("Music.play");
  std::string     name("GraphicsLib/assets/MenuSamples/selectmenu.mp3");
  std::string     music("SOUND");
  ev->set<std::string>(std::string("FILE"), name);
  ev->set<std::string>(std::string("TYPE"), music);
  ModulesManager::getInstance()->get<EventModule>()->trigger(ev)->handle();
  if (it != _actions.end()) {
    ModulesManager::getInstance()->get<MenuModule>()->activatePage(MenuModule::HOME);
    std::string	event = (*it).second;
    if (event == "Bomberman.quit" || event == "GameMode.multi") {
      ModulesManager::getInstance()->get<EventModule>()->trigger(event)->handle();
      return ;
    }
    MapModule	*mapMod = ModulesManager::getInstance()->get<MapModule>();
    if (_linkedPage == MenuModule::PLAY) {
      MapGenerator map(mapMod->getSize(), mapMod->isMultiplayer() ? 2 : 1, mapMod->getIA());
      map.generate();
    }
    if (event == "Maps/default")
      event = mapMod->isMultiplayer() ? "Maps/defaultMul.map" : "Maps/default.map";
    Loader	ld(event);
    ld.execute();
    ModulesManager::getInstance()->get<MenuModule>()->toggle(false);
  }
  else {
    ModulesManager::getInstance()->get<MenuModule>()->activatePage(_linkedPage);
    if (_linkedPage == MenuModule::MULTIPLAYER)
      ModulesManager::getInstance()->get<EventModule>()->trigger("GameMode.multi")->handle();
  }
}

void	Button::initialize(Event *) { }

void	Button::update(const gdl::Clock &, gdl::Input &input) {
  if (_isSelected && input.getKey(SDLK_RETURN)) {
    if (!_buttonPressed) {
      _buttonPressed = true;
      activate();
    }
  }
  else if (_isSelected && !_buttonPressed && _sliderDelta.find(_linkedPage) != _sliderDelta.end()
	   && (input.getKey(SDLK_LEFT) || input.getKey(SDLK_RIGHT))) {
    _buttonPressed = true;
    MusicModule	*music = ModulesManager::getInstance()->get<MusicModule>();
    MapModule	*map = ModulesManager::getInstance()->get<MapModule>();
    if (input.getKey(SDLK_LEFT))
      _value -= _sliderDelta[_linkedPage];
    else if (input.getKey(SDLK_RIGHT))
      _value += _sliderDelta[_linkedPage];
    if (_mapSetters.find(_linkedPage) != _mapSetters.end())
      (ModulesManager::getInstance()->get<MapModule>()->*_mapSetters[_linkedPage])(_value);
    else if (_musicSetters.find(_linkedPage) != _musicSetters.end())
      (ModulesManager::getInstance()->get<MusicModule>()->*_musicSetters[_linkedPage])(_value);
    _sliderValue[MenuModule::MVOLUME] = music->getMusicVolume();
    _sliderValue[MenuModule::SVOLUME] = music->getSoundVolume();
    _sliderValue[MenuModule::SIZE] = map->getSize();
    _sliderValue[MenuModule::NIA] = map->getIA();
    _value = _sliderValue[_linkedPage];
  }
  else
    _buttonPressed = false;
}

void	Button::_writeSliderValue() const {
  std::list<gdl::Geometry *>	letters;
  std::list<gdl::Texture *>	textures;
  TexturesModule		*textMgr = ModulesManager::getInstance()->get<TexturesModule>();
  gdl::BasicShader		*shader = ModulesManager::getInstance()->get<GameRoutine>()->getShader();
  glm::vec3			pos = _position;
  int				divider;
  int				begin;

  if (_linkedPage == MenuModule::MVOLUME || _linkedPage == MenuModule::SVOLUME)
    begin = _value * 100;
  else
    begin = _value;
  for (divider = 1; divider <= begin; divider *= 10);
  if (divider > 1)
    divider /= 10;
  while (divider >= 1) {
    int	current = begin / divider;
    std::stringstream	strm;
    strm << "./GraphicsLib/assets/Textures/nb" << current << ".tga";
    letters.push_back(textMgr->getGeoInstance("letter"));
    textures.push_back(textMgr->getTextInstance(strm.str()));
    begin %= divider;
    divider /= 10;
  }
  pos.x += 0.135;
  pos.z -= 0.13;
  std::list<gdl::Geometry *>::iterator	geoIt = letters.begin();
  for (std::list<gdl::Texture *>::iterator it = textures.begin(); it != textures.end(); ++it) {
    (*it)->bind();
    glm::mat4			transform(1);
    transform = glm::translate(transform, pos);
    transform = glm::scale(transform, glm::vec3(0.1, 0.1, 0.1));
    (*geoIt)->draw(*shader, transform, GL_QUADS);
    pos.z -= 0.06;
    geoIt++;
  }
}

void	Button::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  if (_isSelected) {
    if (!_cursor) {
      _cursor = new Bomb(0, false);
      _cursor->initialize(0);
      std::stringstream	strm;
      strm << _position.x;
      strm << " ";
      strm << _position.z;
      strm << " 2 270 0 90 0.028 0.028 0.028 bomb";
      _cursor->configure(strm.str());
    }
    _cursor->draw(shader, clock);
  }
  if (_value != -42)
    _writeSliderValue();
}
