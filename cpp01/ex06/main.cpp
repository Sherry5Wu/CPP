#include "Harl.hpp"


int	main(int ac, std::string *av){
	Harl	harl;

	if (ac != 2){
		std::cerr << "Error\nThe program takes and only take on parameter"
			<< std::endl;
		std::cout << "Valid inputs: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}
	std::cout << "Testing harlFilter" << std::endl;
	harl.complain(av[1]);
	return (0);
}