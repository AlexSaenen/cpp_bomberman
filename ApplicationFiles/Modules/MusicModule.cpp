//
// MusicModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 10:46:57 2015 Alexander Saenen
// Last update Fri Jun  5 10:53:38 2015 Alexander Saenen
//

#include <MusicModule.hh>

MusicModule::MusicModule()
  : _musicVolume(50), _soundVolume(50), _playMusic(true), _playSound(true) { }

MusicModule::~MusicModule() { }

void	MusicModule::initialize(Event *) {
  /* initialize FMOD music */  
}

void	MusicModule::volumeMusic(const double increase) {
  _musicVolume += increase;
  if (_musicVolume > 100)
    _musicVolume = 100;
  else if (_musicVolume < 0)
    _musicVolume = 0;
}

void	MusicModule::volumeSound(const double increase) {
  _soundVolume += increase;
  if (_soundVolume > 100)
    _soundVolume = 100;
  else if (_soundVolume < 0)
    _soundVolume = 0;
}

void	MusicModule::toggleMusic(const bool status) {
  _playMusic = status;
}

void	MusicModule::toggleSound(const bool status) {
  _playSound = status;
}

void	MusicModule::playFile(Event *) {
  /* get music file path or file type by get the param from the event */
}
