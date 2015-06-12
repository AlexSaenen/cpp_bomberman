//
// MusicModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Fri Jun 12 15:54:50 2015 Thibaud PEAUGER
//

#ifndef _SOUND_HH_
# define _SOUND_HH_

# include <ModulesManager.hpp>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <fmod.h>
# include <Event.hh>
# include <string>
# include <iostream>

class	Sound : public AModule
{
  FMOD_SYSTEM	*system;
  FMOD_SOUND	*sound;
  FMOD_RESULT	ret;
  FMOD_CHANNELGROUP *chan_grp;
  FMOD_BOOL	state;
  std::string const	path_file;
  std::string const	type;
  double	_musicVolume;
  double	_soundVolume;
  bool		_playMusic;
  bool		_playSound;

public:
  Sound(std::string const, std::string const, double const);
  virtual ~Sound();

  std::string	getPath() const;

  void	initialize();
  void	setVolume(double const volume);
  void	setLoop();
  void	pause();
  void	volumeMusic(const double increase = 0.05);
  void	volumeSound(const double increase = 0.05);
  void	toggleMusic(const bool status);
  void	toggleSound(const bool status);
  void	playFile();
};

#endif /* Sound.hh */
