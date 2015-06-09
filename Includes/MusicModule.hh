//
// MusicModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Mon Jun  8 18:18:42 2015 Thibaud PEAUGER
//

#ifndef MUSICMODULE_HH_
# define MUSICMODULE_HH_

# include <ModulesManager.hpp>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <fmod.h>
# include <Event.hh>
# include <string>
# include <iostream>

class	MusicModule : public AModule
{
  double	_musicVolume;
  double	_soundVolume;
  bool		_playMusic;
  bool		_playSound;
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*sound;
  FMOD_RESULT	ret;
  FMOD_CHANNELGROUP *chan;
  FMOD_BOOL	state;
  std::string	path_file;
  std::string	type;

public:
  MusicModule();
  virtual ~MusicModule();

  void	initialize(Event *);
  void	volumeMusic(const double increase = 0.05);
  void	volumeSound(const double increase = 0.05);
  void	toggleMusic(const bool status);
  void	toggleSound(const bool status);
  void	playFile();
};

#endif /* MusicModule.hh */
