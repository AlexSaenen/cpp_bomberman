//
// Camera.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun 12 12:55:54 2015 Alexander Saenen
// Last update Fri Jun 12 17:34:00 2015 Alexander Saenen
//

#ifndef CAMERA_HH_
# define CAMERA_HH_

# include <AModule.hh>
# include <BasicShader.hh>
# include <ModulesManager.hpp>
# include <glm/glm.hpp>

class	Camera : public AModule
{
  glm::vec3	_eye;
  glm::vec3	_center;
  glm::vec3	_up;
  float	_fovy;
  float	_aspect;
  float	_near;
  float	_far;
  gdl::BasicShader	*_shader;
  bool		_followPlayers;
  bool		_isMulti;

public:
  Camera();
  virtual ~Camera();

  Camera	*setPerspective(const float fovy, const float aspect, const float near, const float far);
  Camera	*setLookAt(const glm::vec3 &eye);
  Camera	*set3Dimension(const bool status = true);
  Camera	*followPlayers(const bool follow = true);
  void		confirm();
  void		setCameraMode(const bool isMulti);

private:
  glm::vec3	getPlayerPos(const GameObject::ObjectType type) const;
};

#endif /* Camera.hh */
