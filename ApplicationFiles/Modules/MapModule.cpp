//
// MapModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 11:16:49 2015 Alexander Saenen
// Last update Sun Jun 14 22:53:15 2015 Alexander Saenen
//

#include <MapModule.hh>

MapModule::MapModule()
  : _hasTextures(false), _isMultiplayer(false) {
  _size = 5;
  _ia = 0;
}

MapModule::~MapModule() { }

bool	MapModule::isMultiplayer() const {
  return (_isMultiplayer);
}

void	MapModule::setGameMode(Event *ev) {
  if (ev->getName() == "GameMode.multi") {
    _isMultiplayer = true;
    ModulesManager::getInstance()->get<Camera>()->setCameraMode(true);
  }
}

void	MapModule::loadMapValues() {
  _textureMap["cube"] = "./GraphicsLib/assets/Textures/stone.tga";
  _textureMap["destroy"] = "./GraphicsLib/assets/Textures/crate.tga";
  _textureMap["bonus0"] = "./GraphicsLib/assets/Textures/Bomberman_Bombs.tga";
  _textureMap["bonus2"] = "./GraphicsLib/assets/Textures/Bomberman_Flames.tga";
  _textureMap["bonus1"] = "./GraphicsLib/assets/Textures/Bomberman_Speed.tga";
  _textureMap["bomb"] = "./GraphicsLib/assets/bomb.fbx";
  _textureMap["player1"] = "./GraphicsLib/assets/archer.fbx";
  _textureMap["player2"] = "./GraphicsLib/assets/warrior.fbx";
  _textureMap["ia1"] = "./GraphicsLib/assets/skeletarcher.fbx";
  _textureMap["ia2"] = "./GraphicsLib/assets/skeletwarrior1.fbx";
  _textureMap["ia3"] = "./GraphicsLib/assets/skeletwarrior2.fbx";
  _textureMap["ia4"] = "./GraphicsLib/assets/skeletwarrior3.fbx";
  _hasTextures = true;
  ModulesManager::getInstance()->get<EventModule>()
    ->observe(std::string("GameMode.multi"), new Functor<MapModule>(this, &MapModule::setGameMode), 1000);
}

std::string	MapModule::getTexturePath(const std::string &textureType) const {
  std::map<std::string, std::string>::const_iterator	it;

  if (!_hasTextures)
    throw LogicException("No map textures are loaded");
  it = _textureMap.find(textureType);
  if (it == _textureMap.end())
    throw ArgException("Trying to load a texture that doesn't exist");
  return ((*it).second);
}

int     MapModule::getSize() const {
  return (_size);
}

void    MapModule::setSize(const int size) {
  if (size >= 5 && size % 2 != 0)
    _size = size;
  if (_size > 499)
    _size = 499;
}

int     MapModule::getIA() const {
  return (_ia);
}

void    MapModule::setIA(const int ia) {
  if (ia >= 0)
    _ia = ia;
  if (_ia > 50)
    _ia = 50;
}

bool	MapModule::isLoaded() const {
  return (_hasTextures);
}
