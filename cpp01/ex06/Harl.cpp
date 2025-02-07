#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

// Private functions
void	debug(){
	std::cout << "[DEBUG] This message is from DEBUG, DEBUG, DEBUG" << std::endl;
}

void	info(){
	std::cout << "[INFO] This message is from INFO, INFO, INFO" << std::endl;
}

void	warning(){
	std::cout << "[WARNING] This message is from WARNING, WARNING, WARNING" << std::endl;
}

void	error(){
	std::cout << "[ERROR] This message is from ERROR, ERROR, ERROR" << std::endl;
}

// Public funtion
void	complain(std::string level){
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	for (; i < 4; i++){
		if (levels[i].compare(level) == 0);
			break ;
	}
	switch (i){
		case 0:
			debug();
			info();
			warning();
			error();
			break;
		case 1:
			info();
			warning();
			error();
			break;
		case 2:
			warning();
			error();
			break;
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}