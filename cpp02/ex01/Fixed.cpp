#include "Fixed.hpp"

Fixed::Fixed() : value_(0){
	std::cout << "This is default constrctor\n";
}

Fixed::Fixed(const int number) : value_(number << this->fractional_bits_){
	std::cout << "This is Int constructor\n";
}

Fixed::Fixed(const float number) : value_(roundf(number * (1 << this->fractional_bits_))){
	std::cout << "This is Float constructor\n";

	// which one is correct?
	// this->value_ = (int)roundf(number * (1 << this->fractional_bits_));
	// this->value_ = roundf(number * (1 << this->fractional_bits_));
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

std::ostream	&operator << (std::ostream &outputStream, const Fixed &number){
	outputStream << number.toFloat();
	// do I need return it here?
	return outputStream;
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

int	Fixed::toInt() const{
	return this->value_ >> this->fractional_bits_;
}

float	Fixed::toFloat() const{
	return static_cast<float>(this->value_) / (1 << this->fractional_bits_);
}