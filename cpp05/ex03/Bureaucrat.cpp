/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 08:56:23 by jingwu            #+#    #+#             */
/*   Updated: 2025/03/11 08:56:23 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name_("default"), grade_(150){}

Bureaucrat::Bureaucrat(const std::string name, int grade): name_(name){
	if (grade < 1){
		throw GradeTooHighException();
	}
	else if (grade >150){
		throw GradeTooLowException();
	}else{
		grade_ = grade;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_),
grade_(other.grade_){}


Bureaucrat::~Bureaucrat(){}

/**
 * @brief Because name_ is const type, so can't be overwrite, so here
 * just need to copy grade
 */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other){
	if (this != &other){
		grade_ = other.grade_;
	}
	return *this;
}


const std::string&	Bureaucrat::getName() const{
	return name_;
}
int	Bureaucrat::getGrade() const{
	return grade_;
}

/**
 * Here we need to check if the grade will be over range first before to do
 * the self minus operation. Because if we do the operation first, then the
 * value of the grade_ already been changes even though it is invalid.
 */
void	Bureaucrat::increament(){
	if (grade_ == 1){
		throw GradeTooHighException();
	}
	grade_--;
}

void	Bureaucrat::decrement(){
	if (grade_ == 150){
		throw GradeTooLowException();
	}
	grade_++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept{
	return "Grade is too low!";
}

void	Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	}catch (const std::exception& e){
		std::cerr << name_ << " couldn't sign " << form.getName()
		<< ", because " << e.what() << std::endl; // what is what()?????
	}
}

void	Bureaucrat::executeForm(const AForm& form){
	try{
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	}catch (const std::exception& e){
		std::cerr << name_ << "'s grade it too low to execute " << form.getName()
		<< std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}

/*---------below functions are for the conveniences of testing---------*/
void	Bureaucrat::print() const{
	std::cout << " * Name: " << name_ << std::endl;
	std::cout << " * Grade: " << grade_ << std::endl;
}
