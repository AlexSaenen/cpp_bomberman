#pragma once

# include "Event.hh"

class EventManager
{
public:
	typedef void (*handler)(Event &);

protected:
	class HandlerEncapsulation
	{
		int _priority;
		handler _handle;

	public:
		HandlerEncapsulation(int priority, handler handle): _priority(priority), _handle(handle) {}

		bool operator<(HandlerEncapsulation const &right) const {
			return (this->_priority < right._priority);
		}

		void operator()(Event *ev)
		{
			this->_handle(ev);
		}
	};

public:
	EventManager() {}

public:
	EventManager *observe(std::string const &, handler, int priority = 0);
	EventManager *trigger(Event *);
	EventManager *trigger(std::string const &, int priority = 0);
	EventManager *handle();

protected:
	std::map<std::string, std::priority_queue<HandlerEncapsulation *> >	_observers;
	std::priority_queue<Events *>										_events;
};