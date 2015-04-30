#include "application.hh"
#include "functor.hh"

Application::Application(int ac, char **av):
	_run(true)
{
	// TODO : save ac and av somewhere... look for something named design pattern Registry...
	this->_initialize();
	ServicesManager::getInstance()->get<EventManager *>()->observe("Application.Quit", new functor(this, &Application::_onQuit));
}

void Application::_initialize()
{
	// TODO : add services here...
	ServicesManager::getInstance()->addConstructor<EventManager>();
	ServicesManager::getInstance()->addConstructor<DisplayManager>();
	ServicesManager::getInstance()->add("music", /* Create a function here */);
}

void Application::run()
{
	EventManager *ev = ServicesManager::getInstance()->get<EventManager *>("event");

	ev->trigger("Application.init")->handle();
	while (this->_run)
		ev->trigger("Application.loop.pre")
		  ->trigger("Application.loop.main", 1000)
		  ->trigger("Application.loop.post", 2000)
		  ->handle();
	ev->trigger("Application.quit")->handle();
}

void Application::_onQuit(Event *)
{
	this->_run = false;
}