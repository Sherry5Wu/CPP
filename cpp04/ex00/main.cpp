#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void	fromSubject(){
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); // will output the dog sound!
	meta->makeSound(); // will not output any sound!

	// free memories
	delete i;
	i = nullptr;
	delete j;
	j = nullptr;
	delete meta;
	meta = nullptr;
}

static void	postiveTestCases(){

}

static void	negativestCase(){

}

// Animal is Purple color, Dog is dark-yellow, cat is blue color
int main(){

	// not Done Yet

	std::cout << "Test cases from Subject:\n";
	fromSubject();

	std::cout << "\nPostive test cases:\n";
	postiveTestCases();

	std::cout << "\nNegative test cases:\n";
	negativestCase();
	return 0;
}

