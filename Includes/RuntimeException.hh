//
// RuntimeException.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:33:52 2015 Alexander Saenen
// Last update Tue May 19 18:01:56 2015 Alexander Saenen
//

#ifndef RUNTIMEEXCEPTION_HH_
# define RUNTIMEEXCEPTION_HH_

#include <stdexcept>
#include <string>

class RuntimeException : public std::runtime_error
{
public:
  virtual ~RuntimeException() throw ();
  RuntimeException(std::string const &message);
  RuntimeException(const RuntimeException &other);
  RuntimeException &operator=(const RuntimeException &other);
  
  virtual std::string const &getMessage() const;
private:
  std::string	_message;
};

#endif /* RuntimeException.hh */
