//
// Event.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:09:26 2015 Alexander Saenen
// Last update Mon Jun  8 11:02:55 2015 Alexander Saenen
//

#include "Event.hh"
#include "RangeException.hh"

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
  this->_parameters.insert(std::make_pair(name, reinterpret_cast<void *>(&what)));
}

template<typename T>
T	Event::get(const std::string &name) {
  if (this->_parameters.find(name) == this->_parameters.end())
    throw RangeException("Tried to get a parameter when none are available");
  return *(reinterpret_cast<T *>(this->_parameters[name]));
}

void	Event::stop() {
  this->_propagate = false;
}

bool	Event::CompareE::operator()(const Event *lhs, const Event *rhs) const {
  return (lhs->priority() < rhs->priority());
}

template void	Event::set<std::string>(std::string &name, std::string &what);
template std::string	Event::get<std::string>(const std::string &name);
