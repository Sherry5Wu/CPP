#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
	std::cout << "This is default constrctor\n";
}

Fixed::Fixed(const Fixed &newValue){
	std::cout << "This is copy constructor\n";
	*this = newValue;
}

Fixed	&Fixed::operator=(const Fixed &newValue){
	if (this != &newValue){
		std::cout << "This is copy assignment operator\n";
		this->value_ = newValue.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "This is deconstructor\n";
}

int	Fixed::getRawBits() const{
	// return this->value_ equals to return value_
	return value_;
}

void	Fixed::setRawBits(int const raw){
	this->value_ = raw;
}