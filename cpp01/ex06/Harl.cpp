/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 08:19:24 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/10 08:19:24 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){
}

Harl::~Harl(){
}

// Private functions
void	Harl::debug(){
	std::cout << "[ DEBUG ]\nThis message is from DEBUG, DEBUG, DEBUG\n" << std::endl;
}

void	Harl::info(){
	std::cout << "[ INFO ]\nThis message is from INFO, INFO, INFO\n" << std::endl;
}

void	Harl::warning(){
	std::cout << "[ WARNING ]\nThis message is from WARNING, WARNING, WARNING\n" << std::endl;
}

void	Harl::error(){
	std::cout << "[ ERROR ]\nThis message is from ERROR, ERROR, ERROR\n" << std::endl;
}

// Public funtion
void	Harl::complain(std::string level){
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	for (; i < 4; i++){
		if (levels[i].compare(level) == 0)
			break ;
	}
	switch (i){
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
