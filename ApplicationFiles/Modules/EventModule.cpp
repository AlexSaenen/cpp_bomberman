//
// EventModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Tue May 19 11:08:54 2015 Alexander Saenen
// Last update Tue May 19 11:08:55 2015 Alexander Saenen
//

#include "EventModule.hh"

EventModule::EventModule() : _isFlushed(false) { }

EventModule::~EventModule() {
  Event			*event;
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

EventModule *EventModule::observe(const std::string &what, IFunctor *handle, const int priority) {
  EventModule::Handler	*caps = new EventModule::Handler(priority, handle);

  // TODO : add an element if none exist in map
  std::cout << "Adding an observer for: " << what << std::endl;
  this->_observers[what].push(caps);
  return this;
}

EventModule *EventModule::trigger(Event *ev) {
  if (_isFlushed)
    _isFlushed = false;
  this->_events.push(ev);
  return this;
}

EventModule *EventModule::trigger(const std::string &name, const int priority) {
  if (_isFlushed)
    _isFlushed = false;
  this->_events.push(new Event(name, priority));
  return this;
}

EventModule *EventModule::handle() {
  std::cout << "Handling Events\n" << std::endl;
  while (!this->_events.empty() && !_isFlushed)
    {
      Event *ev = this->_events.top();
      this->_events.pop();
      std::cout << "\tGetting all handlers for: " << ev->getName() << std::endl;
      std::priority_queue<Handler *, std::vector<Handler *>, CompareH>	handlers = this->_observers[ev->getName()];
      std::cout << "\t\tGoing to handle: propagating=" << ev->propagate() << " emptyHandlers=" << handlers.empty() << " size=" << handlers.size() << std::endl;
      while (!handlers.empty() && ev->propagate()) {
	Handler	*manage = handlers.top();
	std::cout << "\t\tHandling" << std::endl;
	(*manage)(ev);
	handlers.pop();
      }
      delete ev;
    }
  std::cout << "\nFinished handling" << std::endl;
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
