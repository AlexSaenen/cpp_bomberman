//
// MapModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 11:16:49 2015 Alexander Saenen
// Last update Fri Jun  5 15:36:22 2015 Alexander Saenen
//

#include <MapModule.hh>

MapModule::MapModule()
  : _hasTextures(false) {
  _size = 0;
}

MapModule::~MapModule() { }

void	MapModule::loadMapValues() {
  _textureMap["cube"] = "./GraphicsLib/assets/stone.tga";
  _textureMap["destroy"] = "./GraphicsLib/assets/crate.tga";
  _hasTextures = true;
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
  _size = size;
}
