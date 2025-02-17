#include "Animal.hpp"

Animal::Animal() : type_(""){
	std::cout << "Father class Animal-- DEFAULT constructor called\n";
}

Animal::Animal(const std::string type) : type_(type){
	std::cout << "Father class Animal-- PARAMETRIED constructor called\n";
}


Animal::Animal(const Animal& other) : type_(other.type_){
	std::cout << "Father class Animal-- COPY constructor called\n";
}

Animal::~Animal(){
	std::cout << "Father class Animal-- DECONSTRUCTOR called\n";
}

Animal&	Animal::operator=(const Animal& other){
	std::cout << "Father class Animal-- ASSIGNMENT operator called\n";
	if (this != &other){
		this->type_ = other.type_;
	}
	return *this;
}

void	Animal::makeSound(){

}
		const std::string	getType();
		void				setType(const std::string newType);