##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Tue May 12 17:04:56 2015 Alexander Saenen
##

CXX		= g++

RM		= rm -f

NAME		= bomberman

SRCDIR		= Objects/

CMPDIR		= Components/

APPDIR		= ApplicationFiles/

GRADIR		= GraphicsLib/

SRC		= $(APPDIR)main.cpp \
		  $(APPDIR)Application.cpp \
		  $(APPDIR)ModulesManager.cpp \
		  $(SRCDIR)EventModule.cpp \
		  $(SRCDIR)Event.cpp \
		  $(CMPDIR)Cube.cpp \
		  $(SRCDIR)Shape.cpp \
		  $(SRCDIR)GameRoutine.cpp \
		  $(SRCDIR)GameObject.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -I$(GRADIR)includes/ -IHeaderObjects -W -Wall -Werror -Wextra -g3

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
