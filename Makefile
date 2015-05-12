##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Tue May 12 11:52:04 2015 Alexander Saenen
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

LIB		= -L$(GRADIR)libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
