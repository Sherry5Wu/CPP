/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:35 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:35 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << CYAN << "WrongCat class -- Default constructor called\n"
	<< RESET;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
	std::cout << CYAN << "WrongCat class -- Copy constructor called\n"
	<< RESET;
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
WrongCat::~WrongCat(){
	std::cout << CYAN << "WrongCat class -- Deconstructor called\n"
	<< RESET;
}

WrongCat&	WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		WrongAnimal::operator=(other);
		std::cout << CYAN << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	WrongCat::makeSound() const{
	std::cout << CYAN << "Miao Miao Miao...\n"<< RESET;
}
