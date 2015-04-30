#pragma once

class Event
{
public:
	Event(std::string const &name, int priority = 0): _name(name), _propagate(true), _priority(priority) {}

public:
	std::string const &getName() const {
		return this->_name;
	}

	bool propagate() const {
		return this->_propagate;
	}

	int priority() const {
		return this->_priority;
	}

	template<typename T> void set(std::string name, T what) {
		// TODO : specialize this template to handle scalar types
		this->_parameters.add(name, (void *) what);
	}

	template<typename T> T get(std::string name) {
		// TODO : handle errors here
		return (T) this->_parameters[name];
	}

	void stop() {
		this->_propagate = false;
	}

	bool operator<(Event const &right) const {
		return this._priority < right._priority;
	}

protected:
	std::string const _name;
	std::map<std::string, void *>	_parameters;
	bool	_propagate;
	int const		_priority;
}