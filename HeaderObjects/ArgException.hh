//
// DispRunError.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri May 15 15:04:11 2015 Alexander Saenen
// Last update Fri May 15 15:06:32 2015 Alexander Saenen
//

#ifndef ARGEXCEPTION_HH_
# define ARGEXCEPTION_HH_

#include <stdexcept>
#include <string>

class ArgException : public std::invalid_argument
{
public:
  virtual ~ArgException() throw ();
  ArgException(std::string const &message);
  ArgException(const ArgException &other);
  ArgException &operator=(const ArgException &other);
  
  virtual std::string const &getMessage() const;
private:
  std::string	_message;
};

#endif /* ArgException.hh */
