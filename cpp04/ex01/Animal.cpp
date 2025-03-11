/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:44:40 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:44:40 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type_("default"){
	std::cout << PURPLE << "Father class Animal-- DEFAULT constructor called\n"
	<< RESET;
}

Animal::Animal(const std::string type) : type_(type){
	std::cout << PURPLE << "Father class Animal-- PARAMETERIED constructor called\n"
	<< RESET;
}

Animal::Animal(const Animal& other) : type_(other.type_){
	std::cout << PURPLE << "Father class Animal-- COPY constructor called\n"
	<< RESET;
}

Animal::~Animal(){
	std::cout << PURPLE << "Father class Animal-- DECONSTRUCTOR called\n"
	<< RESET;
}

Animal&	Animal::operator=(const Animal& other){
	std::cout << PURPLE << "Father class Animal-- ASSIGNMENT operator called\n"
	<< RESET;
	if (this != &other){
		this->type_ = other.type_;
	}
	return *this;
}

void	Animal::makeSound() const{}

std::string	Animal::getType() const{
	return this->type_;
}
void	Animal::setType(const std::string newType){
	this->type_ = newType;
}
