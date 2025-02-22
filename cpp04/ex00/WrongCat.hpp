#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>


class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		// WrongCat(const std::string type);
		WrongCat(const WrongCat& other);
		~WrongCat();

		WrongCat&	operator=(const WrongCat& other);

		void	makeSound() const;
};

#endif //WRONGCAT_HPP