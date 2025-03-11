/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:03:18 by jingwu            #+#    #+#             */
/*   Updated: 2025/02/24 14:03:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define GREEN "\033[1;32m"

#if 1
static void	fromSubject(){
	const Animal* meta = new Animal();
	std::cout << "--------------------------------------------\n";
	const Animal* j = new Dog();
	std::cout << "--------------------------------------------\n";
	const Animal* i = new Cat();
	std::cout << "--------------------------------------------\n";

	std::cout << j->getType() << " " << std::endl;
	j->makeSound(); // will output the dog sound!
	std::cout << "--------------------------------------------\n";

	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << "--------------------------------------------\n";
	meta->makeSound(); // will not output any sound!

	std::cout << "Always remeber to free memories that be created\n\n";
	delete i;
	i = nullptr;

	std::cout << "--------------------------------------------\n";
	delete j;
	j = nullptr;

	std::cout << "--------------------------------------------\n";
	delete meta;
	meta = nullptr;
}
#endif

static void	postiveTestCases(){
	Animal	bird;
	Dog		goldebRetriever;
	Dog		dogCopy(goldebRetriever);
	Cat		britishShort;
	Cat		catCopy(britishShort);

	std::cout << "\nAnimal sound\n";
	bird.makeSound();

	std::cout << "\nDog sound\n";
	goldebRetriever.makeSound();
	dogCopy.makeSound();

	std::cout << "\nCat sound\n";
	britishShort.makeSound();
	catCopy.makeSound();
}

static void	negativestCase(){
	WrongAnimal	wrongAnimal;
	std::cout<< wrongAnimal.getType() << std::endl;
	wrongAnimal.makeSound();
	std::cout << "\n********************************************************\n";
	WrongCat	cat;
	std::cout<< cat.getType() << std::endl;
	cat.makeSound();

	std::cout << "\n********************************************************\n";
	const WrongAnimal *catA = new WrongCat();
	std::cout << catA->getType() << "\n";
	std::cout << "We are expected hear cat sounds, but because we write the "
	<< "'makeSound' function wrongly.\nSo we will hear the sound like this:\n";
	catA->makeSound();

	delete catA;
}

// Animal is Purple color, Dog is dark-yellow, cat is blue color
int main(){
	std::cout << GREEN << "------------Test cases from Subject----------------\n\n" << RESET;
	fromSubject();

	std::cout << GREEN << "\n------------Postive test cases------------\n\n"<< RESET;
	postiveTestCases();

	std::cout << GREEN << "\n------------WrongAnimal test cases------------\n\n"<< RESET;
	negativestCase();
	return 0;
}

