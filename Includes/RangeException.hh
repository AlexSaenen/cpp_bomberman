//
// RangeException.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:33:29 2015 Alexander Saenen
// Last update Sun Jun 14 17:50:19 2015 Vividy
//

#ifndef RANGEEXCEPTION_HH_
# define RANGEEXCEPTION_HH_

#include <stdexcept>
#include <string>

class RangeException : public std::invalid_argument
{
public:
  virtual ~RangeException() throw ();
  RangeException(std::string const &message);
  RangeException(const RangeException &other);
  RangeException &operator=(const RangeException &other);

  virtual std::string const &getMessage() const;
private:
  std::string	_message;
};

#endif /* RangeException.hh */
