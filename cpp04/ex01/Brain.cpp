#include "Brain.hpp"

Brain::Brain(){
	std::cout << CYAN << "Brain class -- default constructor called\n"<< RESET;
	for (int i = 0; i < 100; i++){
		ideas_[i] = "This is a default idea";
	}
}

Brain::Brain(const Brain& other){
	std::cout << CYAN << "Brain class -- copy constructor called\n"<< RESET;
	for (int i = 0; i < 100; i++){
		ideas_[i] = other.ideas_[i];
	}
}

Brain::~Brain(){
	std::cout << CYAN << "Brain class -- deconstructor called\n"<< RESET;
}

Brain& Brain::operator=(const Brain& other){
	std::cout << CYAN << "Brain class -- copy constructor called\n"<< RESET;
	if (this != &other){
		for (int i = 0; i < 100; i++){
			ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}