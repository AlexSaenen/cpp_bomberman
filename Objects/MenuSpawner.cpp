//
// MenuSpawner.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 09:56:01 2015 Alexander Saenen
// Last update Fri Jun 12 18:00:47 2015 Alexander Saenen
//

#include <MenuSpawner.hh>

MenuSpawner::MenuSpawner() {
  _buttonPositions[MenuModule::OPTIONS] = std::string("0 0.6 0");
  _buttonPositions[MenuModule::HOME] = std::string("0.53 0.3 0");
  _buttonPositions[MenuModule::SCORE] = std::string("0 0.6 0");
  _buttonPositions[MenuModule::CONTINUE] = std::string("0 0.6 0");
  _buttonPositions[MenuModule::NEW] = std::string("-0.56 0.3 0");
  _buttonPositions[MenuModule::NSCORE] = std::string("-0.20 -0.45 0");
  _buttonPositions[MenuModule::NOPTIONS] = std::string("0.17 -0.45 0");
  _buttonPositions[MenuModule::SINGLEPLAYER] = std::string("0.01 0.95 0");
  _buttonPositions[MenuModule::MULTIPLAYER] = std::string("0 -0.4 0");
  _buttonPositions[MenuModule::DEFAULT] = std::string("0.01 0.9 0");
  _buttonPositions[MenuModule::RANDOM] = std::string("0 -0.42 0");
  _buttonPositions[MenuModule::MVOLUME] = std::string("-0.31 -0.39 0");
  _buttonPositions[MenuModule::SVOLUME] = std::string("0.07 -0.38 0");
  _buttonPositions[MenuModule::EXIT] = std::string("0.54 0.3 0");
  _buttonPositions[MenuModule::PLAY] = std::string("-0.56 0.3 0");
  _buttonPositions[MenuModule::NIA] = std::string("-0.31 -0.41 0");
  _buttonPositions[MenuModule::SIZE] = std::string("0.07 -0.41 0");
}

MenuSpawner::~MenuSpawner() { }

GameObject	*MenuSpawner::createMenuPage(const std::string &texture,
					     const MenuModule::MenuPage *pages, const size_t size) {
  GameObject	*go = new GameObject(GameObject::MENUPAGE, "menuPage");
  Wallpaper	*background = new Wallpaper;
  std::list<MenuModule::MenuPage>	buttons;

  buttons.clear();
  for (size_t i = 0; i < size; i++)
    buttons.push_back(pages[i]);
  background->initialize(0);
  background->configure("0 0 -1.85");
  background->setTexture(texture);
  go->pushComponent(background);
  for (std::list<MenuModule::MenuPage>::const_iterator it = buttons.begin();
       it != buttons.end(); ++it) {
    std::map<MenuModule::MenuPage, std::string>::iterator	at = _buttonPositions.find((*it));
    Button	*bt = new Button((*it));
    if (it == buttons.begin())
      bt->select(true);
    bt->configure((*at).second);
    go->pushComponent(bt);
  }
  return (go);
}
