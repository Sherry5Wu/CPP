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
#include "Bureaucrat.hpp"

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0;0m"

static void	printGreenFond(const std::string& msg){
	std::cout << GREEN << msg << RESET << std::endl;
}

static void	printPurpleFond(const std::string& msg){
	std::cout << PURPLE << msg << RESET << std::endl;
}

int main(){
	printGreenFond("<----------------Instantiation Positive Testing--------------------------------->");
	printPurpleFond("1. default constructor testing");
	try{
		Bureaucrat normalA;
		normalA.print();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}


	printPurpleFond("2. parameterized constructor testing");
	try{
		Bureaucrat normalA("normal", 1);
		normalA.print();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat normalA("normal", 150);
		normalA.print();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printGreenFond("\n<----------------Instantiation Negative Testing--------------------------------->");
	printPurpleFond("3. grade is too low");
	try{
		Bureaucrat tooLow("toolow", 151);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printPurpleFond("4. grade is too high");
	try{
		Bureaucrat tooHigh("toohigh", 0);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printGreenFond("\n<----------------Increase--------------------------------->");
	printPurpleFond("5. Increase postively");
	Bureaucrat bob("Bob", 3);
	std::cout << "Before incresement\n";
	bob.print();
	try{
		bob.increament();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "After incresement\n";
	bob.print();

	try{
		bob.increament();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "After incresement again\n";
	bob.print();

	printPurpleFond("6. Increase negatively");
	try{
		bob.increament();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	bob.print();

	printGreenFond("\n<----------------Decrease--------------------------------->");
	printPurpleFond("7. Decrease postively");
	Bureaucrat ali("Ali", 148);
	std::cout << "Before decresement\n";
	ali.print();
	try{
		ali.decrement();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "After decresement\n";
	ali.print();

	try{
		ali.decrement();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "After decresement again\n";
	ali.print();

	printPurpleFond("8. Decrease negatively");
	try{
		ali.decrement();
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	ali.print();

	return 0;
}

