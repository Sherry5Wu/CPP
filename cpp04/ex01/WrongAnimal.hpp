#pragma once

#include <iostream>
#include <string>
#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

class WrongAnimal{
	protected:
		std::string	type_;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		std::string		getType() const;
		void			makeSound() const;
};