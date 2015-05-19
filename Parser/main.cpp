//
// main.cpp for main in /home/bonald_j/cpp_abstractvm
// 
// Made by Jérôme Bonaldo
// Login   <bonald_j@epitech.net>
// 
// Started on  Sun Mar  1 21:46:49 2015 Jérôme Bonaldo
// Last update Sun Mar  1 21:46:51 2015 Jérôme Bonaldo
//

#include "Parser.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <string>

int	main(int ac, char **av)
{
  std::list<GameObject *> objectList;
  std::istream *is;
  std::list<GameObject *>::iterator i;
  std::filebuf file;
  Lexer *lexer;
  int	files;

  try {
    if (ac > 1)
      {
	files = 1;
	while (files != ac)
	  {
	    std::cout << "Execution of file " << files << " : " << std::endl;
	    if (file.open(av[files], std::ios::in))
	      is = new std::istream(&file);
	    else
	      std::cout << "Invalid : " << av[files] << std::endl;
	    lexer = new Lexer(is);
	    tokenList = lexer->execute();
	    Parser p(tokenList);
	    Heart heart(p.execute());
	    heart.execute_list();
	    file.close();
	    files++;
	  }
      }
    else
      {
	std::cout << "Wrongs parameters" << std::endl;
	return (-1);
      }
    tokenList = lexer->execute();
    Parser p(tokenList);
  }
  catch(std::exception e)
    {
      return (0);
    }
  return (0);
}
