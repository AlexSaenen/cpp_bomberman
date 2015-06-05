//
// MusicModule.hh for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
// 
// Made by Alexander Saenen
// Login   <saenen_a@epitech.net>
// 
// Started on  Wed Jun  3 11:42:53 2015 Alexander Saenen
// Last update Fri Jun  5 10:54:07 2015 Alexander Saenen
//

#ifndef MUSICMODULE_HH_
# define MUSICMODULE_HH_

# include <ModulesManager.hpp>

class	MusicModule : public AModule
{
  double	_musicVolume;
  double	_soundVolume;
  bool		_playMusic;
  bool		_playSound;

public:
  MusicModule();
  virtual ~MusicModule();

  void	initialize(Event *);
  void	volumeMusic(const double increase = 0.05);
  void	volumeSound(const double increase = 0.05);
  void	toggleMusic(const bool status);
  void	toggleSound(const bool status);
  void	playFile(Event *);
};

#endif /* MusicModule.hh */
