/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:55:49 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:55:49 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
: AForm("Robotomy_Request_Form", 72, 45, "unknow"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy_Request_Form", 72, 45, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o) : AForm(o){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& o){
	if (this != &o){
		AForm::operator=(o);
	}
	return *this;
}

/**
 * std::tim(0):
 *  -- std::time: is a function in the C++ <ctime> header that returns the current
 *    calendar time as the number of seconds elapsed since January 1,1970
 *    (the Unix epoch).
 *  -- When you pass 0 to std::time(0), it returns the current time as an integer
 *    representing the number of seconds since that epoch.
 *  -- The number of seconds is typically a constantly increasing value, meaning
 *     it will vary each time you call std::time(0).
 *
 * std::srand(...):
 *  -- std::srand is a function in the C++ <cstdlib> header that sets the seed for
 *     the pseudo-random number generator used by std::rand().
 *  -- By providing a seed to std::srand, you ensure that the random numbers
 *     generated by std::rand() will be different each time your program runs
 *     (since the seed changes over time).
 *  -- Without seeding, std::rand() would produce the same sequence of numbers
 *     every time you run the program, which is not useful for random behavior.
 *
 * So, std::srand(std::time(0)) ensures that each time you run your program,
 * the random number sequence will be different because the time at the moment
 * of execution will be different.
 */
void	RobotomyRequestForm::executeForm() const{
	std::cout << "Drilling noises is coming: Ziiii Ziiiiii Ziiiiiii\n";

	std::srand(std::time(0)); // set a seed
	bool	isSuccessed = std::rand() % 2; // based on the seed to generate random number
	if (isSuccessed){
		std::cout << this->getTarget() << " has been robotomized\n";
	}else{
		std::cout << this->getTarget() << " robotomy failed.\n";
	}
}
