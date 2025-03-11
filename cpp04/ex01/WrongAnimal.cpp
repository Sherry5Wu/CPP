/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:45:24 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:45:24 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type_("default"){
	std::cout << ORANGE << "WrongAnimal -- default constructor called\n"
	<< RESET;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type_(other.type_){
	std::cout << ORANGE << "WrongAnimal -- copy constructor called\n"
	<< RESET;
}
WrongAnimal::~WrongAnimal(){
	std::cout << ORANGE << "WrongAnimal -- deconstructor called\n" << RESET;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other){
	if (this != &other){
		std::cout << ORANGE << "WrongAnimal -- Assignment operator called\n"
		<< RESET;
		this->type_ = other.type_;
	}
	return *this;
}

std::string		WrongAnimal::getType() const{
	return this->type_;
}

void	WrongAnimal::makeSound() const{}
