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

#define AMONUT	(8)

static void	simpleTestCases(){
	const	Animal* dog = new Dog();
	const	Animal* cat = new Cat();
	std::cout << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << cat->getType() << std::endl;
	cat->makeSound();

	delete dog;
	dog = nullptr;
	delete cat;
	cat = nullptr;
}

static void	animalArrayTestCases(){
	const Animal	*animal[AMONUT];

	for (int i = 0; i < AMONUT; i++){
		if (i < AMONUT / 2)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}
	int j = 0;
	for (; j < AMONUT; j++){
		animal[j]->makeSound();
	}
	j--;
	for (; j >= 0; j--){
		delete animal[j];
		animal[j] = nullptr;
	}
}

static void	deepCopyTestCases(){
	Cat	cat;
	Cat	copyCat(cat);
	Cat	operatorCopyCat = cat;

	cat.makeSound();
	copyCat.makeSound();
	operatorCopyCat.makeSound();
}

// Animal is Purple color, Dog is dark-yellow, cat is blue color
int main(){
	std::cout << GREEN << "\n---------Simple test cases------------\n\n"<< RESET;
	simpleTestCases();

	std::cout << GREEN << "\n------------Animal Array test cases-------------\n\n"<< RESET;
	animalArrayTestCases();

	std::cout << GREEN << "\n------------Deep copy test cases-------------\n\n"<< RESET;
	deepCopyTestCases();

	return 0;
}

