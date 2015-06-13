//
// Wallpaper.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 15:35:31 2015 Alexander Saenen
// Last update Sat Jun 13 10:31:56 2015 Alexander Saenen
//

#include "Wallpaper.hh"

Wallpaper::Wallpaper() { }

Wallpaper::~Wallpaper() { }

Wallpaper	*Wallpaper::setTexture(const std::string &texturePath) {
  _texture = ModulesManager::getInstance()->get<TexturesModule>()
    ->getTextInstance(texturePath);
  return (this);
}

void	Wallpaper::initialize(Event *) {
  // glm::vec2	uvMap[4] = {
  //   glm::vec2(0.0f, 0.0f),
  //   glm::vec2(1.0f, 0.0f),
  //   glm::vec2(1.0f, 1.0f),
  //   glm::vec2(0.0f, 1.0f)    
  // };
  _speed = 10.0f;
  _scale.x = 2.5;
  _scale.y = 2.5;
  _scale.z = 2.5;
  _geometry = ModulesManager::getInstance()->get<TexturesModule>()
    ->getGeoInstance("Wall");
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.667));
  // _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.667));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.667));
  // _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.667));
  // for (int i = 0; i < 4; i++)
  //   _geometry.pushUv(uvMap[i]);
  // _geometry.build();
}

void	Wallpaper::update(const gdl::Clock &, gdl::Input &) { }

void	Wallpaper::draw(gdl::AShader &shader, const gdl::Clock &) {
  _texture->bind();
  _geometry->draw(shader, getTransformation(), GL_QUADS);
}

void	Wallpaper::configure(const std::string &conf)
{
  std::stringstream	*stream = new std::stringstream(conf);
  
  *stream >> _position.x;
  *stream >> _position.z;
  *stream >> _position.y;
  delete stream;
}
