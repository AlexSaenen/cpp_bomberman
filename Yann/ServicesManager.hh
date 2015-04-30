#pragma once

class ServicesManager
{
static ServicesManager *instance = null;

public:
	static ServicesManager *getInstance()
	{
		if (ServicesManager::instance == null)
			ServicesManager::instance = new ServicesManager();
		return ServicesManager::instance;
	}

protected:
	ServicesManager() {}

public:
	~ServicesManager() {
		// TODO : Free les différents services ici
	}

public:
	void add(std::string const &name, void *(*constructor)())
	{
		this->_constructors.add(name, constructor);
	}

	template <typename T> void addConstructor() {
		this->add(typeid(T).name(), new constructor<T>());
	}

	template <typename T> T get(std::string const &name) {
		if (this->_instances.find(name) == this->_instances.end())
		{
			if (this->_constructors.find(name) == this->_constructors.end())
			{
				// TODO : throw an exception
			}
			this->_instances.add(name, this->_constructors[name]());
		}

		return this->_instances[name];
	}

	template <typename T> T get() {
		return this->get<T>(typeid(T).name());
	}
};

protected:
	std::map<std::string, void *(*)()>	_constructors;
	std::map<std::string, void *>		_instances;
}