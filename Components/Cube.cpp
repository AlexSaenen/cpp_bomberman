//
// Cube.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed May 27 15:35:31 2015 Alexander Saenen
// Last update Wed Jun  3 18:30:41 2015 Alexander Saenen
//

#include "Cube.hh"

Cube::Cube() { }

Cube::~Cube() { }

Cube	*Cube::setTexture(const std::string &texturePath) {
 if (_texture.load(texturePath) == false) {
    throw ArgException("Cannot load the cube texture : " + texturePath);
  }
 return (this);
}

void	Cube::initialize(Event *) {
  glm::vec2	uvMap[4] = {
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f)    
  };
  // glm::vec3	vertexMap[8] = {
  //   glm::vec3(0.5, -0.5, 0.5),
  //   glm::vec3(0.5, 0.5, 0.5),
  //   glm::vec3(-0.5, 0.5, 0.5),
  //   glm::vec3(-0.5, -0.5, 0.5),
  //   glm::vec3(0.5, -0.5, -0.5),
  //   glm::vec3(0.5, -0.5, 0.5),
  //   glm::vec3(-0.5, 0.5, -0.5),
  //   glm::vec3(-0.5, -0.5, -0.5)
  // };

  _speed = 10.0f;
  _scale.x = 2.5;
  _scale.y = 2.5;
  _scale.z = 2.5;
  _position.y = 1.2;

  _setTexture("./GraphicsLib/assets/wall_512_1_05.tga");

  _geometry.setColor(glm::vec4(0.64, 0.447, 0.46, 1));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.pushVertex(glm::vec3(0.5, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(-0.5, 0.5, 0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.pushVertex(glm::vec3(0.5, -0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(-0.5, -0.5, -0.5));
  for (int i = 0; i < 4; i++)
    _geometry.pushUv(uvMap[i]);
  _geometry.build();
}

void	Cube::update(const gdl::Clock &, gdl::Input &) {
}

void	Cube::draw(gdl::AShader &shader, const gdl::Clock &) {
  _texture.bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}

void	Cube::configure(const std::string &conf)
{
  (void)conf;
  // _position.x = 1.8;
  // _position.y = 1.8;
  // _position.z = 1.8;
}
