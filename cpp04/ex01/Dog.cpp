#include "Dog.hpp"

Dog::Dog() : Animal(){
	std::cout << DARK_YELLOW << "Dog class -- Default constructor called\n"
	<< RESET;
	this->type_ = "Dog";
	this->brain_ = new Brain();
}

Dog::Dog(const std::string type) : Animal(type){
	std::cout << DARK_YELLOW << "Dog class -- Parameterized constructor called\n"
	<< RESET;
	this->type_ = "Dog";
	this->brain_ = new Brain();
}

Dog::Dog(const Dog& other): Animal(other){
	std::cout << DARK_YELLOW << "Dog class -- Copy constructor called\n"
	<< RESET;
	this->brain_ = new Brain(*other.brain_);
}

// Here we don't need ":Animal()", because we don't need to call
// father class.
Dog::~Dog(){
	std::cout << DARK_YELLOW << "Dog class -- Deconstructor called\n"
	<< RESET;
	delete this->brain_;
	this->brain_ = nullptr;
}

Dog&	Dog::operator=(const Dog& other){
	if (this != &other){
		Animal::operator=(other);
		if (this->brain_ != nullptr){
			delete this->brain_;
			this->brain_ = nullptr;
		}
		this->brain_ = new Brain(*other.brain_);
		std::cout << DARK_YELLOW << "Dog class -- Assignment operator called\n"
		<< RESET;
	}
	return *this;
}

void	Dog::makeSound() const{
	std::cout << DARK_YELLOW << "Wang Wang Wang...\n" << RESET;
}