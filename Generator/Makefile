##
## makefile for  in /home/pradel_v/rendu/piscine_cpp_d01/ex01
## 
## Made by Vivien Pradelles
## Login   <pradel_v@epitech.net>
## 
## Started on  Wed Jan  7 12:16:05 2015 Vivien Pradelles
## Last update Fri Jun 12 16:38:28 2015 Vividy
##

CXX	= g++

RM	= rm -f

CXXFLAGS	= -Wextra -Werror -Wall

NAME	= MapGenerator

SRC	= $(NAME).cpp \
	  main.cpp

OBJ	= $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	@$(CXX) -o $(NAME) $(OBJ)

c:
	clang++ -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
