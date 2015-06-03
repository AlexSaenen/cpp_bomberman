//
// EventModule.hh for bomberman in /home/saenen_a/Work/Rendu/Application_test
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May  5 13:10:47 2015 Alexander Saenen
// Last update Wed Jun  3 13:35:30 2015 Alexander Saenen
//

#ifndef EVENTMODULE_HH_
# define EVENTMODULE_HH_

# include <queue>
# include <iostream>
# include <vector>
# include "IFunctor.hh"
# include "AModule.hh"
# include "Event.hh"

class EventModule : public AModule
{
public:
  typedef void (*handler)(Event *);

  class Handler
  {
    int		_priority;
    IFunctor	*_handle;

  public:
    Handler(const int priority, IFunctor *);
    ~Handler();

    void operator()(Event *ev);
    int	priority() const;
  };

public:
  class CompareH
  {
  public:
    bool operator()(const Handler *lhs, const Handler *rhs) const;
  };

public:
  EventModule();
  virtual ~EventModule();

public:
  EventModule	*abandon(const std::string &what, const int priority);
  EventModule	*observe(const std::string &, IFunctor *, const int priority = 0);
  EventModule	*trigger(Event *);
  EventModule	*trigger(const std::string &, const int priority = 0);
  EventModule	*handle();
  void		flush();

private:
  std::map<std::string, std::priority_queue<Handler *, std::vector<Handler *>, CompareH> >	_observers;
  std::priority_queue<Event *, std::vector<Event *>, Event::CompareE>				_events;

  bool	_isFlushed;
};

#endif /* EventModule.hh */
