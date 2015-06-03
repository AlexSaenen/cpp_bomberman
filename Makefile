##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Mon Jun  1 17:58:35 2015 Alexander Saenen
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
		  $(ERRDIR)RuntimeException.cpp \
		  $(APPDIR)main.cpp \
		  $(APPDIR)Bomberman.cpp \
		  $(APPDIR)ModulesManager.cpp \
		  $(APPDIR)$(MODDIR)EventModule.cpp \
		  $(APPDIR)$(MODDIR)GameModule.cpp \
		  $(APPDIR)$(MODDIR)GameRoutine.cpp \
		  $(SRCDIR)Event.cpp \
		  $(CMPDIR)Cube.cpp \
		  $(CMPDIR)ObjModel.cpp \
		  $(SRCDIR)Player.cpp \
		  $(SRCDIR)PlayerOne.cpp \
		  $(SRCDIR)PlayerTwo.cpp \
		  $(SRCDIR)IA.cpp \
		  $(SRCDIR)Shape.cpp \
		  $(SRCDIR)GameObject.cpp \
		  $(SRCDIR)Loader.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -I$(GRADIR)includes/ -IIncludes -W -Wall -Werror -Wextra -std=c++11 -g3

LIB		= -L$(GRADIR)libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl

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
