/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:07 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:07 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << DARK_YELLOW << "Dog class -- Default constructor called\n"
	<< RESET;
	this->type_ = "Dog";
}

Dog::Dog(const std::string type) : Animal(type){
	std::cout << DARK_YELLOW << "Dog class -- Parameterized constructor called\n"
	<< RESET;
	this->type_ = "Dog";
}

Dog::Dog(const Dog& other): Animal(other){
	std::cout << DARK_YELLOW << "Dog class -- Copy constructor called\n"
	<< RESET;
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
Dog::~Dog(){
	std::cout << DARK_YELLOW << "Dog class -- Deconstructor called\n"
	<< RESET;
}

Dog&	Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << DARK_YELLOW << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	Dog::makeSound() const{
	std::cout << DARK_YELLOW << "Wang Wang Wang...\n" << RESET;
}
