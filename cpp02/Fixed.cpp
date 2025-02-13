/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:43:21 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/13 10:43:21 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
	std::cout << "Default constrctor called\n";
}

/**
 * @brief This function changes an integer number to a fixed-point number.
 * The way we do that is just move the integer fractional_bits(here is 8 bits)
 * left.
 */
Fixed::Fixed(const int number) : value_(number << this->fractional_bits_){
	std::cout << "Int constructor called\n";
}

/**
 * @brief This function changes a float number to a fixed-point number.
 * The way we do that : number * 2^(fractionl_bits), after this , the number
 * might still have fractions, then we use roundf to get rid of the fraction.
 */
Fixed::Fixed(const float number) : value_(roundf(number * (1 << this->fractional_bits_))){
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other){
	if (this != &other){
		std::cout << "Copy assignment operator called\n";
		// this->value_ = other.getRawBits();
		this->value_ = other.value_;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& outputStream, const Fixed& number){
	// Send the float repreasentation to the stream
	outputStream << number.toFloat();
	// return the stream for chaining
	return outputStream;
}

Fixed::~Fixed(){
	std::cout << "Deconstructor called\n";
}

int	Fixed::getRawBits() const{
	// return this->value_ equals to return value_
	return value_;
}

void	Fixed::setRawBits(int const raw){
	this->value_ = raw;
}

/**
 * @brief Becasue the fraction takes fractional_bits (8 bits here)
 * So if we move the parament to right 8 bits, then we will get ride
 * off the fraction part, only save the integer part in the parament.
 * And it we move a integer value to left 8 bits, then we change the
 * integer into a fixe-point value to save.
 */
int	Fixed::toInt() const{
	return this->value_ >> this->fractional_bits_;
}

/**
 * @brief static_cast<fast> kinda equals to float(value), but the first one
 * is more safe to use, because it explicitly tell the compiler that "I am
 * going to convert the value type."
 */
float	Fixed::toFloat() const{
	return static_cast<float>(this->value_) / (1 << this->fractional_bits_);
}
