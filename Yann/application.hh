#pragma once

#include "ServiceManager.hh"

class Application
{
public:
	Application(int ac, char **av);

public:
	void run ();

protected:
	void _initialize();

protected:
	void _onQuit(Event *);

protected:
	bool	_run;
}