//
// Camera.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun 12 13:02:38 2015 Alexander Saenen
// Last update Fri Jun 12 16:13:54 2015 Alexander Saenen
//

#include <Camera.hh>

Camera::Camera()
  : _eye(0, 10, -10), _center(0, 0, 0), _up(0, 1, 0), _fovy(60.0f), _aspect(800.0f / 600.0f), _near(0.1f), _far(100.0f), _followPlayers(false) {
  _shader = ModulesManager::getInstance()->get<GameRoutine>()->getShader();
  confirm();
}

Camera::~Camera() { }

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

void	Camera::confirm() {
  glm::mat4 projection;
  glm::mat4 transformation;

  projection = glm::perspective(_fovy, _aspect, _near, _far);
  if (!_followPlayers)
    transformation = glm::lookAt(_eye, _center, _up);
  else {
    std::vector<GameObject *> players = ModulesManager::getInstance()->get<GameRoutine>()
      ->getGObjects(GameObject::PLAYER1);
    GameObject *player = players.back();
    std::list<IComponent *> components = player->getComponents();
    Shape	*shape = 0;
    for (std::list<IComponent *>::const_iterator it = components.begin();
	 it != components.end() && !shape; ++it)
      shape = dynamic_cast<Shape *>(*it);
    if (!shape)
      return ;
    glm::vec3	eye(0, 15, 0);
    glm::vec3	center(0, 0, 0);
    eye.x = shape->getPosX();
    if (eye.x == 0)
      eye.x = 0.001;
    eye.z = shape->getPosY() - 15;
    center.x = eye.x;
    center.z = eye.z + 15;
    transformation = glm::lookAt(eye, center, _up);
  }
  _shader->bind();
  _shader->setUniform("view", transformation);
  _shader->setUniform("projection", projection);  
}
