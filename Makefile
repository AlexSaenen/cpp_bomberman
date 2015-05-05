##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Tue May  5 17:33:04 2015 Alexander Saenen
##

CXX		= g++

RM		= rm -f

NAME		= bomberman

SRCDIR		= Objects/

APPDIR		= ApplicationFiles/

GRADIR		= GraphicsLib/

SRC		= $(APPDIR)main.cpp \
		  $(APPDIR)Application.cpp \
		  $(APPDIR)ModulesManager.cpp \
		  $(SRCDIR)EventModule.cpp \
		  $(SRCDIR)Event.cpp \
		  $(SRCDIR)AObject.cpp \
		  $(SRCDIR)Cube.cpp \
		  $(SRCDIR)Marvin.cpp \
		  $(SRCDIR)GameRoutine.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -I$(GRADIR)includes/ -IHeaderObjects -W -Wall -Werror -Wextra

LIB		= -L$(GRADIR)libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
