//
// GameOver.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sun Jun 14 05:43:43 2015 Vividy
// Last update Sun Jun 14 06:19:15 2015 Vividy
//

#ifndef GameOver_HH_
# define GameOver_HH_

#include "GameRoutine.hh"
#include "ModulesManager.hpp"
#include "AModule.hh"

class	GameRoutine;

class	GameOver : public AModule
{
private:
  GameRoutine	*gr;
  bool		isPlayerOne;
  bool		isPlayerTwo;
  bool		isIa;
  Event		*ev;

public:
  GameOver();
  ~GameOver();
public:
  void	execute(Event *);
};

#endif //!GameOver_HH_
