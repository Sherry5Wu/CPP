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
#include "Intern.hpp"


#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define PURPLE "\033[0;35m"
#define RESET "\033[0;0m"

static void	printString(const std::string& msg, std::string colour){
	std::cout << colour << msg << RESET << std::endl;
}

int main(){
	Intern	worker;

	printString("1.Testing making shrubbery form\n", PURPLE);
	AForm* shrub = worker.makeForm("shrubbery", "strawberry");
	shrub->executeForm();

	printString("\n2.Testing making robot form\n", PURPLE);
	AForm* robot = worker.makeForm("robotomy", "bee");
	robot->executeForm();

	printString("\n3.Testing making president form\n", PURPLE);
	AForm* pres = worker.makeForm("presidential", "Luiea");
	pres->executeForm();

	printString("\n4.Testing making invalid form\n", PURPLE);
	worker.makeForm("shrubber", "xxx");

	printString("\n5.Testing making nullptr string\n", PURPLE);
	worker.makeForm("", "xxx");

	printString("\n6.Testing valid form with nullptr target \n", PURPLE);
	AForm* aaa = worker.makeForm("presidential", "");
	aaa->executeForm();

	std::cout << std::endl;
	delete shrub;
	delete robot;
	delete pres;
	delete aaa;

	return 0;
}

