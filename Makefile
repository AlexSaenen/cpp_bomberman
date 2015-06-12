##
## Makefile for bomberman in /home/saenen_a/Work/Rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Thu Jun 11 18:00:49 2015 Alexander Saenen
## Last update Fri Jun 12 14:27:05 2015 Thibaud PEAUGER
##

CXX		= g++

RM		= rm -f

NAME		= bomberman

SRCDIR		= Objects/

CMPDIR		= Components/

APPDIR		= ApplicationFiles/

MODDIR		= Modules/

ERRDIR		= Exceptions/

GRADIR		= GraphicsLib/

SRC		= $(ERRDIR)ArgException.cpp \
		  $(ERRDIR)LogicException.cpp \
		  $(ERRDIR)RangeException.cpp \
		  $(ERRDIR)RuntimeException.cpp \
		  $(APPDIR)main.cpp \
		  $(APPDIR)Bomberman.cpp \
		  $(APPDIR)ModulesManager.cpp \
		  $(APPDIR)$(MODDIR)EventModule.cpp \
		  $(APPDIR)$(MODDIR)GameModule.cpp \
		  $(APPDIR)$(MODDIR)MapModule.cpp \
		  $(APPDIR)$(MODDIR)MusicModule.cpp \
		  $(APPDIR)$(MODDIR)Sound.cpp \
		  $(APPDIR)$(MODDIR)MenuModule.cpp \
		  $(APPDIR)$(MODDIR)TexturesModule.cpp \
		  $(APPDIR)$(MODDIR)GameRoutine.cpp \
		  $(APPDIR)$(MODDIR)Camera.cpp \
		  $(CMPDIR)Cube.cpp \
		  $(CMPDIR)ObjModel.cpp \
		  $(CMPDIR)Wallpaper.cpp \
		  $(CMPDIR)Button.cpp \
		  $(CMPDIR)Player.cpp \
		  $(CMPDIR)PlayerOne.cpp \
		  $(CMPDIR)PlayerTwo.cpp \
		  $(CMPDIR)Bomb.cpp \
		  $(CMPDIR)IA.cpp \
		  $(SRCDIR)Event.cpp \
		  $(SRCDIR)MenuSpawner.cpp \
		  $(SRCDIR)Shape.cpp \
		  $(SRCDIR)GameObject.cpp \
		  $(SRCDIR)Loader.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -I$(GRADIR)includes/ -IIncludes -W -Wall -Werror -Wextra

LIB		= -L$(GRADIR)libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl -lfmod

RED		= \033[00;34m

WHITE		= \033[00;0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) $(LIB) -o $(NAME)
	@echo -e "$(RED)export LD_LIBRARY_PATH=GraphicsLib/libs/$(WHITE)"

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
