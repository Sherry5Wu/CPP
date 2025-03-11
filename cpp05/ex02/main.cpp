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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	printPurpleFond("1. testing three forms' constructors\n");
	ShrubberyCreationForm	shrub;
	RobotomyRequestForm		robot;
	PresidentialPardonForm	pres("Vice_president");

	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pres << std::endl;
}

static void	shrubTesting(const Bureaucrat& greatGuy, const Bureaucrat& nobody){
	ShrubberyCreationForm	form("bluebery");
	std::cout << std::endl << form << std::endl;

	printPurpleFond("2. Execute a form without signing it\n");
	try{
		form.execute(greatGuy);
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n3. sign the form\n");
	form.beSigned(greatGuy);
	std::cout << form << std::endl;

	printPurpleFond("\n4. nobody(grade too low) is going to execute shrub form\n");
	try{
		form.execute(nobody);
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n5. greatGuy(grade is good) is going to execute shrub form\n");
	form.execute(greatGuy);
}


static void	robotTesting(const Bureaucrat& greatGuy, const Bureaucrat& nobody){
	RobotomyRequestForm	form("eating_robot");
	std::cout << form << std::endl;

	printPurpleFond("1. Execute a form without signing it\n");
	try{
		form.execute(greatGuy);
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n2. sign the form\n");
	form.beSigned(greatGuy);
	std::cout << form << std::endl;

	printPurpleFond("\n3. nobody(grade too low) is going to execute robot form\n");
	try{
		form.execute(nobody);
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n4. greatGuy(grade is good) is going to execute robot form\n");
	form.execute(greatGuy);
}
#endif

static void	presidentTesting(const Bureaucrat& greatGuy, const Bureaucrat& nobody){
	PresidentialPardonForm	form("vice_president");
	std::cout << form << std::endl;

	printPurpleFond("1. Execute a form without signing it\n");
	try{
		form.execute(greatGuy);
	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n2. sign the form\n");
	form.beSigned(greatGuy);
	std::cout << form << std::endl;

	printPurpleFond("\n3. nobody(grade too low) is going to execute president form\n");
	try{
		form.execute(nobody);
	} catch(std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	printPurpleFond("\n4. greatGuy(grade is good) is going to execute president form\n");
	form.execute(greatGuy);
}

int main(){
	printGreenFond("<--------------constructors testing----------------->\n");
	constructorsTesting();

	Bureaucrat	boss("Boss", 5);
	Bureaucrat	manager("Manager", 45);
	Bureaucrat	worker("Workder", 137);
	Bureaucrat nobody("nobody", 138);

	std::cout << boss << std::endl;
	std::cout << manager << std::endl;
	std::cout << worker << std::endl;
	std::cout << nobody << std::endl;

	printGreenFond("\n<--------------ShrubberyCreationForm testing----------------->\n");
	shrubTesting(worker, nobody);

	printGreenFond("\n<--------------RobotomyRequestForm testing----------------->\n");
	robotTesting(manager, nobody);

	printGreenFond("\n<--------------PresidentialPardonForm testing----------------->\n");
	presidentTesting(boss, nobody);

	return 0;
}

