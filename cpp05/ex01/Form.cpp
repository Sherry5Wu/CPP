/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:55:09 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:55:09 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name_("default_form"), isSigned_(false), gradeToSign_(150),
GradeToExecute_(150){}

Form::Form(const std::string& name, int gradeToS, int gradeToG) : name_(name),
isSigned_(false), gradeToSign_(gradeToS), GradeToExecute_(gradeToG){
	if (gradeToSign_ < 1 || GradeToExecute_ < 1){
		throw GradeTooHighException("Grade too high, failed to construct");
	}
	if (gradeToSign_ > 150 || GradeToExecute_ > 150){
		throw GradeTooLowException("Grade too low, failed to construct");
	}
}

Form::Form(const Form& other) : name_(other.name_), isSigned_(other.isSigned_),
gradeToSign_(other.gradeToSign_), GradeToExecute_(other.GradeToExecute_){}

Form::~Form(){}

Form&	Form::operator=(const Form& other){
	if (this != &other){
		isSigned_ = other.isSigned_;
	}
	return *this;
}

const std::string&	Form::getName() const{
	return name_;
}

bool	Form::getIsSigned() const{
	return isSigned_;
}

int	Form::getGradeToSign() const{
	return gradeToSign_;
}

int	Form::geteGradeToExecute() const{
	return GradeToExecute_;
}

void	Form::beSigned(const Bureaucrat& bureau){
	if (bureau.getGrade() > gradeToSign_){
		throw GradeTooLowException("grade is too low");
	} else {
		isSigned_ = true;
	}
}

/*--------------------------Exception funtions-------------------------------*/

Form::GradeTooHighException::GradeTooHighException(const std::string& message)
: message_(message){}

/**
 * Here the function needs to return "const char*" type value, but message_
 * is a std::string type, so here need use "c_str()" to change message_ to
 * "const char*"
 */
const char* Form::GradeTooHighException::what() const noexcept{
	return message_.c_str();
}

Form::GradeTooLowException::GradeTooLowException(const std::string& message)
: message_(message){}

const char* Form::GradeTooLowException::what() const noexcept{
	return message_.c_str();
}

/*--------------------------opertator <<-------------------------------*/
std::ostream&	operator<<(std::ostream& os, const Form& form){
	os << " * Form's name: " << form.getName() << "\n"
		<< " * isSigned: " << form.getIsSigned() << "\n"
		<< " * Grade to Sign: " << form.getGradeToSign() << "\n"
		<< " * Grade to Execute: " << form.geteGradeToExecute() << "\n";
	return os;
}
