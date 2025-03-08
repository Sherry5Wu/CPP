#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern::~Intern(){}

Intern&	Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target){
	std::string formType[] = {"shrubbery", "robotomy", "predidential"};

	AForm* (*from)
}