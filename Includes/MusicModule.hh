//
// MusicModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Fri Jun 12 14:41:00 2015 Thibaud PEAUGER
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
# include <list>
# include "Sound.hh"

class	MusicModule : public AModule
{
  std::list<Sound *> listSound;
  double	musicVolume;
  double        soundVolume;

public:
  MusicModule();
  virtual ~MusicModule();

  double	getMusicVolume() const;
  void		setMusicVolume(double const);
  double	getSoundVolume() const;
  void		setSoundVolume(double const);

  bool		checkIn(std::string const& path, std::string const& type);
  void		addSound(Event *);
  void		removeSound(std::string const& path);
  void		clearList();
};

#endif /* MusicModule.hh */
