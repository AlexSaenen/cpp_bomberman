#include "EventManager.hh"

EventManager *EventManager::observe(std::string const &what, EventManager::handler handle, int priority)
{
	EventManager::HandlerEncapsulation	*caps = new EventManager::HandlerEncapsulation(handle, priority);

	// TODO : add an element if none exist in map
	this->_observers[what].push(caps);
	return this;
}

EventManager *EventManager::trigger(Event *ev)
{
	this->_events.push(ev);
	return this;
}

EventManager *EventManager::handle()
{
	while (!this->_events.empty())
	{
		Event *ev = this->_events.pop();
		std::priority_queue<HandlerEncapsulation>	handlers = this->_observers[ev->getName()];

		while (!handlers.empty() && ev->propagate())
		{
			HandlerEncapsulation	handle = handlers.pop();

			handle(ev);
		}
	}
}