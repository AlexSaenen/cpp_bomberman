//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sun Jun 14 05:06:56 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap() {
  time_t	rawtime;
  struct tm	* timeinfo;
  char		buffer [40];
  std::string	str(buffer);

  time ( &rawtime );
  timeinfo = localtime (&rawtime);
  strftime (buffer,40,"Save/Save_%F_%T.map",timeinfo);

  this->file = new std::filebuf();
  if (this->file->open(buffer, std::ios::out))
    this->is = new std::ostream(this->file);
  else
    throw ArgException("Cannot open the file : " + str);
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
  this->mm = ModulesManager::getInstance()->get<MapModule>();
  this->isPlayerOne = gr->getGOStatus(GameObject::PLAYER1, this->playerOne);
  this->isPlayerTwo = gr->getGOStatus(GameObject::PLAYER2, this->playerTwo);
  this->isIa = gr->getGOStatus(GameObject::IA, this->ia);
  this->isCube = gr->getGOStatus(GameObject::CUBE, this->cube);
  this->isCubeDestr = gr->getGOStatus(GameObject::CUBEDESTR, this->cubeDestr);
  _modelType["./GraphicsLib/assets/Textures/stone.tga"] = "cube";
  _modelType["./GraphicsLib/assets/Textures/crate.tga"] = "destroy";
  _modelType["./GraphicsLib/assets/archer.fbx"] = "player1";
  _modelType["./GraphicsLib/assets/warrior.fbx"] = "player2";
  _modelType["./GraphicsLib/assets/skeletarcher.fbx"] = "ia1";
  _modelType["./GraphicsLib/assets/skeletwarrior1.fbx"] = "ia2";
  _modelType["./GraphicsLib/assets/skeletwarrior2.fbx"] = "ia3";
  _modelType["./GraphicsLib/assets/skeletwarrior3.fbx"] = "ia4";
  std::cout << "Save is going" << std::endl;
}

SaveMap::~SaveMap()
{
  delete this->is;
  delete this->file;
  std::cout << "Map Saved!" << std::endl;
}

void	SaveMap::execute()
{
  std::list<IComponent *> comp;;
  Shape   *shape = 0;
  std::stringstream     string;
  std::string           str;
  std::list<IComponent *>::iterator at;
  int	i;

  string << mm->getSize() << " " << mm->getIA();
  if (isCube)
    {
      for (i = 0; i < (int)cube.size(); i++)
	{
	  shape = 0;
	  comp = cube[i]->getComponents();
	  for (std::list<IComponent *>::iterator it = comp.begin(); it != comp.end() && !shape; ++it) {
	    shape = dynamic_cast<Shape *>((*it));
	    at = it;
	  }
	  if (shape) {
	      string << "\n" << cube[i]->getName() << " " << cube[i]->getType() << "\n$Cube%" << shape->getPosX() << " " << shape->getPosY() << " 0\n@";
	}
      }
    }
  if (isPlayerOne)
    {
      shape = 0;
      comp = playerOne.back()->getComponents();
      for (std::list<IComponent *>::iterator it = comp.begin(); it != comp.end() && !shape; ++it) {
	shape = dynamic_cast<Shape *>((*it));
	at = it;
      }
      if (shape) {
	ObjModel  *model = dynamic_cast<ObjModel *>((*at));
	if (model) {
	  string << "\n" << playerOne.back()->getName() << " " << playerOne.back()->getType() << "\n$PlayerOne%" << shape->getPosX() << " " << shape->getPosY() << " " << playerOne.back()->getType() << " 0 0 0 0.1 0.1 0.1 " << _modelType[model->getModelName()] << "\n@";
	}
      }
    }
  if (isPlayerTwo)
    {
      shape = 0;
      comp = playerTwo.back()->getComponents();
      for (std::list<IComponent *>::iterator it = comp.begin(); it != comp.end() && !shape; ++it) {
	shape = dynamic_cast<Shape *>((*it));
	at = it;
      }
      if (shape) {
	ObjModel  *model = dynamic_cast<ObjModel *>((*at));
	if (model) {
	  string << "\n" << playerTwo.back()->getName() << " " << playerTwo.back()->getType() << "\n$PlayerTwo%" << shape->getPosX() << " " << shape->getPosY() << " " << playerTwo.back()->getType() << " 0 0 0 0.1 0.1 0.1 " << _modelType[model->getModelName()] << "\n@";
	}
      }
    }
  if (isIa)
    {
      for (i = 0; i < (int)ia.size(); i++)
	{
	  shape = 0;
	  comp = ia[i]->getComponents();
	  for (std::list<IComponent *>::iterator it = comp.begin(); it != comp.end() && !shape; ++it) {
	    shape = dynamic_cast<Shape *>((*it));
	    at = it;
	  }
	  if (shape) {
	    ObjModel  *model = dynamic_cast<ObjModel *>((*at));
	    if (model) {
	      string << "\n" << ia[i]->getName() << " " << ia[i]->getType() << "\n$IA%" << shape->getPosX() << " " << shape->getPosY() << " " << ia[i]->getType() << " 0 0 0 0.1 0.1 0.1 " << _modelType[model->getModelName()] << "\n@";
	    }
	}
      }
    }
  if (isCubeDestr)
    {
      for (i = 0; i < (int)cubeDestr.size(); i++)
	{
	  shape = 0;
	  comp = cubeDestr[i]->getComponents();
	  for (std::list<IComponent *>::iterator it = comp.begin(); it != comp.end() && !shape; ++it) {
	    shape = dynamic_cast<Shape *>((*it));
	    at = it;
	  }
	  if (shape) {
	      string << "\n" << cubeDestr[i]->getName() << " " << cubeDestr[i]->getType() << "\n$Cube%" << shape->getPosX() << " " << shape->getPosY() << " 0\n@";
	}
      }
    }
  str = string.str();
  this->is->write(str.c_str(), str.size());
}

