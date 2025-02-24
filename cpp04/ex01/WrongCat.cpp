#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << ORANGE << "WrongCat class -- Default constructor called\n"
	<< RESET;
	this->type_ = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
	std::cout << ORANGE << "WrongCat class -- Copy constructor called\n"
	<< RESET;
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
WrongCat::~WrongCat(){
	std::cout << ORANGE << "WrongCat class -- Deconstructor called\n"
	<< RESET;
}

WrongCat&	WrongCat::operator=(const WrongCat& other){
	if (this != &other){
		WrongAnimal::operator=(other);
		std::cout << ORANGE << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	WrongCat::makeSound() const{
	std::cout << ORANGE << "Miao Miao Miao...\n"<< RESET;
}