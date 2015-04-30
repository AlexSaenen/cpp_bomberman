#pragma once

template<typename RETURN, classname ME>
class functor
{
	typedef RETURN (*ME::handler)();
	ME	*_instance;
	handler _handle;

	public:
		functor(ME *instance, handler what): _instance(instance), _handle(handler) {

		}

		RETURN operator()() {
			return this->_instance->_handle();
		}
};

template<typename RETURN, classname ME, typename PARAMETER>
class functor
{
	typedef RETURN (*ME::handler)(PARAMETER);
	ME	*_instance;
	handler _handle;

	public:
		functor(ME *instance, handler what): _instance(instance), _handle(handler) {

		}

		RETURN operator()(PARAMETER what) {
			return this->_instance->_handle(what);
		}
};

template<classname ME>
class constructor
{
public:
	constructor() {}

	ME *operator() {
		return new ME();
	}
}