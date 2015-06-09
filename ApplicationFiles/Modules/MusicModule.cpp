//
// MusicModule.cpp for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Fri Jun  5 10:46:57 2015 Alexander Saenen
// Last update Mon Jun  8 18:16:28 2015 Thibaud PEAUGER
//

#include <MusicModule.hh>
#include <Event.hh>

MusicModule::MusicModule()
  : _musicVolume(50), _soundVolume(50), _playMusic(true), _playSound(true) {
}

MusicModule::~MusicModule() {
  FMOD_Sound_Release(sound);
  FMOD_System_Close(system);
  FMOD_System_Release(system);
}

void	MusicModule::initialize(Event *ev) {
  path_file = ev->get<std::string>("FILE");
  type = ev->get<std::string>("TYPE");
  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  ret = FMOD_System_CreateSound(system, path_file.c_str(), FMOD_2D | FMOD_CREATESTREAM, 0, &sound);
  if (ret != FMOD_OK)
    std::cout << "Music path invalid" << std::endl; // throw
  FMOD_System_GetMasterChannelGroup(system, &chan);
  FMOD_ChannelGroup_GetPaused(chan, &state);
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

void	MusicModule::playFile() {

  //FMOD_Channel_SetVolume(chan, _soundVolume);
  if ((type == "MUSIC" && _playMusic) || (type == "SOUND" && _playSound))
    FMOD_System_PlaySound(system, sound, chan, state, NULL);
}
