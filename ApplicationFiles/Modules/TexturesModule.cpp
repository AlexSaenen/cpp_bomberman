//
// TexturesModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 16:18:18 2015 Alexander Saenen
// Last update Thu Jun 11 20:18:26 2015 Alexander Saenen
//

#include <TexturesModule.hh>

TexturesModule::TexturesModule() { }

TexturesModule::~TexturesModule() {
  for (std::map<std::string, gdl::Texture *>::iterator it = _textureInstances.begin();
       it != _textureInstances.end(); ++it) {
    delete (*it).second;
  }
}

gdl::Texture	*TexturesModule::getInstance(const std::string &texture) {
  if (_textureInstances.find(texture) == _textureInstances.end()) {
    gdl::Texture	*_texture = new gdl::Texture;
    if (_texture->load(texture) == false)
      throw ArgException("Cannot load the cube texture : " + texture);
    _textureInstances[texture] = _texture;
  }
  return (_textureInstances[texture]);
}
