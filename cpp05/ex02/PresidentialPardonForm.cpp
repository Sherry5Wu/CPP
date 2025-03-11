/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:55:39 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:55:39 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
: AForm("Presidential_Pardon_Form", 25, 5, "unknow"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential_Pardon_Form", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o) : AForm(o){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& o){
	if (this != &o){
		AForm::operator=(o);
	}
	return *this;
}

void	PresidentialPardonForm::executeForm() const{
	// if (!getIsSigned()){
	// 	throw FormNotSignedException("From isn't signed yet");
	// }
	// if (executor.getGrade() > this->geteGradeToExecute()){
	// 	throw GradeTooLowException("The executor's grade is too low, can't execute");
	// }
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}
