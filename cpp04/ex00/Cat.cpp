#include "Cat.hpp"

Cat::Cat() : Animal(){
	std::cout << BLUE << "Cat class -- Default constructor called\n"
	<< RESET;
	this->type_ = "Cat";
}

Cat::Cat(const std::string type) : Animal(type){
	std::cout << BLUE << "Cat class -- Parameterized constructor called\n"
	<< RESET;
	this->type_ = "Cat";
}

Cat::Cat(const Cat& other): Animal(other){
	std::cout << BLUE << "Cat class -- Copy constructor called\n"
	<< RESET;
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
Cat::~Cat(){
	std::cout << BLUE << "Cat class -- Deconstructor called\n"
	<< RESET;
}

Cat&	Cat::operator=(const Cat& other){
	if (this != &other){
		Animal::operator=(other);
		std::cout << BLUE << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	Cat::makeSound() const{
	std::cout << BLUE << "Miao Miao Miao...\n"<< RESET;
}