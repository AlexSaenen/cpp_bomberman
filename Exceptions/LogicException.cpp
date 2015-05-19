//
// LogicException.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:32:48 2015 Alexander Saenen
// Last update Tue May 19 12:35:37 2015 Alexander Saenen
//

#include "LogicException.hh"

LogicException::LogicException(std::string const &message)
  : logic_error(message), _message(message) { }

LogicException::~LogicException() throw() { }

LogicException::LogicException(const LogicException &other)
  : logic_error(other._message), _message(other._message) { }

LogicException	&LogicException::operator=(const LogicException &other) {
  if (this != &other)
    _message = other._message;
  return (*this);
}

std::string const	&LogicException::getMessage() const {
  return (_message);
}
