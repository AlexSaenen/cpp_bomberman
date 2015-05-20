//
// RuntimeException.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:32:48 2015 Alexander Saenen
// Last update Tue May 19 18:03:44 2015 Alexander Saenen
//

#include "RuntimeException.hh"

RuntimeException::RuntimeException(std::string const &message)
  : runtime_error(message), _message(message) { }

RuntimeException::~RuntimeException() throw() { }

RuntimeException::RuntimeException(const RuntimeException &other)
  : runtime_error(other._message), _message(other._message) { }

RuntimeException	&RuntimeException::operator=(const RuntimeException &other) {
  if (this != &other)
    _message = other._message;
  return (*this);
}

std::string const	&RuntimeException::getMessage() const {
  return (_message);
}
