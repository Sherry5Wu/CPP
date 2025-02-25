/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 07:59:04 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/25 07:59:04 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << BLUE << "Cat class -- Default constructor called\n"
	<< RESET;
	this->type_ = "Cat";
	this->brain_ = new Brain();
}

Cat::Cat(const std::string type) : Animal(type){
	std::cout << BLUE << "Cat class -- Parameterized constructor called\n"
	<< RESET;
	this->type_ = "Cat";
	this->brain_ = new Brain();
}

Cat::Cat(const Cat& other): Animal(other){
	std::cout << BLUE << "Cat class -- Copy constructor called\n"
	<< RESET;
	this->brain_ = new Brain(*other.brain_);
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
Cat::~Cat(){
	std::cout << BLUE << "Cat class -- Deconstructor called\n"
	<< RESET;
	delete this->brain_;
	this->brain_ = nullptr;
}

Cat&	Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		if (this->brain_ != nullptr){
			delete this->brain_;
			this->brain_ = nullptr;
		}
		this->brain_ = new Brain(*other.brain_);
		std::cout << BLUE << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	Cat::makeSound() const{
	std::cout << BLUE << "Miao Miao Miao...\n"<< RESET;
}
