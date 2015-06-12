//
// Event.hh for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Mon May  4 18:52:45 2015 Alexander Saenen
// Last update Fri Jun 12 14:43:55 2015 Thibaud PEAUGER
//

#ifndef EVENT_HH_
# define EVENT_HH_

# include <string>
# include <map>

class Event
{
public:
  Event(const std::string &name, const int priority = 0);
  ~Event();

private:
  std::map<std::string, void *>	_parameters;
  std::string const	_name;
  bool			_propagate;
  int const		_priority;

public:
  std::string const	&getName() const;
  bool			propagate() const;
  int			priority() const;

  template<typename T> void	set(std::string name, T &what);
  template<typename T> T	get(const std::string &name);

  void			stop();

  class	CompareE
  {
  public:
    bool	operator()(const Event *lhs, const Event *rhs) const;
  };
};

#endif /* Event.hh */
