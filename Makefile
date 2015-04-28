##
## Makefile for  in /home/saenen_a/SchoolWork/rendu/cpp_bomberman
## 
## Made by Alexander Saenen
## Login   <saenen_a@epitech.net>
## 
## Started on  Mon Apr 27 12:06:58 2015 Alexander Saenen
## Last update Mon Apr 27 15:21:54 2015 Alexander Saenen
##

CXX		= g++

RM		= rm -f

NAME		= bomberman

SRCDIR		= objects/

SRC		= src/main.cpp \
		  $(SRCDIR)AObject.cpp \
		  $(SRCDIR)Cube.cpp \
		  $(SRCDIR)GameRoutine.cpp

OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -ILibBomberman_linux_x64/includes/ -IheaderObjects -W -Wall -Werror -Wextra

LIB		= -LLibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
