//
// Camera.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun 12 12:55:54 2015 Alexander Saenen
// Last update Fri Jun 12 13:31:39 2015 Alexander Saenen
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

public:
  Camera();
  virtual ~Camera();

  Camera	*setPerspective(const float fovy, const float aspect, const float near, const float far);
  Camera	*setLookAt(const glm::vec3 &eye);
  Camera	*set3Dimension(const bool status = true);
  void	confirm();
};

#endif /* Camera.hh */
