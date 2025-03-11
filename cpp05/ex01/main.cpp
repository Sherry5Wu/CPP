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
#include "Form.hpp"

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

#if 1
static void	constructorsTesting(){
	printPurpleFond("\n1. defalut Form constrcutor\n");
	Form c;
	std::cout << c;

	printPurpleFond("\n2. parameterized Form constrcutor -- positive\n");
	Form flower("flower", 150, 1);
	std::cout << flower;

	printPurpleFond("\n3. parameterized Form constrcutor -- grade to sign is too high\n");
	try{
		Form x("x", 0, 42);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printPurpleFond("\n4. parameterized Form constrcutor -- grade to sign is too low\n");
	try{
		Form x("x", 151, 42);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printPurpleFond("\n5. parameterized Form constrcutor -- grade to execute is too high\n");
	try{
		Form x("x", 42, 0);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printPurpleFond("\n6. parameterized Form constrcutor -- grade to execute is too low\n");
	try{
		Form x("x", 42, 151);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}

	printPurpleFond("\n7. parameterized Form constrcutor -- ");
	printPurpleFond("grade to sign is too high but grade to execute is too low\n");
	try{
		Form x("x", 0, 151);
	}catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
}
#endif

static void	signFormTesting(){
	Form	applyingJob("Apply Jobs", 25, 10);
	Bureaucrat	eris("Eris", 26);
	Bureaucrat	jenny("Jenny", 24);
	Bureaucrat	julie("Julie", 25);

	eris.signForm(applyingJob);
	jenny.signForm(applyingJob);
	julie.signForm(applyingJob);
}

int main(){
	printGreenFond("<-------Form constructors testing--------->\n");
	constructorsTesting();

	printGreenFond("\n<-----------signForm testing------------->\n");
	signFormTesting();

	return 0;
}

