//
// RangeException.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:33:41 2015 Alexander Saenen
// Last update Mon Jun  8 10:37:47 2015 Alexander Saenen
//

#include "RangeException.hh"

RangeException::RangeException(std::string const &message)
  : invalid_argument(message), _message(message) { }

RangeException::~RangeException() throw() { }

RangeException::RangeException(const RangeException &other)
  : invalid_argument(other._message), _message(other._message) { }

RangeException	&RangeException::operator=(const RangeException &other) {
  if (this != &other)
    _message = other._message;
  return (*this);
}

std::string const	&RangeException::getMessage() const {
  return (_message);
}
