#ifndef INTERNHPP
# define INTERNHPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);
		AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif // INTERNHPP