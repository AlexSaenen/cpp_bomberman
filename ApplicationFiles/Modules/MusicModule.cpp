//
// MusicModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 10:46:57 2015 Alexander Saenen
// Last update Thu Jun 11 12:29:14 2015 Thibaud PEAUGER
//

#include <MusicModule.hh>
#include <Event.hh>

MusicModule::MusicModule()
  : musicVolume(0.5), soundVolume(0.5) {
}

void	MusicModule::clearList() {
  while (!listSound.empty())
    {
      delete listSound.front();
      listSound.pop_front();
    }
}

MusicModule::~MusicModule() {
}

double	MusicModule::getMusicVolume() const {
  return (musicVolume);
}

void	MusicModule::setMusicVolume(double const _volume) {
  musicVolume = _volume;
}

double	MusicModule::getSoundVolume() const {
  return (soundVolume);
}

void	MusicModule::setSoundVolume(double const _volume) {
  soundVolume = _volume;
}

bool	MusicModule::checkIn(std::string const& path_file, std::string const& type) {
  for (std::list<Sound *>::iterator it = listSound.begin(); it != listSound.end(); ++it)
    if ((*it)->getPath() == path_file)
      {
	if (type == "MUSIC")
	  (*it)->setVolume(musicVolume);
	else
	  (*it)->setVolume(soundVolume);
	(*it)->playFile();
	return (true);
      }
  return (false);
}

void	MusicModule::addSound(Event *ev)
{
  std::string	path_file;
  std::string	type;

  path_file = ev->get<std::string>("FILE");
  type = ev->get<std::string>("TYPE");
  if (checkIn(path_file, type) == false)
    {
      Sound	*s = new Sound(path_file, type, soundVolume);
      s->initialize();
      if (type == "MUSIC")
	s->setVolume(musicVolume);
      else
	s->setVolume(soundVolume);
      s->playFile();
      listSound.push_back(s);
    }
}
