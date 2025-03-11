/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:34 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:34 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNHPP
# define INTERNHPP

#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);
		AForm*	makeForm(const std::string& name, const std::string& target);
		static AForm* makeShrub(const std::string& target);
		static AForm* makeRobot(const std::string& target);
		static AForm* makePresi(const std::string& target);
};

#endif // INTERNHPP
