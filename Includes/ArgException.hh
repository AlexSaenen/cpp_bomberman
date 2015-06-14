//
// ArgException.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 12:33:29 2015 Alexander Saenen
// Last update Sun Jun 14 16:48:36 2015 Vividy
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
