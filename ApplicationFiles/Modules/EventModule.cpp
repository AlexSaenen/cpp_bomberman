//
// EventModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:08:54 2015 Alexander Saenen
// Last update Sun Jun 14 08:56:41 2015 Alexander Saenen
//

#include "EventModule.hh"

EventModule::EventModule() : _isFlushed(false) { }

EventModule::~EventModule() {
  Event		*event;
  Handler	*handler;

  while (!this->_events.empty()) {
    event = _events.top();
    delete event;
    _events.pop();
  }
  for (std::map<std::string, std::priority_queue<Handler *, std::vector<Handler *>, CompareH> >::iterator
  	 it = this->_observers.begin(); it != this->_observers.end(); ++it) {
    std::priority_queue<Handler *, std::vector<Handler *>, CompareH>	handlers = (*it).second;
    while (!handlers.empty()) {
      handler = handlers.top();
      handlers.pop();
      delete handler;
    }
  }
}

EventModule::Handler::Handler(const int priority, IFunctor *handle)
  : _priority(priority), _handle(handle) { }

EventModule::Handler::~Handler() {
  delete _handle;
}

void	EventModule::Handler::operator()(Event *ev) {
  (*this->_handle)(ev);
}

EventModule	*EventModule::observe(const std::string &what, IFunctor *handle, const int priority) {
  EventModule::Handler	*caps = new EventModule::Handler(priority, handle);

  this->_observers[what].push(caps);
  return this;
}

EventModule	*EventModule::abandon(const std::string &what, const int priority) {
  std::priority_queue<Handler *, std::vector<Handler *>, CompareH>	handlers;
  std::priority_queue<Handler *, std::vector<Handler *>, CompareH>	stack;

  if (_observers.find(what) == _observers.end())
    return (this);
  handlers = _observers[what];
  while (!handlers.empty()) {
    Handler	*handler = handlers.top();
    if (handler->priority() != priority)
      stack.push(handler);
    handlers.pop(); 
  }
  _observers[what] = stack;
  return (this);
}

EventModule	*EventModule::trigger(Event *ev) {
  if (_isFlushed)
    _isFlushed = false;
  this->_events.push(ev);
  return this;
}

EventModule	*EventModule::trigger(const std::string &name, const int priority) {
  if (_isFlushed)
    _isFlushed = false;
  this->_events.push(new Event(name, priority));
  return this;
}

EventModule	*EventModule::handle() {
  while (!this->_events.empty())
    {
      Event *ev = this->_events.top();
      this->_events.pop();
      std::priority_queue<Handler *, std::vector<Handler *>, CompareH>	handlers = this->_observers[ev->getName()];
      while (!handlers.empty() && ev->propagate() && !_isFlushed) {
	Handler	*manage = handlers.top();
	handlers.pop();
	(*manage)(ev);
      }
      delete ev;
    }
  return (this);
}

void	EventModule::flush() {
  this->_isFlushed = true;
}

int	EventModule::Handler::priority() const {
  return (this->_priority);
}

bool	EventModule::CompareH::operator()(const Handler *lhs, const Handler *rhs) const {
  return (lhs->priority() < rhs->priority());
}
