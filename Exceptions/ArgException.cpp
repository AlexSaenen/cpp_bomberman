//
// DispRunError.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman/Exceptions
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri May 15 15:02:48 2015 Alexander Saenen
// Last update Fri May 15 15:08:31 2015 Alexander Saenen
//

#include "ArgException.hh"

ArgException::ArgException(std::string const &message)
  : invalid_argument(message), _message(message) { }

ArgException::~ArgException() throw() { }

ArgException::ArgException(const ArgException &other)
  : invalid_argument(other._message), _message(other._message) { }

ArgException	&ArgException::operator=(const ArgException &other) {
  if (this != &other)
    _message = other._message;
  return (*this);
}

std::string const	&ArgException::getMessage() const {
  return (_message);
}
