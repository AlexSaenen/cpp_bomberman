//
// GameOver.hh for  in /home/vividy/rendu/cpp_bomberman/Includes
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sun Jun 14 05:43:43 2015 Vividy
// Last update Sun Jun 14 17:04:35 2015 Alexander Saenen
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
