/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:19:02 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:19:02 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

// Private functions
void	Harl::debug(){
	std::cout << "[DEBUG] This message is from DEBUG, DEBUG, DEBUG" << std::endl;
}

void	Harl::info(){
	std::cout << "[INFO] This message is from INFO, INFO, INFO" << std::endl;
}

void	Harl::warning(){
	std::cout << "[WARNING] This message is from WARNING, WARNING, WARNING" << std::endl;
}

void	Harl::error(){
	std::cout << "[ERROR] This message is from ERROR, ERROR, ERROR" << std::endl;
}

// Public funtion
void	Harl::complain(std::string level){
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
	std::cout << "[UNKNOW] Harl doesn't know this type. UNKNOW, UNKNOW, UNKNOW" << std::endl;
}
