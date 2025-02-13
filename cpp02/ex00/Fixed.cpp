/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 09:13:48 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 09:13:48 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
	std::cout << "Default constrctor called\n";
}

/**
 * @brief In the C++ programming language, a copy constructor is a special
 * constructor for creating a new object as a copy of an existing object. Copy
 * constructors are the standard way of copying objects in C++.
 */
Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called\n";
	*this = other;
}

/**
 * @brief
 * My_Array first;           // initialization by default constructor
 * My_Array second(first);   // initialization by copy constructor
 * My_Array third = first;   // Also initialization by copy constructor
 * second = third;           // assignment by copy assignment operator
 */
Fixed&	Fixed::operator=(const Fixed& other){
	if (this != &other){ // protect against invalid self-assignment
		std::cout << "Copy assignment operator called\n";
		this->value_ = other.getRawBits();
	}
	// by convention, always return *this
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Deconstructor called\n";
}

int	Fixed::getRawBits() const{
	std::cout << "getRawBits member function called\n";
	// return this->value_ equals to return value_
	return value_;
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called\n";
	this->value_ = raw;
}
