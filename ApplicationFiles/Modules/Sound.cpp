//
// MusicModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 10:46:57 2015 Alexander Saenen
// Last update Thu Jun 11 18:38:39 2015 Thibaud PEAUGER
//

#include <Sound.hh>
#include <Event.hh>
#include "RuntimeException.hh"

Sound::Sound(std::string const _path, std::string const _type, double const _volume)
  : path_file(_path), type(_type), _musicVolume(1), _soundVolume(_volume), _playMusic(true), _playSound(true) {
}

Sound::~Sound() {
  FMOD_Sound_Release(sound);
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}

void	Sound::initialize() {
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  ret = FMOD_System_CreateSound(system, path_file.c_str(), FMOD_2D | FMOD_CREATESTREAM, 0, &sound);
  if (ret != FMOD_OK)
    throw RuntimeException("Fmod Couldn't create the sound");
  FMOD_System_GetMasterChannelGroup(system, &chan_grp);
  FMOD_ChannelGroup_GetPaused(chan_grp, &state);
}

std::string	Sound::getPath() const
{
  return (path_file);
}

void	Sound::setVolume(double volume) {
  _soundVolume = volume;
}

void	Sound::volumeMusic(const double increase) {
  _musicVolume += increase;
  if (_musicVolume > 100)
    _musicVolume = 100;
  else if (_musicVolume < 0)
    _musicVolume = 0;
}

void	Sound::volumeSound(const double increase) {
  _soundVolume += increase;
  if (_soundVolume > 100)
    _soundVolume = 100;
  else if (_soundVolume < 0)
    _soundVolume = 0;
}

void	Sound::toggleMusic(const bool status) {
  _playMusic = status;
}

void	Sound::toggleSound(const bool status) {
  _playSound = status;
}

void	Sound::playFile() {
  FMOD_ChannelGroup_SetVolume(chan_grp, _soundVolume);
  FMOD_System_PlaySound(system, sound, chan_grp, state, NULL);
}
