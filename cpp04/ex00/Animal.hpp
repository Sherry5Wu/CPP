#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal{
	protected:
		std::string	type_;

		Animal();
		Animal(const std::string type);
		Animal(const Animal& other);
		~Animal();

		Animal&	operator=(const Animal& other);
	public:
		void				makeSound();
		const std::string	getType();
		void				setType(const std::string newType);

};

#endif