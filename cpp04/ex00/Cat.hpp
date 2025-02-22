#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>
#define BLUE "\033[0;34m"

class Cat : public Animal{
	public:
		Cat();
		Cat(const std::string type);
		Cat(const Cat& other);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound() const override;
};

#endif //CAT_HPP