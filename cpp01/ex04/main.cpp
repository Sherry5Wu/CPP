#include <string>
#include <iostream>
#include "CopyReplace.hpp"

int	main(int ac, std::string *av){
	if (ac != 4)
	{
		std::cerr << "Error\nThe program takes and only takes 3 parameters\n";
		return (1);
	}
	std::string	fileName = av[1];
	std::string	s1 = av[2];
	std::string	s2 = av[3];

	//create an instance of CopyReplay and process the file
	CopyReplace copier(fileName, s1, s2);
	if(!copier.process()){
		return (1);
	}
	return (0);
}