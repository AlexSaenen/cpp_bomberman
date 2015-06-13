//
// TexturesModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Thu Jun 11 16:18:18 2015 Alexander Saenen
// Last update Sat Jun 13 12:28:35 2015 Alexander Saenen
//

#include <TexturesModule.hh>

TexturesModule::TexturesModule() { }

TexturesModule::~TexturesModule() {
  for (std::map<std::string, gdl::Texture *>::iterator it = _textureInstances.begin();
       it != _textureInstances.end(); ++it) {
    delete (*it).second;
  }
  for (std::map<std::string, gdl::Geometry *>::iterator it = _geometryInstances.begin();
       it != _geometryInstances.end(); ++it) {
    delete (*it).second;
  }
}

gdl::Texture	*TexturesModule::getTextInstance(const std::string &texture) {
  if (_textureInstances.find(texture) == _textureInstances.end()) {
    gdl::Texture	*_texture = new gdl::Texture;
    if (_texture->load(texture) == false)
      throw ArgException("Cannot load the cube texture : " + texture);
    _textureInstances[texture] = _texture;
  }
  return (_textureInstances[texture]);
}

gdl::Geometry	*TexturesModule::getGeoInstance(const std::string &geometry) {
  if (_geometryInstances.find(geometry) == _geometryInstances.end()) {
    gdl::Geometry	*_geometry = new gdl::Geometry;
    if (geometry == "Cube")
      _loadCubeGeometry(_geometry);
    else if (geometry == "Wall")
      _loadWallGeometry(_geometry);
    else
      _loadLetterGeometry(_geometry);
    _geometryInstances[geometry] = _geometry;
  }
  return (_geometryInstances[geometry]);
}

void	TexturesModule::_loadCubeGeometry(gdl::Geometry *_geometry) const {
  glm::vec2     uvMap[4] = {
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f)
  };
  glm::vec3     vertexMap[8] = {
    glm::vec3(0.5, 0.5, 0.5),
    glm::vec3(0.5, 0.5, -0.5),
    glm::vec3(0.5, -0.5, 0.5),
    glm::vec3(0.5, -0.5, -0.5),
    glm::vec3(-0.5, 0.5, 0.5),
    glm::vec3(-0.5, 0.5, -0.5),
    glm::vec3(-0.5, -0.5, 0.5),
    glm::vec3(-0.5, -0.5, -0.5)
  };
  int           vertexOrder[16] = {
    3, 1, 5, 7, 3, 1, 0, 2,
    6, 4, 5, 7, 0, 1, 5, 4
  };
  _geometry->setColor(glm::vec4(0.64, 0.447, 0.46, 1));
  for (int i = 0; i < 16; ++i) {
    _geometry->pushVertex(vertexMap[vertexOrder[i]]);
    if (i > 0 && (i + 1) % 4 == 0)
      for (int i = 0; i < 4; i++)
        _geometry->pushUv(uvMap[i]);
  }
  _geometry->build();
}

void	TexturesModule::_loadWallGeometry(gdl::Geometry *_geometry) const {
  glm::vec2     uvMap[4] = {
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f)
  };
  _geometry->pushVertex(glm::vec3(0.5, 0.5, 0.667));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, -0.667));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, -0.667));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, 0.667));
  for (int i = 0; i < 4; i++)
    _geometry->pushUv(uvMap[i]);
  _geometry->build();
}

void	TexturesModule::_loadLetterGeometry(gdl::Geometry *_geometry) const {
  glm::vec2     uvMap[4] = {
    glm::vec2(0.0f, 0.0f),
    glm::vec2(1.0f, 0.0f),
    glm::vec2(1.0f, 1.0f),
    glm::vec2(0.0f, 1.0f)
  };
  _geometry->pushVertex(glm::vec3(0.5, 0.5, 0.3));
  _geometry->pushVertex(glm::vec3(0.5, 0.5, -0.3));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, -0.3));
  _geometry->pushVertex(glm::vec3(-0.5, 0.5, 0.3));
  for (int i = 0; i < 4; i++)
    _geometry->pushUv(uvMap[i]);
  _geometry->build();
}
