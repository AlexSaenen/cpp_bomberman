##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Tue May 19 12:35:02 2015 Alexander Saenen
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
		  $(APPDIR)main.cpp \
		  $(APPDIR)Bomberman.cpp \
		  $(APPDIR)ModulesManager.cpp \
		  $(APPDIR)$(MODDIR)EventModule.cpp \
		  $(APPDIR)$(MODDIR)GameModule.cpp \
		  $(SRCDIR)Event.cpp \
		  $(CMPDIR)Cube.cpp \
		  $(CMPDIR)ObjModel.cpp \
		  $(SRCDIR)Shape.cpp \
		  $(SRCDIR)GameRoutine.cpp \
		  $(SRCDIR)GameObject.cpp \
		  Parser/Parser.cpp

OBJ		= $(SRC:.cpp=.o)

<<<<<<< HEAD
CXXFLAGS	= -I$(GRADIR)includes/ -IHeaderObjects -W -Wall -Werror -Wextra -g3
=======
CXXFLAGS	= -I$(GRADIR)includes/ -IIncludes -W -Wall -Werror -Wextra
>>>>>>> a7d50315522872591351c8e0afd77d094eb7361c

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
