//
// Event.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:09:26 2015 Alexander Saenen
// Last update Tue May 19 11:09:27 2015 Alexander Saenen
//

#include "Event.hh"

Event::Event(const std::string &name, const int priority)
  : _name(name), _propagate(true), _priority(priority) { }

Event::~Event() { }

std::string const	&Event::getName() const {
  return (this->_name);
}

bool	Event::propagate() const {
  return (this->_propagate);
}

int	Event::priority() const {
  return (this->_priority);
}

template<typename T>
void	Event::set(std::string &name, T &what) {
  // TODO : specialize this template to handle scalar types
  this->_parameters.insert(std::make_pair(name, (void *) what));
}

template<typename T>
T	Event::get(const std::string &name) {
  // TODO : handle errors here (find != empty => throw)
  return reinterpret_cast<T>(this->_parameters[name]);
}

void	Event::stop() {
  this->_propagate = false;
}

bool	Event::CompareE::operator()(const Event *lhs, const Event *rhs) const {
  return (lhs->priority() < rhs->priority());
}
