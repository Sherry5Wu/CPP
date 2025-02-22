#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
#define DARK_YELLOW "\033[0;33m"


class Dog : public Animal{
	public:
		Dog();
		Dog(const std::string type);
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		void	makeSound() const override;
};

#endif // DOG_HPP