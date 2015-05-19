//
// LogicException.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:33:52 2015 Alexander Saenen
// Last update Tue May 19 12:34:37 2015 Alexander Saenen
//

#ifndef LOGICEXCEPTION_HH_
# define LOGICEXCEPTION_HH_

#include <stdexcept>
#include <string>

class LogicException : public std::logic_error
{
public:
  virtual ~LogicException() throw ();
  LogicException(std::string const &message);
  LogicException(const LogicException &other);
  LogicException &operator=(const LogicException &other);
  
  virtual std::string const &getMessage() const;
private:
  std::string	_message;
};

#endif /* LogicException.hh */
