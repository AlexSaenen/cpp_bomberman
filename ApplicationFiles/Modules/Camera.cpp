//
// Camera.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun 12 13:02:38 2015 Alexander Saenen
// Last update Sun Jun 14 17:24:34 2015 Alexander Saenen
//

#include <Camera.hh>

Camera::Camera()
  : _eye(0, 10, -10), _center(0, 0, 0), _up(0, 1, 0), _fovy(60.0f), _aspect(800.0f / 600.0f), _near(0.1f), _far(1000.0f), _followPlayers(false), _isMulti(false) {
  _shader = ModulesManager::getInstance()->get<GameRoutine>()->getShader();
  confirm();
}

Camera::~Camera() { }

void	Camera::setCameraMode(const bool isMulti) {
  _isMulti = isMulti;
}

Camera	*Camera::followPlayers(const bool follow) {
  _followPlayers = follow;
  return (this);
}

Camera	*Camera::set3Dimension(const bool status) {
  if (!status)
    _up = glm::vec3(-1, 0, 0);
  else
    _up = glm::vec3(0, 1, 0);
  return (this);
}

Camera	*Camera::setPerspective(const float fovy, const float aspect, const float near, const float far) {
  _fovy = fovy;
  _aspect = aspect;
  _near = near;
  _far = far;
  return (this);
}

Camera	*Camera::setLookAt(const glm::vec3 &eye) {
  _eye = eye;
  return (this);
}

glm::vec3	Camera::getPlayerPos(const GameObject::ObjectType type) const {
  std::vector<GameObject *> players;
  if (!ModulesManager::getInstance()->get<GameRoutine>()->getGOStatus(type, players))
    return (glm::vec3(0, 0, 0));
  GameObject *player = players.back();
  std::list<IComponent *> components = player->getComponents();
  Shape	*shape = 0;
  for (std::list<IComponent *>::const_iterator it = components.begin();
       it != components.end() && !shape; ++it)
    shape = dynamic_cast<Shape *>(*it);
  if (!shape)
    throw RuntimeException("GameObject hasn't got a shape");
  glm::vec3	pos(0, 0, 0);
  pos.x = shape->getPosX();
  if (pos.x == 0)
    pos.x = 0.00001;
  pos.z = shape->getPosY();
  return (pos);
}

void	Camera::confirm() {
  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(_fovy, _aspect, _near, _far);
  if (!_followPlayers)
    transformation = glm::lookAt(_eye, _center, _up);
  else {
    glm::vec3	center(0.0f, 0.0f, 0.0f);
    glm::vec3	eye(0.1f, 15.1f, 0.1f);
    glm::vec3	posPOne = getPlayerPos(GameObject::PLAYER1);
    glm::vec3	posPTwo = posPOne;
    if (_isMulti)
      posPTwo = getPlayerPos(GameObject::PLAYER2);
    glm::vec3	combined(posPOne.x - posPTwo.x, posPOne.z - posPTwo.z, 0);
    eye.x = (posPOne.x + posPTwo.x) / 2;
    eye.z = ((posPOne.z + posPTwo.z) / 2) - 15;
    if (_isMulti)
      eye.y = (sqrt(((combined.x) * (combined.x)) + ((combined.y) * (combined.y))) / 1.2) + 15;
    center.x = eye.x;
    center.z = eye.z + 15.0;
    transformation = glm::lookAt(eye, center, _up);
  }
  _shader->bind();
  _shader->setUniform("view", transformation);
  _shader->setUniform("projection", projection);  
}
