//
// ObjModel.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Components
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 12 17:13:34 2015 Alexander Saenen
// Last update Thu May 21 13:57:07 2015 Alexander Saenen
//

#include <ObjModel.hh>
#include <GameObject.hh>

#include <Input.hh>

ObjModel::ObjModel(const std::string &model, const GameObject::ObjectType type)
  : _modelName(model), _isLoaded(false), _isMoving(false), _animDuration(0), _lastMovement(0), _type(type) {
  _movementMap.insert(std::pair<int, int>(SDLK_UP, 0));
  _movementMap.insert(std::pair<int, int>(SDLK_DOWN, 180));
  _movementMap.insert(std::pair<int, int>(SDLK_LEFT, 90));
  _movementMap.insert(std::pair<int, int>(SDLK_RIGHT, 270));
  /* Configure differently for player 2 and IA */
}

ObjModel::~ObjModel() { }

void	ObjModel::initialize(Event *) {
  _speed = 10.0f;
  _scale.x = 0.004;
  _scale.y = 0.004;
  _scale.z = 0.004;
  if (_model.load(_modelName) == false) {
    throw ArgException("Cannot load the model : " + _modelName);
  }
  _isLoaded = true;
  _model.createSubAnim(0, "Run.start", 0, 40);
  _model.createSubAnim(0, "Run", 40, 60);
  _model.createSubAnim(0, "Run.stop", 60, 140);
}

void	ObjModel::playAnimation(const std::string &animation, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set an Animation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentAnim(animation, loop)) {
    throw RuntimeException("Couldn't launch the animation : " + animation);
  }
}

void	ObjModel::playAnimation(int stack, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set an Animation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentAnim(stack, loop)) {
    throw RuntimeException("Couldn't launch the animation");
  }
}

void	ObjModel::playSubAnim(const std::string &subAnimation, bool loop) {
  if (!_isLoaded) {
    throw LogicException("Can't set a subAnimation when the model hasn't been loaded yet");
  }
  if (!_model.setCurrentSubAnim(subAnimation, loop)) {
    throw RuntimeException("Couldn't launch the subAnimation");
  }  
}

void	ObjModel::update(const gdl::Clock &clock, gdl::Input &input) {
  if (_lastMovement && !input.getKey(_lastMovement) && _isMoving) {
    playSubAnim("Run.stop", false);
    _lastMovement = 0;
    _isMoving = false;
  }
  for (std::map<int, int>::const_iterator it = _movementMap.begin(); it != _movementMap.end(); ++it)
    if (input.getKey((*it).first)) {
      _rotation.y = _movementMap[(*it).first];
      if (input.getKey((*it).first)) {
	if (!_lastMovement) {
	  playSubAnim("Run.start", false);
	  _animDuration = 40 * _model.getFrameDuration();
	}
	else if (_animDuration <= 0 && !_isMoving) {
	  playSubAnim("Run");
	  _isMoving = true;
	}
	else
	  _animDuration -= clock.getElapsed();
	_lastMovement = (*it).first;
      }
    }
  std::cout << _model.getAnimationFrameNumber(0) << std::endl;
}

void	ObjModel::draw(gdl::AShader &shader, const gdl::Clock &clock) {
  _model.draw(shader, getTransformation(), clock.getElapsed());
}
