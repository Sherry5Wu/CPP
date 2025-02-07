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

	// (Harl::*functions[4]) is a A pointer to a member function of the Harl class that takes
	// no parameters and returns void, here it includes debug, info, warning and error.
	// here it must be "&Harl::debug", using '&' to get the address of the function
	void	(Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; i++){
		if (level == levels[i]){
			// functions[i] is a pointer that point to a member function. And "*function[i]"
			// is the function.
			(this->*functions[i])();
		return ;
		}
	}
	std::cout << "[UNKNOW] Harl doesn't know this type." << std::endl;
}