//
// Sound.hh for  in /home/peauge_t/rendu/cpp_bomberman/Fmod
// 
// Made by Thibaud PEAUGER
// Login   <peauge_t@epitech.net>
// 
// Started on  Sun Jun  7 22:39:21 2015 Thibaud PEAUGER
// Last update Mon Jun  8 16:42:37 2015 Thibaud PEAUGER
//

#ifndef		_SOUND_HH_
# define	_SOUND_HH_

# include <cstdlib>
# include <cstdio>
# include <SDL/SDL.h>
# include <SDL/SDL_image.h>
# include <fmod.h>
# include <string>
# include <iostream>

class		Sound
{
private:

  FMOD_SYSTEM *system;
  FMOD_SOUND *s;
  FMOD_RESULT ret;
  FMOD_CHANNELGROUP *chan;
  FMOD_BOOL state;
  std::string path;

public:

  Sound(std::string const &_path);
  ~Sound();

  void	play();
  void	pause();
  void	unpause();
};

#endif		/* Sound.hh */
