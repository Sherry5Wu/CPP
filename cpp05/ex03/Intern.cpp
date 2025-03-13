/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:30 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:30 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other){
	(void)other;
}

Intern::~Intern(){}

Intern&	Intern::operator=(const Intern& other){
	(void)other;
	return *this;
}

AForm* Intern::makeShrub(const std::string& target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobot(const std::string& target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresi(const std::string& target){
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& name, const std::string& target){
	std::string formType[3] = {"shrubbery", "robotomy", "presidential"};

	// the function array point to form making functions
	AForm* (*formFunction[3])(const std::string& target) = {&Intern::makeShrub,
															&Intern::makeRobot,
															&Intern::makePresi};

	for (int i = 0; i < 3 ;i++){
		if (name == formType[i]){
			std::cout << "Intern creates " << formType[i] << std::endl;
			return formFunction[i](target);
		}
	}
	std::cout << "Invalid form type, can't create that form\n";
	return 0;
}
