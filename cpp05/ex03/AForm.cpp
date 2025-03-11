/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:15 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:15 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name_("default_AForm"), isSigned_(false), gradeToSign_(150),
GradeToExecute_(150), traget_("default_target"){}

AForm::AForm(const std::string& name, int gradeToS, int gradeToG, const std::string& target)
: name_(name), isSigned_(false), gradeToSign_(gradeToS), GradeToExecute_(gradeToG),
traget_(target){
	if (gradeToSign_ < 1 || GradeToExecute_ < 1){
		throw GradeTooHighException("Grade too high, failed to constrcut");
	}
	if (gradeToSign_ > 150 || GradeToExecute_ > 150){
		throw GradeTooLowException("Grade too low, failed to constrcut");
	}
}

AForm::AForm(const AForm& other) : name_(other.name_), isSigned_(other.isSigned_),
gradeToSign_(other.gradeToSign_), GradeToExecute_(other.GradeToExecute_),
traget_(other.traget_){}

AForm::~AForm(){}

AForm&	AForm::operator=(const AForm& other){
	if (this != &other){
		isSigned_ = other.isSigned_;
	}
	return *this;
}

const std::string&	AForm::getName() const{
	return name_;
}

bool	AForm::getIsSigned() const{
	return isSigned_;
}

int	AForm::getGradeToSign() const{
	return gradeToSign_;
}

int	AForm::geteGradeToExecute() const{
	return GradeToExecute_;
}

const std::string&	AForm::getTarget() const{
	return traget_;
}

void	AForm::beSigned(const Bureaucrat& bureau){
	if (bureau.getGrade() > gradeToSign_){
		throw GradeTooLowException("Grade too low, can't not sign the AForm");
	} else {
		isSigned_ = true;
	}
}

void	AForm::execute(const Bureaucrat& executor) const{
	if (!getIsSigned()){
		throw FormNotSignedException("From isn't signed yet");
	}
	if (executor.getGrade() > this->geteGradeToExecute()){
		throw GradeTooLowException("The executor's grade is too low, can't execute");
	}
	this->executeForm(executor);
}

/*--------------------------Exception funtions-------------------------------*/

AForm::GradeTooHighException::GradeTooHighException(const std::string& message)
: message_(message){}

/**
 * Here the function needs to return "const char*" type value, but message_
 * is a std::string type, so here need use "c_str()" to change message_ to
 * "const char*"
 */
const char* AForm::GradeTooHighException::what() const noexcept{
	return message_.c_str();
}

AForm::GradeTooLowException::GradeTooLowException(const std::string& message)
: message_(message){}

const char* AForm::GradeTooLowException::what() const noexcept{
	return message_.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string& message)
: message_(message){}

const char* AForm::FormNotSignedException::what() const noexcept{
	return message_.c_str();
}

/*--------------------------opertator <<-------------------------------*/
std::ostream&	operator<<(std::ostream& os, const AForm& form){
	os << " * AForm's name: " << form.getName() << "\n"
		<< " * isSigned: " << form.getIsSigned() << "\n"
		<< " * Grade to Sign: " << form.getGradeToSign() << "\n"
		<< " * Grade to Execute: " << form.geteGradeToExecute() << "\n"
		<< " * Target is: " << form.getTarget() << "\n";
	return os;
}
