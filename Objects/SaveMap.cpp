//
// SaveMap.cpp for  in /home/vividy/rendu/cpp_bomberman/Objects
//
// Made by Vividy
// Login   <vividy@epitech.net>
//
// Started on  Sat Jun 13 22:03:46 2015 Vividy
// Last update Sun Jun 14 03:31:50 2015 Vividy
//

#include "SaveMap.hh"

SaveMap::SaveMap() {
  this->file = new std::filebuf();
  if (this->file->open("Save/zizi.map", std::ios::out))
    this->is = new std::ostream(this->file);
  else
    throw ArgException("Cannot open the file : Save/zizi.map");
  this->gr = ModulesManager::getInstance()->get<GameRoutine>();
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
  std::list<IComponent *> comp;
  Shape   *shape = 0;
  std::stringstream     string;
  std::string           str;
  std::list<IComponent *>::iterator at;

  if (isPlayerOne)
    {
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
  std::cout << (isPlayerTwo == true ? "true" : "la mere de lucas") << std::endl;
  if (isPlayerTwo)
    {
      std::cout << "toto" << std::endl;
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
  str = string.str();
  this->is->write(str.c_str(), str.size());
}

